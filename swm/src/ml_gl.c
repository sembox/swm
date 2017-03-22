//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  main.cpp
// desc:  Opengl Wrapper
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include "ml_app.h"
#include "ml_llist.h"
#include "ml_events.h"
#include "ml_event_mgr.h"
#include "ml_utils.h"

#include <stdlib.h>

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLint WIDTH = 800;
const GLint HEIGHT = 600;

GLfloat verteces[256] =
{
	-0.5f, -0.5f, 0.0f, //bottom left
	0.5f, -0.5f, 0.0f,  //bottom right
	0.0f, 0.5f, 0.0f,   //top middle
	-0.5f, -0.5f, 0.0f, //bottom left
};
uint32_t vert_cnt = 0;
 
bool_t start_draw = FALSE;
const GLchar *vertexShaderSource = "#version 330 core\n"
"layout ( location = 0 ) in vec3 position;\n "
"void main()\n"
"{\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}\n";


const GLchar *fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(0.5f, 0.5f, 0.5f, 1.0f);\n"
"}\n";


GLint shader_program;
GLuint VBO, VAO;
GLFWwindow *window = NULL;

uint32_t s_w = 800;
uint32_t s_h = 600;

void window_size_callback(GLFWwindow *win, int w, int h)
{
	//std::cout << "Window size is changed" << std::endl;
	glViewport(0, 0, w, h);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(shader_program);
	glBindVertexArray(VBO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
	glfwSwapBuffers(win);
	s_w = w;
	s_h = h;
}



void ml_fix_size(void)
{
	float xpos = verteces[0];
	float ypos = verteces[1];

	if (verteces[3] > (xpos + 180.0f / s_w))
	{
		verteces[3] = xpos + 180.0f / s_w;
		verteces[4] = ypos;
		verteces[5] = 0.0f;

		verteces[6] = xpos + 180.0f / s_w;
		verteces[7] = ypos - 60.0f / s_h;
		verteces[8] = 0.0f;

		verteces[9] = xpos;
		verteces[10] = ypos - 60.0f / s_h;
		verteces[11] = 0.0f;

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verteces), verteces, GL_DYNAMIC_DRAW);
	}
	else
	{
		ml_stop_timer();
	}
}

// mouse button call back
void mouse_button_fun(GLFWwindow *win, int btn, int action, int mod)
{
	ml_event_t *evt;
	double xpos, ypos;
	glfwGetCursorPos(win, &xpos, &ypos);
	//post mouse button event 
	ML_LOG(ML_LOG_INFO, "Mouse button[%d] was [%d] with mod[%d]", btn, action, mod);
	// create event or get from pool
	evt = ml_em_get_free_evt();
	// fill event filed
	evt->is_valid = TRUE;
	evt->type = ML_EVT_TYPE_MOUSE_BTN;
	evt->data[0] = btn;
	evt->data[1] = action;
	evt->data[2] = mod;
	evt->data[3] = 0;
	ml_em_add_event(evt);
	if (action == 1)
	{
		verteces[0] = (float)(2*xpos / s_w)- 1.0f;
		verteces[1] = 1.0f - (float)(2*ypos / s_h);
		verteces[2] = 0.0f;

		verteces[3] = (float)(2 * xpos / s_w) - 1.0f;
		verteces[4] = 1.0f - (float)(2 * ypos / s_h);
		verteces[5] = 0.0f;

		verteces[6] = (float)(2 * xpos / s_w) - 1.0f;
		verteces[7] = 1.0f - (float)(2 * ypos / s_h);
		verteces[8] = 0.0f;

		verteces[9] = (float)(2 * xpos / s_w) - 1.0f;
		verteces[10] = 1.0f - (float)(2 * ypos / s_h);
		verteces[11] = 0.0f;

		verteces[12] = (float)(2 * xpos / s_w) - 1.0f;
		verteces[13] = 1.0f - (float)(2 * ypos / s_h);
		verteces[14] = 0.0f;

		vert_cnt = 5;
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verteces), verteces, GL_DYNAMIC_DRAW);
		start_draw = TRUE;

	}
	else
	{
		ml_start_timer(100, ml_fix_size);
		start_draw = FALSE;
	}

		
}

void cursor_pos_fun(GLFWwindow* win, double xpos, double ypos)
{
	//post mouse button event 
	//ML_LOG(ML_LOG_INFO, "Mouse moved to x[%f] y [%f]", x, y);
	if (start_draw)
	{
	
		verteces[3] = (float)(2 * xpos / s_w) - 1.0f;
		//verteces[4] = 1.0f - (float)(2 * ypos / s_h);
		verteces[5] = 0.0f;

		verteces[6] = (float)(2 * xpos / s_w) - 1.0f;
		verteces[7] = 1.0f - (float)(2 * ypos / s_h);
		verteces[8] = 0.0f;

		//verteces[9] = (float)(2 * xpos / s_w) - 1.0f;
		verteces[10] = 1.0f - (float)(2 * ypos / s_h);
		verteces[11] = 0.0f;

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verteces), verteces, GL_DYNAMIC_DRAW);
	}
}

//-------------------------------------------------------------------------------
// basic open gl initialization
//-------------------------------------------------------------------------------
bool_t ml_init_opengl(GLFWwindow **window)
{

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);


	*window = glfwCreateWindow(WIDTH, HEIGHT, "SWM", NULL, NULL);
	if (NULL == *window)
	{
		ML_LOG(ML_LOG_ERR, "Failed to create GLFW window");
		return FALSE;
	}

	glfwSetWindowSizeCallback(*window, window_size_callback);

	// set mouse button callback 
	glfwSetMouseButtonCallback(*window, mouse_button_fun);
	// set cursor move call back
	glfwSetCursorPosCallback(*window, cursor_pos_fun);

	int screen_width, screen_height;

	glfwGetFramebufferSize(*window, &screen_width, &screen_height);

	glfwMakeContextCurrent(*window);

	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit())
	{
		ML_LOG(ML_LOG_ERR, "Failed to initialize GLEW..");
		return FALSE;
	}

	glViewport(0, 0, screen_width, screen_height);


	GLuint vertex_sharder = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_sharder, 1, &vertexShaderSource, NULL);
	glCompileShader(vertex_sharder);

	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertex_sharder, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex_sharder, 512, NULL, infoLog);
		ML_LOG(ML_LOG_ERR, "SHADER:VERTEX:COMPILATION_FAILED");
	}

	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
		ML_LOG(ML_LOG_ERR, "SHADER:FRAGMENT:COMPILATION_FAILED");
		return FALSE;
	}


	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_sharder);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

	glGetShaderiv(shader_program, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader_program, 512, NULL, infoLog);
		ML_LOG(ML_LOG_ERR, "SHADER:PROGARAM:LINK");
		return FALSE;
	}

	glDeleteShader(vertex_sharder);
	glDeleteShader(fragment_shader);



	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verteces), verteces, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return TRUE;

}

void ml_create_gl_win()
{
	// init opengl subsystem
	ML_LOG(ML_LOG_INFO, "Initialize opengl subsystem..");
	ml_init_opengl(&window);
}

bool_t ml_gl_shold_close()
{
	return glfwWindowShouldClose(window);
}

void ml_gl_draw()
{
	glfwPollEvents();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBufferData(GL_ARRAY_BUFFER, sizeof(verteces), verteces, GL_DYNAMIC_DRAW);

	//draw stuff
	glUseProgram(shader_program);
	glBindVertexArray(VBO);
	glDrawArrays(GL_LINE_STRIP, 0, vert_cnt);
	//glDrawArrays(GL_LINES, 0, 3);
	glBindVertexArray(0);
	glfwSwapBuffers(window);
}

void ml_gl_terminate()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glfwTerminate();
}