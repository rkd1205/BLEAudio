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
/** POSIX wrapper for THREADX                                             */ 
/**                                                                       */
/**                                                                       */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

/* Include necessary system files.  */

#include "tx_api.h"    /* Threadx API */
#include "pthread.h"  /* Posix API */
#include "px_int.h"    /* Posix helper functions */


/**************************************************************************/ 
/*                                                                        */ 
/*  FUNCTION                                               RELEASE        */ 
/*                                                                        */ 
/*    pthread_mutex_timedlock                             PORTABLE C      */ 
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    William E. Lamie, Microsoft Corporation                             */
/*                                                                        */
/*  DESCRIPTION                                                           */ 
/*                                                                        */ 
/*    This function locks the mutex object referenced. If the mutex is    */
/*    already locked, the calling thread shall block until the mutex      */
/*    becomes available as in the pthread_mutex_lock( ) function. If the  */
/*    mutex cannot be locked without waiting for another thread to unlock */
/*    the mutex, this wait shall be terminated when the specified timeout */
/*    expires. This operation shall return with the mutex object          */
/*    referenced by mutex in the locked state with the calling thread as  */
/*    its owner.                                                          */
/*                                                                        */
/*  INPUT                                                                 */ 
/*                                                                        */
/*    mutex                          Address of the mutex                 */
/*    timespec                       Pointer to timespec structure which  */
/*                                   holds timeout period in clock ticks  */
/*                                                                        */ 
/*  OUTPUT                                                                */ 
/*                                                                        */ 
/*     0                             if successful                        */ 
/*     Value                         in case of any error                 */ 
/*                                                                        */ 
/*  CALLS                                                                 */ 
/*                                                                        */ 
/*  tx_thread_identify               Get calling thread's pointer         */ 
/*  tx_mutex_get                     ThreadX Mutex Service                */ 
/*                                                                        */
/*  CALLED BY                                                             */ 
/*                                                                        */ 
/*    Application Code                                                    */ 
/*                                                                        */ 
/*  RELEASE HISTORY                                                       */ 
/*                                                                        */ 
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     William E. Lamie         Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
INT  pthread_mutex_timedlock(pthread_mutex_t *mutex, struct timespec *abs_timeout)
{

    TX_MUTEX         *mutex_ptr;
    TX_THREAD        *thread_ptr;
    INT               retval,status;
    ULONG             timeout_ticks;


    mutex_ptr = (TX_MUTEX*)mutex;

    thread_ptr = tx_thread_identify();
    if ( (mutex_ptr->tx_mutex_ownership_count > 0 ) && (thread_ptr == (mutex_ptr->tx_mutex_owner )))
    {
        posix_errno = EDEADLK;
        posix_set_pthread_errno(EDEADLK);
        return (EDEADLK);
    }

    timeout_ticks = posix_abs_time_to_rel_ticks(abs_timeout);

    status = tx_mutex_get( mutex_ptr, timeout_ticks);

    switch ( status)
    {
        case TX_SUCCESS:
            retval = OK;
            break;

        case TX_NOT_AVAILABLE:
            posix_errno  = ETIMEDOUT;
            posix_set_pthread_errno(ETIMEDOUT);
            retval = ETIMEDOUT;
            break;

        default:
            posix_errno = EINVAL;
            posix_set_pthread_errno(EINVAL);
            retval = EINVAL;
            break;
    }
    return(retval);
}
