/*
  Constants.h - Library API for sending data to the ThingsBoard
  Based on PubSub MQTT library.
  Created by Olender M. Oct 2018.
  Released into the public domain.
*/
#ifndef Constants_h
#define Constants_h

// Library includes.
#include <Arduino.h>

// Local includes.
#include "Configuration.h"

#define Default_Payload 1024
#define Default_Fields_Amt 16
class ThingsBoardDefaultLogger;

#if !THINGSBOARD_ENABLE_PROGMEM
// Ensure snprintf_P and vsnprintf_P are defined,
// when not using PROGMEM and if Arduino itself has not already defined it
#ifndef snprintf_P
#define snprintf_P    snprintf
#endif // snprintf_P
#ifndef vsnprintf_P
#define vsnprintf_P   vsnprintf
#endif // vsnprintf_P
#endif // THINGSBOARD_ENABLE_PROGMEM

/// ---------------------------------
/// Constant strings in flash memory,
/// used by both ThingsBoard and ThingsBoardHttp.
/// ---------------------------------
// Log messages.
#if THINGSBOARD_ENABLE_PROGMEM
constexpr char UNABLE_TO_SERIALIZE[] PROGMEM = "Unable to serialize key-value json";
#if !THINGSBOARD_ENABLE_DYNAMIC
constexpr char TOO_MANY_JSON_FIELDS[] PROGMEM = "Too many JSON fields passed (%u), increase MaxFieldsAmt (%u) accordingly";
#endif // !THINGSBOARD_ENABLE_DYNAMIC
constexpr char CONNECT_FAILED[] PROGMEM = "Connecting to server failed";
constexpr char UNABLE_TO_SERIALIZE_JSON[] PROGMEM = "Unable to serialize json data";
#else
constexpr char UNABLE_TO_SERIALIZE[] = "Unable to serialize key-value json";
#if !THINGSBOARD_ENABLE_DYNAMIC
constexpr char TOO_MANY_JSON_FIELDS[] = "Too many JSON fields passed (%u), increase MaxFieldsAmt (%u) accordingly";
#endif // !THINGSBOARD_ENABLE_DYNAMIC
constexpr char CONNECT_FAILED[] = "Connecting to server failed";
constexpr char UNABLE_TO_SERIALIZE_JSON[] = "Unable to serialize json data";
#endif // THINGSBOARD_ENABLE_PROGMEM

#endif // Constants_h
