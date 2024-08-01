/*

############################################################################################################################################
#                                                                                                                                          #
#                                                                                                                                          #
#                          This file was autogenerated from the data on https://github.com/probonopd/irdb                                  #
#                it represents the collection of remotes controls data in a C structure suitable for a microcontroller.                    #           
#                                                                                                                                          #
#                                                                                                                                          #
############################################################################################################################################

*/


// Contains/accesses irdb by Simon Peter and contributors, used under permission. 
// For licensing details and for information on how to contribute to the database, 
// see  https://github.com/probonopd/irdb


#ifndef REMOTE_COMMANDS_H
#define REMOTE_COMMANDS_H

#include <pgmspace.h>
#include <stddef.h>
#include <stdint.h>
#include <string>
#include <cstring>
#include <vector>

#define NUM_MANUFACTURERS 631

// Protocoles IR
typedef enum ProtocolEnum{
    _48_NEC1 = 0,
    _48_NEC2 = 1,
    AIWA = 2,
    AKAI = 3,
    _APPLE = 4,
    BARCO = 5,
    BLAUPUNKT = 6,
    BOSE = 7,
    CANALSAT = 8,
    _DENON = 9,
    DENON_K = 10,
    DENON_1_ = 11,
    DENON_2_ = 12,
    DGTEC = 13,
    DIRECTV = 14,
    DISH_NETWORK = 15,
    DISHPLAYER = 16,
    EMERSON = 17,
    F12 = 18,
    FUJITSU = 19,
    G_I_4DTV = 20,
    G_I_CABLE = 21,
    GXB = 22,
    GRUNDIG16 = 23,
    GRUNDIG16_30 = 24,
    _JVC = 25,
    JVC_48 = 26,
    JVC_2_ = 27,
    JERROLD = 28,
    KATHREIN = 29,
    KONKA = 30,
    LOGITECH = 31,
    LUMAGEN = 32,
    MCE = 33,
    MITSUBISHI = 34,
    _NEC = 35,
    NEC1 = 36,
    NEC1_F16 = 37,
    NEC1_RNC = 38,
    NEC1_Y1 = 39,
    NEC1_Y2 = 40,
    NEC1_Y3 = 41,
    _NEC2 = 42,
    NEC2_F16 = 43,
    NECX1 = 44,
    NECX2 = 45,
    NRC16 = 46,
    NRC17 = 47,
    NOKIA = 48,
    NOKIA12 = 49,
    NOKIA32 = 50,
    PACEMSS = 51,
    _PANASONIC = 52,
    PANASONIC2 = 53,
    PANASONIC_OLD = 54,
    PIONEER = 55,
    PROTON = 56,
    _RC5 = 57,
    RC5_7F = 58,
    _RC6 = 59,
    RC6_6_20 = 60,
    RCA = 61,
    RCA_OLD_ = 62,
    RCA_38 = 63,
    RCA_38_OLD_ = 64,
    RECS80 = 65,
    REPLAY = 66,
    SAMSUNG20 = 67,
    SAMSUNG36 = 68,
    SCATL_6 = 69,
    SEJIN_1_38 = 70,
    SEJIN_1_56 = 71,
    _SHARP = 72,
    SHARPDVD = 73,
    SHARP_1_ = 74,
    SHARP_2_ = 75,
    SONY12 = 76,
    SONY15 = 77,
    SONY20 = 78,
    STREAMZAP = 79,
    TEAC_K = 80,
    THOMSON = 81,
    THOMSON7 = 82,
    TIVO_UNIT_0 = 83,
    TIVO_UNIT_1 = 84,
    TIVO_UNIT_2 = 85,
    TIVO_UNIT_3 = 86,
    TIVO_UNIT_4 = 87,
    TIVO_UNIT_5 = 88,
    TIVO_UNIT_6 = 89,
    TIVO_UNIT_7 = 90,
    TIVO_UNIT_8 = 91,
    TIVO_UNIT_9 = 92,
    VELLEMAN = 93,
    XMP = 94,
    XMP_1 = 95,
    XMP_2 = 96,
    ZAPTOR_56 = 97,
    ZENITH = 98,
    DISH_NETWO = 99,
    PANASONIC_ = 100,
    TIVO_UNIT = 101,
    RCA_38_OLD = 102,
    _KASEIKYO = 103,
} ProtocolEnum;

typedef struct {
    const char* functionName;
    ProtocolEnum protocol;
    int16_t device;  // peut etre negatif
    int16_t subdevice;   // peut etre negatif 
    int16_t function;  
} RemoteCommand;

typedef struct {
    char fileName[14];
    const RemoteCommand *commands;
    size_t commandCount;
} Remote;

typedef struct {
    char name[30];
    const Remote *remotes;
    size_t remoteCount;
} Product;

typedef struct {
    char name[24];
    const Product *products;
    size_t productCount;
} Manufacturer;

typedef struct {
    char manufacturerName[24];
    char productName[30];
    char remoteFileName[14];
    char favoriteName[14];
} FavoriteRemote;

// ########################## CUSTOM ###############################

// Déclaration du tableau de fabricants qui contient toutes les data
extern const Manufacturer manufacturers[];

// Déclaration des fabricants fav
extern const std::vector<std::string> popularManufacturerNames;

// Déclaration des télécommandes default fav
extern const std::vector<FavoriteRemote> defaultFavoriteRemotes;

// Surcharge de l'opérateur == pour comparer nos structs
bool operator==(const Manufacturer& lhs, const Manufacturer& rhs);
bool operator==(const Product& lhs, const Product& rhs);
bool operator==(const Remote& lhs, const Remote& rhs);
bool operator==(const RemoteCommand& lhs, const RemoteCommand& rhs);
bool operator==(const FavoriteRemote& lhs, const FavoriteRemote& rhs);

// !=
bool operator!=(const Manufacturer& lhs, const Manufacturer& rhs);
bool operator!=(const Product& lhs, const Product& rhs);
bool operator!=(const Remote& lhs, const Remote& rhs);
bool operator!=(const RemoteCommand& lhs, const RemoteCommand& rhs);
bool operator!=(const FavoriteRemote& lhs, const FavoriteRemote& rhs);

// Définition des objets vides
const Manufacturer EMPTY_MANUFACTURER = {"", nullptr, 0};
const Product EMPTY_PRODUCT = {"", nullptr, 0};
const Remote EMPTY_REMOTE = {"", nullptr, 0};
const RemoteCommand EMPTY_REMOTE_COMMAND = {"", (ProtocolEnum)0, 0, 0, 0};

#endif // REMOTE_COMMANDS_H
