//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_logger.h
// desc:  Logger
//-------------------------------------------------------------------------------
#ifndef _ML_LOGGER_H_
#define _ML_LOGGER_H_

typedef enum _ml_log_t
{
	ML_LOG_INFO,
	ML_LOG_WARN,
	ML_LOG_ERR
} ml_log_sev_t;

// log destinations
#define LM_LOG_NONE		(0)
#define ML_LOG_STDOUT	(1<<0)
#define ML_LOG_FILE		(1<<1)
#define ML_LOG_SERVER	(1<<2)

// defatult log destination
#define ML_LOG_DEFAULT ML_LOG_STDOUT
#define ML_MAX_LOG_MSG_SIZE 128


typedef struct _ml_logger_t
{
	ml_log_sev_t severity;	// log severity
	uint32_t dest;			// log destination
} ml_logger_t;

bool_t ml_logger_init();
ml_log_sev_t ml_logger_cur_severity();
void ml_log_message(ml_log_sev_t severity, char* str, ...);

#if defined(BLD_TYPE_DEBUG) 
// Logger macro for debug build
#define ML_LOG(severity, str, ... ) \
   if( (ml_logger_cur_severity() <= (severity)) ) { ml_log_message((severity), str, ##__VA_ARGS__  );}
#else 
// Logger macro for release build
# define ML_LOG(severity, str, ...) if( (severity) == ML_LOG_ERR ) { ml_log_message((severity), str, ##__VA_ARGS__  );}
#endif

#define ML_LOG_ALW(severity, str, ... ) ml_log_message((severity), str, ##__VA_ARGS__ )

#endif //_ML_LOGGER_H_