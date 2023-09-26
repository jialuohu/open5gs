#include "nlmf-handler.h"

bool lmf_nlmf_loc_handle_determine_location(
        ogs_sbi_stream_t *stream, ogs_sbi_message_t *recvmsg)
{
    ogs_assert(stream);
    ogs_assert(recvmsg);

/* Handle Request */
    // lmf_determine_location_input_data_t *requestData = recvmsg->LMFLocationData;


/* Handle Response */
    ogs_sbi_message_t sendmsg;
    // ogs_sbi_response_t *response = NULL;
    ogs_sbi_server_t *server = ogs_sbi_server_from_stream(stream);
    ogs_sbi_header_t header = recvmsg->h;
    
    lmf_determine_location_location_data_t *responseData = ogs_malloc(sizeof(lmf_determine_location_location_data_t));

    /* simulated data */
    // Initialize 'locationEstimate'
    responseData->location_estimate->point->lon = 180;
    responseData->location_estimate->point->lat = 90;

    // Initialize 'accuracyFulfilmentIndicator'
    responseData->accuracy_fulfilment_indicator = REQUESTED_ACCURACY_FULFILLED;

    // Initialize 'ageOfLocationEstimate'
    responseData->age_of_location_estimate = 32767;

    // Initialize 'timestampOfLocationEstimate'
    responseData->date_time = (char *) "2023-08-25T22:26:47.397Z";

    // Initialize 'velocityEstimate'
    responseData->velocity_estimate->horizontal_velocity->h_speed = 2047;
    responseData->velocity_estimate->horizontal_velocity->bearing = 360;
    
    // Initialize 'civicAddress'
    responseData->civic_address->country = (char *) "string";
    responseData->civic_address->a1 = (char *) "string";
    responseData->civic_address->a2 = (char *) "string";
    responseData->civic_address->a3 = (char *) "string";
    responseData->civic_address->a4 = (char *) "string";
    responseData->civic_address->a5 = (char *) "string";
    responseData->civic_address->a6 = (char *) "string";
    responseData->civic_address->prd = (char *) "string";
    responseData->civic_address->pod = (char *) "string";
    responseData->civic_address->sts = (char *) "string";
    responseData->civic_address->hno = (char *) "string";
    responseData->civic_address->hns = (char *) "string";
    responseData->civic_address->lmk = (char *) "string";
    responseData->civic_address->loc = (char *) "string";
    responseData->civic_address->nam = (char *) "string";
    responseData->civic_address->pc = (char *) "string";
    responseData->civic_address->bld = (char *) "string";
    responseData->civic_address->unit = (char *) "string";
    responseData->civic_address->room = (char *) "string";
    responseData->civic_address->plc = (char *) "string";
    responseData->civic_address->pcn = (char *) "string";
    responseData->civic_address->pobox = (char *) "string";
    responseData->civic_address->addcode = (char *) "string";
    responseData->civic_address->seat = (char *) "string";
    responseData->civic_address->rd = (char *) "string";
    responseData->civic_address->rdsec = (char *) "string";
    responseData->civic_address->rdbr = (char *) "string";
    responseData->civic_address->rdsubbr = (char *) "string";
    responseData->civic_address->prm = (char *) "string";
    responseData->civic_address->pom = (char *) "string";

    // Initialize 'positioningDataList'
    lmf_positioning_method_and_usage_t *temp_positioning_data = ogs_malloc(sizeof(lmf_positioning_method_and_usage_t));
    temp_positioning_data->method = CELLID;
    temp_positioning_data->mode = UE_BASED;
    temp_positioning_data->usage = UNSUCCESS;
    temp_positioning_data->method_code = 31;

    responseData->positioning_data_list = OpenAPI_list_create();
    OpenAPI_list_add(responseData->positioning_data_list, temp_positioning_data);



    // Initialize 'gnssPositioningDataList'
    lmf_gnss_positioning_method_and_usage_t *temp_gnss_positioning_data = ogs_malloc(sizeof(lmf_gnss_positioning_method_and_usage_t));
    temp_gnss_positioning_data->gnss = GPS;
    temp_gnss_positioning_data->mode = UE_BASED;
    temp_gnss_positioning_data->usage = UNSUCCESS;

    responseData->gnss_positioning_data_list = OpenAPI_list_create();
    OpenAPI_list_add(responseData->gnss_positioning_data_list, temp_gnss_positioning_data);

    // Initialize 'ecgi'
    responseData->ecgi->plmn_id->mcc = (char *) "string";
    responseData->ecgi->plmn_id->mnc = (char *) "string";
    responseData->ecgi->eutra_cell_id = (char *) "string";
    responseData->ecgi->nid = (char *) "string";

    // Initialize 'ncgi'
    responseData->ncgi->plmn_id->mcc = (char *) "string";
    responseData->ncgi->plmn_id->mnc = (char *) "string";
    responseData->ncgi->nr_cell_id = (char *) "string";
    responseData->ncgi->nid = (char *) "string";

    // Initialize 'altitude'
    responseData->altitude = 32767;

    // Initialize 'localLocationEstimate'
    lmf_local_2d_point_uncertainty_ellipse_t *temp_local_2d_point = OpenAPI_local2d_point_uncertainty_ellipse_create(
        OpenAPI_supported_gad_shapes_create(),
        OpenAPI_local_origin_create((char *)"string",OpenAPI_geographical_coordinates_create(180,90)),
        OpenAPI_relative_cartesian_location_create(0,0,false,0),
        OpenAPI_uncertainty_ellipse_create(0,0,180),
        100
    );
    responseData->local_location_estimate->local_2d_point = temp_local_2d_point;

    // Initialize 'barometricPressure'
    responseData->barometric_pressure = 115000;

    // Initialize 'servingLMFIdentification'
    responseData->serving_lmf_identification = (char *) "string";

    // Initialize 'uePositioningCap'
    responseData->ue_positioning_cap = (char *) "string";

    // Initialize 'ueAreaIndication'
    responseData->ue_area_indication->country = (char *) "string";
    responseData->ue_area_indication->international_area_ind = false;

    // Initialize 'supportedFeatures'
    responseData->supported_features = (char *) "string";

    // Initialize 'achievedQos'
    responseData->achieved_qos->h_accuracy = 0;
    responseData->achieved_qos->v_accuracy = 0;

    // Initialize 'directReportInd'
    responseData->direct_report_ind = false;
    /* simulated data */


    sendmsg.h = header;
    // ! issue below
    // sendmsg.LMFLocationData = responseData;
    
    if (server) {
        ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_OK); // Replace with your own status
        ogs_assert(response);
        ogs_sbi_server_send_response(stream, response);
    }
    ogs_free(responseData);
    ogs_free(sendmsg.http.location);
    return true;
}


bool lmf_nlmf_loc_handle_cancel_location(
    ogs_sbi_stream_t *stream, ogs_sbi_message_t *recvmsg)
{
    ogs_assert(stream);
    ogs_assert(recvmsg);


    ogs_sbi_message_t sendmsg;
    // ogs_sbi_response_t *response = NULL;
    ogs_sbi_server_t *server = ogs_sbi_server_from_stream(stream);
    ogs_sbi_header_t header = recvmsg->h;

    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_NO_CONTENT); // Replace with your own status
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);

    return true;
}

