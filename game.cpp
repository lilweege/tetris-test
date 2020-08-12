
class Game {
private:
	struct Tetromino {
		int x, y;
		std::pair<int, int> squares[16];
		int color;
		int rotation;
		
		void init(int type, int i, int j) {
			x = i, y = j;
			rotation = 0;
			switch (type) {
				case 0: // I
					squares[0] = { -1,  0 };
					squares[1] = {  0,  0 };
					squares[2] = {  1,  0 };
					squares[3] = {  2,  0 };
					squares[4] = {  1, -1 };
					squares[5] = {  1,  0 };
					squares[6] = {  1,  1 };
					squares[7] = {  1,  2 };
					squares[8] = { -1,  1 };
					squares[9] = {  0,  1 };
					squares[10] = {  1,  1 };
					squares[11] = {  2,  1 };
					squares[12] = {  0, -1 };
					squares[13] = {  0,  0 };
					squares[14] = {  0,  1 };
					squares[15] = {  0,  2 };
					color = 0x0000FFFF;
					break;
				case 1: // O
					squares[0] = {  0,  0 };
					squares[1] = {  1,  0 };
					squares[2] = {  0,  1 };
					squares[3] = {  1,  1 };
					squares[4] = {  0,  0 };
					squares[5] = {  1,  0 };
					squares[6] = {  0,  1 };
					squares[7] = {  1,  1 };
					squares[8] = {  0,  0 };
					squares[9] = {  1,  0 };
					squares[10] = {  0,  1 };
					squares[11] = {  1,  1 };
					squares[12] = {  0,  0 };
					squares[13] = {  1,  0 };
					squares[14] = {  0,  1 };
					squares[15] = {  1,  1 };
					color = 0x00FFFF00;
					break;
				case 2: // T
					squares[0] = {  0,  0 };
					squares[1] = {  1,  0 };
					squares[2] = { -1,  0 };
					squares[3] = {  0, -1 };
					squares[4] = {  0,  0 };
					squares[5] = {  1,  0 };
					squares[6] = {  0,  1 };
					squares[7] = {  0, -1 };
					squares[8] = {  0,  0 };
					squares[9] = {  1,  0 };
					squares[10] = { -1,  0 };
					squares[11] = {  0,  1 };
					squares[12] = {  0,  0 };
					squares[13] = {  0,  1 };
					squares[14] = { -1,  0 };
					squares[15] = {  0, -1 };
					color = 0x00FF00FF;
					break;
				case 3: // J
					squares[0] = {  0,  0 };
					squares[1] = {  1,  0 };
					squares[2] = { -1,  0 };
					squares[3] = { -1, -1 };
					squares[4] = {  0,  0 };
					squares[5] = {  0,  1 };
					squares[6] = {  0, -1 };
					squares[7] = {  1, -1 };
					squares[8] = {  0,  0 };
					squares[9] = {  1,  0 };
					squares[10] = { -1,  0 };
					squares[11] = {  1,  1 };
					squares[12] = {  0,  0 };
					squares[13] = {  0,  1 };
					squares[14] = {  0, -1 };
					squares[15] = { -1,  1 };
					color = 0x000000FF;
					break;
				case 4: // L
					squares[0] = {  0,  0 };
					squares[1] = {  1,  0 };
					squares[2] = { -1,  0 };
					squares[3] = {  1, -1 };
					squares[4] = {  0,  0 };
					squares[5] = {  0,  1 };
					squares[6] = {  0, -1 };
					squares[7] = {  1,  1 };
					squares[8] = {  0,  0 };
					squares[9] = {  1,  0 };
					squares[10] = { -1,  0 };
					squares[11] = { -1,  1 };
					squares[12] = {  0,  0 };
					squares[13] = {  0,  1 };
					squares[14] = {  0, -1 };
					squares[15] = { -1, -1 };
					color = 0x00FF8000;
					break;
				case 5: // S
					squares[0] = {  0,  0 };
					squares[1] = { -1,  0 };
					squares[2] = {  0, -1 };
					squares[3] = {  1, -1 };
					squares[4] = {  0,  0 };
					squares[5] = {  1,  0 };
					squares[6] = {  0, -1 };
					squares[7] = {  1,  1 };
					squares[8] = {  0,  0 };
					squares[9] = { -1,  1 };
					squares[10] = {  0,  1 };
					squares[11] = {  1,  0 };
					squares[12] = {  0,  0 };
					squares[13] = { -1,  0 };
					squares[14] = { -1, -1 };
					squares[15] = {  0,  1 };
					color = 0x0000FF00;
					break;
				case 6: // Z
					squares[0] = {  0,  0 };
					squares[1] = {  0, -1 };
					squares[2] = { -1, -1 };
					squares[3] = {  1,  0 };
					squares[4] = {  0,  0 };
					squares[5] = {  1,  0 };
					squares[6] = {  1, -1 };
					squares[7] = {  0,  1 };
					squares[8] = {  0,  1 };
					squares[9] = {  0,  0 };
					squares[10] = { -1,  0 };
					squares[11] = {  1,  1 };
					squares[12] = { -1,  0 };
					squares[13] = {  0,  0 };
					squares[14] = {  0, -1 };
					squares[15] = { -1,  1 };
					color = 0x00FF0000;
					break;
				default:
					squares[0] = { 0, 0 };
					squares[1] = { 0, 0 };
					squares[2] = { 0, 0 };
					squares[3] = { 0, 0 };
					squares[4] = { 0, 0 };
					squares[5] = { 0, 0 };
					squares[6] = { 0, 0 };
					squares[7] = { 0, 0 };
					squares[8] = { 0, 0 };
					squares[9] = { 0, 0 };
					squares[10] = { 0, 0 };
					squares[11] = { 0, 0 };
					squares[12] = { 0, 0 };
					squares[13] = { 0, 0 };
					squares[14] = { 0, 0 };
					squares[15] = { 0, 0 };
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
				tetromino.x + tetromino.squares[tetromino.rotation * 4 + i].first,
				tetromino.y + tetromino.squares[tetromino.rotation * 4 + i].second,
				tetromino.color);
	}

	void placeTetromino(Tetromino tetromino) {
		for (int i = 0; i < 4; ++i)
			// this goes out of bounds
			grid[tetromino.y + tetromino.squares[tetromino.rotation * 4 + i].second][tetromino.x + tetromino.squares[tetromino.rotation * 4 + i].first] = tetromino.color;
	}
	
	int width, height,
		scl, px;
public:
	Tetromino currentPiece = Tetromino();
	
	int* pixels;
	POINT mousePos;
	// https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	BYTE keysPressed[256];
	bool firstPress[256];
	
	Game(int w, int h) : width(w), height(h), px(w * h), scl(w * 2 >= h ? h / gridH : w / gridW) {
		srand(time(NULL));
		currentPiece.init(0, gridW / 2, 0);
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
		
		drawTetromino(currentPiece);
		
		int isSpacePressed = keysPressed[VK_SPACE] >> 7,
			isLeftPressed = keysPressed[VK_LEFT] >> 7,
			isRightPressed = keysPressed[VK_RIGHT] >> 7,
			isDownPressed = keysPressed[VK_DOWN] >> 7,
			isUpPressed = keysPressed[VK_UP] >> 7,
			isZPressed = keysPressed['Z'] >> 7,
			isXPressed = keysPressed['X'] >> 7;
		
		if (isSpacePressed && firstPress[VK_SPACE]) {
			placeTetromino(currentPiece);
			currentPiece.init(rand() % 7, gridW / 2, 0);
		}
		
		// no arr yet
		if (isLeftPressed && firstPress[VK_LEFT])
			--currentPiece.x;
		if (isRightPressed && firstPress[VK_RIGHT])
			++currentPiece.x;
		if (isDownPressed && firstPress[VK_DOWN])
			++currentPiece.y;
		if (isUpPressed && firstPress[VK_UP])
			--currentPiece.y;
		if (isZPressed && firstPress['Z'])
			currentPiece.rotation = ((currentPiece.rotation - 1) % 4 + 4) % 4;
		if (isXPressed && firstPress['X'])
			currentPiece.rotation = ((currentPiece.rotation + 1) % 4 + 4) % 4;
		
		
		firstPress[VK_SPACE] = !isSpacePressed;
		firstPress[VK_LEFT] = !isLeftPressed;
		firstPress[VK_RIGHT] = !isRightPressed;
		firstPress[VK_DOWN] = !isDownPressed;
		firstPress[VK_UP] = !isUpPressed;
		firstPress['Z'] = !isZPressed;
		firstPress['X'] = !isXPressed;
		
		// printf("%d\n", tick);
	}
};