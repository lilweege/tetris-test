
class Game {
private:
	struct Tetromino {
		int x, y;
		std::pair<int, int> squares[4];
		int color;
		
		Tetromino(int type) {
			x = 0, y = 0;
			switch (type) {
				case 0: // I
					squares[0] = { -1,  0 };
					squares[1] = {  0,  0 };
					squares[2] = {  1,  0 };
					squares[3] = {  2,  0 };
					color = 0x0000FFFF;
					break;
				case 1: // O
					squares[0] = {  0,  0 };
					squares[1] = {  1,  0 };
					squares[2] = {  0,  1 };
					squares[3] = {  1,  1 };
					color = 0x00FFFF00;
					break;
				case 2: // T
					squares[0] = {  0,  0 };
					squares[1] = {  1,  0 };
					squares[2] = { -1,  0 };
					squares[3] = {  0, -1 };
					color = 0x00FF00FF;
					break;
				case 3: // J
					squares[0] = {  0,  0 };
					squares[1] = {  1,  0 };
					squares[2] = { -1,  0 };
					squares[3] = { -1, -1 };
					color = 0x000000FF;
					break;
				case 4: // L
					squares[0] = {  0,  0 };
					squares[1] = {  1,  0 };
					squares[2] = { -1,  0 };
					squares[3] = {  1, -1 };
					color = 0x00FF8000;
					break;
				case 5: // S
					squares[0] = {  0,  0 };
					squares[1] = { -1,  0 };
					squares[2] = {  0, -1 };
					squares[3] = {  1, -1 };
					color = 0x0000FF00;
					break;
				case 6: // Z
					squares[0] = {  0,  0 };
					squares[1] = {  0, -1 };
					squares[2] = { -1, -1 };
					squares[3] = {  1,  0 };
					color = 0x00FF0000;
					break;
				default:
					squares[0] = { 0, 0 };
					squares[1] = { 0, 0 };
					squares[2] = { 0, 0 };
					squares[3] = { 0, 0 };
					color = 0x00FFFFFF;
					break;
			}
		}
	};
	
	
	const static int
		gridW = 10,
		gridH = 20;
	
	int grid[gridH][gridW] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};
	
	void drawSquare(int x, int y, int c) {
		if (x >= 0 &&
			y >= 0 &&
			x < gridW &&
			y < gridH) {
			x *= scl;
			y *= scl;
			for (int i = 0; i < scl; ++i)
				for (int j = 0; j < scl; ++j)
					// this might go out of bounds
					pixels[(x + i) + (y + j) * width] = c;
		}
	}
	
	void drawTetromino(Tetromino tetromino) {
		for (int i = 0; i < 4; ++i)
			drawSquare(
				tetromino.x + tetromino.squares[i].first,
				tetromino.y + tetromino.squares[i].second,
				tetromino.color);
	}

	void placeTetromino(Tetromino tetromino) {
		for (int i = 0; i < 4; ++i)
			// this goes out of bounds
			grid[tetromino.y + tetromino.squares[i].second][tetromino.x + tetromino.squares[i].first] = tetromino.color;
	}
	
	int width, height,
		scl, px;
	
public:
	Tetromino theDawgs = Tetromino(0);
	
	int* pixels;
	POINT mousePos;
	// https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	BYTE keysPressed[256];
	
	Game(int w, int h) : width(w), height(h), px(w * h), scl(w * 2 >= h ? h / gridH : w / gridW) {
		pixels = (int*)malloc(px * sizeof(int));
		for (int i = 0; i < px; ++i)
			pixels[i] = 0x00FFFFFF;
	}
	
	~Game() {
		free(pixels);
	}
	
	void update(int tick) {
		for (int i = 0; i < gridW; ++i)
			for (int j = 0; j < gridH; ++j)
				drawSquare(i, j, grid[j][i]);
		// drawSquare(mousePos.x / scl, mousePos.y / scl, 0x00FFFFFF);
		
		theDawgs = Tetromino((tick / 1000) % 7);
		theDawgs.x = mousePos.x / scl;
		theDawgs.y = mousePos.y / scl;
		drawTetromino(theDawgs);
		if (keysPressed[1] >> 7)
			placeTetromino(theDawgs);
		// printf("%d\n", tick);
		/*
		if (mousePos.x >= 0 &&
			mousePos.y >= 0 && 
			mousePos.x < w && 
			mousePos.y < h &&
			keysPressed[1] >> 7) {
			pixels[mousePos.y * w + mousePos.x] = 0;
		}
		*/
		
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