from string import Template
   
headerTemplate = Template("""\
/******************************************************************************
 *
 * clSNMPConfig.c
 *
 ******************************************************************************
 * This code is auto-generated by OpenClovis IDE Version 3.0
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
{{NULL, 0}, {{{0, 0}}, 0, 0}, {0}, 0, NULL}
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