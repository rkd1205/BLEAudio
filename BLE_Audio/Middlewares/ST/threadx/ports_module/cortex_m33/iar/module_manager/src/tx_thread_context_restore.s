/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** ThreadX Component                                                     */
/**                                                                       */
/**   Thread                                                              */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

    EXTERN  _tx_execution_isr_exit
    SECTION `.text`:CODE:NOROOT(2)
    THUMB
/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _tx_thread_context_restore                        Cortex-M/IAR      */
/*                                                           6.1.5        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Scott Larson, Microsoft Corporation                                 */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function is only needed for legacy applications and it should  */
/*    not be called in any new development on a Cortex-M.                 */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    [_tx_execution_isr_exit]              Execution profiling ISR exit  */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    ISRs                                  Interrupt Service Routines    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  03-02-2021      Scott Larson            Initial Version 6.1.5         */
/*                                                                        */
/**************************************************************************/
// VOID   _tx_thread_context_restore(VOID)
// {
    PUBLIC  _tx_thread_context_restore
_tx_thread_context_restore:

#ifdef TX_ENABLE_EXECUTION_CHANGE_NOTIFY
    /* Call the ISR exit function to indicate an ISR is complete.  */
    PUSH    {r0, lr}                                // Save return address
    BL      _tx_execution_isr_exit                  // Call the ISR exit function
    POP     {r0, lr}                                // Recover return address
#endif

    BX      lr

// }
    END
