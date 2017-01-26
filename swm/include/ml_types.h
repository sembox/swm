//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_types.h
// desc:  basic types definitions
//-------------------------------------------------------------------------------
#ifndef _ML_TYPES_
#define _ML_TYPES_

//---------------------------------------------------------
// Global SWM Application types definitions
//---------------------------------------------------------
typedef unsigned long long  uint64_t;
typedef long long           int64_t;
typedef unsigned int        uint32_t;
typedef int                 int32_t;
typedef unsigned short      uint16_t;
typedef short               int16_t;
typedef unsigned char       uint8_t;
typedef signed char         int8_t;
typedef unsigned char       bool_t;

#ifndef TRUE
#define TRUE                1
#endif
#ifndef FALSE
#define FALSE               0
#endif

#endif //_ML_TYPES_