#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hwnd;
	MSG mensaje;
	WNDCLASSEX wincl;


	wincl.hInstance = hInstance;

	wincl.lpszClassName = "EJEMPLO";

	wincl.lpfnWndProc = WindowProcedure;

	wincl.style = CS_DBLCLKS;

	wincl.cbSize = sizeof(WNDCLASSEX);


	wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;
	wincl.cbClsExtra = 0;
	wincl.cbWndExtra = 0;
	wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND;


	if (!RegisterClassEx(&wincl)) return 0;

	hwnd = CreateWindowEx(
		0,
		"EJEMPLO",
		"1884119",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		640,
		480,
		HWND_DESKTOP,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, SW_SHOWDEFAULT);

	while (TRUE == GetMessage(&mensaje, 0, 0, 0)) {
		TranslateMessage(&mensaje);
		DispatchMessage(&mensaje);
	}
	return mensaje.wParam;
}



LRESULT CALLBACK WindowProcedure(HWND hwnd,
	UINT mensaje,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (mensaje) {
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, mensaje, wParam, lParam);
	}
	return 0;
}