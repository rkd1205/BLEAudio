/**
  *******************************************************************************
  * @file    DataLogExtended\Src\vcom.c
  * @brief   VCOM message handler
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "cube_hal.h"
#include "vcom.h"
#include "main.h"

/** @addtogroup SENSORTILE_Examples
  * @{
  */

/** @addtogroup DATALOG_EXTENDED DATALOG EXTENDED
  * @{
  */

/* Private typedef -----------------------------------------------------------*/

/* Private defines -----------------------------------------------------------*/
#define DATA_SIZE  (2 * TMsg_MaxLen)

/* Private macro -------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/
USBD_HandleTypeDef USBD_Device;

volatile uint8_t VCOM_RxData    = 0;    /* Data received from USB (Yes = 1, No = 0). */
volatile uint8_t *VCOM_RxBuffer = NULL; /* Pointer to data buffer (received from USB). */
volatile uint32_t VCOM_RxLength = 0;    /* Data length (received from USB). */

/* Private variables ---------------------------------------------------------*/
static uint8_t dataOut[DATA_SIZE]; /*!< DataOut buffer */

/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

/**
  * @brief  Initialize VCOM (Virtual COM Port)
  * @param  None
  * @retval Init OK: 0, Init ERROR: 1 (_TODO_: implement this)
  */
int VCOM_init(void)
{
  /* Enable USB power on Pwrctrl CR2 register */
  HAL_PWREx_EnableVddUSB();

  /*** USB CDC Configuration ***/
  /* Init Device Library */
  USBD_Init(&USBD_Device, &VCP_Desc, 0);

  /* Add Supported Class */
  USBD_RegisterClass(&USBD_Device, USBD_CDC_CLASS);

  /* Add Interface callbacks for CDC Class */
  USBD_CDC_RegisterInterface(&USBD_Device, &USBD_CDC_fops);

  /* Start Device Process */
  USBD_Start(&USBD_Device);

  return 0;
}

/**
  * @brief  Check if a message is received via VCOM and read it.
  * @param  Msg the pointer to the message to be received
  * @param  len_max Max. length of message.
  * @retval Message status.
  */
vcom_msg_status_t VCOM_receive_MSG(TMsg *Msg, uint32_t len_max)
{
  vcom_msg_status_t status;

  /* VCOM data receive not completed or no VCOM data received at all. */
  if (VCOM_RxData == 0)
  {
    return NO_DATA;
  }

  /* ERROR: No VCOM data ready. */
  if (VCOM_RxLength == 0 || VCOM_RxBuffer == NULL)
  {
    Error_Handler();
  }

  /* Read message. */
  uint32_t s0_index = 0;
  uint32_t s1_index = 1;
  uint32_t d_index  = 0;
  uint32_t incr     = 0;
  while (1)
  {
    uint8_t  source[2];
    uint8_t* dest;

    /* End of VCOM recieve buffer.
       ERROR: Unexpected end of message. */
    if (s0_index >= VCOM_RxLength)
    {
      status = UNEXP_END_ERR;
      break;
    }

    source[0] = VCOM_RxBuffer[s0_index];

    /* End of message found. */
    if (source[0] == TMsg_EOF)
    {
      status = OK;
      break;
    }

    /* Message length exceeded */
    if (d_index >= len_max)
    {
      status = MSG_LEN_ERR;
      break;
    }

    /* End of VCOM recieve buffer.
       ERROR: Unexpected end of message. */
    if (s1_index >= VCOM_RxLength)
    {
      status = UNEXP_END_ERR;
      break;
    }

    source[1] = VCOM_RxBuffer[s1_index];
    dest      = &Msg->Data[d_index];

    incr = ReverseByteStuffCopyByte2(source[0], source[1], dest);
    Msg->Len = d_index + 1;

    /* ERROR: Invalid sequence found. */
    if (incr == 0)
    {
      status = WRONG_SEQ_ERR;
      break;
    }

    s0_index += incr;
    s1_index = s0_index + 1;
    d_index++;
  }

  switch (status)
  {
  case OK:
    {
      /* More data in VCOM recieve buffer. */
      if (s1_index < VCOM_RxLength)
      {
        VCOM_RxBuffer += s1_index;
        VCOM_RxLength -= s1_index;
      }

      /* End of VCOM recieve buffer. */
      else
      {
        VCOM_RxData   = 0;
        VCOM_RxBuffer = NULL;
        VCOM_RxLength = 0;

        CDC_Next_Packet_Rx();
      }

      /* Check message integrity. */
      if (CHK_CheckAndRemove(Msg))
      {
        return OK;
      }

      else
      {
        return WRONG_CHECK_ERR;
      }
    }

  case UNEXP_END_ERR:
    {
      VCOM_RxData   = 0;
      VCOM_RxBuffer = NULL;
      VCOM_RxLength = 0;

      CDC_Next_Packet_Rx();

      return UNEXP_END_ERR;
    }

  case WRONG_SEQ_ERR:
    {
      VCOM_RxBuffer += s1_index;
      VCOM_RxLength -= s1_index;

      return WRONG_SEQ_ERR;
    }

  case MSG_LEN_ERR:
    {
      VCOM_RxBuffer += s0_index;
      VCOM_RxLength -= s0_index;

      return MSG_LEN_ERR;
    }

  default:
    return UNKNOWN_ERROR;
  }
}

/**
  * @brief  Send a message via VCOM
  * @param  Msg the pointer to the message to be sent
  * @retval None
  */
vcom_msg_status_t VCOM_send_MSG(TMsg *Msg)
{
  uint32_t length;
  uint32_t written;

  CHK_ComputeAndAdd(Msg);
  length = ByteStuffCopy(dataOut, Msg);

  if (CDC_Fill_Buffer(dataOut, length, &written) == USBD_OK)
  {
    return OK;
  }

  else
  {
    return UNKNOWN_ERROR;
  }
}

/**
 * @brief  Read from VCOM
 * @param  Pointer to buffer.
 * @param  Data max. length.
 * @retval Number of really read data bytes.
 */
uint32_t VCOM_read(char *buffer, uint32_t len_max)
{
  /* VCOM data receive not completed or no VCOM data received at all. */
  if (VCOM_RxData == 0)
  {
    return 0;
  }

  /* ERROR: No VCOM data ready. */
  if (VCOM_RxLength == 0 || VCOM_RxBuffer == NULL)
  {
    Error_Handler();
  }

  /* Read all data */
  if (VCOM_RxLength <= len_max)
  {
    uint32_t len = VCOM_RxLength;
    memcpy((uint8_t*)buffer, (uint8_t*)VCOM_RxBuffer, len);

    VCOM_RxData   = 0;
    VCOM_RxBuffer = NULL;
    VCOM_RxLength = 0;

    CDC_Next_Packet_Rx();
    return len;
  }
  /* Read part of data that fits into buffer. */
  else
  {
    memcpy((uint8_t*)buffer, (uint8_t*)VCOM_RxBuffer, len_max);

    VCOM_RxBuffer += len_max;
    VCOM_RxLength -= len_max;

    return len_max;
  }
}

/**
 * @brief  Write to VCOM
 * @param  Pointer to buffer.
 * @param  Number of data bytes to write.
 * @retval Number of really written data bytes.
 */
uint32_t VCOM_write(char *buffer, uint32_t len)
{
  uint32_t written;

  CDC_Fill_Buffer((uint8_t *)buffer, len, &written);
  return written;
}

/**
  * @}
  */

/**
  * @}
  */

