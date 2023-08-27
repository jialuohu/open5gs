// TODO Implement event handler
#include "nlmf-handler.h"



bool lmf_nlmf_loc_handle_determine_location(
        ogs_sbi_stream_t *stream, ogs_sbi_message_t *recvmsg)
{
    ogs_assert(stream);
    ogs_assert(recvmsg);

/* Handle Request */
    lmf_determine_location_input_data_t *requestData = recvmsg->LMFLocationData;


/* Handle Response */
    ogs_sbi_message_t sendmsg;
    ogs_sbi_response_t *response = NULL;
    ogs_sbi_server_t *server = ogs_sbi_server_from_stream(stream);
    ogs_sbi_header_t header = recvmsg->h;
    
    lmf_determine_location_location_data_t *responseData = ogs_malloc(sizeof(lmf_determine_location_location_data_t));

    /* simulated data */
    // Initialize 'locationEstimate'
    responseData->location_estimate->point->point->lon = 180;
    responseData->location_estimate->point->point->lat = 90;
    responseData->location_estimate->point->shape = "POINT";

    // Initialize 'accuracyFulfilmentIndicator'
    responseData->accuracy_fulfilment_indicator = REQUESTED_ACCURACY_FULFILLED;

    // Initialize 'ageOfLocationEstimate'
    responseData->age_of_location_estimate = 32767;

    // Initialize 'timestampOfLocationEstimate'
    responseData->date_time = "2023-08-25T22:26:47.397Z";

    // Initialize 'velocityEstimate'
    responseData->velocity_estimate->horizontal_velocity->h_speed = 2047;
    responseData->velocity_estimate->horizontal_velocity->bearing = 360;
    
    // Initialize 'civicAddress'
    responseData->civic_address->country = "string";
    responseData->civic_address->A1 = "string";
    responseData->civic_address->A2 = "string";
    responseData->civic_address->A3 = "string";
    responseData->civic_address->A4 = "string";
    responseData->civic_address->A5 = "string";
    responseData->civic_address->A6 = "string";
    responseData->civic_address->PRD = "string";
    responseData->civic_address->POD = "string";
    responseData->civic_address->STS = "string";
    responseData->civic_address->HNO = "string";
    responseData->civic_address->HNS = "string";
    responseData->civic_address->LMK = "string";
    responseData->civic_address->LOC = "string";
    responseData->civic_address->NAM = "string";
    responseData->civic_address->PC = "string";
    responseData->civic_address->BLD = "string";
    responseData->civic_address->UNIT = "string";
    responseData->civic_address->ROOM = "string";
    responseData->civic_address->PLC = "string";
    responseData->civic_address->PCN = "string";
    responseData->civic_address->POBOX = "string";
    responseData->civic_address->ADDCODE = "string";
    responseData->civic_address->SEAT = "string";
    responseData->civic_address->RD = "string";
    responseData->civic_address->RDSEC = "string";
    responseData->civic_address->RDBR = "string";
    responseData->civic_address->RDSUBBR = "string";
    responseData->civic_address->PRM = "string";
    responseData->civic_address->POM = "string";

    // Initialize 'positioningDataList'
    responseData->positioning_data_list = ogs_malloc(sizeof(lmf_positioning_method_and_usage_t));
    responseData->positioning_data_list[0]->method = "CELLID";
    responseData->positioning_data_list[0]->mode = "UE_BASED";
    responseData->positioning_data_list[0]->usage = "UNSUCCESS";
    responseData->positioning_data_list[0]->method_code = 31;


    // Initialize 'gnssPositioningDataList'
    responseData->gnss_positioning_data_list = ogs_malloc(sizeof(lmf_gnss_positioning_method_and_usage_t));
    responseData->gnss_positioning_data_list[0]->gnss = "GPS";
    responseData->gnss_positioning_data_list[0]->mode = "UE_BASED";
    responseData->gnss_positioning_data_list[0]->usage = "UNSUCCESS";


    // Initialize 'ecgi'
    responseData->ecgi->plmn_id->mcc = "string";
    responseData->ecgi->plmn_id->mnc = "string";
    responseData->ecgi->eutra_cell_id = "string";
    responseData->ecgi->nid = "string";

    // Initialize 'ncgi'
    responseData->ncgi->plmn_id->mcc = "string";
    responseData->ncgi->plmn_id->mnc = "string";
    responseData->ncgi->nr_cell_id = "string";
    responseData->ncgi->nid = "string";

    // Initialize 'altitude'
    responseData->altitude = 32767;

    // Initialize 'localLocationEstimate'
    responseData->local_location_estimate->local_2d_point->shape = "POINT";
    responseData->local_location_estimate->local_2d_point->local_origin->coordinate_id = "string";
    responseData->local_location_estimate->local_2d_point->local_origin->point->lon = 180;
    responseData->local_location_estimate->local_2d_point->local_origin->point->lat = 90;
    responseData->local_location_estimate->local_2d_point->point->x = 0;
    responseData->local_location_estimate->local_2d_point->point->y = 0;
    responseData->local_location_estimate->local_2d_point->point->z = 0;
    responseData->local_location_estimate->local_2d_point->uncertainty_ellipse->semi_major = 0;
    responseData->local_location_estimate->local_2d_point->uncertainty_ellipse->semi_minor = 0;
    responseData->local_location_estimate->local_2d_point->uncertainty_ellipse->orientation_major = 180;
    responseData->local_location_estimate->local_2d_point->confidence = 100;

    // Initialize 'barometricPressure'
    responseData->barometric_pressure = 115000;

    // Initialize 'servingLMFIdentification'
    responseData->serving_lmf_identification = "string";

    // Initialize 'uePositioningCap'
    responseData->ue_positioning_cap = "string";

    // Initialize 'ueAreaIndication'
    responseData->ue_area_indication->country = "string";
    responseData->ue_area_indication->international_area_ind = false;

    // Initialize 'supportedFeatures'
    responseData->supported_features = "string";

    // Initialize 'achievedQos'
    responseData->achieved_qos->h_accuracy = 0;
    responseData->achieved_qos->v_accuracy = 0;

    // Initialize 'directReportInd'
    responseData->direct_report_ind = false;
    /* simulated data */


    sendmsg.h = header;
    sendmsg.LMFLocationData = responseData;
    
    if (server) {
        ogs_sbi_response_t *response = ogs_sbi_build_response(&sendmsg, OGS_SBI_HTTP_STATUS_OK); // Replace with your own status
        ogs_assert(response);
        ogs_sbi_server_send_response(stream, response);
    }
    ogs_free(responseData);
    ogs_free(sendmsg.http.location);
    return true;
}


