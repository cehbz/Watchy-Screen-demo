#pragma once

#define TZ "AEST-10AEDT,M10.1.0,M4.1.0/3"
#define NTP_SERVER "pool.ntp.org"

// debugging "#define DEBUGPORT Serial" for debugging output
#define DEBUGPORT Serial
#ifdef DEBUGPORT
#define DEBUG(...)      DEBUGPORT.printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif