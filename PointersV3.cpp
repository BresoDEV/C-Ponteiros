
#include <iostream>
#include <windows.h>
#include <iostream>
#include <vector>
#include <conio.h> 
#include <TlHelp32.h>
#include <stdio.h> 
#include <tchar.h> 

using namespace std;

#include <iostream>
#include <windows.h>
#include <iostream>
#include <vector>
#include <conio.h> 
#include <TlHelp32.h>
#include <stdio.h> 
#include <tchar.h> 

using namespace std;


namespace Configuracoes_Jogo
{
	LPCWSTR Jogo = TEXT("NFS Underground 2");			//Nome da janela do jogo
	LPCWSTR Jogo_exe = TEXT("speed2.exe");		//Nome do executavel do jogo .exe
}


namespace FuncoesUteis
{
	bool Check_JogoAberto()
	{
		HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
		DWORD pId;
		GetWindowThreadProcessId(hWnd, &pId);
		HANDLE process = OpenProcess(SYNCHRONIZE, FALSE, pId);
		DWORD ret = WaitForSingleObject(process, 0);
		CloseHandle(process);
		return ret == WAIT_TIMEOUT;
	}

	uintptr_t GetModuleBaseAddress(DWORD procId, const TCHAR* modName)
	{
		uintptr_t modBaseAddr = 0;
		HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
		if (hSnap != INVALID_HANDLE_VALUE)
		{
			MODULEENTRY32 modEntry;
			modEntry.dwSize = sizeof(modEntry);
			if (Module32First(hSnap, &modEntry))
			{
				do
				{
					if (!lstrcmpi(modEntry.szModule, modName))
					{
						modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
						break;
					}
				} while (Module32Next(hSnap, &modEntry));
			}
		}
		CloseHandle(hSnap);
		return modBaseAddr;
	}

	bool SobrescreverMemoria(DWORD Offset, int valor)
	{
		DWORD pId;
		//HWND hWnd = FindWindow(0, TEXT("Minecraft 1.8.9"));
		HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
		GetWindowThreadProcessId(hWnd, &pId);
		HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
		return WriteProcessMemory(hProc, (void*)Offset, &valor, sizeof(valor), nullptr); //write
	}

}

namespace Ponteiros
{
	DWORD Jump_Ponteiro(DWORD EnderecoAdicional, DWORD ponteiro1 = NULL,
		DWORD ponteiro2 = NULL, DWORD ponteiro3 = NULL, DWORD ponteiro4 = NULL,
		DWORD ponteiro5 = NULL, DWORD ponteiro6 = NULL, DWORD ponteiro7 = NULL,
		DWORD ponteiro8 = NULL, DWORD ponteiro9 = NULL, DWORD ponteiro10 = NULL)
	{
		DWORD pId;
		HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
		GetWindowThreadProcessId(hWnd, &pId);
		HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
		DWORD Modulo_Base_Jogo = FuncoesUteis::GetModuleBaseAddress(pId, Configuracoes_Jogo::Jogo_exe);
		DWORD base = Modulo_Base_Jogo + EnderecoAdicional;
		DWORD address = 0;
		DWORD EnderecoFinal = base;
		if (ponteiro1 != NULL)
		{
			ReadProcessMemory(hProc, (void*)EnderecoFinal, &address, sizeof(address), nullptr);
			address += ponteiro1;
			EnderecoFinal = address;
		}
		if (ponteiro2 != NULL)
		{
			address = 0;
			ReadProcessMemory(hProc, (void*)EnderecoFinal, &address, sizeof(address), nullptr);
			address += ponteiro2;
			EnderecoFinal = address;
		}
		if (ponteiro3 != NULL)
		{
			address = 0;
			ReadProcessMemory(hProc, (void*)EnderecoFinal, &address, sizeof(address), nullptr);
			address += ponteiro3;
			EnderecoFinal = address;
		}
		if (ponteiro4 != NULL)
		{
			address = 0;
			ReadProcessMemory(hProc, (void*)EnderecoFinal, &address, sizeof(address), nullptr);
			address += ponteiro4;
			EnderecoFinal = address;
		}
		if (ponteiro5 != NULL)
		{
			address = 0;
			ReadProcessMemory(hProc, (void*)EnderecoFinal, &address, sizeof(address), nullptr);
			address += ponteiro5;
			EnderecoFinal = address;
		}
		if (ponteiro6 != NULL)
		{
			address = 0;
			ReadProcessMemory(hProc, (void*)EnderecoFinal, &address, sizeof(address), nullptr);
			address += ponteiro6;
			EnderecoFinal = address;
		}
		if (ponteiro7 != NULL)
		{
			address = 0;
			ReadProcessMemory(hProc, (void*)EnderecoFinal, &address, sizeof(address), nullptr);
			address += ponteiro7;
			EnderecoFinal = address;
		}
		if (ponteiro8 != NULL)
		{
			address = 0;
			ReadProcessMemory(hProc, (void*)EnderecoFinal, &address, sizeof(address), nullptr);
			address += ponteiro8;
			EnderecoFinal = address;
		}
		if (ponteiro9 != NULL)
		{
			address = 0;
			ReadProcessMemory(hProc, (void*)EnderecoFinal, &address, sizeof(address), nullptr);
			address += ponteiro9;
			EnderecoFinal = address;
		}
		if (ponteiro10 != NULL)
		{
			address = 0;
			ReadProcessMemory(hProc, (void*)EnderecoFinal, &address, sizeof(address), nullptr);
			address += ponteiro10;
			EnderecoFinal = address;
		}
		return EnderecoFinal;
	}
}



//Pronto
namespace String
{

	namespace Com_Modulo
	{

		bool Escrever(DWORD Offset, string valor)
		{
			DWORD pId;
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			DWORD Modulo_Base_Jogo = FuncoesUteis::GetModuleBaseAddress(pId, Configuracoes_Jogo::Jogo_exe);
			Modulo_Base_Jogo += Offset;
			return WriteProcessMemory(hProc, (void*)Modulo_Base_Jogo, valor.c_str(), sizeof(valor), nullptr); //write
		}

		string Ler(DWORD offset)
		{
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			DWORD pId;
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			DWORD Modulo_Base_Jogo = FuncoesUteis::GetModuleBaseAddress(pId, Configuracoes_Jogo::Jogo_exe);
			Modulo_Base_Jogo += offset;
			string retorno;
			ReadProcessMemory(hProc, (void*)Modulo_Base_Jogo, &retorno, sizeof(retorno), nullptr);
			return retorno.c_str();

		}
	}

	namespace Fixos
	{
		bool Escrever(DWORD Offset, string valor)
		{
			DWORD pId;
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			return WriteProcessMemory(hProc, (void*)Offset, valor.c_str(), sizeof(valor), nullptr); //write
		}

		string Ler(DWORD offset)
		{
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			DWORD pId;
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			//DWORD Modulo_Base_Jogo = FuncoesUteis::GetModuleBaseAddress(pId, Jogo_exe);
			//Modulo_Base_Jogo += offset;
			string retorno;
			ReadProcessMemory(hProc, (void*)offset, &retorno, sizeof(retorno), nullptr);
			return retorno.c_str();

			  

		}
	}
	 
}

//Pronto
namespace Float
{
	namespace Com_Modulo
	{
		float Ler(DWORD Offset)
		{
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			DWORD pId;
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			DWORD Modulo_Base_Jogo = FuncoesUteis::GetModuleBaseAddress(pId, Configuracoes_Jogo::Jogo_exe);
			Modulo_Base_Jogo += Offset;
			float retorno;
			ReadProcessMemory(hProc, (void*)Modulo_Base_Jogo, &retorno, sizeof(retorno), nullptr);
			return retorno;
		}

		bool Escrever(DWORD Offset, float valor)
		{
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			DWORD pId;
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			DWORD Modulo_Base_Jogo = FuncoesUteis::GetModuleBaseAddress(pId, Configuracoes_Jogo::Jogo_exe);
			DWORD base = Modulo_Base_Jogo + Offset;
			float aa = valor;
			return WriteProcessMemory(hProc, (void*)base, &aa, sizeof(aa), nullptr);
		}
	}

	namespace Fixos
	{
		bool Escrever(DWORD Offset, float valor)
		{
			DWORD pId;
			//HWND hWnd = FindWindow(0, TEXT("Minecraft 1.8.9"));
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			return WriteProcessMemory(hProc, (void*)Offset, &valor, sizeof(valor), nullptr); //write
		}

		float Ler(DWORD Offset)
		{
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			DWORD pId;
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			//DWORD Modulo_Base_Jogo = FuncoesUteis::GetModuleBaseAddress(pId, Jogo_exe);
			//Modulo_Base_Jogo += Offset;
			float retorno;
			ReadProcessMemory(hProc, (void*)Offset, &retorno, sizeof(retorno), nullptr);
			return retorno;
		}
	}
	
}

//Pronto
namespace Int
{
	namespace Com_Modulo
	{
		bool Escrever(DWORD Offset, int valor)
		{
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			DWORD pId;
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			DWORD Modulo_Base_Jogo = FuncoesUteis::GetModuleBaseAddress(pId, Configuracoes_Jogo::Jogo_exe);
			DWORD base = Modulo_Base_Jogo + Offset;
			return WriteProcessMemory(hProc, (void*)base, &valor, sizeof(valor), nullptr);
		}

		int Ler(DWORD offset)
		{
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			DWORD pId;
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			DWORD Modulo_Base_Jogo = FuncoesUteis::GetModuleBaseAddress(pId, Configuracoes_Jogo::Jogo_exe);
			Modulo_Base_Jogo += offset;
			DWORD retorno;
			ReadProcessMemory(hProc, (void*)Modulo_Base_Jogo, &retorno, sizeof(retorno), nullptr);
			return retorno;

		}
	}

	namespace Fixos
	{
		bool Escrever(DWORD Offset, int valor)
		{
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			DWORD pId;
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			//DWORD Modulo_Base_Jogo = FuncoesUteis::GetModuleBaseAddress(pId, Jogo_exe);
			//DWORD base = Modulo_Base_Jogo + Offset;
			return WriteProcessMemory(hProc, (void*)Offset, &valor, sizeof(valor), nullptr);
		}

		int Ler_sem_Modulo(DWORD offset)
		{
			HWND hWnd = FindWindow(0, Configuracoes_Jogo::Jogo);
			DWORD pId;
			GetWindowThreadProcessId(hWnd, &pId);
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
			//DWORD Modulo_Base_Jogo = FuncoesUteis::GetModuleBaseAddress(pId, Jogo_exe);
			//Modulo_Base_Jogo += offset;
			DWORD retorno;
			ReadProcessMemory(hProc, (void*)offset, &retorno, sizeof(retorno), nullptr);
			return retorno;
		}
	}
 
}

 
 

int main()
{
	cout << String::Fixos::Ler(0x09CBE0F5);
}

 
