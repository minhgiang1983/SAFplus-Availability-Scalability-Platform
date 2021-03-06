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


/*********************************************************************
* ModuleName  : idl
*********************************************************************/
/*********************************************************************
* Description : This file contains the declarations for marshall 
*               and unmarshall funtions of ClEvtUnsubscribeEventRequestT 
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/

#ifndef _XDR_CL_EVT_UNSUBSCRIBE_EVENT_REQUEST_T_H_
#define _XDR_CL_EVT_UNSUBSCRIBE_EVENT_REQUEST_T_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "clXdrApi.h"

#include "clEventCommonIpi.h"
#include "xdrClEvtUserIdT.h"

struct _ClEvtUnsubscribeEventRequestT_4_0_0;


ClRcT  clXdrMarshallClEvtUnsubscribeEventRequestT_4_0_0(void *,ClBufferHandleT , ClUint32T);

ClRcT  clXdrUnmarshallClEvtUnsubscribeEventRequestT_4_0_0(ClBufferHandleT, void *);

#define clXdrMarshallArrayClEvtUnsubscribeEventRequestT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallArray((pointer), sizeof(ClEvtUnsubscribeEventRequestT_4_0_0), (multiplicity), clXdrMarshallClEvtUnsubscribeEventRequestT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallArrayClEvtUnsubscribeEventRequestT_4_0_0(msg,pointer, multiplicity) \
clXdrUnmarshallArray((msg),(pointer), sizeof(ClEvtUnsubscribeEventRequestT_4_0_0), (multiplicity), clXdrUnmarshallClEvtUnsubscribeEventRequestT_4_0_0)

#define clXdrMarshallPointerClEvtUnsubscribeEventRequestT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPointer((pointer), sizeof(ClEvtUnsubscribeEventRequestT_4_0_0), (multiplicity), clXdrMarshallClEvtUnsubscribeEventRequestT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPointerClEvtUnsubscribeEventRequestT_4_0_0(msg,pointer) \
clXdrUnmarshallPointer((msg),(pointer), sizeof(ClEvtUnsubscribeEventRequestT_4_0_0), clXdrUnmarshallClEvtUnsubscribeEventRequestT_4_0_0)

#define clXdrMarshallPtrClEvtUnsubscribeEventRequestT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPtr((pointer), sizeof(ClEvtUnsubscribeEventRequestT_4_0_0), (multiplicity), clXdrMarshallClEvtUnsubscribeEventRequestT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPtrClEvtUnsubscribeEventRequestT_4_0_0(msg,pointer,multiplicity) \
clXdrUnmarshallPtr((msg),(pointer), sizeof(ClEvtUnsubscribeEventRequestT_4_0_0),multiplicity, clXdrUnmarshallClEvtUnsubscribeEventRequestT_4_0_0)


typedef ClEvtUnsubscribeEventRequestT ClEvtUnsubscribeEventRequestT_4_0_0;



#ifdef __cplusplus
}
#endif

#endif /*_XDR_CL_EVT_UNSUBSCRIBE_EVENT_REQUEST_T_H_*/
