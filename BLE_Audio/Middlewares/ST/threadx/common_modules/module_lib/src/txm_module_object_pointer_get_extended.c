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
/**   Module                                                              */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define TXM_MODULE
#include "txm_module.h"

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _txm_module_manager_object_pointer_get_extended     PORTABLE C      */
/*                                                           6.1          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Scott Larson, Microsoft Corporation                                 */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function retrieves the object pointer of a particular type     */
/*    with a particular name. If the object is not found, an error is     */
/*    returned. Otherwise, if the object is found, the address of that    */
/*    object is placed in object_ptr.                                     */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    object_type                       Type of object, as follows:       */
/*                                                                        */
/*                                          TXM_BLOCK_POOL_OBJECT         */
/*                                          TXM_BYTE_POOL_OBJECT          */
/*                                          TXM_EVENT_FLAGS_OBJECT        */
/*                                          TXM_MUTEX_OBJECT              */
/*                                          TXM_QUEUE_OBJECT              */
/*                                          TXM_SEMAPHORE_OBJECT          */
/*                                          TXM_THREAD_OBJECT             */
/*                                          TXM_TIMER_OBJECT              */
/*    name                              Name to search for                */
/*    name_length                       Length of the name excluding      */
/*                                        null-terminator                 */
/*    object_ptr                        Pointer to the object             */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    TX_SUCCESS                        Successful completion             */
/*    TX_PTR_ERROR                      Invalid name or object ptr        */
/*    TX_OPTION_ERROR                   Invalid option type               */
/*    TX_NO_INSTANCE                    Object not found                  */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _txm_module_kernel_call_dispatcher                                  */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Module application code                                             */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  09-30-2020     Scott Larson             Initial Version 6.1           */
/*                                                                        */
/**************************************************************************/
UINT _txm_module_object_pointer_get_extended(UINT object_type, CHAR *name, UINT name_length, VOID **object_ptr)
{

UINT return_value;
ALIGN_TYPE extra_parameters[2];

    extra_parameters[0] = (ALIGN_TYPE) name_length;
    extra_parameters[1] = (ALIGN_TYPE) object_ptr;

    /* Call module manager dispatcher.  */
    return_value = (UINT) (_txm_module_kernel_call_dispatcher)(TXM_MODULE_OBJECT_POINTER_GET_EXTENDED_CALL, (ALIGN_TYPE) object_type, (ALIGN_TYPE) name, (ALIGN_TYPE) extra_parameters);

    /* Return value to the caller.  */
    return(return_value);
}
