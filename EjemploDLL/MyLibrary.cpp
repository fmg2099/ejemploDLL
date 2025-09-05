#include "pch.h"
#include "MyLibrary.h"
#include "curl/curl.h"

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

MYLIBRARY_API int HTTPGet(const char* url, WriteCallback callback)
{
	//inicializa curl
	CURL* curl;
	CURLcode res; 
	
	curl = curl_easy_init();

	if (curl)
	{
		std::string response;
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunction);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, callback);

		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
		{
			std::cerr << "Error al hacer la peticion: " << curl_easy_strerror(res) << std::endl;
			return -1;
		}
		else
		{
			////llama a la funcion callback del usuario
			//if (callback)
			//{
			//	callback(response.c_str());
			//}
			std::cout << "peticion completada" << std::endl;
		}
		curl_easy_cleanup(curl);

	}
}

//definicion de la funcion callback para curl
size_t writefunction(void* ptr, size_t size, size_t nmemb, void* userdata)
{
	//total de bytes que se descargaron
	size_t totalSize = size * nmemb;

	////llama a la funcion callback del usuario
	WriteCallback userCallback = reinterpret_cast<WriteCallback>(userdata);
	if (userCallback)
	{
		userCallback(  "hola desde la DLL :D");
	}
	else
	{
		std::cout << "no se pudo hacer el cast" << std::endl;
	}
	std::cout << "recibidos " << totalSize << " bytes" << std::endl;
	return totalSize;
}