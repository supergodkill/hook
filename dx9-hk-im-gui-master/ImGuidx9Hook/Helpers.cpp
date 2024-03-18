#include "pch.h"
#include "Helpers.h"

// ��ʼHOOK
void Helpers::HookFunction(PVOID* oFunction, PVOID Function)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(oFunction, Function);
	DetourTransactionCommit();
}

// ����HOOK
void Helpers::UnHookFunction(PVOID* oFunction, PVOID Function)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(oFunction, Function);
	DetourTransactionCommit();
}
