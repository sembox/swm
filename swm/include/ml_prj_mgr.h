//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_prj_mgr.h
// desc:  SWM Project manager
//		  Project manager is responsible for managment SWM project:
//		  - create new project
//        - save projects
//		  - open existing projects (several projects can be opened at the same time
//		  - delete projects
//-------------------------------------------------------------------------------
#include "ml_globals.h"


#define MAX_PROJECT_TITLE_LEN 64
#define MAX_PROJECT_DESC_LEN 256

// supported project storage types
typedef enum _ml_prj_storage_type_t
{
	ML_PRJ_STOARGE_FAKE,	// fake storage for debug purpose only
	ML_PRJ_STORAGE_LOCAL,	// local file system
	ML_PRJ_STORAGE_CLOUD,	// cloud
	ML_PRJ_STOARGE_GIT,		// git repo
	ML_PRJ_STORAGE_SVC		// priate service
} ml_prj_storage_type_t;


//project definition structure
typedef struct _ml_project_t
{
	uint32_t id;								//unique project id
	char*	 title[MAX_PROJECT_TITLE_LEN];		//project title
	char*	 desc[MAX_PROJECT_DESC_LEN];		//project description 
	
} ml_project_t;

typedef struct _ml_prj_list_t
{
	ml_project_t *proj;
} ml_prj_list_t;


typedef struct _ml_prj_mgr_data_t
{
	ml_prj_list_t open_proj_list;
	ml_prj_list_t recen_proj_list;
} ml_prj_mgr_data_t;





bool_t ml_prj_init();
bool_t ml_proj_list(char* project_list, uint32_t *size);
bool_t ml_prj_open();
bool_t ml_prj_close(uint32_t prj_id);
bool_t ml_prj_close(uint32_t prj_id);
bool_t ml_project_close(uint32_t prj_id);
