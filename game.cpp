
class Game {
	int w, h, px;
public:
	
	int* pixels;
	POINT mousePos;
	// https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	BYTE keysPressed[256];
	
	Game(int w, int h) : w(w), h(h), px(w * h) {
		pixels = (int*)malloc(px * sizeof(int));
		for (int i = 0; i < px; ++i)
			pixels[i] = 0x00FFFFFF;
	}
	
	~Game() {
		free(pixels);
	}
	
	void update(int tick) {
		if (mousePos.x >= 0 &&
			mousePos.y >= 0 && 
			mousePos.x < w && 
			mousePos.y < h &&
			keysPressed[1] >> 7) {
			pixels[mousePos.y * w + mousePos.x] = 0;
		}
		
		// don't uncomment unless you want a seizure
		/*
		int r = (rand() % 255),
			g = (rand() % 255),
			b = (rand() % 255);
		for (int i = 0; i < px; ++i)
			pixels[i] = r << 16 | g << 8 | b;
		*/
	}
};