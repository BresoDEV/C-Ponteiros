
#include <iostream>
#include <windows.h>
#include <iostream>
#include <vector>
#include <conio.h> 
#include <TlHelp32.h>
#include <stdio.h> 
#include <tchar.h> 

using namespace std;


#pragma region GAME CONFIG
LPCWSTR Jogo = TEXT("blablabla");		//Nome da janela do jogo
LPCWSTR Jogo_exe = TEXT("blabla.exe");		//Nome do executavel do jogo .exe
#pragma endregion


#pragma region PONTEIROS DE MEMORIA
/// <summary>
/// Funcao usada para pegar o endereço de um jogo, para poder usar jogo.exe + ponteiro, como no Cheat Engine
/// </summary>
/// <param name="ID do processo"></param>
/// <param name="Nome"></param>
/// <returns></returns>

bool Check_JogoAberto()
{
	HWND hWnd = FindWindow(0, Jogo);
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

/// <summary>
/// Funcao usada para percorer 1 ponteiro a partir de um offset e retornar o valor final
/// </summary>
/// <param name="EnderecoAdicional"></param>
/// <param name="ponteiro1"></param>
/// <returns></returns>
DWORD Jump_Ponteiro1(DWORD EnderecoAdicional, DWORD ponteiro1)
{
	DWORD pId;
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + EnderecoAdicional;
	DWORD address = 0;
	ReadProcessMemory(hProc, (void*)base, &address, sizeof(address), nullptr);
	address += ponteiro1;
	return base;
}

/// <summary>
///  Funcao usada para percorer 2 ponteiros a partir de um offset e retornar o valor final
/// </summary>
/// <param name="EnderecoAdicional"></param>
/// <param name="ponteiro1"></param>
/// <param name="ponteiro2"></param>
/// <returns></returns>
DWORD Jump_Ponteiro2(DWORD EnderecoAdicional, DWORD ponteiro1, DWORD ponteiro2)
{
	DWORD pId;
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + EnderecoAdicional;
	DWORD address = 0;
	ReadProcessMemory(hProc, (void*)base, &address, sizeof(address), nullptr);
	address += ponteiro1;
	DWORD address2 = 0;
	ReadProcessMemory(hProc, (void*)address, &address2, sizeof(address2), nullptr);
	address2 += ponteiro2;
	return address2;
}
/// <summary>
/// Funcao usada para percorer 3 ponteiros a partir de um offset e retornar o valor final
/// </summary>
/// <param name="EnderecoAdicional"></param>
/// <param name="ponteiro1"></param>
/// <param name="ponteiro2"></param>
/// <param name="ponteiro3"></param>
/// <returns></returns>
DWORD Jump_Ponteiro3(DWORD EnderecoAdicional, DWORD ponteiro1, DWORD ponteiro2, DWORD ponteiro3)
{
	DWORD pId;
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + EnderecoAdicional;
	DWORD address = 0;
	ReadProcessMemory(hProc, (void*)base, &address, sizeof(address), nullptr);
	address += ponteiro1;
	DWORD address2 = 0;
	ReadProcessMemory(hProc, (void*)address, &address2, sizeof(address2), nullptr);
	address2 += ponteiro2;
	DWORD address22 = 0;
	ReadProcessMemory(hProc, (void*)address2, &address22, sizeof(address22), nullptr);
	address22 += ponteiro3;
	return address22;
}
/// <summary>
/// Funcao usada para percorer 4 ponteiros a partir de um offset e retornar o valor final
/// </summary>
/// <param name="EnderecoAdicional"></param>
/// <param name="ponteiro1"></param>
/// <param name="ponteiro2"></param>
/// <param name="ponteiro3"></param>
/// <param name="ponteiro4"></param>
/// <returns></returns>
DWORD Jump_Ponteiro4(DWORD EnderecoAdicional, DWORD ponteiro1, DWORD ponteiro2, DWORD ponteiro3, DWORD ponteiro4)
{
	DWORD pId;
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + EnderecoAdicional;
	DWORD address = 0;
	ReadProcessMemory(hProc, (void*)base, &address, sizeof(address), nullptr);
	address += ponteiro1;
	DWORD address2 = 0;
	ReadProcessMemory(hProc, (void*)address, &address2, sizeof(address2), nullptr);
	address2 += ponteiro2;
	DWORD address22 = 0;
	ReadProcessMemory(hProc, (void*)address2, &address22, sizeof(address22), nullptr);
	address22 += ponteiro3;
	DWORD address222 = 0;
	ReadProcessMemory(hProc, (void*)address22, &address222, sizeof(address222), nullptr);
	address222 += ponteiro4;
	return address222;
}
/// <summary>
/// Funcao usada para percorer 5 ponteiros a partir de um offset e retornar o valor final
/// </summary>
/// <param name="EnderecoAdicional"></param>
/// <param name="ponteiro1"></param>
/// <param name="ponteiro2"></param>
/// <param name="ponteiro3"></param>
/// <param name="ponteiro4"></param>
/// <param name="ponteiro5"></param>
/// <returns></returns>
DWORD Jump_Ponteiro5(DWORD EnderecoAdicional, DWORD ponteiro1, DWORD ponteiro2, DWORD ponteiro3, DWORD ponteiro4, DWORD ponteiro5)
{
	DWORD pId;
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + EnderecoAdicional;
	DWORD address = 0;
	ReadProcessMemory(hProc, (void*)base, &address, sizeof(address), nullptr);
	address += ponteiro1;
	DWORD address2 = 0;
	ReadProcessMemory(hProc, (void*)address, &address2, sizeof(address2), nullptr);
	address2 += ponteiro2;
	DWORD address22 = 0;
	ReadProcessMemory(hProc, (void*)address2, &address22, sizeof(address22), nullptr);
	address22 += ponteiro3;
	DWORD address222 = 0;
	ReadProcessMemory(hProc, (void*)address22, &address222, sizeof(address222), nullptr);
	address222 += ponteiro4;
	DWORD address2222 = 0;
	ReadProcessMemory(hProc, (void*)address222, &address2222, sizeof(address2222), nullptr);
	address2222 += ponteiro5;
	return address2222;
}
/// <summary>
/// Funcao usada para percorer 6 ponteiros a partir de um offset e retornar o valor final
/// </summary>
/// <param name="EnderecoAdicional"></param>
/// <param name="ponteiro1"></param>
/// <param name="ponteiro2"></param>
/// <param name="ponteiro3"></param>
/// <param name="ponteiro4"></param>
/// <param name="ponteiro5"></param>
/// <param name="ponteiro6"></param>
/// <returns></returns>
DWORD Jump_Ponteiro6(DWORD EnderecoAdicional, DWORD ponteiro1, DWORD ponteiro2, DWORD ponteiro3, DWORD ponteiro4, DWORD ponteiro5, DWORD ponteiro6)
{
	DWORD pId;
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + EnderecoAdicional;
	DWORD address = 0;
	ReadProcessMemory(hProc, (void*)base, &address, sizeof(address), nullptr);
	address += ponteiro1;
	DWORD address2 = 0;
	ReadProcessMemory(hProc, (void*)address, &address2, sizeof(address2), nullptr);
	address2 += ponteiro2;
	DWORD address22 = 0;
	ReadProcessMemory(hProc, (void*)address2, &address22, sizeof(address22), nullptr);
	address22 += ponteiro3;
	DWORD address222 = 0;
	ReadProcessMemory(hProc, (void*)address22, &address222, sizeof(address222), nullptr);
	address222 += ponteiro4;
	DWORD address2222 = 0;
	ReadProcessMemory(hProc, (void*)address222, &address2222, sizeof(address2222), nullptr);
	address2222 += ponteiro5;
	DWORD address22222 = 0;
	ReadProcessMemory(hProc, (void*)address2222, &address22222, sizeof(address22222), nullptr);
	address22222 >= ponteiro6;
	return address22222;
}
/// <summary>
/// Funcao usada para percorer 7 ponteiros a partir de um offset e retornar o valor final
/// </summary>
/// <param name="EnderecoAdicional"></param>
/// <param name="ponteiro1"></param>
/// <param name="ponteiro2"></param>
/// <param name="ponteiro3"></param>
/// <param name="ponteiro4"></param>
/// <param name="ponteiro5"></param>
/// <param name="ponteiro6"></param>
/// <param name="ponteiro7"></param>
/// <returns></returns>
DWORD Jump_Ponteiro7(DWORD EnderecoAdicional, DWORD ponteiro1, DWORD ponteiro2, DWORD ponteiro3, DWORD ponteiro4, DWORD ponteiro5, DWORD ponteiro6, DWORD ponteiro7)
{
	DWORD pId;
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + EnderecoAdicional;
	DWORD address = 0;
	ReadProcessMemory(hProc, (void*)base, &address, sizeof(address), nullptr);
	address += ponteiro1;
	DWORD address2 = 0;
	ReadProcessMemory(hProc, (void*)address, &address2, sizeof(address2), nullptr);
	address2 += ponteiro2;
	DWORD address22 = 0;
	ReadProcessMemory(hProc, (void*)address2, &address22, sizeof(address22), nullptr);
	address22 += ponteiro3;
	DWORD address222 = 0;
	ReadProcessMemory(hProc, (void*)address22, &address222, sizeof(address222), nullptr);
	address222 += ponteiro4;
	DWORD address2222 = 0;
	ReadProcessMemory(hProc, (void*)address222, &address2222, sizeof(address2222), nullptr);
	address2222 += ponteiro5;
	DWORD address22222 = 0;
	ReadProcessMemory(hProc, (void*)address2222, &address22222, sizeof(address22222), nullptr);
	address22222 >= ponteiro6;
	DWORD address222222 = 0;
	ReadProcessMemory(hProc, (void*)address22222, &address222222, sizeof(address222222), nullptr);
	address222222 += ponteiro7;
	return address222222;
}
/// <summary>
/// Funcao usada para percorer 8 ponteiros a partir de um offset e retornar o valor final
/// </summary>
/// <param name="EnderecoAdicional"></param>
/// <param name="ponteiro1"></param>
/// <param name="ponteiro2"></param>
/// <param name="ponteiro3"></param>
/// <param name="ponteiro4"></param>
/// <param name="ponteiro5"></param>
/// <param name="ponteiro6"></param>
/// <param name="ponteiro7"></param>
/// <param name="ponteiro8"></param>
/// <returns></returns>
DWORD Jump_Ponteiro8(DWORD EnderecoAdicional, DWORD ponteiro1, DWORD ponteiro2, DWORD ponteiro3, DWORD ponteiro4, DWORD ponteiro5, DWORD ponteiro6, DWORD ponteiro7, DWORD ponteiro8)
{
	DWORD pId;
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + EnderecoAdicional;
	DWORD address = 0;
	ReadProcessMemory(hProc, (void*)base, &address, sizeof(address), nullptr);
	address += ponteiro1;
	DWORD address2 = 0;
	ReadProcessMemory(hProc, (void*)address, &address2, sizeof(address2), nullptr);
	address2 += ponteiro2;
	DWORD address22 = 0;
	ReadProcessMemory(hProc, (void*)address2, &address22, sizeof(address22), nullptr);
	address22 += ponteiro3;
	DWORD address222 = 0;
	ReadProcessMemory(hProc, (void*)address22, &address222, sizeof(address222), nullptr);
	address222 += ponteiro4;
	DWORD address2222 = 0;
	ReadProcessMemory(hProc, (void*)address222, &address2222, sizeof(address2222), nullptr);
	address2222 += ponteiro5;
	DWORD address22222 = 0;
	ReadProcessMemory(hProc, (void*)address2222, &address22222, sizeof(address22222), nullptr);
	address22222 >= ponteiro6;
	DWORD address222222 = 0;
	ReadProcessMemory(hProc, (void*)address22222, &address222222, sizeof(address222222), nullptr);
	address222222 += ponteiro7;
	DWORD address2222222 = 0;
	ReadProcessMemory(hProc, (void*)address222222, &address2222222, sizeof(address2222222), nullptr);
	address2222222 += ponteiro8;
	return address2222222;
}
/// <summary>
/// Funcao usada para percorer 9 ponteiros a partir de um offset e retornar o valor final
/// </summary>
/// <param name="EnderecoAdicional"></param>
/// <param name="ponteiro1"></param>
/// <param name="ponteiro2"></param>
/// <param name="ponteiro3"></param>
/// <param name="ponteiro4"></param>
/// <param name="ponteiro5"></param>
/// <param name="ponteiro6"></param>
/// <param name="ponteiro7"></param>
/// <param name="ponteiro8"></param>
/// <param name="ponteiro9"></param>
/// <returns></returns>
DWORD Jump_Ponteiro9(DWORD EnderecoAdicional, DWORD ponteiro1, DWORD ponteiro2, DWORD ponteiro3, DWORD ponteiro4, DWORD ponteiro5, DWORD ponteiro6, DWORD ponteiro7, DWORD ponteiro8, DWORD ponteiro9)
{
	DWORD pId;
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + EnderecoAdicional;
	DWORD address = 0;
	ReadProcessMemory(hProc, (void*)base, &address, sizeof(address), nullptr);
	address += ponteiro1;
	DWORD address2 = 0;
	ReadProcessMemory(hProc, (void*)address, &address2, sizeof(address2), nullptr);
	address2 += ponteiro2;
	DWORD address22 = 0;
	ReadProcessMemory(hProc, (void*)address2, &address22, sizeof(address22), nullptr);
	address22 += ponteiro3;
	DWORD address222 = 0;
	ReadProcessMemory(hProc, (void*)address22, &address222, sizeof(address222), nullptr);
	address222 += ponteiro4;
	DWORD address2222 = 0;
	ReadProcessMemory(hProc, (void*)address222, &address2222, sizeof(address2222), nullptr);
	address2222 += ponteiro5;
	DWORD address22222 = 0;
	ReadProcessMemory(hProc, (void*)address2222, &address22222, sizeof(address22222), nullptr);
	address22222 >= ponteiro5;
	DWORD address222222 = 0;
	ReadProcessMemory(hProc, (void*)address22222, &address222222, sizeof(address222222), nullptr);
	address222222 += ponteiro7;
	DWORD address2222222 = 0;
	ReadProcessMemory(hProc, (void*)address222222, &address2222222, sizeof(address2222222), nullptr);
	address2222222 += ponteiro8;
	DWORD address22222222 = 0;
	ReadProcessMemory(hProc, (void*)address2222222, &address22222222, sizeof(address22222222), nullptr);
	address22222222 += ponteiro9;
	return address22222222;
}
/// <summary>
/// Funcao usada para percorer 10 ponteiros a partir de um offset e retornar o valor final
/// </summary>
/// <param name="EnderecoAdicional"></param>
/// <param name="ponteiro1"></param>
/// <param name="ponteiro2"></param>
/// <param name="ponteiro3"></param>
/// <param name="ponteiro4"></param>
/// <param name="ponteiro5"></param>
/// <param name="ponteiro6"></param>
/// <param name="ponteiro7"></param>
/// <param name="ponteiro8"></param>
/// <param name="ponteiro9"></param>
/// <param name="ponteiro10"></param>
/// <returns></returns>
DWORD Jump_Ponteiro10(DWORD EnderecoAdicional, DWORD ponteiro1, DWORD ponteiro2, DWORD ponteiro3, DWORD ponteiro4, DWORD ponteiro5, DWORD ponteiro6, DWORD ponteiro7, DWORD ponteiro8, DWORD ponteiro9, DWORD ponteiro10)
{
	DWORD pId;
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + EnderecoAdicional;
	DWORD address = 0;
	ReadProcessMemory(hProc, (void*)base, &address, sizeof(address), nullptr);
	address += ponteiro1;
	DWORD address2 = 0;
	ReadProcessMemory(hProc, (void*)address, &address2, sizeof(address2), nullptr);
	address2 += ponteiro2;
	DWORD address22 = 0;
	ReadProcessMemory(hProc, (void*)address2, &address22, sizeof(address22), nullptr);
	address22 += ponteiro3;
	DWORD address222 = 0;
	ReadProcessMemory(hProc, (void*)address22, &address222, sizeof(address222), nullptr);
	address222 += ponteiro4;
	DWORD address2222 = 0;
	ReadProcessMemory(hProc, (void*)address222, &address2222, sizeof(address2222), nullptr);
	address2222 += ponteiro5;
	DWORD address22222 = 0;
	ReadProcessMemory(hProc, (void*)address2222, &address22222, sizeof(address22222), nullptr);
	address22222 += ponteiro6;
	DWORD address222222 = 0;
	ReadProcessMemory(hProc, (void*)address22222, &address222222, sizeof(address222222), nullptr);
	address222222 += ponteiro7;
	DWORD address2222222 = 0;
	ReadProcessMemory(hProc, (void*)address222222, &address2222222, sizeof(address2222222), nullptr);
	address2222222 += ponteiro8;
	DWORD address22222222 = 0;
	ReadProcessMemory(hProc, (void*)address2222222, &address22222222, sizeof(address22222222), nullptr);
	address22222222 += ponteiro9;
	DWORD address222222222 = 0;
	ReadProcessMemory(hProc, (void*)address22222222, &address222222222, sizeof(address222222222), nullptr);
	address222222222 += ponteiro10;
	return address222222222;
}

/// <summary>
/// Funcao usada para sobrescrever endereços de memoria, a partir de um offset 
/// </summary>
/// <param name="Offset"></param>
/// <param name="valor"></param>
/// <returns></returns>
bool SobrescreverMemoria(DWORD Offset, int valor)
{
	DWORD pId;
	//HWND hWnd = FindWindow(0, TEXT("Minecraft 1.8.9"));
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	return WriteProcessMemory(hProc, (void*)Offset, &valor, sizeof(valor), nullptr); //write
}


bool SobrescreverMemoriaFloat(DWORD Offset, float valor)
{
	DWORD pId;
	//HWND hWnd = FindWindow(0, TEXT("Minecraft 1.8.9"));
	HWND hWnd = FindWindow(0, Jogo);
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	return WriteProcessMemory(hProc, (void*)Offset, &valor, sizeof(valor), nullptr); //write
}

bool EscreverMemoria_enderecoFixo(DWORD Offset, int valor)
{
	HWND hWnd = FindWindow(0, Jogo);
	DWORD pId;
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + Offset; 
	return WriteProcessMemory(hProc, (void*)base, &valor, sizeof(valor), nullptr);
}

bool EscreverMemoria_enderecoFixoFloat(DWORD Offset, float valor)
{
	HWND hWnd = FindWindow(0, Jogo);
	DWORD pId;
	GetWindowThreadProcessId(hWnd, &pId);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
	DWORD ac_client = GetModuleBaseAddress(pId, Jogo_exe);
	DWORD base = ac_client + Offset;
	float aa = valor;
	return WriteProcessMemory(hProc, (void*)base, &aa, sizeof(aa), nullptr);
}

#pragma endregion
