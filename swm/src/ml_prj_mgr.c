//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_prj_mgr.c
// desc:  SWM Project manager
//		  Project manager is responsible for managment SWM project:
//		  - create new project
//        - save projects
//		  - open existing projects (several projects can be opened at the same time
//		  - delete projects
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include "ml_prj_mgr.h"


//-------------------------------------------------------------------------------
// Initialize project manager
//-------------------------------------------------------------------------------
bool_t ml_prj_init()
{
	return TRUE;
}


//-------------------------------------------------------------------------------
// List available projects
//-------------------------------------------------------------------------------
bool_t ml_proj_list(char* project_list, uint32_t *size)
{

}


//-------------------------------------------------------------------------------
// Open existing project
//-------------------------------------------------------------------------------
bool_t ml_prj_open()
{
	return TRUE;
}


//-------------------------------------------------------------------------------
// Close project (save unsaved changes and realease resources
//-------------------------------------------------------------------------------
bool_t ml_prj_close(uint32_t prj_id)
{
	return TRUE;
}


//-------------------------------------------------------------------------------
// Delete existing project
//-------------------------------------------------------------------------------
bool_t ml_prj_close(uint32_t prj_id)
{
	return TRUE;
}

//-------------------------------------------------------------------------------
// Close project (save unsaved changes and realease resources
//-------------------------------------------------------------------------------
bool_t ml_project_close(uint32_t prj_id)
{
	return TRUE;
}