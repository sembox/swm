//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_logger.h
// desc:  Logger
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include "ml_utils.h"
#include "ml_io.h"
#include "ml_logger.h" 

#include <stdio.h>
#include <stdarg.h>
#include <string.h>


ml_logger_t logger;
static const char SEVERITY_SYMB[] = {'I', 'W', 'E'};
char print_buf[ML_MAX_LOG_MSG_SIZE]; 


//-------------------------------------------------------------------------------
// Send log message for processing
//-------------------------------------------------------------------------------
void ml_log_message(ml_log_sev_t severity, char* str, ...)
{
	
	uint64_t cur_time;
	ml_io_stream_t *io_str = ml_get_cur_io_str();
	va_list     args;
	uint32_t	msg_len;
	char time_str[64];
	// First, print log data into global stdio print buffer
	cur_time = ml_get_system_time();
	ml_fomat_time(cur_time, time_str, 64);
	// Print message header to temporary buffer
	//msg_len = sprintf(print_buf, "<%c %010llu> ", SEVERITY_SYMB[((int)severity - ML_LOG_INFO)], cur_time);
	msg_len = sprintf(print_buf, "<%c %s> ", SEVERITY_SYMB[((int)severity - ML_LOG_INFO)], time_str);
	// Print message string
	va_start(args, str);
	msg_len += vsnprintf(print_buf + msg_len, ((ML_MAX_LOG_MSG_SIZE - 1) - msg_len), str, args);
	va_end(args);

	// vsnprintf can overrun the max size if formatting parameter located on the end of the string (on the limit)
	// make sure the final result fits in the message size
	if (msg_len > (ML_MAX_LOG_MSG_SIZE - 2))
	{
		msg_len = (ML_MAX_LOG_MSG_SIZE - 2);
	}

	// Add line termination
	print_buf[msg_len] = '\n';
	print_buf[msg_len + 1] = 0;

	// Print the message
	ml_put_str(io_str, print_buf);

	return;
}


//-------------------------------------------------------------------------------
// return current logger severity
//-------------------------------------------------------------------------------
ml_log_sev_t ml_logger_cur_severity()
{
	return logger.severity;
}


//-------------------------------------------------------------------------------
// init logger 
//-------------------------------------------------------------------------------
bool_t ml_logger_init()
{
	logger.severity = DEF_LOG_SEVERITY;
	// init io
	ml_io_init();
	return TRUE;
}

