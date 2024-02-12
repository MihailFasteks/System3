#include "Windows.h"
#include "windowsx.h"
#include "tchar.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void KeyDownHandler(HWND hwnd, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	WCHAR className[] = L"FirstWindow";

	WNDCLASSEX wndClass;
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hIconSm = NULL;
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = className;

	wndClass.lpfnWndProc = WindowProc;

	if (!RegisterClassEx(&wndClass)) {
		return 0;
	}

	HWND hWnd = CreateWindowEx(
		0,
		className,
		L"My first window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, //x,y
		CW_USEDEFAULT, CW_USEDEFAULT, //width, height
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hWnd, nShowCmd);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static int rButton=0;
	static int lButton=0;
	static int cButton=0;
	WCHAR str[50];
	
	switch (uMsg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0); //WM_QUIT
		break;
	}
	//task3
	case WM_KEYDOWN:
		KeyDownHandler(hwnd, wParam, lParam);
		break;
	//task2
	/*case WM_CREATE:
	{

		ShellExecute(NULL, L"open", L"calc.exe", NULL, NULL, SW_SHOWNORMAL);
		
		
		
		break;
	}
	case WM_LBUTTONDOWN:
	{
		HWND calcWin = FindWindow(L"CalcFrame", NULL);

		if (calcWin != NULL) {

			SetWindowText(calcWin, L"My text of head");
		}

		break;
	}*/
		
		
		
		
		//task1
	/*case WM_LBUTTONDOWN:
		lButton++;
		wsprintf(str, L"rightButton: %d, leftButton: %d, centerButton: %d", rButton, lButton, cButton);
			SetWindowText(hwnd, str);
		
		break;
	case WM_RBUTTONDOWN:

		rButton++;
		wsprintf(str, L"rightButton: %d, leftButton: %d, centerButton: %d", rButton, lButton, cButton);
		SetWindowText(hwnd, str);
		break;
	case WM_MBUTTONDOWN:

		cButton++;
		wsprintf(str, L"rightButton: %d, leftButton: %d, centerButton: %d", rButton, lButton, cButton);
		SetWindowText(hwnd, str);
		break;*/

	

	

	

	

	/*case WM_MBUTTONUP:
	{
		RECT rect;
		GetClientRect(hwnd, &rect);

		WCHAR str[50];
		wsprintf(str, L"left: %d, top: %d, right: %d, bottom: %d", rect.left, rect.top, rect.right, rect.bottom);

		MessageBox(hwnd, str, L"Get client rect", MB_OK);

		break;
	}*/

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}
//task3
void KeyDownHandler(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	int vkey = wParam;
	bool isOk;
	if (vkey == VK_RETURN)
	{
		MoveWindow(hwnd, 0, 0, 300, 300, true);
		isOk = true;
	}
	RECT rect;
	GetWindowRect(hwnd, &rect);

	if (vkey == VK_LEFT) {
		MoveWindow(hwnd, rect.left-10, rect.top, 300, 300, true);
	}
	if (vkey == VK_RIGHT) {
		MoveWindow(hwnd, rect.left + 10, rect.top, 300, 300, true);
	}
	if (vkey == VK_UP) {
		MoveWindow(hwnd, rect.left, rect.top-10, 300, 300, true);
	}
	if (vkey == VK_DOWN) {
		MoveWindow(hwnd, rect.left, rect.top + 10, 300, 300, true);
	}
	

	


}
