#ifndef LMF_CONTEXT_H
#define LMF_CONTEXT_H

// TODO Check included .h files.
#include "ogs-app.h"
#include "ogs-sbi.h"

#include "lmf-sm.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int __lmf_log_domain;

#undef OGS_LOG_DOMAIN
#define OGS_LOG_DOMAIN __lmf_log_domain


typedef struct lmf_context_s {
    ogs_list_t      udm_ue_list;
    ogs_hash_t     *suci_hash;          // * temp
    ogs_hash_t     *supi_hash;          // * temp
} lmf_context_t;

// Temporary array size given
#define MAX_NUM_OF_POS_DATA_LIST                            100

// Common Definitions
#define number                                              float
#define integer                                             int
#define boolean                                             char
#define string                                              char*

#define false                                               0
#define true                                                1

typedef string                                              correlation_id_t;
typedef string                                              supi_t;
typedef string                                              pei_t;
typedef string                                              gpsi_t;
typedef string                                              mcc_t;
typedef string                                              mnc_t;
typedef string                                              eutra_cell_id_t;
typedef string                                              nid_t;
typedef string                                              nr_cell_id_t;
typedef string                                              timestamp_of_location_estimate;
typedef string                                              lmf_identification_t;
typedef string                                              ue_positioning_capabilities_t;
typedef string                                              supported_features_t;
typedef string                                              nf_instance_id;
typedef string                                              uri_t;
typedef string                                              ldr_reference_t;
typedef string                                              lir_reference_t;
typedef string                                              tac_t;
typedef string                                              access_type_t;
typedef string                                              lcs_broadcast_assistance_types_data_t;          // ! openapi definition problem
typedef string                                              date_time_t;
typedef string                                              bytes_t;                                        // ! openapi definition problem

typedef integer                                             orientation_t;
typedef integer                                             age_of_location_estimate_t;
typedef integer                                             confidence_t;
typedef integer                                             inner_radius_t;
typedef integer                                             angle_t;
typedef integer                                             barometric_pressure_t;
typedef integer                                             lcs_service_type_t;
typedef integer                                             reporting_amount_t;
typedef integer                                             reporting_interval_t;
typedef integer                                             reporting_interval_ms_t;
typedef integer                                             minimum_interval_t;
typedef integer                                             maximum_interval_t;
typedef integer                                             sampling_interval_t;
typedef integer                                             reporting_duration_t;
typedef integer                                             linear_distance_t;
typedef integer                                             duration_sec_t;


typedef number                                              uncertainty_t;
typedef number                                              altitude_t;
typedef number                                              horizontal_speed_t;
typedef number                                              vertical_speed_t;
typedef number                                              speed_uncertainty_t;
typedef number                                              accuracy_t;




// * enum member index starts at 0
#define LMF_ENUM_START(name)                                typedef enum name##_e { name##_NULL = 0,
#define LMF_ENUM_END(name)                                  } name##_t;
#define LMF_ENUM_FORWARD_DECLARATION(name)                  typedef enum name##_e name##_t;
#define LMF_STRUCT_FORWARD_DECLARATION(name)                typedef struct name##_s name##_t;
#define LMF_UNION_FORWARD_DECLARATION(name)                 typedef union name##_u name##_t;


// * enum forward declaration
LMF_ENUM_FORWARD_DECLARATION(lmf_response_time)
LMF_ENUM_FORWARD_DECLARATION(lmf_lcs_priority)
LMF_ENUM_FORWARD_DECLARATION(lmf_velocity_requested)
LMF_ENUM_FORWARD_DECLARATION(lmf_external_client_type)
LMF_ENUM_FORWARD_DECLARATION(lmf_supported_gad_shapes)
LMF_ENUM_FORWARD_DECLARATION(lmf_accuracy_fulfilment_indicator)
LMF_ENUM_FORWARD_DECLARATION(lmf_vertical_direction)
LMF_ENUM_FORWARD_DECLARATION(lmf_positioning_method)
LMF_ENUM_FORWARD_DECLARATION(lmf_positioning_mode)
LMF_ENUM_FORWARD_DECLARATION(lmf_usage)
LMF_ENUM_FORWARD_DECLARATION(lmf_gnss_id)
LMF_ENUM_FORWARD_DECLARATION(lmf_ldr_type)
LMF_ENUM_FORWARD_DECLARATION(lmf_reporting_area_type)
LMF_ENUM_FORWARD_DECLARATION(lmf_occurrence_info)
LMF_ENUM_FORWARD_DECLARATION(lmf_reporting_access_type)
LMF_ENUM_FORWARD_DECLARATION(lmf_cm_state)
LMF_ENUM_FORWARD_DECLARATION(lmf_ue_location_service_ind)
LMF_ENUM_FORWARD_DECLARATION(lmf_lp_hap_type)


// * struct forward_declaration
LMF_STRUCT_FORWARD_DECLARATION(lmf_location_qos)
LMF_STRUCT_FORWARD_DECLARATION(ecgi)
LMF_STRUCT_FORWARD_DECLARATION(lmf_plmn_id)
LMF_STRUCT_FORWARD_DECLARATION(ncgi)
LMF_STRUCT_FORWARD_DECLARATION(lmf_geographical_coordinates)
LMF_STRUCT_FORWARD_DECLARATION(lmf_point)
LMF_STRUCT_FORWARD_DECLARATION(lmf_uncertainty_ellipse)
LMF_STRUCT_FORWARD_DECLARATION(lmf_uncertainty_ellipsoid)
LMF_STRUCT_FORWARD_DECLARATION(lmf_point_uncertainty_ellipse)
LMF_STRUCT_FORWARD_DECLARATION(lmf_point_uncertainty_circle)
LMF_STRUCT_FORWARD_DECLARATION(lmf_polygon)
LMF_STRUCT_FORWARD_DECLARATION(lmf_point_altitude)
LMF_STRUCT_FORWARD_DECLARATION(lmf_point_altitude_uncertainty)
LMF_STRUCT_FORWARD_DECLARATION(lmf_ellipsoid_arc)
LMF_STRUCT_FORWARD_DECLARATION(lmf_geographic_area)
LMF_STRUCT_FORWARD_DECLARATION(lmf_horizontal_velocity)
LMF_STRUCT_FORWARD_DECLARATION(lmf_velocity_estimate)
LMF_STRUCT_FORWARD_DECLARATION(lmf_horizontal_velocity_with_uncertainty)
LMF_STRUCT_FORWARD_DECLARATION(lmf_horizontal_with_vertical_velocity_and_uncertainty)
LMF_STRUCT_FORWARD_DECLARATION(lmf_civic_address)
LMF_STRUCT_FORWARD_DECLARATION(lmf_positioning_method_and_usage)
LMF_STRUCT_FORWARD_DECLARATION(lmf_gnss_positioning_method_and_usage)
LMF_STRUCT_FORWARD_DECLARATION(lmf_local_origin)
LMF_STRUCT_FORWARD_DECLARATION(lmf_relative_cartesian_location)
LMF_STRUCT_FORWARD_DECLARATION(lmf_local_2d_point_uncertainty_ellipse)
LMF_STRUCT_FORWARD_DECLARATION(lmf_local_3d_point_uncertainty_ellipsoid)
LMF_STRUCT_FORWARD_DECLARATION(lmf_ue_area_indication)
LMF_STRUCT_FORWARD_DECLARATION(lmf_minor_location_qos)
LMF_STRUCT_FORWARD_DECLARATION(lmf_ue_lcs_capability)
LMF_STRUCT_FORWARD_DECLARATION(lmf_periodic_event_info)
LMF_STRUCT_FORWARD_DECLARATION(lmf_area_event_info)
LMF_STRUCT_FORWARD_DECLARATION(lmf_motion_event_info)
LMF_STRUCT_FORWARD_DECLARATION(lmf_ue_connectivity_state)
LMF_STRUCT_FORWARD_DECLARATION(lmf_ref_to_binary_data)
LMF_STRUCT_FORWARD_DECLARATION(lmf_tnap_id)
LMF_STRUCT_FORWARD_DECLARATION(lmf_twap_id)



// * union forward_declaration
LMF_UNION_FORWARD_DECLARATION(lmf_local_area)


// Contents of enum and struct
typedef enum lmf_response_time_e{
    LOW_DELAY,
    DELAY_TOLERANT
} lmf_response_time_t;

typedef enum lmf_lcs_priority_e {
    HIGHEST_PRIORITY,
    NORMAL_PRIORITY
} lmf_lcs_priority_t;

typedef enum lmf_velocity_requested_e {
    VELOCITY_IS_NOT_REQUESTED,
    VELOCITY_IS_REQUESTED
} lmf_velocity_requested_t;

typedef enum lmf_external_client_type_e { 
    EMERGENCY_SERVICES, 
    VALUE_ADDED_SERVICES, 
    PLMN_OPERATOR_SERVICES, 
    LAWFUL_INTERCEPT_SERVICES, 
    PLMN_OPERATOR_BROADCAST_SERVICES, 
    PLMN_OPERATOR_OM, 
    PLMN_OPERATOR_ANONYMOUS_STATISTICS, 
    PLMN_OPERATOR_TARGET_MS_SERVICE_SUPPORT     
} lmf_external_client_type_t;

typedef enum lmf_supported_gad_shapes_e {
    POINT,
    POINT_UNCERTAINTY_CIRCLE,
    POINT_UNCERTAINTY_ELLIPSE,
    POLYGON,
    POINT_ALTITUDE,
    POINT_ALTITUDE_UNCERTAINTY,
    ELLIPSOID_ARC
} lmf_supported_gad_shapes_t;

typedef enum lmf_accuracy_fulfilment_indicator_e {
    REQUESTED_ACCURACY_FULFILLED,
    REQUESTED_ACCURACY_NOT_FULFILLED
} lmf_accuracy_fulfilment_indicator_t;

typedef enum lmf_vertical_direction_e {
    UPWARD,
    DOWNWARD
} lmf_vertical_direction_t;

typedef enum lmf_positioning_method_e {
    CELLID,
    ECID,
    OTDOA,
    BAROMETRIC_PRESSURE,
    WLAN,
    BLUETOOTH,
    MBS
} lmf_positioning_method_t;

typedef enum lmf_positioning_mode_e {
    UE_BASED,
    UE_ASSISTED,
    CONVENTIONAL
} lmf_positioning_mode_t;

typedef enum lmf_usage_e {
    UNSUCCESS,
    SUCCESS_RESULTS_NOT_USED,
    SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION,
    SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION,
    SUCCESS_METHOD_NOT_DETERMINED
} lmf_usage_t;

typedef enum lmf_gnss_id_e {
    GPS,
    GALILEO,
    SBAS,
    MODERNIZED_GPS,
    QZSS,
    GLONASS
} lmf_gnss_id_t;

typedef enum lmf_ldr_type_e {
    UE_AVAILABLE,
    PERIODIC,
    ENTERING_INTO_AREA,
    LEAVING_FROM_AREA,
    BEING_INSIDE_AREA,
    MOTION
} lmf_ldr_type_t;

typedef enum lmf_reporting_area_type_e {
    EPS_TRACKING_AREA_IDENTITY,
    E_UTRAN_CELL_GLOBAL_IDENTIFICATION,
    FIVE_GS_TRACKING_AREA_IDENTITY,
    NR_CELL_GLOBAL_IDENTITY
} lmf_reporting_area_type_t;

typedef enum lmf_occurrence_info_e {
    ONE_TIME_EVENT,
    MULTIPLE_TIME_EVENT
} lmf_occurrence_info_t;

typedef enum lmf_reporting_access_type_e {
    NR,
    EUTRA_CONNECTED_TO_5GC,
    NON_3GPP_CONNECTED_TO_5GC,
    NR_LEO,
    NR_MEO,
    NR_GEO,
    NR_OTHER_SAT
} lmf_reporting_access_type_t;

typedef enum lmf_cm_state_e {
    IDLE,
    CONNECTED
} lmf_cm_state_t;

typedef enum lmf_ue_location_service_ind_e {
    LOCATION_ESTIMATE,
    LOCATION_ASSISTANCE_DATA
} lmf_ue_location_service_ind_t;

typedef enum lmf_lp_hap_type_e {
    LOW_POW_HIGH_ACCU_POS
} lmf_lp_hap_type_t;



typedef struct lmf_location_qos_s {
    number hAccuracy;
    number vAccuracy;
    boolean vertRequested;
    lmf_response_time_t responseTime;
} lmf_location_qos_t;

typedef struct ecgi_s {
    lmf_plmn_id_t *plmn_id;
    eutra_cell_id_t eutra_cell_id;
    nid_t nid;
} ecgi_t;

typedef struct lmf_plmn_id_s {
    mcc_t mcc;
    mnc_t mnc;
} lmf_plmn_id_t;

typedef struct ncgi_s {
    lmf_plmn_id_t *plmn_id;
    nr_cell_id_t nr_cell_id;
    nid_t nid;
} ncgi_t;

typedef struct tai_s {
    lmf_plmn_id_t *plmn_id;
    tac_t tac;
    nid_t nid;
} tai_t;


typedef struct lmf_geographical_coordinates_s{
    number lon;
    number lat;
} lmf_geographical_coordinates_t;

typedef struct lmf_point_s {
    lmf_supported_gad_shapes_t shape;
    lmf_geographical_coordinates_t *point;
} lmf_point_t;

typedef struct lmf_uncertainty_ellipse_s {
    uncertainty_t semi_major;
    uncertainty_t semi_minor;
    orientation_t orientation_major;
} lmf_uncertainty_ellipse_t;

typedef struct lmf_uncertainty_ellipsoid_s {
    uncertainty_t semi_major;
    uncertainty_t semi_minor;
    uncertainty_t vertical;
    orientation_t orientation_major;
} lmf_uncertainty_ellipsoid_t;

typedef struct lmf_point_uncertainty_ellipse_s{
    lmf_supported_gad_shapes_t shape;
    lmf_geographical_coordinates_t *point;
    lmf_uncertainty_ellipse_t *uncertainty_ellipse;
    confidence_t confidence;
} lmf_point_uncertainty_ellipse_t;

typedef struct lmf_point_uncertainty_circle_s {
    lmf_supported_gad_shapes_t shape;
    lmf_geographical_coordinates_t *point;
    uncertainty_t uncertainty;
} lmf_point_uncertainty_circle_t;

typedef struct lmf_polygon_s {
    lmf_supported_gad_shapes_t shape;
    lmf_geographical_coordinates_t *point_list[15];                  // TODO confirm with the maximum
} lmf_polygon_t;

typedef struct lmf_point_altitude_s {
    lmf_supported_gad_shapes_t shape;
    lmf_geographical_coordinates_t *point;
    altitude_t altitude;
} lmf_point_altitude_t;

typedef struct lmf_point_altitude_uncertainty_s {
    lmf_supported_gad_shapes_t shape;
    lmf_geographical_coordinates_t *point;
    altitude_t altitude;
    lmf_uncertainty_ellipse_t *uncertainty_ellipse;
    uncertainty_t uncertainty;
    confidence_t  confidence;
} lmf_point_altitude_uncertainty_t;

typedef struct lmf_ellipsoid_arc_s {
    lmf_supported_gad_shapes_t shape;
    lmf_geographical_coordinates_t *point;
    inner_radius_t inner_radius;
    uncertainty_t uncertainty_radius;
    angle_t offset_angle;
    angle_t included_angle;
    confidence_t confidence;
} lmf_ellipsoid_arc_t;

typedef struct lmf_geographic_area_s {
    lmf_point_t *point;
    lmf_point_uncertainty_ellipse_t *point_uncertainty_ellipse;
    lmf_point_uncertainty_circle_t *point_uncertainty_circle;
    lmf_polygon_t *polygon;
    lmf_point_altitude_t *point_altitude;
    lmf_point_altitude_uncertainty_t *point_altitude_uncertainty;
    lmf_ellipsoid_arc_t *ellipsoid_arc;
} lmf_geographic_area_t;

typedef struct lmf_horizontal_velocity_s {
    horizontal_speed_t h_speed;
    angle_t bearing;
} lmf_horizontal_velocity_t;

typedef struct lmf_horizontal_with_vertical_velocity_s {
    horizontal_speed_t h_speed;
    angle_t bearing;
    vertical_speed_t v_speed;
    lmf_vertical_direction_t v_direction;
} lmf_horizontal_with_vertical_velocity_t;

typedef struct lmf_horizontal_velocity_with_uncertainty_s {
    horizontal_speed_t h_speed;
    angle_t bearing;
    speed_uncertainty_t uncertainty;
} lmf_horizontal_velocity_with_uncertainty_t;

typedef struct lmf_horizontal_with_vertical_velocity_and_uncertainty_s {
    horizontal_speed_t h_speed;
    angle_t bearing;
    vertical_speed_t v_speed;
    lmf_vertical_direction_t v_direction;
    speed_uncertainty_t h_uncertainty;
    speed_uncertainty_t v_uncertainty;
} lmf_horizontal_with_vertical_velocity_and_uncertainty_t;

typedef struct lmf_velocity_estimate_s {
    lmf_horizontal_velocity_t *horizontal_velocity;
    lmf_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity;
    lmf_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty;
    lmf_horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty;
} lmf_velocity_estimate_t;

typedef struct lmf_civic_address_s {
    string country;
    string A1;
    string A2;
    string A3;
    string A4;
    string A5;
    string A6;
    string PRD;
    string POD;
    string STS;
    string HNO;
    string HNS;
    string LMK;
    string LOC;
    string NAM;
    string PC;
    string BLD;
    string UNIT;
    string ROOM;
    string PLC;
    string PCN;
    string POBOX;
    string ADDCODE;
    string SEAT;
    string RD;
    string RDSEC;
    string RDBR;
    string RDSUBBR;
    string PRM;
    string POM;
} lmf_civic_address_t;


typedef struct lmf_local_2d_point_uncertainty_ellipse_s{
    lmf_supported_gad_shapes_t shape;
    lmf_local_origin_t *local_origin;
    lmf_relative_cartesian_location_t *point;
    lmf_uncertainty_ellipse_t *uncertainty_ellipse;
    confidence_t confidence;
} lmf_local_2d_point_uncertainty_ellipse_t;


typedef struct lmf_local_3d_point_uncertainty_ellipsoid_s{
    lmf_supported_gad_shapes_t shape;
    lmf_local_origin_t *local_origin;
    lmf_relative_cartesian_location_t *point;
    lmf_uncertainty_ellipsoid_t *uncertainty_ellipsoid;
    confidence_t confidence;
} lmf_local_3d_point_uncertainty_ellipsoid_t;


typedef union lmf_local_area_u{
    lmf_local_2d_point_uncertainty_ellipse_t *local_2d_point;
    lmf_local_3d_point_uncertainty_ellipsoid_t *local_3d_point;
} lmf_local_area_t;


typedef struct lmf_positioning_method_and_usage_s {
    lmf_positioning_method_t method;
    lmf_positioning_mode_t mode;
    lmf_usage_t usage;
    integer method_code;
} lmf_positioning_method_and_usage_t;


typedef struct lmf_gnss_positioning_method_and_usage_s {
    lmf_positioning_mode_t mode;
    lmf_gnss_id_t gnss;
    lmf_usage_t usage;
} lmf_gnss_positioning_method_and_usage_t;


typedef struct lmf_local_origin_s{
    string coordinate_id;
    lmf_geographical_coordinates_t *point;
} lmf_local_origin_t;


typedef struct lmf_relative_cartesian_location_s{
    float x;
    float y;
    float z;
} lmf_relative_cartesian_location_t;


typedef struct lmf_ue_area_indication_s{
    string country;
    boolean international_area_ind;
} lmf_ue_area_indication_t;


typedef struct lmf_minor_location_qos_s{
    accuracy_t h_accuracy;
    accuracy_t v_accuracy;
} lmf_minor_location_qos_t;


typedef struct lmf_ue_lcs_capability_s {
    boolean lpp_support;
    boolean ciot_optimisation;
} lmf_ue_lcs_capability_t;


typedef struct lmf_periodic_event_info_s {
    reporting_amount_t reporting_amount;
    reporting_interval_t reporting_interval;
    boolean reporting_infinite_ind;
    reporting_interval_ms_t reporting_interval_ms;
} lmf_periodic_event_info_t;


typedef struct lmf_area_event_info_s {
    lmf_reporting_area_t **area_definition;                 // Array
    lmf_occurrence_info_t occurrence_info;
    minimum_interval_t minimum_interval;
    maximum_interval_t maximum_interval;
    sampling_interval_t sampling_interval;
    reporting_duration_t reporting_duration;
    boolean reporting_location_req;
} lmf_area_event_info_t;


typedef struct lmf_reporting_area_s{
    lmf_reporting_area_type_t reporting_area_type;
    tai_t tai;
    ecgi_t* ecgi;
    ncgi_t* ncgi;
} lmf_reporting_area_t;


typedef struct lmf_motion_event_info_s{
    linear_distance_t linear_distance;
    lmf_occurrence_info_t occurrence_info;
    minimum_interval_t minimum_interval;
    maximum_interval_t maximum_interval;
    sampling_interval_t sampling_interval;
    reporting_duration_t reporting_duration;
    boolean reporting_location_req;
} lmf_motion_event_info_t;


typedef struct lmf_ue_connectivity_state_s {
    access_type_t access_type;
    lmf_cm_state_t connectivity_state;
} lmf_ue_connectivity_state_t;


typedef struct lmf_ref_to_binary_data_s{
    string content_id;
} lmf_ref_to_binary_data_t;

typedef struct lmf_tnap_id_s {
    string ss_id;
    string bss_id;
    bytes_t civic_address;
} lmf_tnap_id_t;

typedef struct lmf_twap_id_s {
    string ss_id;
    string bss_id;
    bytes_t civic_address;
} lmf_twap_id_t;

// Determine Location Input Data Structure
typedef struct lmf_determine_location_input_data_s {
    lmf_external_client_type_t external_client_type;
    correlation_id_t correlation_id;
    nf_instance_id amf_id;
    lmf_location_qos_t* location_qos;
    lmf_supported_gad_shapes_t supported_gad_shapes;
    supi_t supi;
    pei_t pei;
    gpsi_t gpsi;
    ecgi_t *ecgi;
    ecgi_t *ecgi_on_second_node;
    ncgi_t *ncgi;
    ncgi_t *ncgi_on_second_node;
    lmf_lcs_priority_t priority;
    lmf_velocity_requested_t velocityRequested;
    lmf_ue_lcs_capability_t *ue_lcs_cap;
    lcs_service_type_t lcs_service_type;
    lmf_ldr_type_t ldr_type;
    uri_t hgmlc_call_back_uri;
    uri_t lir_gmlc_call_back_uri;
    uri_t vgmlc_address;
    ldr_reference_t ldr_reference;
    lir_reference_t lir_reference;
    lmf_periodic_event_info_t *periodic_event_info;
    lmf_area_event_info_t *area_event_info;
    lmf_motion_event_info_t *motion_event_info;
    lmf_reporting_access_type_t *reporting_access_types;                       // Array
    lmf_ue_connectivity_state_t **ue_connectivity_states;                       // Array
    lmf_ue_location_service_ind_t ue_location_service_ind;
    lcs_broadcast_assistance_types_data_t mo_assistance_data_types;
    lmf_ref_to_binary_data_t *ref_to_binary_data;
    lmf_ref_to_binary_data_t **lpp_message_ext;                                 //Array
    supported_features_t supported_features;
    ue_positioning_capabilities_t ue_positioning_cap;
    lmf_tnap_id_t tnap_id;
    lmf_twap_id_t twap_id;
    boolean ue_country_det_ind;
    date_time_t scheduled_loc_time;
    boolean reliable_loc_req;
    lmf_reporting_area_t **evt_rpt_allowed_areas;                                  // Array
    boolean ue_unaware_ind;
    boolean intermediate_location_ind;
    duration_sec_t max_resp_time;
    lmf_lp_hap_type_t lp_hap_type;
} lmf_determine_location_input_data_t;


// Determine Location Location Data Structure
typedef struct lmf_determine_location_location_data_s {
    lmf_geographic_area_t *location_estimate;
    lmf_accuracy_fulfilment_indicator_t accuracy_fulfilment_indicator;
    age_of_location_estimate_t age_of_location_estimate;
    timestamp_of_location_estimate date_time;
    lmf_local_area_t *local_location_estimate;
    barometric_pressure_t barometric_pressure;
    lmf_identification_t serving_lmf_identification;
    ue_positioning_capabilities_t ue_positioning_cap;
    lmf_ue_area_indication_t *ue_area_indication;
    supported_features_t supported_features;
    lmf_velocity_estimate_t *velocity_estimate;
    lmf_civic_address_t *civic_address;
    lmf_positioning_method_and_usage_t **positioning_data_list;               // Array         
    lmf_gnss_positioning_method_and_usage_t **gnss_positioning_data_list;     // Array      
    ecgi_t *ecgi;
    ncgi_t *ncgi;
    altitude_t altitude;
    lmf_minor_location_qos_t *achieved_qos;
    boolean direct_report_ind;
} lmf_determine_location_location_data_t;



void lmf_context_init(void);
void lmf_context_final(void);
lmf_context_t *lmf_self(void);

int lmf_context_parse_config(void);


#ifdef __cplusplus
}
#endif

#endif  /* LMF_CONTEXT_H */