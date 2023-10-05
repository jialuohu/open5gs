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
    ogs_sbi_server_t *server = ogs_sbi_server_from_stream(stream);
    ogs_sbi_header_t header = recvmsg->h;
    
    lmf_determine_location_location_data_t *responseData = ogs_malloc(sizeof(lmf_determine_location_location_data_t));
    // ! OpenAPI_input_data_t *input_data = ogs_malloc(sizeof(OpenAPI_input_data_t));
    // !input_data = recvmsg->input_data;
    // ! input_data->supi
    /* simulated data */
    // Initialize 'locationEstimate'
    responseData->location_estimate->point->lon = 180;
    responseData->location_estimate->point->lat = 90;

    // Initialize 'accuracyFulfilmentIndicator'
    responseData->accuracy_fulfilment_indicator = REQUESTED_ACCURACY_FULFILLED;

    // Initialize 'ageOfLocationEstimate'
    responseData->age_of_location_estimate = 32767;

    // Initialize 'timestampOfLocationEstimate'
    char *dummy_time = ogs_malloc(25 * sizeof(char));
    dummy_time = strdup("2023-08-25T22:26:47.397Z");
    responseData->date_time = dummy_time;

    // Initialize 'velocityEstimate'
    responseData->velocity_estimate->horizontal_velocity->h_speed = 2047;
    responseData->velocity_estimate->horizontal_velocity->bearing = 360;
    
    // Initialize 'civicAddress'
    char *dummy_str = ogs_malloc(7 * sizeof(char));
    dummy_str = strdup("string");
    responseData->civic_address->country = dummy_str;
    responseData->civic_address->a1 = dummy_str;
    responseData->civic_address->a2 = dummy_str;
    responseData->civic_address->a3 = dummy_str;
    responseData->civic_address->a4 = dummy_str;
    responseData->civic_address->a5 = dummy_str;
    responseData->civic_address->a6 = dummy_str;
    responseData->civic_address->prd = dummy_str;
    responseData->civic_address->pod = dummy_str;
    responseData->civic_address->sts = dummy_str;
    responseData->civic_address->hno = dummy_str;
    responseData->civic_address->hns = dummy_str;
    responseData->civic_address->lmk = dummy_str;
    responseData->civic_address->loc = dummy_str;
    responseData->civic_address->nam = dummy_str;
    responseData->civic_address->pc = dummy_str;
    responseData->civic_address->bld = dummy_str;
    responseData->civic_address->unit = dummy_str;
    responseData->civic_address->room = dummy_str;
    responseData->civic_address->plc = dummy_str;
    responseData->civic_address->pcn = dummy_str;
    responseData->civic_address->pobox = dummy_str;
    responseData->civic_address->addcode = dummy_str;
    responseData->civic_address->seat = dummy_str;
    responseData->civic_address->rd = dummy_str;
    responseData->civic_address->rdsec = dummy_str;
    responseData->civic_address->rdbr = dummy_str;
    responseData->civic_address->rdsubbr = dummy_str;
    responseData->civic_address->prm = dummy_str;
    responseData->civic_address->pom = dummy_str;

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
    responseData->ecgi->plmn_id->mcc = dummy_str;
    responseData->ecgi->plmn_id->mnc = dummy_str;
    responseData->ecgi->eutra_cell_id = dummy_str;
    responseData->ecgi->nid = dummy_str;

    // Initialize 'ncgi'
    responseData->ncgi->plmn_id->mcc = dummy_str;
    responseData->ncgi->plmn_id->mnc = dummy_str;
    responseData->ncgi->nr_cell_id = dummy_str;
    responseData->ncgi->nid = dummy_str;

    // Initialize 'altitude'
    responseData->altitude = 32767;

    // Initialize 'localLocationEstimate'
    lmf_local_2d_point_uncertainty_ellipse_t *temp_local_2d_point = OpenAPI_local2d_point_uncertainty_ellipse_create(
        OpenAPI_supported_gad_shapes_create(),
        OpenAPI_local_origin_create(dummy_str,OpenAPI_geographical_coordinates_create(180,90)),
        OpenAPI_relative_cartesian_location_create(0,0,false,0),
        OpenAPI_uncertainty_ellipse_create(0,0,180),
        100
    );
    responseData->local_location_estimate->local_2d_point = temp_local_2d_point;

    // Initialize 'barometricPressure'
    responseData->barometric_pressure = 115000;

    // Initialize 'servingLMFIdentification'
    responseData->serving_lmf_identification = dummy_str;

    // Initialize 'uePositioningCap'
    responseData->ue_positioning_cap = dummy_str;

    // Initialize 'ueAreaIndication'
    responseData->ue_area_indication->country = dummy_str;
    responseData->ue_area_indication->international_area_ind = false;

    // Initialize 'supportedFeatures'
    responseData->supported_features = dummy_str;

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

/*
    // * 204
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_NO_CONTENT);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 307
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_TEMPORARY_REDIRECT);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 308
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_PERMANENT_REDIRECT);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 400
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_BAD_REQUEST);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 401
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_UNAUTHORIZED);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 403
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_FORBIDDEN);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 404
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_NOT_FOUND);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 411
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_LENGTH_REQUIRED);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 413
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_PAYLOAD_TOO_LARGE);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 415
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 429
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_TOO_MANY_REQUESTS);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 500
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_INTERNAL_SERVER_ERROR);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 502
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_BAD_GATEWAY);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 503
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_SERVICE_UNAVAILABLE);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);


    // * 504
    ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_GATEWAY_TIMEOUT);
    ogs_assert(response);
    ogs_sbi_server_send_response(stream, response);

*/

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
    ogs_sbi_server_t *server = ogs_sbi_server_from_stream(stream);
    // ogs_sbi_header_t header = recvmsg->h;

    if (server){
        ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_NO_CONTENT); // Replace with your own status
        ogs_assert(response);
        ogs_sbi_server_send_response(stream, response);
    }

    return true;
}

