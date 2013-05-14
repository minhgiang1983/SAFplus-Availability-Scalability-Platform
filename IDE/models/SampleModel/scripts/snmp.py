################################################################################
# ModuleName  : SampleModel
# $File$
# $Author$
# $Date$
################################################################################
# Description :
# usage: python cor.py <args>
# create corMetaStruct.c
################################################################################
import sys
import string
import xml.dom.minidom
from string import Template
import time
import getpass

   
headerTemplate = Template("""\
/******************************************************************************
 *
 * clSNMPConfig.c
 *
 ******************************************************************************
 * This code is auto-generated by OpenClovis IDE Version 2.2.0
 *
 ***************************** Description ************************************
 *
 * 
 * Date : $DateTime 
 * User : $Author 
 *
 *****************************************************************************/
 
#include <clSnmpDataDefinition.h>
#include <clAlarmDefinitions.h>
#include <clCorMetaStruct.h>
#include <clCpmApi.h>
#include <ipi/clAlarmIpi.h>

#define CL_ALARM_ROW_STATUS 1
""")

trapOidMapTableTemplate = Template("""\
ClSnmpTrapOidMapTableItemT  trapOidMapTable[] = {
{{NULL, 0}, 0, NULL}
};
""")


oidMapTableTemplate = Template("""\

ClSnmpOidMapTableItemT  oidMapTable[] = {
${oidMapTableEntries}
""")

imTableEntryTemplate = Template("""\

{{(ClUint8T *)"1.3.6.1.4.1.21458.2.3", 1},
{${moPath}, (CL_COR_INVALID_SVC_ID), ${depth}}, {CL_MED_ATTR_VALUE_END}},
/*SNMP_IM_MOID,*/
{{(ClUint8T *)"1.3.6.1.4.1.21458.2.3.1.1", 1},
{${moPath}, (CL_COR_INVALID_SVC_ID), ${depth}}, {CL_MED_ATTR_VALUE_END}},
/*SNMP_IM_ASVS,*/
{{(ClUint8T *)"1.3.6.1.4.1.21458.2.3.1.2", 1},
{${moPath}, (CL_COR_INVALID_SVC_ID), ${depth}}, {CL_MED_ATTR_VALUE_END}},
/*SNMP_IM_MO_ROW_STATUS,*/
{{(ClUint8T *)"1.3.6.1.4.1.21458.2.3.1.3", 1},
{${moPath}, (CL_COR_INVALID_SVC_ID), ${depth}}, {CL_MED_ATTR_VALUE_END}},
""")


alarmTableEntryTemplate = Template("""\

 /* SNMP_OBJ_ALARM_ID*/	  /* 1.3.6.1.4.1.21458.2.4.1.1 */
	{{(ClUint8T *)"1.3.6.1.4.1.21458.2.4.1.1", 1},
	{${moPath}, CL_COR_SVC_ID_ALARM_MANAGEMENT, ${depth}}, {CL_ALARM_INFO_CONT_CLASS, CL_COR_INDEX_WILD_CARD, CL_ALARM_ID, CL_MED_ATTR_VALUE_END}},

	/* SNMP_OBJ_ALARM_CATEGORY*/		/* 1.3.6.1.4.1.21458.2.4.1.2 */
	{{(ClUint8T *)"1.3.6.1.4.1.21458.2.4.1.2", 1},
	{${moPath}, CL_COR_SVC_ID_ALARM_MANAGEMENT, ${depth}}, {CL_ALARM_INFO_CONT_CLASS, CL_COR_INDEX_WILD_CARD, CL_ALARM_CATEGORY, CL_MED_ATTR_VALUE_END}},

	/* SNMP_OBJ_ALARM_SEVERITY*/		/* 1.3.6.1.4.1.21458.2.4.1.3 */
	{{(ClUint8T *)"1.3.6.1.4.1.21458.2.4.1.3", 1},
	{${moPath}, CL_COR_SVC_ID_ALARM_MANAGEMENT, ${depth}}, {CL_ALARM_INFO_CONT_CLASS, CL_COR_INDEX_WILD_CARD, CL_ALARM_SEVERITY, CL_MED_ATTR_VALUE_END}},

	/* SNMP_OBJ_TIME_LAST_RAISED	*/	/* 1.3.6.1.4.1.21458.2.4.1.4 */
	{{(ClUint8T *)"1.3.6.1.4.1.21458.2.4.1.4", 1},
	{${moPath}, CL_COR_SVC_ID_ALARM_MANAGEMENT, ${depth}}, {CL_ALARM_INFO_CONT_CLASS, CL_COR_INDEX_WILD_CARD, CL_ALARM_EVENT_TIME, CL_MED_ATTR_VALUE_END}},

	/* SNMP_OBJ_SPECIFIC_PROBLEM*/		/* 1.3.6.1.4.1.21458.2.4.1.5 */
	{{(ClUint8T *)"1.3.6.1.4.1.21458.2.4.1.5", 1},
	{${moPath}, CL_COR_SVC_ID_ALARM_MANAGEMENT, ${depth}}, {CL_ALARM_INFO_CONT_CLASS, CL_COR_INDEX_WILD_CARD, CL_ALARM_SPECIFIC_PROBLEM, CL_MED_ATTR_VALUE_END}},

	/* SNMP_OBJ_ALARM_CLEAR*/	   /* 1.3.6.1.4.1.21458.2.4.1.6 */
	{{(ClUint8T *)"1.3.6.1.4.1.21458.2.4.1.6", 1},
	{${moPath}, CL_COR_SVC_ID_ALARM_MANAGEMENT, ${depth}}, {CL_ALARM_INFO_CONT_CLASS, CL_COR_INDEX_WILD_CARD, CL_ALARM_CLEAR, CL_MED_ATTR_VALUE_END}},

	/* SNMP_OBJ_ALARM_ENABLE*/	  /* 1.3.6.1.4.1.21458.2.4.1.7 */
	{{(ClUint8T *)"1.3.6.1.4.1.21458.2.4.1.7", 1},
	{${moPath}, CL_COR_SVC_ID_ALARM_MANAGEMENT, ${depth}}, {CL_ALARM_INFO_CONT_CLASS, CL_COR_INDEX_WILD_CARD, CL_ALARM_ENABLE, CL_MED_ATTR_VALUE_END}},

	/* SNMP_OBJ_ALARM_SUSPEND*/	 /* 1.3.6.1.4.1.21458.2.4.1.8 */
	{{(ClUint8T *)"1.3.6.1.4.1.21458.2.4.1.8", 1},
	{${moPath}, CL_COR_SVC_ID_ALARM_MANAGEMENT, ${depth}}, {CL_ALARM_INFO_CONT_CLASS, CL_COR_INDEX_WILD_CARD, CL_ALARM_SUSPEND, CL_MED_ATTR_VALUE_END}},

	/* SNMP_OBJ_ALARM_OP_STATE*/		/* 1.3.6.1.4.1.21458.2.4.1.9 */
	{{(ClUint8T *)"1.3.6.1.4.1.21458.2.4.1.9", 1},
	{${moPath}, CL_COR_SVC_ID_ALARM_MANAGEMENT, ${depth}}, {CL_ALARM_INFO_CONT_CLASS, CL_COR_INDEX_WILD_CARD, CL_ALARM_ACTIVE, CL_MED_ATTR_VALUE_END}},

	/* SNMP_OBJ_ALARM_ROW_STATUS*/	  /* 1.3.6.1.4.1.21458.2.4.1.10 */
	{{(ClUint8T *)"1.3.6.1.4.1.21458.2.4.1.10", 1},
	{${moPath}, CL_COR_SVC_ID_ALARM_MANAGEMENT, ${depth}}, {CL_ALARM_INFO_CONT_CLASS, CL_COR_INDEX_WILD_CARD, CL_ALARM_ROW_STATUS, CL_MED_ATTR_VALUE_END}},

   /* SNMP_ATTR_MAX */
""")

staticComponentTableEntries= Template("""\
{{(ClUint8T *)"1.3.6.1.4.1.21458.2.2.1.1", 1}, {{{CL_CPM_CLASS_CLUSTER, CL_COR_INSTANCE_WILD_CARD} ,{CL_CPM_CLASS_NODE, CL_COR_INSTANCE_WILD_CARD} ,{CL_CPM_CLASS_SU, CL_COR_INSTANCE_WILD_CARD} ,{CL_CPM_CLASS_COMP, CL_COR_INSTANCE_WILD_CARD} }, CL_COR_INVALID_SVC_ID, 4}, {CL_CPM_COMP_NAME,CL_MED_ATTR_VALUE_END}},
   /* SNMP_COMPONENT_OPRATIONAL_STATUS,*/
{{(ClUint8T *)"1.3.6.1.4.1.21458.2.2.1.2", 1}, {{{CL_CPM_CLASS_CLUSTER, CL_COR_INSTANCE_WILD_CARD} ,{CL_CPM_CLASS_NODE, CL_COR_INSTANCE_WILD_CARD} ,{CL_CPM_CLASS_SU, CL_COR_INSTANCE_WILD_CARD} ,{CL_CPM_CLASS_COMP, CL_COR_INSTANCE_WILD_CARD} }, CL_COR_INVALID_SVC_ID, 4}, {CL_CPM_COMP_OPERATIONAL_STATE,CL_MED_ATTR_VALUE_END}},
   /* SNMP_COMPONENT_PRESENCE_STATUS, */ {{(ClUint8T *)"1.3.6.1.4.1.21458.2.2.1.3", 1}, {{{CL_CPM_CLASS_CLUSTER, CL_COR_INSTANCE_WILD_CARD} ,{CL_CPM_CLASS_NODE, CL_COR_INSTANCE_WILD_CARD} ,{CL_CPM_CLASS_SU, CL_COR_INSTANCE_WILD_CARD} ,{CL_CPM_CLASS_COMP, CL_COR_INSTANCE_WILD_CARD} }, CL_COR_INVALID_SVC_ID, 4}, {CL_CPM_COMP_PRESENCE_STATE,CL_MED_ATTR_VALUE_END}},
""")


moTemplate = Template("""\
{CLASS_${classid}_MO, CL_COR_INSTANCE_WILD_CARD}
""")

oidTemplate = Template("""
{{(ClUint8T *) \"${oid}\", 1},
{{""")

serviceIdTemplate = Template("""\
}, ${serviceId}, ${depth}}, {""")

AttributeIdTemplate = Template("""\
${attrId}, """)

AttributeEndString = """\
CL_MED_ATTR_VALUE_END}},
"""
StructEndString = """\
{{NULL, 0}, {{{0, 0}}, 0, 0}, {0}}
};
"""
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def getBaseClasses(resource):	
	resKey = resource.attributes["CWKEY"].value;		
	baseClasses = []
	for inheritence in inheritenceList:
		sourceKey = inheritence.attributes["source"].value		
		if sourceKey == resKey:
			baseClass = getResourceFromKey(inheritence.attributes["target"].value)
			if baseClass != None:
				baseClasses.append(baseClass)			
	return baseClasses
	
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def getParents(resource):	
	resKey = resource.attributes["CWKEY"].value;		
	parents = []
	for composition in compositionList:
		targetKey = composition.attributes["target"].value		
		if targetKey == resKey:
			parent = getResourceFromKey(composition.attributes["source"].value)
			if parent != None:
				parents.append(parent)
	return parents
	
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def getResourceFromKey(key):	
	for res in resourceList:				
		resKey = res.attributes["CWKEY"].value;		
		if resKey == key:
			return res
			
	return None

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def getDepths(resource, depth, depthList, chassisList):
	depth += 1
	if resource in chassisList:
		depthList.append(depth)
	parents = getParents(resource)
	for i in range(len(parents)):
		parent = parents[i]
		getDepths(parent, depth, depthList, chassisList)	   
	return depthList		

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def getMOPaths(resource, parentPath, moPathList, chassisList):
	resName = resource.attributes["Name"].value
	parentPath +=  string.upper(resName) + "#"
	if resource in chassisList:
		moPathList.append(parentPath)
	parents = getParents(resource)
	for i in range(len(parents)):
		parent = parents[i]
		getMOPaths(parent, parentPath, moPathList, chassisList)	   
	return moPathList

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def processMOPaths(moPathList):
	moStringList = []
	for moPath in moPathList:
		resNames = moPath.split("#")
		moString = ""
		length = len(resNames)
		length = length - 2 # to avoid the last blank value returned from split
		moString = ""
		while length >= 0:
			moIdString = moTemplate.safe_substitute(classid = resNames[length])
			moString += moIdString
			if length != 0:
				moString += ", "
			length = length - 1
		moStringList.append(moString)
	return moStringList
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def isAlarmEnabled(resource):
	try:
		alarmElements=resource.getElementsByTagName("AlarmManagement")		
		if len(alarmElements) > 0:
			if alarmElements[0].attributes["isEnabled"].value == "true":				
				return True
	except:
		print ""
	return False

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def isProvEnabled(resource):
	try:
		provElements=resource.getElementsByTagName("Provisioning")	
		if len(provElements) >0:
			if provElements[0].attributes["isEnabled"].value == "true":				
				return True
	except:
		print ""
	return False
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def createMoMap(resList):
	moMap = dict();
	for res  in resList:
		name = res.attributes["Name"].value
		moMap[name] = moTemplate.safe_substitute(classid = string.upper(res.attributes["Name"].value) )
	return moMap
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def processResourceAttributes(res, moString, result, depth, moName): # moName will not be same as name of res in case of Inheritence RelationShip
	provAttrList = []
	depthList = []
	serviceMap = dict();
	if isProvEnabled(res):
		provList = res.getElementsByTagName("Provisioning")
		serviceMap["serviceId"] = "CL_COR_SVC_ID_PROVISIONING_MANAGEMENT"
		serviceMap["depth"] = depth
		serviceString = serviceIdTemplate.safe_substitute(serviceMap)
		for prov in provList:
			provAttrList = prov.getElementsByTagName("Attributes")
			result += processAttributeList(provAttrList, moName, moString, serviceString)
	moAttributeList = res.getElementsByTagName("Attributes")
	filteredAttrList = []
	provList = res.getElementsByTagName("Provisioning")
	if len(provList) > 0:
		provAttrList = provList[0].getElementsByTagName("Attributes")
	for moAttribute in moAttributeList:
		if moAttribute not in provAttrList:
			filteredAttrList.append(moAttribute)
	serviceMap["serviceId"] = "CL_COR_INVALID_SVC_ID"
	serviceMap["depth"] = depth
	serviceString = serviceIdTemplate.safe_substitute(serviceMap)
	result += processAttributeList(filteredAttrList, moName, moString, serviceString)
	return result
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def processResourceList(resList):
	result = ""
	depthList = []
	for res  in resList:
		parentList = getParents(res)
		if len(parentList) > 1:
			pathList = []
			depthList = []
			pathList = getMOPaths(res, "", pathList, chassisList)
			moStringList = processMOPaths(pathList)
			for i in range(len(moStringList)):
				moString = moStringList[i]
				depth = getDepths(res, 0, depthList, chassisList) [i]
				result = processResourceAttributes(res, moString, result, depth, res.attributes["Name"].value)
		elif len(parentList) == 1:
			pathList = []
			depthList = []
			pathList = getMOPaths(res, "", pathList, chassisList)
			moStringList = processMOPaths(pathList)
			moString = moStringList[0]
			depth = getDepths(res, 0, depthList, chassisList) [0]
			result = processResourceAttributes(res, moString, result, depth, res.attributes["Name"].value)
	return result
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def processInheritedResourceList(resList):
	result = ""
	depthList = []
	for res  in resList:
		baseClasses = getBaseClasses(res)
		if len(baseClasses) > 0:
			for baseResource in baseClasses:
				parentList = getParents(res)
				if len(parentList) > 1:
					pathList = []
					depthList = []
					pathList = getMOPaths(res, "", pathList, chassisList)
					moStringList = processMOPaths(pathList)
					for i in range(len(moStringList)):
						moString = moStringList[i]
						depth = getDepths(res, 0, depthList, chassisList) [i]
						result = processResourceAttributes(baseResource, moString, result, depth, res.attributes["Name"].value)
				elif len(parentList) == 1:
					pathList = []
					depthList = []
					pathList = getMOPaths(res, "", pathList, chassisList)
					moStringList = processMOPaths(pathList)
					moString = moStringList[0]
					depth = getDepths(res, 0, depthList, chassisList) [0]
					result = processResourceAttributes(baseResource, moString, result, depth, res.attributes["Name"].value)
	return result
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def processAttributeList(attrList, moName, moString, serviceString):
	result = ""
	for attr  in attrList:
		attrOid   = attr.attributes["OID"].value
		if attrOid != "":
			result += oidTemplate.safe_substitute(oid = attrOid)
			result += moString + serviceString
			attr = string.upper(moName) + "_" + string.upper(attr.attributes["Name"].value)
			result += AttributeIdTemplate.safe_substitute(attrId = attr)
			result += AttributeEndString
	return result
	
def isSNMPSubAgentPresent(cmpList):		
	result = "-1"
	for cmp in cmpList:
		try:
			if cmp.attributes["isSNMPSubAgent"].value == "true":
				cpmName = cmp.attributes["Name"].value
				result = "1"
		except:
			result = "-1"
	return result
#------------------------------------------------------------------------------
#Script Execution Starts Here.
#Resource Tree information
headerMap = dict();
headerMap['DateTime'] = unicode(time.strftime("%D at %H:%M:%S", time.localtime()))
headerMap['Author'] = getpass.getuser()
mapTableEntries = ""
symbolMap = dict()
resourceXml = sys.argv[1]
componentsXml = sys.argv[2]
componentDoc  = xml.dom.minidom.parse(componentsXml)
componentList = componentDoc.getElementsByTagName("component:SAFComponent");
#identify SAF component with SNMP subagent set to true
snmpSubAgent = isSNMPSubAgentPresent(componentList)

resourceDoc = xml.dom.minidom.parse(resourceXml)
resourceList = resourceDoc.getElementsByTagName("resource:ChassisResource") + resourceDoc.getElementsByTagName("resource:HardwareResource") + resourceDoc.getElementsByTagName("resource:SoftwareResource") + resourceDoc.getElementsByTagName("resource:SystemController") + resourceDoc.getElementsByTagName("resource:NodeHardwareResource")
chassisList = resourceDoc.getElementsByTagName("resource:ChassisResource")
compositionList = resourceDoc.getElementsByTagName("resource:Composition")
inheritenceList = resourceDoc.getElementsByTagName("resource:Inheritence")

moMap = createMoMap(resourceList)
srcFileContents = headerTemplate.safe_substitute(headerMap)

mapTableEntries += "\n /********************* Resource entries START *****************/"
for res in resourceList:
	parentList = getParents(res)
	if len(parentList) > 1:
		pathList = []
		depthList = []
		pathList = getMOPaths(res, "", pathList, chassisList)
		moStringList = processMOPaths(pathList)
		for i in range(len(moStringList)):
			path = moStringList[i]
			path = "{" + path + "}"
			symbolMap['moPath'] = path
			symbolMap['depth'] = getDepths(res, 0, depthList, chassisList)[i]
			mapTableEntries += imTableEntryTemplate.safe_substitute(symbolMap)
			
	elif len(parentList) == 1:
		pathList = []
		depthList = []
		pathList = getMOPaths(res, "", pathList, chassisList)
		moStringList = processMOPaths(pathList)
		path = moStringList[0]
		path = "{" + path + "}"
		symbolMap['moPath'] = path
		symbolMap['depth'] = getDepths(res, 0, depthList, chassisList)[0]
		mapTableEntries += imTableEntryTemplate.safe_substitute(symbolMap)

mapTableEntries += " /********************* Resource entries END *****************/ \n"

#------------ Removing Component Table Entries. It will be a static code ---------------

mapTableEntries += "\n /********************* Alarm entries START *****************/"		
for res in resourceList:
	if isAlarmEnabled(res):
		parentList = getParents(res)
		if len(parentList) > 1:
			pathList = []
			depthList = []
			pathList = getMOPaths(res, "", pathList, chassisList)
			moStringList = processMOPaths(pathList)
			for i in range(len(moStringList)):
				path = moStringList[i]
				path = "{" + path + "}"
				symbolMap['moPath'] = path
				symbolMap['depth'] = getDepths(res, 0, depthList, chassisList)[i]
				mapTableEntries += alarmTableEntryTemplate.safe_substitute(symbolMap)
		else:
			pathList = []
			depthList = []
			pathList = getMOPaths(res, "", pathList, chassisList)
			moStringList = processMOPaths(pathList)
			try:
				path = moStringList[0]
				path = "{" + path + "}"
				symbolMap['moPath'] = path
				symbolMap['depth'] = getDepths(res, 0, depthList, chassisList)[0]
			except:
				print "Resource '" + res.attributes["Name"].value + "' is not contained in any other resource"
			mapTableEntries += alarmTableEntryTemplate.safe_substitute(symbolMap)
mapTableEntries += " /********************* Alarm entries END *****************/ \n"

srcFileContents += oidMapTableTemplate.safe_substitute(oidMapTableEntries = mapTableEntries)
#Now generated in clCompSNMPConfig.py if there is an snmp subagent present
if snmpSubAgent != "1":
	srcFileContents += processResourceList(resourceList)
	srcFileContents += processInheritedResourceList(resourceList)
	
#srcFileContents += staticComponentTableEntries.safe_substitute()
srcFileContents += StructEndString
srcFileContents += trapOidMapTableTemplate.safe_substitute()


out_file = open("clSNMPConfig.c","w")
out_file.write(srcFileContents)
out_file.close()