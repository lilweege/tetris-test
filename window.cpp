// https://docs.microsoft.com/en-us/windows/win32/apiindex/api-index-portal
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <chrono>
#include <thread>
#include "game.cpp"

#define WIDTH 800
#define HEIGHT 600
const char* windowName = "Window";

HBITMAP hbm = NULL;

int doGameLoop(HWND hwnd, const int FRAMERATE = 120, const int MAX_FRAMESKIP = 10) {
	MSG msg;
	const int TICK_SKIP = 1000 / FRAMERATE;
	std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
	DWORD startTick = GetTickCount(),
		currentTick = 0,
		nextTick = 0;
	
	int prevSecond = 0,
		thisSecond = 0,
		frame = 0,
		loops;
		
		
	Game game = Game(WIDTH, HEIGHT);
	while (msg.message != WM_QUIT) {
		// EVENT INTERRUPT
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			// LIMIT FRAMERATE
			a = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> work_time = a - b;
			
			if (work_time.count() < TICK_SKIP) {
				std::chrono::duration<double, std::milli> delta_ms(TICK_SKIP - work_time.count());
				auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
				std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
			}
			
			b = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> sleep_time = b - a;


			loops = 0;
			while ((currentTick = GetTickCount() - startTick) > nextTick && loops < MAX_FRAMESKIP) {
				// UPDATE
				GetCursorPos(&game.mousePos);
				ScreenToClient(hwnd, &game.mousePos);
				GetKeyboardState(game.keysPressed);
				game.update(currentTick);
				hbm = CreateBitmap(WIDTH, HEIGHT, 1, 8 * 4, (void*) game.pixels);
				
				nextTick += TICK_SKIP;
				++loops;
			}
			
			// RENDER
			if (hbm) {
				HDC hdc = GetDC(hwnd);
				HDC tmp = CreateCompatibleDC(hdc);
				SelectObject(tmp, hbm);
				BitBlt(hdc, 0, 0, WIDTH, HEIGHT, tmp, 0, 0, SRCCOPY);
				DeleteDC(tmp);
				ReleaseDC(hwnd, hdc);
			}
			
			// FPS
			++frame;
			thisSecond = currentTick / 1000;
			if (prevSecond != thisSecond) {
				prevSecond =  thisSecond;
				printf("FPS: %d\n", frame);
				frame = 0;
			}
		}
	}
	return msg.wParam;
}


// https://wiki.winehq.org/List_Of_Windows_Messages
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	// printf("MSG: %d\n", msg);
	switch(msg) {
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			DeleteObject(hbm);
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	const char* lpClassName = "windowClass";
	
	WNDCLASSEX wc;
	wc.cbSize        = sizeof(WNDCLASSEX);
	wc.style         = 0;
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = lpClassName;
	wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&wc);
	
	
	HWND hwnd;
	hwnd = CreateWindowEx(
		0,
		lpClassName,
		windowName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		WIDTH, HEIGHT,
		NULL, NULL, hInstance, NULL);
	if (!hwnd)
		return -1;
	
	
	// ShowWindow(GetConsoleWindow(), SW_HIDE); // for final build
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	return doGameLoop(hwnd);
}
