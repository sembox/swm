//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_io.h
// desc:  Shaders-realted managment functionality (load/compile/linkg etc)
//-------------------------------------------------------------------------------
#ifndef _ML_IO_STR_H_
#define _ML_IO_STR_H_

typedef int(*str_in_fun_t)();
typedef int(*str_out_fun_t)(int c);

typedef struct _io_stream_t
{
	uint32_t id;
	str_in_fun_t in_func;
	str_out_fun_t out_func;
} ml_io_stream_t;


ml_io_stream_t *ml_get_cur_io_str(void);
bool_t ml_io_init(void);
uint32_t ml_put_str(ml_io_stream_t *stream, char *string);
uint32_t ml_get_ch(ml_io_stream_t *stream);
void ml_put_ch(ml_io_stream_t *stream, uint32_t ch);
ml_io_stream_t *ml_get_cur_io_str();

#endif //_ML_IO_STR_H_