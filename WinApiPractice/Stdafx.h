#pragma once
#include <SDKDDKver.h>

#define WIN32_LEAN_AND_MEAN 

#include <Windows.h>

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <assert.h>
#include <mmsystem.h>
#include <iostream>
#include <random>

#include <bitset>
#include <vector>
#include <map>

#include <algorithm>
#include <functional>

using namespace std;

//==Singleton
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
#define TIMEMANAGER TimeManager::getSingleton()
#define TEMPSOUNDMANAGER TempSoundManager::getSingleton()
#define FONTMANAGER FontManager::getSingleton()
//Singleton==

// 디그리 1도의 라디안 값
#define DEG_TO_RAD		0.017453f
#define PI				3.141592653f
#define PI_2			6.283185308f

#define FLOAT_EPSILON		0.001f
#define FLOAT_TO_INT(f1)	static_cast<int>(f1 + FLOAT_EPSILON)
#define FLOAT_EQUAL(f1, f2) (fabs(f1 - f2) <= FLOAT_EPSILON)

#define GRAVITY			9.8f
#define RADIAN			57.296

#define FPS		20

#define USE_FULLSCREEN			true

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#if USE_FULLSCREEN
#define WINNAME			(LPSTR)(TEXT("Until We Die"))
#define WINSTYLE		WS_POPUPWINDOW | WS_MAXIMIZE
#define WINSTART_X		0
#define WINSTART_Y		0
#define WINSIZE_X		GetSystemMetrics(SM_CXSCREEN)
#define WINSIZE_Y		GetSystemMetrics(SM_CYSCREEN)

#else
#define WINNAME			(LPSTR)(TEXT("Until We Die"))
#define WINSTYLE		WS_CAPTION | WS_SYSMENU
#define WINSTART_X		0
#define WINSTART_Y		0
#define WINSIZE_X		600
#define WINSIZE_Y		800
#endif

#define CENTER_X		WINSIZE_X / 2
#define CENTER_Y		WINSIZE_Y / 2

// =============================================
// # 매크로 함수 # (클래스에서 동적할당된 부분 해제)
// =============================================
#define SAFE_DELETE(p)         {if(p) {delete (p); (p)=nullptr;}}
#define SAFE_DELETE_ARRAY(p)   {if(p) {delete[] (p); (p)=nullptr;}}
#define SAFE_RELEASE(p)         {if(p) {(p)->release(); (p)=nullptr;}}

//==CommonFunction
#include "RandomFunction.h"
#include "TimeManager.h"
#include "TempSoundManager.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "TempSoundManager.h"
#include "ShapeFunction.h"
#include "FontManager.h"
#include "Utils.h"
//CommonFunction==

using namespace MY_UTIL;

extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;

extern int			_winsizeX;
extern int			_winsizeY;

extern int			_winRealSizeX;
extern int			_winRealSizeY;