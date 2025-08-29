#pragma once

//excluye elementos raramente usados de windows
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>

//indica al compilador que la funcion se exporta en la DLL
#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif

extern "C"
{
	MYLIBRARY_API void HelloWorld();
	//Mostrar caja de mensaje de la aPI de windows
	MYLIBRARY_API int MyMessageBoxError(const wchar_t* message, const wchar_t* boxTitle);
	MYLIBRARY_API int MyMessageBoxWarning(const wchar_t* message, const wchar_t* boxTitle);

}
