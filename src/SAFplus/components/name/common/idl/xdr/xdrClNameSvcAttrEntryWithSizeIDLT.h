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
*               and unmarshall funtions of ClNameSvcAttrEntryWithSizeIDLT 
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/

#ifndef _XDR_CL_NAME_SVC_ATTR_ENTRY_WITH_SIZE_IDLT_H_
#define _XDR_CL_NAME_SVC_ATTR_ENTRY_WITH_SIZE_IDLT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "clXdrApi.h"

#include "xdrClNameSvcAttrEntryIDLT.h"

struct _ClNameSvcAttrEntryWithSizeIDLT_4_0_0;

typedef struct _ClNameSvcAttrEntryWithSizeIDLT_4_0_0 {
    ClUint32T    attrLen;
    ClUint32T    attrCount;
    ClNameSvcAttrEntryIDLT_4_0_0*    attr;

}ClNameSvcAttrEntryWithSizeIDLT_4_0_0;


ClRcT  clXdrMarshallClNameSvcAttrEntryWithSizeIDLT_4_0_0(void *,ClBufferHandleT , ClUint32T);

ClRcT  clXdrUnmarshallClNameSvcAttrEntryWithSizeIDLT_4_0_0(ClBufferHandleT, void *);

#define clXdrMarshallArrayClNameSvcAttrEntryWithSizeIDLT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallArray((pointer), sizeof(ClNameSvcAttrEntryWithSizeIDLT_4_0_0), (multiplicity), clXdrMarshallClNameSvcAttrEntryWithSizeIDLT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallArrayClNameSvcAttrEntryWithSizeIDLT_4_0_0(msg,pointer, multiplicity) \
clXdrUnmarshallArray((msg),(pointer), sizeof(ClNameSvcAttrEntryWithSizeIDLT_4_0_0), (multiplicity), clXdrUnmarshallClNameSvcAttrEntryWithSizeIDLT_4_0_0)

#define clXdrMarshallPointerClNameSvcAttrEntryWithSizeIDLT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPointer((pointer), sizeof(ClNameSvcAttrEntryWithSizeIDLT_4_0_0), (multiplicity), clXdrMarshallClNameSvcAttrEntryWithSizeIDLT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPointerClNameSvcAttrEntryWithSizeIDLT_4_0_0(msg,pointer) \
clXdrUnmarshallPointer((msg),(pointer), sizeof(ClNameSvcAttrEntryWithSizeIDLT_4_0_0), clXdrUnmarshallClNameSvcAttrEntryWithSizeIDLT_4_0_0)

#define clXdrMarshallPtrClNameSvcAttrEntryWithSizeIDLT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPtr((pointer), sizeof(ClNameSvcAttrEntryWithSizeIDLT_4_0_0), (multiplicity), clXdrMarshallClNameSvcAttrEntryWithSizeIDLT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPtrClNameSvcAttrEntryWithSizeIDLT_4_0_0(msg,pointer,multiplicity) \
clXdrUnmarshallPtr((msg),(pointer), sizeof(ClNameSvcAttrEntryWithSizeIDLT_4_0_0),multiplicity, clXdrUnmarshallClNameSvcAttrEntryWithSizeIDLT_4_0_0)


typedef ClNameSvcAttrEntryWithSizeIDLT_4_0_0 ClNameSvcAttrEntryWithSizeIDLT;



#ifdef __cplusplus
}
#endif

#endif /*_XDR_CL_NAME_SVC_ATTR_ENTRY_WITH_SIZE_IDLT_H_*/
