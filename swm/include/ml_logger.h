//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_logger.h
// desc:  Logger
//-------------------------------------------------------------------------------
typedef enum _ml_log_t
{
	ML_LOG_ERROR,
	ML_LOG_WARN,
	ML_LOG_INFO
} ml_log_t;

#define ML_LOG(LOG_LEVEL, LOG_MSG, ...) 