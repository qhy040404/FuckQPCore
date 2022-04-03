#include <iostream>
#include <Windows.h>

void ManagerRun(LPCSTR exe, LPCSTR param, int nShow = SW_SHOW)
{
	SHELLEXECUTEINFO sei;
	sei.cbSize = sizeof(sei);
	sei.fMask = SEE_MASK_NOCLOSEPROCESS;
	sei.hInstApp = NULL;
	sei.hwnd = NULL;
	sei.lpDirectory = NULL;
	sei.lpFile = exe;
	sei.lpParameters = param;
	sei.lpVerb = "runas";
	sei.nShow = nShow;
	bool ret = ShellExecuteEx(&sei);
	CloseHandle(sei.hProcess);
	return;
}

int main()
{
	ManagerRun("taskkill.exe", "/im qqprotect.exe /f");
	std::cout << "QQProtect.exe terminated." << std::endl;
	return 0;
}