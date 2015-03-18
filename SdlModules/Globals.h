#ifndef Globals_H
#define Globals_H

#include <windows.h>
#include <stdio.h>
//#include <stdarg.h>
#include "../MyLibrary/Log.h"
//#define LOG(format, ...)  //log(__FILE__, __LINE__, format, __VA_ARGS__);

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

// Configuration -----------
#define LOG(format, ...) Log::print(__FILE__, __LINE__, format, __VA_ARGS__)
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define FULLSCREEN 0

#define FULLSCREEN_DESKTOP SDL_WINDOW_FULLSCREEN_DESKTOP 

#endif