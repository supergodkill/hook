#include "pch.h"
#include "Helpers.h"

// ¿ªÊ¼HOOK
void Helpers::HookFunction(PVOID* oFunction, PVOID Function)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(oFunction, Function);
	DetourTransactionCommit();
}

// ½áÊøHOOK
void Helpers::UnHookFunction(PVOID* oFunction, PVOID Function)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(oFunction, Function);
	DetourTransactionCommit();
}
