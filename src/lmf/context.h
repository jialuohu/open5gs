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

// ! Not sure if I should implement lmf_context_t like other modules
// ! What is the usage of it?
typedef struct lmf_context_s {
    /*
    ogs_list_t      udm_ue_list;
    ogs_hash_t      *suci_hash;
    ogs_hash_t      *supi_hash;
    */
} lmf_context_t;

// Temporary array size given
#define THE_MAXIMUM_SIZE_OF_N                               100

// Common Definitions
#define number                                              float
#define integer                                             int
#define boolean                                             char
#define string                                              char*


typedef string                                              lmf_correlation_id_t;
typedef string                                              supi_t;
typedef string                                              pei_t;
typedef string                                              gpsi_t;
typedef string                                              mcc_t;
typedef string                                              mnc_t;
typedef string                                              eutra_cell_id_t;
typedef string                                              nid_t;
typedef string                                              nr_cell_id_t;
typedef number                                              uncertainty_t;
typedef integer                                             orientation_t;
typedef integer                                             confidence_t;
typedef number                                              altitude_t;
typedef integer                                             inner_radius_t;
typedef integer                                             angle_t;
typedef number                                              horizontal_speed_t;
typedef number                                              vertical_speed_t;
typedef number                                              speed_uncertainty_t;
typedef integer                                             age_of_location_estimate_t;


// * enum member index starts at 0
#define LMF_ENUM_START(name)                                typedef enum name##_e { name##_NULL = 0,
#define LMF_ENUM_END(name)                                  } name##_t;
#define LMF_ENUM_FORWARD_DECLARATION(name)                  typedef enum name##_e name##_t;
#define LMF_STRUCT_FORWARD_DECLARATION(name)                typedef struct name##_s name##_t;

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

// * struct forward_declaration
LMF_STRUCT_FORWARD_DECLARATION(lmf_location_qos)
LMF_STRUCT_FORWARD_DECLARATION(ecgi)
LMF_STRUCT_FORWARD_DECLARATION(lmf_plmn_id)
LMF_STRUCT_FORWARD_DECLARATION(ncgi)
LMF_STRUCT_FORWARD_DECLARATION(lmf_geographical_coordinates)
LMF_STRUCT_FORWARD_DECLARATION(lmf_point)
LMF_STRUCT_FORWARD_DECLARATION(lmf_uncertainty_ellipse)
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


typedef struct lmf_geographical_coordinates_s{
    number lon;
    number lat;
} lmf_geographical_coordinates_t;

typedef struct lmf_point_s {
    lmf_supported_gad_shapes_t shape;
    lmf_geographical_coordinates_t point;
} lmf_point_t;

typedef struct lmf_uncertainty_ellipse_s {
    uncertainty_t semi_major;
    uncertainty_t semi_minor;
    orientation_t orientation_major;
} lmf_uncertainty_ellipse_t;

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
    lmf_geographical_coordinates_t point_list[15];                  // TODO confirm with the maximum
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

typedef struct lmf_positioning_method_and_usage_s {
    lmf_positioning_method_t method;
    lmf_positioning_mode_t mode;
    lmf_usage_t usage;
} lmf_positioning_method_and_usage_t;

typedef struct lmf_gnss_positioning_method_and_usage_s {
    lmf_positioning_mode_t mode;
    lmf_gnss_id_t gnss;
    lmf_usage_t usage;
} lmf_gnss_positioning_method_and_usage_t;



// Determine Location Input Data Structure
typedef struct lmf_determine_location_input_data_s {
    lmf_external_client_type_t external_client_type;
    lmf_correlation_id_t correlation_id;
    lmf_location_qos_t* location_qos;
    lmf_supported_gad_shapes_t supported_gad_shapes;
    supi_t supi;
    pei_t pei;
    gpsi_t gpsi;
    ecgi_t ecgi;
    ncgi_t ncgi;
    lmf_lcs_priority_t priority;
    lmf_velocity_requested_t velocityRequested;
} lmf_determine_location_input_data_t;


// Determine Location Location Data Structure
typedef struct lmf_determine_location_location_data_s {
    lmf_geographic_area_t *location_estimate;
    lmf_accuracy_fulfilment_indicator_t accuracy_fulfilment_indicator;
    age_of_location_estimate_t age_of_location_estimate;
    lmf_velocity_estimate_t *velocity_estimate;
    lmf_civic_address_t *civic_address;
    lmf_positioning_method_and_usage_t *positioning_data_list[THE_MAXIMUM_SIZE_OF_N];                        
    lmf_gnss_positioning_method_and_usage_t *gnss_positioning_data_list[THE_MAXIMUM_SIZE_OF_N];              
    ecgi_t ecgi;
    ncgi_t ncgi;
    altitude_t altitude;
} lmf_determine_location_location_data_t;



void lmf_context_init(void);
void lmf_context_final(void);
lmf_context_t *lmf_self(void);

int lmf_context_parse_config(void);


#ifdef __cplusplus
}
#endif

#endif  /* LMF_CONTEXT_H */