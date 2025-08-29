#include "pch.h"
#include "MyLibrary.h"

MYLIBRARY_API void HelloWorld()
{
	std::cout << "hola mundo desde la DLL" << std::endl;
}

MYLIBRARY_API int MyMessageBoxError(const wchar_t* message, const wchar_t * boxTitle)
{
	return MessageBoxW(NULL, message, boxTitle, MB_ICONERROR);
}

MYLIBRARY_API int MyMessageBoxWarning(const wchar_t* message, const wchar_t * boxTitle)
{
	return MessageBoxW(NULL, message, boxTitle, MB_ICONEXCLAMATION);
}
