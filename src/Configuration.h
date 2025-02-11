/*
  Configuration.h - Library API for sending data to the ThingsBoard
  Based on PubSub MQTT library.
  Created by Olender M. Oct 2018.
  Released into the public domain.
*/
#ifndef Configuration_h
#define Configuration_h

// Enable the usage of the STL library, depending on if needed STL base functionality is supported
#  ifdef __has_include
#    if __has_include(<string>) && __has_include(<functional>) && __has_include(<vector>) && __has_include(<iterator>) && __has_include(<cassert>)
#      ifndef THINGSBOARD_ENABLE_STL
#        define THINGSBOARD_ENABLE_STL 1
#      endif
#    else
#      ifndef THINGSBOARD_ENABLE_STL
#        define THINGSBOARD_ENABLE_STL 0
#      endif
#    endif
#  else
#    ifdef ARDUINO
#      ifndef THINGSBOARD_ENABLE_STL
#        define THINGSBOARD_ENABLE_STL 0
#      endif
#    else
#      ifndef THINGSBOARD_ENABLE_STL
#        define THINGSBOARD_ENABLE_STL 1
#      endif
#    endif
#  endif

// Enable the usage of the PROGMEM header for constants variables (variables are placed into flash memory instead of sram).
#  ifdef __has_include
#    if  __has_include(<pgmspace>)
#      ifndef THINGSBOARD_ENABLE_PROGMEM
#        define THINGSBOARD_ENABLE_PROGMEM 1
#      endif
#    endif
#  endif

#  ifndef THINGSBOARD_ENABLE_PROGMEM
#    define THINGSBOARD_ENABLE_PROGMEM 0
#  endif

// Enables the ThingsBoard class to be fully dynamic instead of requiring template arguments to statically allocate memory.
// If enabled the programm might be slightly slower and all the memory will be placed onto the heap instead of the stack.
// See https://arduinojson.org/v6/api/dynamicjsondocument/ for the main difference in the underlying code.
# ifndef THINGSBOARD_ENABLE_DYNAMIC
#   define THINGSBOARD_ENABLE_DYNAMIC 0
# endif

#endif // Configuration_h
