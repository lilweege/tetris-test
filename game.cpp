
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
	
	void drawTetromino(const Tetromino& tetromino) {
		for (int i = 0; i < 4; ++i)
			drawSquare(
				tetromino.x + tetromino.squares[tetromino.rotation * 4 + i].first,
				tetromino.y + tetromino.squares[tetromino.rotation * 4 + i].second,
				tetromino.color);
	}

	void placeTetromino(const Tetromino& tetromino) {
		for (int i = 0; i < 4; ++i)
			grid
				[tetromino.y + tetromino.squares[tetromino.rotation * 4 + i].second]
				[tetromino.x + tetromino.squares[tetromino.rotation * 4 + i].first]
				= tetromino.color;
	}
	
	bool moveTetromino(Tetromino& tetromino, int xOff, int yOff) {
		bool valid = true;
		for (int i = 0; i < 4; ++i) {
			int x = xOff + tetromino.x + tetromino.squares[tetromino.rotation * 4 + i].first,
				y = yOff + tetromino.y + tetromino.squares[tetromino.rotation * 4 + i].second;
				
			if (x < 0 || x >= gridW ||
				y < 0 || y >= gridH ||
				grid[y][x]) {
				valid = false;
				break;
			}
		}
		if (valid) {
			tetromino.x += xOff;
			tetromino.y += yOff;
		}
		return valid;
	}
	
	bool rotateTetromino(Tetromino& tetromino, int rOff) {
		int r = ((tetromino.rotation + rOff) % 4 + 4) % 4;
		bool valid = true;
		for (int i = 0; i < 4; ++i) {
			int x = tetromino.x + tetromino.squares[r * 4 + i].first,
				y = tetromino.y + tetromino.squares[r * 4 + i].second;
				
			if (x < 0 || x >= gridW ||
				y < 0 || y >= gridH ||
				grid[y][x]) {
				valid = false;
				break;
			}
		}
		if (valid)
			tetromino.rotation = r;
		return valid;
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
		currentPiece.init(0, gridW / 2, 1);
		pixels = (int*)malloc(px * sizeof(int));
		reset();
	}
	
	~Game() {
		free(pixels);
	}
	
	void reset() {
		for (int i = 0; i < gridW; ++i)
			for (int j = 0; j < gridH; ++j)
				grid[j][i] = 0;
		currentPiece.init(rand() % 7, gridW / 2, 1);
	}
	
	void update(int tick) {
		// printf("%d\n", tick);
		if (keysPressed['R'] >> 7 && firstPress['R'])
			reset();
		
		if (keysPressed[VK_SPACE] >> 7 && firstPress[VK_SPACE]) {
			while (moveTetromino(currentPiece, 0, 1));
			placeTetromino(currentPiece);
			currentPiece.init(rand() % 7, gridW / 2, 1);
		}
		// no arr yet
		if (keysPressed[VK_LEFT] >> 7 && firstPress[VK_LEFT])
			moveTetromino(currentPiece, -1, 0);
		if (keysPressed[VK_RIGHT] >> 7 && firstPress[VK_RIGHT])
			moveTetromino(currentPiece, 1, 0);
		if (keysPressed[VK_DOWN] >> 7 && firstPress[VK_DOWN])
			moveTetromino(currentPiece, 0, 1);
		if (keysPressed[VK_UP] >> 7 && firstPress[VK_UP])
			moveTetromino(currentPiece, 0, -1);
		if (keysPressed['Z'] >> 7 && firstPress['Z'])
			rotateTetromino(currentPiece, -1);
		if (keysPressed['X'] >> 7 && firstPress['X'])
			rotateTetromino(currentPiece, 1);
		
		
		for (int i = 0; i < 256; ++i)
			firstPress[i] = !(keysPressed[i] >> 7);
		
		for (int i = 0; i < gridW; ++i)
			for (int j = 0; j < gridH; ++j)
				drawSquare(i, j, grid[j][i]);
		
		drawTetromino(currentPiece);
	}
};