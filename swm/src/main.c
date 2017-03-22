//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  main.cpp
// desc:  ML app entry point (windows platrform)
//-------------------------------------------------------------------------------
#include <stdlib.h>


extern int ml_app_start(void);

//-------------------------------------------------------------------------------
// application entry point
//-------------------------------------------------------------------------------
int main(int argc, char **argv)
{
	int result;
	result = ml_app_start();
    return result;
}
