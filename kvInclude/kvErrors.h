/*
 * kvErrors.h
 *
 *  Created on: Feb 10, 2015
 *      Author: KEVIN
 */

#ifndef EDITORIALSUBCRIBER_KVINCLUDE_KVERRORS_H_
#define EDITORIALSUBCRIBER_KVINCLUDE_KVERRORS_H_


#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/*!
    Common error messages used across the system
*/
/**************************************************************************/
typedef enum
{
  /*=======================================================================
    GENERIC ERRORS                                         0x0000 .. 0x00FF
    -----------------------------------------------------------------------
    These error codes can be used anywhere in the system
    -----------------------------------------------------------------------*/
    ERROR_NONE                                  = 0x0,  /**< Indicates no error occurred */
    ERROR_TIMEOUT                               = 0x01,
    ERROR_BAD_PARAMETER                         = 0x02,
    ERROR_NULL_PARAMETER                        = 0x03,
    ERROR_BAD_ALLOCATE_MEM                      = 0x04,

}ErrorCode_t;


#ifdef __cplusplus
}
#endif

#endif /* EDITORIALSUBCRIBER_KVINCLUDE_KVERRORS_H_ */
