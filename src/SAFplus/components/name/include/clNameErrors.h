/*
 * Copyright (C) 2002-2012 OpenClovis Solutions Inc.  All Rights Reserved.
 *
 * This file is available  under  a  commercial  license  from  the
 * copyright  holder or the GNU General Public License Version 2.0.
 * 
 * The source code for  this program is not published  or otherwise 
 * divested of  its trade secrets, irrespective  of  what  has been 
 * deposited with the U.S. Copyright office.
 * 
 * This program is distributed in the  hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied  warranty  of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 * 
 * For more  information, see  the file  COPYING provided with this
 * material.
 */
/*******************************************************************************
 * ModuleName  : name                                                          
 * File        : clNameErrors.h
 *******************************************************************************/

/*******************************************************************************
 * Description :                                                                
 *
 *  This module contains NS related errors. 
 *
 *
 *****************************************************************************/                                                                                                                             

/**
 *  \file
 *  \brief Header file of Name Service Related Error Codes
 *  \ingroup name_apis 
 */

/**
 ************************************
 *  \addtogroup name_apis
 *  \{
 */
                                                                                                               
                                                                                                                 
#ifndef _CL_NAME_ERRORS_H_
#define _CL_NAME_ERRORS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <clCommon.h>
#include <clCommonErrors.h>


/******************************************************************************
 * ERROR/RETURN CODE HANDLING MACROS
 *****************************************************************************/

/** 
 * Macro for appending NS component id to the error code.
 */
#define CL_NS_RC(ERROR_CODE)  CL_RC(CL_CID_NS, (ERROR_CODE))

/******************************************************************************
 * ERROR CODES
 *****************************************************************************/

/* Name Service related error codes */

/** 
 * On querying an entry that is not present.
 */
#define CL_NS_ERR_ENTRY_NOT_FOUND          0x100

/**
 * On creating or registering the contexts and entries more than the maximum allowed.
 */
#define CL_NS_ERR_LIMIT_EXCEEDED           0x101

/** 
 * On registering, deregistering or querying a context that does not exist.
 */
#define CL_NS_ERR_CONTEXT_NOT_CREATED      0x102

/** 
 * Trying to delete a service that was not registered.
 */
#define CL_NS_ERR_SERVICE_NOT_REGISTERED   0x103

/**
 * Context creation failed.
 */
#define CL_NS_ERR_CONTEXT_CREATION_FAILED  0x104

/**
 * Requested operation not permitted.
 */
#define CL_NS_ERR_OPERATION_NOT_PERMITTED  0x105

/** 
 * While trying to create a context that is already created.
 */
#define CL_NS_ERR_CONTEXT_ALREADY_CREATED  0x106

                                                                                                                          
#ifdef __cplusplus
}
#endif
                                                                                                                 
                                                                                                                 
#endif /* _CL_NAME_ERRORS_H_ */

/**
 *  \}
 */


