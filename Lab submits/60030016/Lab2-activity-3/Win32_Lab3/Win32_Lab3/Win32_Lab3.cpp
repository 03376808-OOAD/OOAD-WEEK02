#include <windows.h>

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

int 	WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	HWND hwnd;
	MSG msg;
	/***************** 1. Define Windows class ****************************/
	wc.style = 0; // Class style
	wc.lpfnWndProc = (WNDPROC)WndProc; // Window procedure address
	wc.cbClsExtra = 0; // Class extra bytes
	wc.cbWndExtra = 0; // Window extra bytes
	wc.hInstance = hInstance; // Instance handle
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO); // Icon handle
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Cursor handle
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // Background color
	wc.lpszMenuName = NULL; // Menu name
	wc.lpszClassName = "MyWndClass"; // WNDCLASS name

		/***************** 2. Register the Windows class **********************/

	RegisterClass(&wc);

	/***************** 3. Create window **********************/
	hwnd = CreateWindow(
		"MyWndClass", // WNDCLASS name
		"SDK Application", // Window title
		WS_OVERLAPPEDWINDOW, // Window style
		CW_USEDEFAULT, // Horizontal position
		CW_USEDEFAULT, // Vertical position
		CW_USEDEFAULT, // Initial width
		CW_USEDEFAULT, // Initial height
		HWND_DESKTOP, // Handle of parent window
		NULL, // Menu handle
		hInstance, // Application's instance handle
		NULL // Window-creation data
	);

	/***************** 4. Display the window **********************/
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	/***************** 5. Message loop **********************/
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam,
	LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) {

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, 10, 10, 200, 100);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_LBUTTONDOWN:
		char str[256];
		POINT pt;   // point of mouse clicked, received via message
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		wsprintf(str, "WM_LBUTTONDOWN\nCo-ordinate are\n (%i, %i)", pt.x,
			pt.y);
		MessageBox(hwnd, str, "Left Button Clicked", MB_OK);
		return 0;

	case WM_RBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		wsprintf(str, "WM_RBUTTONDOWN\nCo-ordinate are\n (%i, %i)", pt.x,
			pt.y);
		MessageBox(hwnd, str, "Right Button Clicked", MB_OK);
		return 0;

	case WM_CHAR:
		hdc = GetDC(hwnd);
		TextOut(hdc, 1, 1, "  ", 3);
		wsprintf(str, "%c", (char)wParam);
		TextOut(hdc, 1, 1, str, strlen(str));
		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;


	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
