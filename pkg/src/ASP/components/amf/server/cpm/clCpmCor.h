/*
 * Copyright (C) 2002-2009 by OpenClovis Inc. All  Rights Reserved.
 * 
 * The source code for  this program is not published  or otherwise 
 * divested of  its trade secrets, irrespective  of  what  has been 
 * deposited with the U.S. Copyright office.
 * 
 * This program is  free software; you can redistribute it and / or
 * modify  it under  the  terms  of  the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 * 
 * This program is distributed in the  hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied  warranty  of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 * 
 * You  should  have  received  a  copy of  the  GNU General Public
 * License along  with  this program. If  not,  write  to  the 
 * Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/**
 * This header file contains definitions of all the data structures
 * and programming interface used for CPM-COR interaction.
 */

#ifndef _CL_CPM_COR_H_
#define _CL_CPM_COR_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * ASP include files 
 */
#include <clCommon.h>
#include <clCommonErrors.h>
#include <clCorApi.h>
#include <clCorUtilityApi.h>
#include <clAmsTypes.h>

extern ClRcT cpmCorNodeObjectCreate(ClNameT nodeMoIdName);

extern ClRcT cpmCorMoIdToMoIdNameGet(ClCorMOIdT *moId, ClNameT *moIdName);

#ifdef __cplusplus
}
#endif

#endif /* _CL_CPM_COR_H_ */