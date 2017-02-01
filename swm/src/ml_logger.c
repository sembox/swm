//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_logger.h
// desc:  Logger
//-------------------------------------------------------------------------------

// Send log message for processing
void ml_log_message(ml_log_sev_t severity, char* str, ...)
{
	static   const char        SEVERITY_NAME[] = { 'I', 'W', 'E',};
	extern   volatile uint32   uSecTimerHi;
	extern   SIO_ID_t          glbStdErrIf;

	struct s_ts{
		uint32 l;
		uint32 h;
	};

	va_list     args;
	struct s_ts ts;
	int         msgLen;
	uint32      usTimerVal;

	// First, print log data into global stdio print buffer
	do
	{
		ts.h = uSecTimerHi;
		ts.l = TIMER_GetTimerVal(MICROSECOND_HW_TIMER);
	} while (ts.l < TIMER_GetTimerVal(MICROSECOND_HW_TIMER));
	ts.l = 0xFFFFFFFF - ts.l;


	// Print message header to temporary buffer
	msgLen = snprintf(LogPrintfBuffer, (LOGGER_MESSAGE_SIZE - 3), "<%s%02d%c %010llu> ",
		LOGGER_PKG_NAME[(int)pkg], entity, SEVERITY_NAME[((int)severity - LVL_INFO)], *(uint64*)&ts);

	// Print message string
	va_start(args, str);
	msgLen += vsnprintf(LogPrintfBuffer + msgLen, ((LOGGER_MESSAGE_SIZE - 1) - msgLen), str, args);
	va_end(args);

	// vsnprintf can overrun the max size if formatting parameter located on the end of the string (on the limit)
	// make sure the final result fits in the message size
	if (msgLen > (LOGGER_MESSAGE_SIZE - 3))
	{
		msgLen = (LOGGER_MESSAGE_SIZE - 3);
	}

	// Add line termination
	LogPrintfBuffer[msgLen] = '\n';
	LogPrintfBuffer[(msgLen + 1)] = '\r';
	LogPrintfBuffer[(msgLen + 2)] = 0;

	// Print the message
	SIO_DataTx(glbStdErrIf, LogPrintfBuffer);

	LogPrintCounter++;

	// Send message to NAND if there is a free entry in the logger queue
	if ((LogQueueWrIdx - LogQueueRdIdx) < LOGGER_QUEUE_SIZE)
	{
		uint32 entryIdx = (LogQueueWrIdx & LOGGER_QUEUE_SIZE_MASK);

		// For the case we don't have free entry we always use global buffer for formatting
		strncpy(LogQueue[entryIdx], LogPrintfBuffer, LOGGER_MESSAGE_SIZE);

		LogQueueWrIdx++;
	}

	HWMUTEX_Release(HWMUTEX_UART);
	RTOS_ENABLE_INT();
	return;
}
