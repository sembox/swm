#include "ml_globals.h"
#include "ml_io.h"
#include <stdio.h>

ml_io_stream_t cur_stream = {0};

uint32_t ml_put_str(ml_io_stream_t *stream, char *string)
{
	uint32_t length = 0;
	while (*string != '\0')
	{
		ml_put_ch(stream, *string++);
		length++;
	}
	return length;
}


ml_io_stream_t *ml_get_cur_io_str()
{
	return &cur_stream;
}

void ml_put_ch(ml_io_stream_t *stream, uint32_t ch)
{
	if (stream != NULL)
	{
		stream->out_func(ch);
	}
}


uint32_t ml_get_ch(ml_io_stream_t *stream)
{
	if (stream != NULL)
	{ 
		return stream->in_func();
	}
	else
	{
		return 0;
	}
}

// initialize IO and set current output stream to console window
bool_t ml_io_init()
{
	cur_stream.id = 0;
	cur_stream.in_func = getchar;
	cur_stream.out_func = putchar;
	return TRUE;
}
