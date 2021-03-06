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
*               and unmarshall funtions of corRouteInfo_t 
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/

#ifndef _XDR_COR_ROUTE_INFO_T_H_
#define _XDR_COR_ROUTE_INFO_T_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "clXdrApi.h"

#include "clCorTxnJobStream.h"
#include "clTimerApi.h"
#include "clCorNotifyApi.h"
#include "clCorClient.h"
#include "clIocApi.h"
#include "clCorDmData.h"
#include "clCorMetaData.h"
#include "clCorSync.h"
#include "xdrClCorCommInfoT.h"
#include "xdrClCorMOIdT.h"

struct _corRouteInfo_t_4_0_0;


ClRcT  clXdrMarshallcorRouteInfo_t_4_0_0(void *,ClBufferHandleT , ClUint32T);

ClRcT  clXdrUnmarshallcorRouteInfo_t_4_0_0(ClBufferHandleT, void *);

#define clXdrMarshallArraycorRouteInfo_t_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallArray((pointer), sizeof(corRouteInfo_t_4_0_0), (multiplicity), clXdrMarshallcorRouteInfo_t_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallArraycorRouteInfo_t_4_0_0(msg,pointer, multiplicity) \
clXdrUnmarshallArray((msg),(pointer), sizeof(corRouteInfo_t_4_0_0), (multiplicity), clXdrUnmarshallcorRouteInfo_t_4_0_0)

#define clXdrMarshallPointercorRouteInfo_t_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPointer((pointer), sizeof(corRouteInfo_t_4_0_0), (multiplicity), clXdrMarshallcorRouteInfo_t_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPointercorRouteInfo_t_4_0_0(msg,pointer) \
clXdrUnmarshallPointer((msg),(pointer), sizeof(corRouteInfo_t_4_0_0), clXdrUnmarshallcorRouteInfo_t_4_0_0)

#define clXdrMarshallPtrcorRouteInfo_t_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPtr((pointer), sizeof(corRouteInfo_t_4_0_0), (multiplicity), clXdrMarshallcorRouteInfo_t_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPtrcorRouteInfo_t_4_0_0(msg,pointer,multiplicity) \
clXdrUnmarshallPtr((msg),(pointer), sizeof(corRouteInfo_t_4_0_0),multiplicity, clXdrUnmarshallcorRouteInfo_t_4_0_0)


typedef corRouteInfo_t corRouteInfo_t_4_0_0;



#ifdef __cplusplus
}
#endif

#endif /*_XDR_COR_ROUTE_INFO_T_H_*/
