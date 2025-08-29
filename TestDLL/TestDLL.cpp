// TestDLL.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "MyLibrary.h"

int main()
{

	//MyMessageBoxError(L"Este es un error ficticio", L"Fatal error");


	MyMessageBoxWarning(L"Has sido baneado por 30 días", L"Aviso");

    std::cout << "Hello World desde TestDLL::main\n";
	HelloWorld(); // Llama a la función exportada de la DLL

}