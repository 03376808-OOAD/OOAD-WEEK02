#include <windows.h>

 LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

 int 	WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	     	LPSTR lpszCmdLine, int nCmdShow)
	 {
	 	WNDCLASS wc;
	  	HWND hwnd;
	 	MSG msg;
	
		wc.style = 0; 
	 	wc.lpfnWndProc = (WNDPROC)WndProc; 
	 	wc.cbClsExtra = 0; 
	 	wc.cbWndExtra = 0; 
	 	wc.hInstance = hInstance; 
	 	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO); 
	 	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 
	 	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 
	 	wc.lpszMenuName = NULL; 
	 	wc.lpszClassName = "MyWndClass"; 
	
		 	RegisterClass(&wc);
	
		 	
		 	hwnd = CreateWindow(
			 		"MyWndClass", 
			 		"SDK Application", 
			 		WS_OVERLAPPEDWINDOW, 
			 		CW_USEDEFAULT, 
			 		CW_USEDEFAULT, 
			 		CW_USEDEFAULT, 
			 		CW_USEDEFAULT, 
			 		HWND_DESKTOP, 
			 		NULL, 
			 		hInstance, 
			 		NULL 
			);
	
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
			
		 	case WM_DESTROY:
			 		PostQuitMessage(0);
			 		return 0;
			
	}
	 	return DefWindowProc(hwnd, message, wParam, lParam);
	 }
