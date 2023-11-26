/**
  ******************************************************************************
  * @file    BLEMLC\Src\main.c
  * @author  System Research & Applications Team - Agrate/Catania Lab.
  * @version V1.5.0
  * @date    27-Mar-2023
  * @brief   Main program body
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

/** 
 *
 * @page BLEMLC Example on how to program the Machine Learning Core and Finite State Machine
 * 
 * @image html st_logo.png
 *
 * <b>Introduction</b>
 *
 * This firmware package includes Components Device Drivers, Board Support Package
 * and example application for the following STMicroelectronics elements:
 * - STEVAL-MKSBOX1V1 (SensorTile.box) evaluation board that contains the following components:
 *     - MEMS sensor devices: HTS221, LPS22HH, LIS2MDL, LSM6DSOX
 *     - analog microphone
 *
 *
 * <b>Example Application</b>
 *
 * The Example application initializes all the Components, Loading the program on Machine Learning Core (MLC)
 * or Finite State Machine (FSM), initializes the Library creating some Custom Bluetooth services:
 * - The first service exposes all the HW/SW characteristics:
 *    - LSM6DSOX MLC results: Activity Recognition
 *    - LSM6DS0X accelerometer and Gyroscope values
 *    - LSM6DSOX MLC output registers (Only available starting from V4.6.0 of ST BLE Sensor Application)
 *    - LSM6DSOX FSM output registers (Only available starting from V4.6.0 of ST BLE Sensor Application)
 *    - Battery status
 * - The second Service exposes the console services where we have stdin/stdout and stderr capabilities
 * - The last Service is used for configuration purpose
 *
 * This example must be used with the related ST BLE Sensor Android/iOS application available on Play/itune store (Version 4.6.0 or higher),
 * in order to read the sent information by Bluetooth Low Energy protocol
 * 
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "TargetFeatures.h"
#include "main.h"
#include "app_x-cube-ai.h"

#include "ai_datatypes_defines.h"
#include "ai_platform.h"
#include "audio_model.h"
#include "audio_model_data.h"
#include <aiTestHelper.h>
#include <aiTestUtility.h>
#include "aiSystemPerformance.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Imported Variables --------------------------------------------------------*/
extern uint8_t set_connectable;

/* Exported Variables --------------------------------------------------------*/
uint8_t bdaddr[6];
char BoardName[8]={NAME_BLUEMS,0};

BLE_AR_output_t ActivityCode = BLE_AR_ERROR;

#ifdef STBOX1_RESTART_DFU
  #if defined (__GNUC__)
    uint32_t DFU_Var __attribute__ ((section (".noinit")));
  #elif defined (__ARMCC_VERSION)
    uint32_t DFU_Var  __attribute__((at(0x2009FFF0)));
  #elif defined (__IAR_SYSTEMS_ICC__)
    __no_init uint32_t DFU_Var;
  #endif /* defined (__GNUC__) */
#endif /* STBOX1_RESTART_DFU */

/* Private variables ---------------------------------------------------------*/
static volatile int ButtonPressed   = 0;
static volatile int SendBatteryInfo = 0;
volatile        int PowerOff        = 0;
volatile        int RebootBoard     = 0;
volatile        int hci_event       = 0;
static volatile int BlinkLed        = 0;
static volatile int MEMSInterrupt   = 0;
static volatile int SendAccGyro     = 0;

/* Private function prototypes -----------------------------------------------*/

//static void Init_BlueNRG_Custom_Services(void);
//static void Init_BlueNRG_Stack(void);

static void ButtonCallback(void);
static void MEMSCallback(void);
static void SystemClock_Config(void);
static void SendBatteryInfoData(void);
static void AccGyro_Read(BSP_MOTION_SENSOR_Axes_t *ACC_Value,BSP_MOTION_SENSOR_Axes_t *GYR_Value);
//static int aiTestingPerf( ai_handle *idx);

void APP_UserEvtRx(void *pData);

#ifdef STBOX1_ENABLE_PRINTF
static void DisplayFirmwareInfo(void);
#endif /* STBOX1_ENABLE_PRINTF */

/* Global c-array to handle the activations buffer */



float input_data[129]= {
		0x3fafd8a747059870, 0x3fb302787b563479, 0x3f98557d702d4ab4, 0x3f92cf7b06236106,
		0x3f7ef5eed362969e,	0x3f76033bba9663b9,	0x3f6c759e5542fbe1,	0x3f54d807b9e88bba,
		0x3f6bdfddee42b774,	0x3f6ee94df29f78b7,	0x3f7f76afaa26d186,	0x3f7a6b7e055e751a,
		0x3f69d59e8adc0bae,	0x3f61ed64e347d82a,	0x3f33f1db54c734ba,	0x3f21ae8799848db9,
		0x3ef045cfbbc1789c,	0x3f4d03865cbccbb3,	0x3f61222ca45ac0ae,	0x3f5781a3c5208b9a,
		0x3f5341c9be7ccc22,	0x3f3f93641b977c3e,	0x3f170dc10a62e594,	0x3f41f070fdfa44ba,
		0x3f27b1b610e14b54,	0x3f3141585ce1135b,	0x3f2f774e7d15c61f,	0x3f120db4eb3bb08a,
		0x3f3554f9d0ff2a76,	0x3f106ebc55d2c102, 0x3f4e3541d9a4c1c9,	0x3f5fcab1175d5594,
		0x3f4c74f16e303ea5,	0x3f2313f0457b089a,	0x3f5049e64da62d5b,	0x3f57cd765650a43c,
		0x3f57a26dab8f5cd8,	0x3f594f7397221751,	0x3f4628e250541299,	0x3f10ea0215280350,
		0x3f246c757b69ba41,	0x3f1155667da66435,	0x3f5109fcda07c7c4,	0x3f4ec4ff704b1aad,
		0x3f5edf54f9b3baa5,	0x3f73e92c419dd659,	0x3f7e69ec528114c1,	0x3f92756b6b46d014,
		0x3f99b9f4a8f6e036,	0x3f8edeef742b8be2,	0x3f7d0e926e07e79f,	0x3f7301e34d5a2323,
		0x3f55e6fd1e941f58,	0x3f6001508cf43307,	0x3f5c0e7cb5d35d94,	0x3f269aaa4ef623b7,
		0x3f24ed38dc5883a1,	0x3f317afcde08913a,	0x3f443b6f45313ba0,	0x3f408219c4ffdeaf,
		0x3f3b784f273b7762,	0x3f3d4ca6f62c2ea1,	0x3f31873c11a5ab6a,	0x3f14fb723b92d550,
		0x3f16debb1e90e340,	0x3f40c6b5be4023d3,	0x3f37e170e7eafbe3,	0x3f223520c20d552f,
		0x3f227356176ab978,	0x3efab472b48e9281,	0x3f3a7a90bec4677b,	0x3f349dbc8cc5aef5,
		0x3f11a3e585d22fb5,	0x3f306cbd54b0d106,	0x3f1b56e1941b30a8,	0x3f296f465ae7c317,
		0x3f2791c3fc50f969,	0x3f2bf416866c1ca5,	0x3f3bbc99baeab03c,	0x3f21243548f205b6,
		0x3f217c8274c47bd3,	0x3f22766129a689b0,	0x3f2a7cd904474564,	0x3f3e591661370e8b,
		0x3f34a77e66e5036d,	0x3f42211836c45a47,	0x3f44f8bd159b7326,	0x3f277b9ede2a22a6,
		0x3f1fc45f76699cb4,	0x3f337ed680b1fdce,	0x3f354d2ebca1e9e4,	0x3f241393801ae238,
		0x3f3950148089d7d5,	0x3f478afb93bdc0bf,	0x3f4de58dc980dad9,	0x3f61b00b5b2c17e1,
		0x3f67a12dd0830b38,	0x3f5e3e574aed0ba3,	0x3f494496cf4d5cf3,	0x3f2ced14f1f46f31,
		0x3f23ebf6edf2a403,	0x3f2d972413df3062,	0x3f0b05514417ae9f,	0x3ef0f0918a0b7c99,
		0x3f00331c52c6b7d2,	0x3f20b08cc73f3c37,	0x3f2a8408c4141951,	0x3f118560d93caa59,
		0x3f0ae87a921f301a,	0x3f10b08721815684,	0x3edd17d25d5c1c7f,	0x3ee46333634d228f,
		0x3f01b52448decf1d,	0x3efc69d408afb319,	0x3ed0aadf4ad9a482,	0x3ef69a2a7b972c6b,
		0x3eea9535514cb6bc,	0x3ee2be9f56711bee,	0x3f1096bbb54ce9a1,	0x3f0e63b90cdf97a6,
		0x3eff9a7e4c2da32b,	0x3f02f86b7afe9022,	0x3efa04b27b249af2,	0x3ee1722a5582e143,
		0x3ed8d6c7b90deb49,	0x3ef7bec7f8a13857,	0x3f07cc663243b54d,	0x3f094c34a2dad505,
		0x3ef70de28cb4cbf8,
		};



struct dwtTime1 {
  uint32_t fcpu;
  int s;
  int ms;
  int us;
};

int dwtCyclesToTime1(uint64_t clks, struct dwtTime1 *t)
{
  if (!t)
    return -1;
  uint32_t fcpu = HAL_RCC_GetHCLKFreq();
  uint64_t s  = clks / fcpu;
  uint64_t ms = (clks * 1000) / fcpu;
  uint64_t us = (clks * 1000 * 1000) / fcpu;
  ms -= (s * 1000);
  us -= (ms * 1000 + s * 1000000);
  t->fcpu = fcpu;
  t->s = s;
  t->ms = ms;
  t->us = us;
  return 0;
}



/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
 int main(void)
{

	//char nn_name[11] = "Audio_Model";
	//bool flag = 0;
	//char *nn_name;
	//int buf_len = 0;
	ai_error ai_err;
	//const ai_handle acts[] = {"activations"};

	AI_ALIGNED(32)
	ai_float out_data[AI_AUDIO_MODEL_OUT_1_SIZE];

	ai_buffer *ai_input; //[AI_AUDIO_MODEL_IN_NUM];// = AI_AUDIO_MODEL_DATA_IN;
	ai_buffer *ai_output; //[AI_AUDIO_MODEL_OUT_NUM];// = AI_AUDIO_MODEL_DATA_OUT;

	// Chunk of memory used to hold intermediate values for neural network
	 AI_ALIGNED(4) ai_u8 activations[AI_AUDIO_MODEL_DATA_ACTIVATIONS_SIZE];

	 ai_handle audio_nw = AI_HANDLE_NULL;
	 ai_network_report report;

	 AI_ALIGNED(32)
	// ai_float in_data[AI_AUDIO_MODEL_IN_1_SIZE];
	 const ai_handle acts[] = { activations };

#ifdef STBOX1_RESTART_DFU
  /* Check if we need to go to DFU */
  if(DFU_Var == DFU_MAGIC_NUM) {
    typedef void (*pFunction)(void);
    pFunction JumpToDFU;

    /* Reset the Magic Number */
    DFU_Var = 0x00000000;
    HAL_RCC_DeInit();
    SysTick->CTRL = 0;
    SysTick->LOAD = 0;
    SysTick->VAL = 0;
    __disable_irq();
    __HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH();
    JumpToDFU = (void (*)(void)) (*((uint32_t *)(0x1FFF0000 + 4)));
    /* Initialize user application's Stack Pointer */
    __set_MSP(*(__IO uint32_t*) 0x1FFF0000);
    JumpToDFU();
  }
#endif /* STBOX1_RESTART_DFU */

  /* HAL_Init */
  HAL_Init();

  /* Configure the System clock */
  SystemClock_Config();

  InitTargetPlatform();

  /* SET THIS FOR SOME ERROR */
  __HAL_RCC_CRC_CLK_ENABLE();

#ifdef STBOX1_ENABLE_PRINTF
  DisplayFirmwareInfo();
#endif /* STBOX1_ENABLE_PRINTF */


  /* Initialize the BlueNRG */
  STBOX1_PRINTF("\r\nInitializing Bluetooth\r\n");
  BluetoothInit();


  STBOX1_PRINTF("\r\nCreating Neural network\r\n");
  // Create instance of neural network
  ai_err = ai_audio_model_create_and_init(&audio_nw, acts, NULL);
  if (ai_err.type != AI_ERROR_NONE) {
	  STBOX1_PRINTF("ai init_and_create error\n");
	  return -1;
  }

  if (ai_audio_model_get_report(audio_nw, &report) != true) {
	  STBOX1_PRINTF("ai get report error\n");
  return -1;
  }

  STBOX1_PRINTF("Model name : %s\n", report.model_name);
  STBOX1_PRINTF("Model signature : %s\n", report.model_signature);

  ai_input = &report.inputs[0];
  ai_output = &report.outputs[0];
  STBOX1_PRINTF("input[0] : (%ld, %ld, %ld)\n", AI_BUFFER_SHAPE_ELEM(ai_input, AI_SHAPE_HEIGHT),
		  AI_BUFFER_SHAPE_ELEM(ai_input, AI_SHAPE_WIDTH),
		  AI_BUFFER_SHAPE_ELEM(ai_input, AI_SHAPE_CHANNEL));
  STBOX1_PRINTF("output[0] : (%ld, %ld, %ld)\n", AI_BUFFER_SHAPE_ELEM(ai_output, AI_SHAPE_HEIGHT),
		  AI_BUFFER_SHAPE_ELEM(ai_output, AI_SHAPE_WIDTH),
		  AI_BUFFER_SHAPE_ELEM(ai_output, AI_SHAPE_CHANNEL));

	  //in_data = input_data;

  ai_input = ai_audio_model_inputs_get(audio_nw, NULL);
  ai_output = ai_audio_model_outputs_get(audio_nw, NULL);

	  /** @brief Set input/output buffer addresses */
	 // ai_input[0].data = AI_HANDLE_PTR(input_data);
  ai_output[0].data = AI_HANDLE_PTR(&out_data);

  while (1){

	  if(set_connectable){
      uint32_t uhCapture = __HAL_TIM_GET_COUNTER(&TimCCHandle);
      set_connectable =0;
      setConnectable();

      /* Start the TIM Base generation in interrupt mode */
      if(HAL_TIM_OC_Start_IT(&TimCCHandle, TIM_CHANNEL_1) != HAL_OK){
        /* Starting Error */
        Error_Handler();
      }

      /* Set the Capture Compare Register value */
      __HAL_TIM_SET_COMPARE(&TimCCHandle, TIM_CHANNEL_1, (uhCapture + STBOX1_UPDATE_LED));
    }

    /* Handle BLE event */
    if(hci_event) {
      hci_event =0;
      hci_user_evt_proc();
    }

    int iter;
   // ai_i32 batch;
    int niter;

    ai_error ai_err;
    struct dwtTime1 t, t2;
    uint64_t tcumul;
    uint32_t cmacc;
	uint64_t count = 0;


    /* Handle user button */
    if(ButtonPressed) {
      //ButtonCallback();
      ButtonPressed=0;


      STBOX1_PRINTF("Starting Inference\n");
      /* Adding random data to the input */

      niter = 2;
      STBOX1_PRINTF("\r\nRunning PerfTest on \"%s\" with random inputs (%d iterations)...\r\n",
    		  report.model_name, niter);

      /* reset/init cpu clock counters */
      tcumul = 0ULL;


      /* Main inference loop */
      for (iter = 0; iter < niter; iter++) {
    	  //ai_size cnt = 0;

    	  cyclesCounterStart();

    	  	  /* Fill/set the input tensor descriptors */
    	  for (int i = 0; i < report.n_inputs; i++) {
    		  ai_input = report.inputs;
    		  if (report.inputs[i].data)
    			  ai_input[i].data = AI_HANDLE_PTR(report.inputs[i].data);
    		  else {
    			  const float v = 2.0f * (ai_float) rand() / (ai_float) RAND_MAX - 1.0f;
    			  	  *(ai_float *)(ai_input[i].data + i * 4) = v;
    		  }
    	  }

    	  /* Fill/set the output tensor descriptors */
    	  /*for (int i = 0; i < report.n_outputs; i++) {

    	    ai_output[i] = report.outputs[i];
    	    if (report.outputs[i].data)
    	      ai_output[i].data = AI_HANDLE_PTR(report.outputs[i].data);
    	    else
    	      ai_output[i].data = AI_HANDLE_PTR(data_outs[i]);
    	  } */

    	  ai_i32 n_batch;

    	  STBOX1_PRINTF("Run Inference\n");
    	  dwtCyclesToTime1(count, &t);

    	  n_batch = ai_audio_model_run(audio_nw, ai_input, ai_output);
    	   if (n_batch != 1) {
    	 	  ai_err = ai_audio_model_get_error(audio_nw);
    	 	  STBOX1_PRINTF("ai run error %d, %d\n", ai_err.type, ai_err.code);
    	   }

    	   count = cyclesCounterEnd();
    	   dwtCyclesToTime1(count, &t2);

    	   /** @brief Post-process the output results/predictions */
    	   STBOX1_PRINTF("Inference output.. ");
    	   for (int i = 0; i < AI_AUDIO_MODEL_OUT_1_SIZE; i++) {
    	 	  STBOX1_PRINTF("%f,", out_data[i]);
    	   }
    	   STBOX1_PRINTF("\n");
    	   STBOX1_PRINTF(" Time Take: %8d.%03dms (%ld cycles)\r\n",
    			   t2.ms-t.ms, t2.ms-t.us, (long)count);
    	   STBOX1_PRINTF("Results for \"%s\", %d inferences @%dMHz/%dMHz (complexity: %lu MACC)\r\n",
    			   	   	 report.model_name, (int)iter,
    	 		        (int)(port_hal_rcc_get_sys_clock_freq() / 1000000),
    	 		        (int)(port_hal_rcc_get_hclk_freq() / 1000000),
    	 		        (unsigned long)report.n_macc);
    	   STBOX1_PRINTF("\n");

    	   tcumul += count;


      } /* end of the main loop */


      STBOX1_PRINTF("\r\n");

      tcumul /= (uint64_t)iter;

      dwtCyclesToTime1(tcumul, &t);

      STBOX1_PRINTF("Results for \"%s\", %d inferences @%dMHz/%dMHz (complexity: %lu MACC)\r\n",
          report.model_name, (int)iter,
          (int)(HAL_RCC_GetSysClockFreq() / 1000000),
          (int)(HAL_RCC_GetHCLKFreq() / 1000000),
          (unsigned long)report.n_macc);

      STBOX1_PRINTF(" duration     : %d.%03d ms (average)\r\n", t.s * 1000 + t.ms, t.us);
      if (tcumul / 100000) {
    	  STBOX1_PRINTF(" CPU cycles   : %ld%ld (average)\r\n",
          (unsigned long)(tcumul / 100000), (unsigned long)(tcumul - ((tcumul / 100000) * 100000)));
      } else {
    	  STBOX1_PRINTF(" CPU cycles   : %ld (average)\r\n", (unsigned long)(tcumul));
      }

      STBOX1_PRINTF(" CPU Workload : %d%c (duty cycle = 1s)\r\n", (int)((tcumul * 100) / t.fcpu), '%');
      cmacc = (uint32_t)((tcumul * 100)/ report.n_macc);
      STBOX1_PRINTF(" cycles/MACC  : %d.%02d (average for all layers)\r\n",
          (int)(cmacc / 100), (int)(cmacc - ((cmacc / 100) * 100)));

//      aiTestingPerf(&audio_nw);

    }

    /* Power Off the SensorTile.box */
    if(PowerOff){
      BSP_BC_CmdSend(SHIPPING_MODE_ON);
      PowerOff =0;
    }

    /* Interrupt from LSM6DSOX */
    if(MEMSInterrupt) {
      MEMSCallback();
      MEMSInterrupt =0;
    }

    /* Reboot the Board */
    if(RebootBoard) {
      RebootBoard=0;
      HAL_NVIC_SystemReset();
    }

    /* Handle Acc/Gyro */
    if(SendAccGyro) {
      BSP_MOTION_SENSOR_Axes_t ACC_Value;
      BSP_MOTION_SENSOR_Axes_t GYR_Value;

      BLE_MANAGER_INERTIAL_Axes_t ACC_SensorValue;
      BLE_MANAGER_INERTIAL_Axes_t GYR_SensorValue;
      BLE_MANAGER_INERTIAL_Axes_t MAG_SensorValue;

      SendAccGyro =0;

      /* Read the Inertial Sensors */
      AccGyro_Read(&ACC_Value,&GYR_Value);
      
      ACC_SensorValue.x= ACC_Value.x;
      ACC_SensorValue.y= ACC_Value.y;
      ACC_SensorValue.z= ACC_Value.z;
      
      GYR_SensorValue.x= GYR_Value.x;
      GYR_SensorValue.y= GYR_Value.y;
      GYR_SensorValue.z= GYR_Value.z;

      MAG_SensorValue.x= 0;
      MAG_SensorValue.y= 0;
      MAG_SensorValue.z= 0;

      /* Send the Data with BLE */
      BLE_AccGyroMagUpdate(&ACC_SensorValue,&GYR_SensorValue,&MAG_SensorValue);

    }

    /* Battery Info Data */
    if(SendBatteryInfo) {
      SendBatteryInfo=0;
      SendBatteryInfoData();
    }

    /* Blinking the Led */
    if(BlinkLed) {
      BlinkLed = 0;
      LedToggleTargetPlatform();
    }
    /* Wait next event */
    __WFI();
  }
}

#ifdef STBOX1_ENABLE_PRINTF
/**
  * @brief Display all the Firmware Information
  * @param  None
  * @retval None
  */
static void DisplayFirmwareInfo(void)
{
    STBOX1_PRINTF("\r\n------------------------------------------------------------\r\n");
    STBOX1_PRINTF("STMicroelectronics %s\r\n"
         "\tVersion %c.%c.%c\r\n"
        "\tSTM32L4R9ZI-SensorTile.box board\r\n",
          STBOX1_PACKAGENAME,
          STBOX1_VERSION_MAJOR,STBOX1_VERSION_MINOR,STBOX1_VERSION_PATCH);

    STBOX1_PRINTF("\t(HAL %ld.%ld.%ld_%ld)\r\n\tCompiled %s %s"
#if defined (__IAR_SYSTEMS_ICC__)
        " (IAR)\r\n",
#elif defined (__ARMCC_VERSION)
        " (KEIL)\r\n",
#elif defined (__GNUC__)
        " (STM32CubeIDE)\r\n",
#endif
           HAL_GetHalVersion() >>24,
          (HAL_GetHalVersion() >>16)&0xFF,
          (HAL_GetHalVersion() >> 8)&0xFF,
           HAL_GetHalVersion()      &0xFF,
           __DATE__,__TIME__);
  STBOX1_PRINTF("------------------------------------------------------------\r\n");
}
#endif /* STBOX1_ENABLE_PRINTF */

/*static int aiTestingPerf(ai_handle *handle)
{
  int iter;
 // ai_i32 batch;
  int niter;

  ai_error ai_err;
  struct dwtTime1 t;
  uint64_t tcumul;
  uint64_t tend;
  uint32_t cmacc;

 // ai_buffer ai_input[AI_MNETWORK_IN_NUM];
 // ai_buffer ai_output[AI_MNETWORK_OUT_NUM];


  STBOX1_PRINTF("Starting Inference\n");

 // niter = 2;
 // STBOX1_PRINTF("\r\nRunning PerfTest on \"%s\" with random inputs (%d iterations)...\r\n",
  //    report.model_name, niter);

  //tcumul = 0ULL;



/* for (iter = 0; iter < niter; iter++) {

	  ai_size cnt = 0;

	  cyclesCounterStart();
*/
	  /* Fill/set the input tensor descriptors */
	  /*for (int i = 0; i < report.n_inputs; i++) {
		  ai_input = report.inputs;
		  if (report.inputs[i].data)
			  ai_input[i].data = AI_HANDLE_PTR(report.inputs[i].data);
		  else {
			  const float v = 2.0f * (ai_float) rand() / (ai_float) RAND_MAX - 1.0f;
			  *(ai_float *)(ai_input[i].data + i * 4) = v;
		  }
	  }*/

	  /* Fill/set the output tensor descriptors */
	 /* for (int i = 0; i < report.n_outputs; i++) {
	    ai_output[i] = report.outputs[i];
	    if (report.outputs[i].data)
	      ai_output[i].data = AI_HANDLE_PTR(report.outputs[i].data);
	    else
	      ai_output[i].data = AI_HANDLE_PTR(data_outs[i]);
	  }

	  ai_i32 n_batch;

	  STBOX1_PRINTF("Run Inference\n");
	  n_batch = ai_audio_model_run(handle, ai_input, ai_output);
	   if (n_batch != 1) {
	 	  ai_err = ai_audio_model_get_error(handle);
	 	  STBOX1_PRINTF("ai run error %d, %d\n", ai_err.type, ai_err.code);
	   }


	   count = cyclesCounterEnd();

	   dwtCyclesToTime1(count, &t);
	    @brief Post-process the output results/predictions */
/*	   STBOX1_PRINTF("Inference output.. ");
	   for (int i = 0; i < AI_AUDIO_MODEL_OUT_1_SIZE; i++) {
	 	  STBOX1_PRINTF("%f,", out_data[i]);
	   }
	   STBOX1_PRINTF(" Time Take: %8d.%03dms (%ld cycles)\r\n",
	           t.ms, t.us, (long)count);
	   STBOX1_PRINTF("Results for \"%s\", %d inferences @%dMHz/%dMHz (complexity: %lu MACC)\r\n",
	 		  report.model_name, (int)iter,
	 		        (int)(port_hal_rcc_get_sys_clock_freq() / 1000000),
	 		        (int)(port_hal_rcc_get_hclk_freq() / 1000000),
	 		        (unsigned long)report.n_macc);
	   STBOX1_PRINTF("\n");

    tcumul += tend;

    dwtCyclesToTime1(tend, &t);

  }  end of the main loop */


  /*STBOX1_PRINTF("\r\n");

  tcumul /= (uint64_t)iter;

  dwtCyclesToTime1(tcumul, &t);

  STBOX1_PRINTF("Results for \"%s\", %d inferences @%dMHz/%dMHz (complexity: %lu MACC)\r\n",
      report.model_name, (int)iter,
      (int)(HAL_RCC_GetSysClockFreq() / 1000000),
      (int)(HAL_RCC_GetHCLKFreq() / 1000000),
      (unsigned long)report.n_macc);

  STBOX1_PRINTF(" duration     : %d.%03d ms (average)\r\n", t.s * 1000 + t.ms, t.us);
  if (tcumul / 100000) {
	  STBOX1_PRINTF(" CPU cycles   : %ld%ld (average)\r\n",
      (unsigned long)(tcumul / 100000), (unsigned long)(tcumul - ((tcumul / 100000) * 100000)));
  } else {
	  STBOX1_PRINTF(" CPU cycles   : %ld (average)\r\n", (unsigned long)(tcumul));
  }

  STBOX1_PRINTF(" CPU Workload : %d%c (duty cycle = 1s)\r\n", (int)((tcumul * 100) / t.fcpu), '%');
  cmacc = (uint32_t)((tcumul * 100)/ report.n_macc);
  STBOX1_PRINTF(" cycles/MACC  : %d.%02d (average for all layers)\r\n",
      (int)(cmacc / 100), (int)(cmacc - ((cmacc / 100) * 100)));
  return 0;
}
*/
/**
  * @brief  Read The Inertial Data (Acc/Gyro)
  * @param  BSP_MOTION_SENSOR_Axes_t ACC_Value Structure containing acceleration value in mg
  * @param  BSP_MOTION_SENSOR_Axes_t GYR_Value Structure containing Gyroscope value
  * @retval None
 */
static void AccGyro_Read(BSP_MOTION_SENSOR_Axes_t *ACC_Value,BSP_MOTION_SENSOR_Axes_t *GYR_Value)
{
  /* Read the Acc values */
  BSP_MOTION_SENSOR_GetAxes(LSM6DSOX_0,MOTION_ACCELERO,ACC_Value);

  /* Read the Gyro values */
  BSP_MOTION_SENSOR_GetAxes(LSM6DSOX_0,MOTION_GYRO,GYR_Value);
}

/**
  * @brief  Callback for user button
  * @param  None
  * @retval None
  */
static void ButtonCallback(void)
{
  STBOX1_PRINTF("User button pressed\r\n");
  STBOX1_PRINTF("The board will be switched off\r\n");
  //PowerOff =1;
}

/**
  * @brief  Callback for LSM6DS0X interrupt
  * @param  None
  * @retval None
  */
static void MEMSCallback(void)
{
  lsm6dsox_all_sources_t      status;
  uint8_t MLCStatus;
  uint8_t FSMStatus;
  
  STBOX1_PRINTF("MEMSCallback\n\r");
  
  lsm6dsox_all_sources_get(LSM6DSOX_Contex, &status);
  
  MLCStatus = ((status.mlc1)    | (status.mlc2<<1) | (status.mlc3<<2) | (status.mlc4<<3) |
                       (status.mlc5<<4) | (status.mlc6<<5) | (status.mlc7<<6) | (status.mlc8<<7));
  
  FSMStatus = ((status.fsm1)     | (status.fsm2<<1)  | (status.fsm3<<2)  | (status.fsm4<<3)  |
                       (status.fsm5<<4)  | (status.fsm6<<5)  | (status.fsm7<<6)  | (status.fsm8<<7)  |
                       (status.fsm9<<8)  | (status.fsm10<<9)  | (status.fsm11<<10) | (status.fsm12<<11) |
                       (status.fsm13<<12) | (status.fsm14<<13) | (status.fsm15<<14) | (status.fsm16<<15));

  if(MLCStatus!=0) {
    uint8_t mlc_out[8];
    lsm6dsox_mlc_out_get(LSM6DSOX_Contex, mlc_out);

    /* Check if we need to update the MLC BLE char */
    if(MLC_Enabled) {
      BLE_MachineLearningCoreUpdate(mlc_out,&MLCStatus);
    }

    /* Check if we need to update the Activity Recognition BLE char */
    if(AR_Enabled) {
      if (status.mlc1) {
        ActivityCode = BLE_MappingToHAR_ouput_t[mlc_out[0]];
        if(ActivityCode!=BLE_AR_ERROR) {
          BLE_ActRecUpdate(ActivityCode, HAR_MLC_LSM6DSOX_ID);
          if(BLE_StdTerm_Service==BLE_SERV_ENABLE) {
            BytesToWrite =sprintf((char *)BufferToWrite,"Rec ActivityCode %02X [%02X]\n",ActivityCode,mlc_out[0]);
            Term_Update(BufferToWrite,BytesToWrite);
          } else {
            STBOX1_PRINTF("Rec ActivityCode %02X [%02X]\r\n",ActivityCode,mlc_out[0]);
          }
        } else {
          if(BLE_StdTerm_Service==BLE_SERV_ENABLE) {
            BytesToWrite =sprintf((char *)BufferToWrite,"Wrong ActivityCode %02X [%02X]\n",ActivityCode,mlc_out[0]);
            Term_Update(BufferToWrite,BytesToWrite);
          } else {
            STBOX1_PRINTF("Wrong ActivityCode %02X [%02X]\r\n",ActivityCode,mlc_out[0]);
          }
        }
      }
    }
  } else  if(FSMStatus!=0) {
    lsm6dsox_fsm_out_t fsm_out;
    lsm6dsox_fsm_out_get(LSM6DSOX_Contex, &fsm_out);

    if(FSM_Enabled) {
      BLE_FiniteStateMachineUpdate((uint8_t *)&fsm_out,&FSMStatus,/* this is dummy */ &FSMStatus);
    }
  }
}

/**
  * @brief  Send Battery Info Data (Voltage/Current/Soc) to BLE
  * @param  None
  * @retval None
  */
static void SendBatteryInfoData(void)
{
  uint32_t BatteryLevel;
  uint32_t Voltage;

  /* Read the Battery Charger voltage and Level values */
  BSP_BC_GetVoltageAndLevel(&Voltage,&BatteryLevel);

  BLE_BatteryUpdate(BatteryLevel,Voltage,0x8000 ,0x04 /* Unknown */);
}

/**
  * @brief  System Clock tree configuration
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

    /**Configure the main internal regulator output voltage 
    */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST) != HAL_OK) {
    /* Initialization Error */
    while(1);
  }
  
   /**Configure LSE Drive Capability 
    */
  HAL_PWR_EnableBkUpAccess();

  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|
                                     RCC_OSCILLATORTYPE_LSE  |
                                     RCC_OSCILLATORTYPE_HSE  |
                                     RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_11;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 60;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    /* Initialization Error */
    while(1);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK   |
                                RCC_CLOCKTYPE_SYSCLK |
                                RCC_CLOCKTYPE_PCLK1  |
                                RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
    /* Initialization Error */
    while(1);
  }
  
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_SAI1   |
                                      RCC_PERIPHCLK_DFSDM1 |
                                      RCC_PERIPHCLK_USB    |
                                      RCC_PERIPHCLK_RTC    |
                                      RCC_PERIPHCLK_SDMMC1 |
                                      RCC_PERIPHCLK_ADC;

  PeriphClkInit.Sai1ClockSelection = RCC_SAI1CLKSOURCE_PLLSAI1;
  PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;  
  PeriphClkInit.Dfsdm1ClockSelection = RCC_DFSDM1CLKSOURCE_PCLK2;  
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  PeriphClkInit.Sdmmc1ClockSelection = RCC_SDMMC1CLKSOURCE_PLLP;
  PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_HSE;
  PeriphClkInit.PLLSAI1.PLLSAI1M = 5;
  PeriphClkInit.PLLSAI1.PLLSAI1N = 96;
  PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV25;
  PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV4;
  PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV4;
  PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_ADC1CLK|RCC_PLLSAI1_SAI1CLK;  
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
    /* Initialization Error */
    while(1);
  }
}

///**
//  * @brief This function provides accurate delay (in milliseconds) based
//  *        on variable incremented.
//  * @note This is a user implementation using WFI state
//  * @param Delay: specifies the delay time length, in milliseconds.
//  * @retval None
//  */
//void HAL_Delay(__IO uint32_t Delay)
//{
//  uint32_t tickstart = 0;
//  tickstart = HAL_GetTick();
//  while((HAL_GetTick() - tickstart) < Delay){
//    __WFI();
//  }
//}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  STBOX1_PRINTF("Error_Handler\r\n");
  /* User may add here some code to deal with this error */
  while(1){
  }
}

/**
 * @brief  EXTI line detection callback.
 * @param  uint16_t GPIO_Pin Specifies the pin connected EXTI line
 * @retval None
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  switch(GPIO_Pin) {
    case HCI_TL_SPI_EXTI_PIN:
      hci_tl_lowlevel_isr();
      hci_event=1;
    break;
    case USER_BUTTON_PIN:
      ButtonPressed = 1;    
    break;
    case GPIO_PIN_2:
    case GPIO_PIN_3:
      MEMSInterrupt = 1;
    break;
  }
}


/**
  * @brief  Output Compare callback in non blocking mode
  * @param  TIM_HandleTypeDef *htim TIM OC handle
  * @retval None
  */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
  uint32_t uhCapture=0;
  /* TIM1_CH1 toggling with frequency = 1Hz */
  if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
    uhCapture = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
    /* Set the Capture Compare Register value */
    __HAL_TIM_SET_COMPARE(&TimCCHandle, TIM_CHANNEL_1, (uhCapture + STBOX1_UPDATE_LED));

    BlinkLed =1;
  }

  /* TIM1_CH2 toggling with frequency = 0.5Hz */
  if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2) {
    uhCapture = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
    /* Set the Capture Compare Register value */
    __HAL_TIM_SET_COMPARE(&TimCCHandle, TIM_CHANNEL_2, (uhCapture + STBOX1_UPDATE_BATTERY));
    SendBatteryInfo=1;
  }

#ifdef STBOX1_ENABLE_PRINTF
  if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3) {
    uhCapture = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
    /* Set the Capture Compare Register value */
    __HAL_TIM_SET_COMPARE(&TimCCHandle, TIM_CHANNEL_3, (uhCapture + STBOX1_UPDATE_VCOM));
    CDC_PeriodElapsedCallback();
  }
#endif /* STBOX1_ENABLE_PRINTF */

  /* TIM1_CH4 toggling with frequency = 0.5Hz */
  if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4) {
    uhCapture = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
    /* Set the Capture Compare Register value */
    __HAL_TIM_SET_COMPARE(&TimCCHandle, TIM_CHANNEL_4, (uhCapture + STBOX1_UPDATE_INV));
    SendAccGyro=1;
  }
}


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: STBOX1_PRINTF("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1){
  }
}
#endif
