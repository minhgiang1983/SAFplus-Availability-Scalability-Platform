/******************************************************************************
 *
 * clcsa104Compcsa104Res.c
 *
 ******************************************************************************
 * This code is auto-generated by OpenClovis IDE Version 3.1
 *
 *****************************************************************************/

#include <clcsa104CompOAMPConfig.h>
#include <clDebugApi.h>


/*
 * ---BEGIN_APPLICATION_CODE---
 */

/*
 * Additional #includes and globals go here.
 */

#include <clCorUtilityApi.h>
#include <clCorMetaData.h>
#include <clCorMetaStruct.h>
/*
 * ---END_APPLICATION_CODE---
 */


extern ClLogStreamHandleT gEvalLogStream;
#define clprintf(severity, ...)   clAppLog(gEvalLogStream, severity, 10,                                   CL_LOG_AREA_UNSPECIFIED, CL_LOG_CONTEXT_UNSPECIFIED,                                  __VA_ARGS__)

/*
 * ---BEGIN_APPLICATION_CODE---
 */

/*
 * Additional user defined functions go here.
 */

extern ClUint32T delta_t;
extern ClUint32T seq;

/*
 * ---END_APPLICATION_CODE---
 */

/**** Prov functions */


/**
 * The contructor function is called by the provisioning library when a Managed Object 
 * is created. Inside this function, the callback functions for validate, update, 
 * rollback and read are assigned. 
 *
 * There are two variants of these callback functions, one at the object level and 
 * another at the attribute level. The object level functions are used to 
 * group validate/update/rollback/read multiple requests, and the other one is used 
 * to handle one request at a time. If both the callbacks are filled (i.e. non-null),
 * by default the object level callback will be invoked by prov library. To handle 
 * a single request at a time, the object level callbacks has to be set to NULL.
 * 
 * Inside this constructor function, user can add his/her own logic which need to be 
 * done on per object basis. If this logic involves allocation of some resource, 
 * it can be freed in the destructor function, which is called when the Managed 
 * Object is deleted.
 */ 
ClRcT clcsa104CompCSA104RESProvConstructor( void *pThis, void *pUsrData, ClUint32T usrDataLen )
{
    ClRcT rc = CL_OK;

    /* Override "semantic check" virtual method in provClass*/
    ((CL_OM_PROV_CLASS*)pThis)->clProvObjectStart = clcsa104CompCSA104RESProvObjectStart;      
    ((CL_OM_PROV_CLASS*)pThis)->clProvValidate = (fp)clcsa104CompCSA104RESProvValidate;    
    ((CL_OM_PROV_CLASS*)pThis)->clProvUpdate = (fp)clcsa104CompCSA104RESProvUpdate;    
    ((CL_OM_PROV_CLASS*)pThis)->clProvRollback = (fp)clcsa104CompCSA104RESProvRollback;
    ((CL_OM_PROV_CLASS*)pThis)->clProvRead = (fp)clcsa104CompCSA104RESProvRead;
	((CL_OM_PROV_CLASS*)pThis)->clProvObjectValidate = clcsa104CompCSA104RESProvObjectValidate; 	 
    ((CL_OM_PROV_CLASS*)pThis)->clProvObjectUpdate = clcsa104CompCSA104RESProvObjectUpdate; 	 
    ((CL_OM_PROV_CLASS*)pThis)->clProvObjectRollback = clcsa104CompCSA104RESProvObjectRollback;
    ((CL_OM_PROV_CLASS*)pThis)->clProvObjectRead = clcsa104CompCSA104RESProvObjectRead;
    ((CL_OM_PROV_CLASS*)pThis)->clProvObjectEnd = clcsa104CompCSA104RESProvObjectEnd;      
    
    /*
     * ---BEGIN_APPLICATION_CODE---
    */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */
     
    return rc;
}

/**
 * This function is called by the provisioning library when the managed resource 
 * is deleted. This can have logic of deleting the resources which might have 
 * been allocated in the constructor function.
 */ 
ClRcT clcsa104CompCSA104RESProvDestructor ( void *pThis , void  *pUsrData, ClUint32T usrDataLen )
{
    ClRcT rc = CL_OK;
    
    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */

    return rc;  
}

/**
 * This function is called by the provisioning library before forwarding any of the
 * transaction requests to this application on this managed resource. Please refer the file
 * clcsa104CompCSA104RESOAMPConfig.h for detailed documentation for this function.
 */
void clcsa104CompCSA104RESProvObjectStart(ClCorMOIdPtrT pMoId, ClHandleT txnHandle)
{
    /*
     * ---BEGIN_APPLICATION_CODE---
    */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
    */
}

/**
 * This function is called by the provisioning library whenever the object modification 
 * operation is done on the resource being managed. This callback is called to validate
 * the job. For a single job request, this is called once before calling update or 
 * rollback based on the success or failure of this function. For a request containing
 * multiple jobs, this function is called for all the jobs for validating them.
 * Only when validation for all the jobs are success, the update callback is called for
 * all the jobs. In case of failure, the rollback it called for all the jobs till which
 * the failure was detected.
 *
 * The pThis is a pointer to the provisioning class. 
 * The txnHandle is the unique handle for all the jobs which are part of same session. So for
 * a session containing multiple jobs, then it is unique of all the jobs and it can be used
 * to identify them.
 *
 * The pProvTxnData is a pointer to the ClProvTxnDataT structure which contains 
 * the information about the job being performed on the managed resource. 
 * The pProvTxnData->provCmd stores the operation type which can be 
 * CL_COR_OP_CREATE_AND_SET, CL_COR_OP_CREATE, CL_COR_OP_SET or CL_COR_OP_DELETE
 * based on what is the operation happening on the resource.
 * In the case of set operation, the various fields of pProvTxnData provide the
 * the details about the operation which is happening on the resource. It contain 
 * MOID of the managed resource and information about the attribute on which set
 * operation is done. For a create, create-set and delete operation, the pProvTxnData 
 * contains the MOID of the resource on which the given operation is done.
 *
 * ** Note : This function is being deprecated, if clProvObjectValidate() callback 
 * is filled in the constructor, then that callback function will be called 
 * instead of this to group validate all the requests.
 */ 
ClRcT clcsa104CompCSA104RESProvValidate(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnData)
{
    ClRcT rc = CL_OK;
    
    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */
        
    return rc;
}

/**
 * This function is called by the provisioning library whenever the object modification 
 * operation is done on the resource being managed. This is called to update the jobs
 * after being validated in validate phase.
 *
 * The pThis is a pointer to the provisioning class. 
 * The txnHandle is the unique handle for all the jobs which are part of same session. So for
 * a session containing multiple jobs, then it is unique of all the jobs and it can be used
 * to identify them.
 *
 * The pProvTxnData is a pointer to the ClProvTxnDataT structure which contains 
 * the information about the job being performed on the managed resource. 
 * The pProvTxnData->provCmd stores the operation type which can be 
 * CL_COR_OP_CREATE_AND_SET, CL_COR_OP_CREATE, CL_COR_OP_SET or CL_COR_OP_DELETE
 * based on what is the operation happening on the resource.
 * In the case of set operation, the various fields of pProvTxnData provide the
 * the details about the operation which is happening on the resource. It contain 
 * MOID of the managed resource and information about the attribute on which set
 * operation is done. For a create, create-set and delete operation, the pProvTxnData 
 * contains the MOID of the resource on which the given operation is done.
 *
 * ** Note : This function is being deprecated, if clProvObjectUpdate() callback 
 * is filled in the constructor, then that callback function will be called 
 * instead of this to group update all the requests.
 */ 
ClRcT clcsa104CompCSA104RESProvUpdate(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnData)
{
    ClRcT rc = CL_OK;

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    ClNameT     moIdName = {0};
    
    rc = clCorMoIdToMoIdNameGet((ClCorMOIdPtrT)pProvTxnData->pMoId, &moIdName);
    if (CL_OK != rc)
    {
        clprintf(CL_LOG_SEV_ERROR,"Failed while getting the MOId Name from moid. rc[0x%x] ", rc);
        return rc;
    }
    /*
     * ---END_APPLICATION_CODE---
     */
     
    switch (pProvTxnData->provCmd)
    {
        case CL_COR_OP_CREATE :
        case CL_COR_OP_CREATE_AND_SET:
            
        /*
         * ---BEGIN_APPLICATION_CODE---
         */

        clprintf(CL_LOG_SEV_INFO,"Inside create request for the object [%s] ", moIdName.value);    

        /*
         * ---END_APPLICATION_CODE---
         */

        break;
        case CL_COR_OP_SET:
        
        /*
         * ---BEGIN_APPLICATION_CODE---
         */
        if ( pProvTxnData->attrId == CSA104RES_DELTA_T)
        {
            delta_t = *(ClUint32T *)pProvTxnData->pProvData;
            clprintf(CL_LOG_SEV_INFO,"The delta time is now [%d] ", delta_t);
        }

        /*
         * ---END_APPLICATION_CODE---
         */

        break;

        case  CL_COR_OP_DELETE:

        /*
         * ---BEGIN_APPLICATION_CODE---
         */

        /*
         * ---END_APPLICATION_CODE---
         */

        break;
        default:
            clprintf (CL_LOG_SEV_ERROR, "Prov command is not proper");

    }

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    /*
     * ---END_APPLICATION_CODE---
     */

    return rc;   
}


/**
 * This function is called by the provisioning library whenever the object 
 * modification operation is done on the resource being managed. For a single job 
 * request, this function is called if the validate function is failed. For a 
 * multiple job request, on encountering a validate failure, this function is 
 * called to rollback all the jobs before the one (including) on which the 
 * validation failure is reported.
 *
 * The pThis is a pointer to the provisioning class. 
 * The txnHandle is the unique handle for all the jobs which are part of same session. So for
 * a session containing multiple jobs, then it is unique of all the jobs and it can be used
 * to identify them.
 * 
 * The pProvTxnData is a pointer to the ClProvTxnDataT structure which contains 
 * the information about the job being performed on the managed resource. 
 * The pProvTxnData->provCmd stores the operation type which can be 
 * CL_COR_OP_CREATE_AND_SET, CL_COR_OP_CREATE, CL_COR_OP_SET or CL_COR_OP_DELETE
 * based on what is the operation happening on the resource.
 * In the case of set operation, the various fields of pProvTxnData provide the
 * the details about the operation which is happening on the resource. It contain 
 * MOID of the managed resource and information about the attribute on which set
 * operation is done. For a create, create-set and delete operation, the pProvTxnData 
 * contains the MOID of the resource on which the given operation is done.
 *
 * ** Note : This function is being deprecated, if clProvObjectRollback() callback 
 * is filled in the constructor, then that callback function will be called 
 * instead of this to group rollback all the requests.
 */
ClRcT clcsa104CompCSA104RESProvRollback(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnData)
{
    ClRcT rc = CL_OK;

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */

    return rc;
}

/**
 * This function is called to perform a get operation on the transient attribute
 * which is owned by the primary object implementer (OI). As the COR doesn't have
 * the latest value of the transient attribute, it is obtained from the OI. This
 * function is called in the OI's context which it can use to fill the latest
 * value of the runtime or transient attribute.
 *
 * The pThis is pointer to the provisioning class.
 * The txnHandle is used to identify the jobs which are part of same bundle request.
 * For single request this field is of not much significance, but for a multiple job
 * request, this feild is used to identify all the jobs which are part of same
 * bundle request sent by COR.
 *
 * The pProvTxnData contains the information about the attribute jobs. It contains 
 * the MOId of the managed resource, the attribute identifier, its type (array or 
 * simple), its basic type (data type), index (in case it is array attriubte), 
 * size and the pointer (allocated by the library) to the memory on which the 
 * data can be copied.
 *
 * For a request containing only single job, this function is called only once. But
 * for a multiple job request, this is called for all the attributes one at a time.
 *
 * ** Note : This function is being deprecated, if clProvObjectRead() callback is filled 
 * in the constructor, then that callback function will be called instead of this 
 * to group read all the requests.
 */ 
ClRcT clcsa104CompCSA104RESProvRead(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnData)
{
    ClRcT rc = CL_OK;

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */

    return rc;
}

/**
 * This function is called by the provisioning library after all the transaction requests
 * for this managed resource are forwarded to this application. Please refer the file
 * clcsa104CompCSA104RESOAMPConfig.h for detailed documentation for this function.
 */
void clcsa104CompCSA104RESProvObjectEnd(ClCorMOIdPtrT pMoId, ClHandleT txnHandle)
{
    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */
}

/**
 * Validate all the jobs in an object sent from northbound as a single request.
 * Please refer protptype of this function in the file clcsa104CompCSA104RESOAMPConfig.h
 * for detailed documentation for this function.
 */
ClRcT clcsa104CompCSA104RESProvObjectValidate(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnDataList, ClUint32T txnDataEntries)
{
    ClRcT rc = CL_OK;
	
	/*
	 * ---BEGIN_APPLICATION_CODE$objectValidate$---
	 */
 	
    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

	/*
	 * ---END_APPLICATION_CODE---
	 */
 	 
    return rc;
}

/**
 * Update all the jobs of an object sent from north bound as a single request. 
 * Please refer protptype of this function in the file clcsa104CompCSA104RESOAMPConfig.h
 * for detailed documentation for this function.
 */
ClRcT clcsa104CompCSA104RESProvObjectUpdate(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnDataList, ClUint32T txnDataEntries)
{
    ClRcT rc = CL_OK;
    ClProvTxnDataT* pProvTxnData = NULL;
    ClUint32T i = 0;
	
	/*
	 * ---BEGIN_APPLICATION_CODE$objectUpdate$---
	 */
 	
    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    ClNameT     moIdName = {0};
    
    /*
     * ---END_APPLICATION_CODE---
     */

    for (i=0; i < txnDataEntries; i++)
    {
        pProvTxnData = (pProvTxnDataList + i);

        switch (pProvTxnData->provCmd)
        {
            case CL_COR_OP_CREATE :
            case CL_COR_OP_CREATE_AND_SET:
                
            /*
             * ---BEGIN_APPLICATION_CODE$objectUpdateCreateAndSet$---
             */
              clprintf(CL_LOG_SEV_INFO,"Inside create request for the object [%s] ", moIdName.value);
            /*
             * ---END_APPLICATION_CODE---
             */

            break;
            case CL_COR_OP_SET:
            
            /*
             * ---BEGIN_APPLICATION_CODE$objectUpdateSet$---
                 */
                if ( pProvTxnData->attrId == CSA104RES_DELTA_T)
                {
                    delta_t = *(ClUint32T *)pProvTxnData->pProvData;
                    clprintf(CL_LOG_SEV_INFO,"The delta time is now [%d] ", delta_t);
                }
        
            /*
             * ---END_APPLICATION_CODE---
             */

            break;

            case  CL_COR_OP_DELETE:

            /*
             * ---BEGIN_APPLICATION_CODE$objectUpdateDelete$---
             */

            /*
             * ---END_APPLICATION_CODE---
             */

            break;
            default:
                clprintf (CL_LOG_SEV_ERROR, "Prov command is not proper");

        }
    }

    /*
     * ---BEGIN_APPLICATION_CODE$objectUpdate1$---
     */

	/*
	 * ---END_APPLICATION_CODE---
	 */
 	 
    return rc;
}

/**
 * Rollback all the jobs of an object whose validation failed.
 * Please refer protptype of this function in the file clcsa104CompCSA104RESOAMPConfig.h
 * for detailed documentation for this function.
 */
ClRcT clcsa104CompCSA104RESProvObjectRollback(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnDataList, ClUint32T txnDataEntries)
{
    ClRcT rc = CL_OK;
	
	/*
	 * ---BEGIN_APPLICATION_CODE$objectRollback$---
	 */
 	
    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

	/*
	 * ---END_APPLICATION_CODE---
	 */
 	 
    return rc;
}

/**
 * Read all the transient attributes values in an object in a single request.
 * Please refer protptype of this function in the file clcsa104CompCSA104RESOAMPConfig.h
 * for detailed documentation for this function.
 */
ClRcT clcsa104CompCSA104RESProvObjectRead(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnDataList, ClUint32T txnDataEntries)
{
    ClRcT rc = CL_OK;
	
	/*
	 * ---BEGIN_APPLICATION_CODE$objectRead$---
	 */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);
 	
	/*
	 * ---END_APPLICATION_CODE---
	 */
 	 
    return rc;
}


