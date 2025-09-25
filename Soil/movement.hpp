#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "elements.hpp"


char idle[15] = "img\\idle.bmp";
char walkRight[3][20] = { "img\\R1.bmp", "img\\R2.bmp", "img\\R3.bmp" };
char walkLeft[3][20] = { "img\\L1.bmp", "img\\L2.bmp", "img\\L3.bmp" };
char walkUp[3][20] = { "img\\U1.bmp", "img\\U2.bmp", "img\\U3.bmp" };
char walkDown[3][20] = { "img\\D1.bmp", "img\\D2.bmp", "img\\D3.bmp" };


int charIndex = 0;
bool idlePosition = true;
int idleCounter = 0;

int x = 0;
int y = 0;

// Tile dimensions
const int TILE_WIDTH = 48;
const int TILE_HEIGHT = 48;
const int TILE_ROWS = 15;
const int TILE_COLS = 26;

// Home map tilemap
int tileMapHome[TILE_ROWS][TILE_COLS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
};

// Market map tilemap
int tileMapMarket[TILE_ROWS][TILE_COLS] = {
	{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
	{ 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 },
	{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};


bool isBlocked(double px, double py) {
	int corners[4][2] = {
		{ (int)(px) / TILE_WIDTH, (int)(py) / TILE_HEIGHT },
		{ (int)(px + 47) / TILE_WIDTH, (int)(py) / TILE_HEIGHT },
		{ (int)(px) / TILE_WIDTH, (int)(py + 47) / TILE_HEIGHT },
		{ (int)(px + 47) / TILE_WIDTH, (int)(py + 47) / TILE_HEIGHT },
	};

	int(*activeMap)[TILE_COLS];  // pointer to active map
	if (currentmap == 1) activeMap = tileMapHome;
	else activeMap = tileMapMarket;

	for (int i = 0; i < 4; i++) {
		int col = corners[i][0];
		int row = TILE_ROWS - 1 - corners[i][1];
		if (row < 0 || row >= TILE_ROWS || col < 0 || col >= TILE_COLS || activeMap[row][col] == 1)
			return true;
	}
	return false;
}



void movementDraw() {
	if (!idlePosition) {
		if (x == 1)
			iShowBMP2(charX, charY, walkRight[charIndex], 0);
		else if (x == -1)
			iShowBMP2(charX, charY, walkLeft[charIndex], 0);
		else if (y == 1)
			iShowBMP2(charX, charY, walkUp[charIndex], 0);
		else if (y == -1)
			iShowBMP2(charX, charY, walkDown[charIndex], 0);

		idleCounter++;
		if (idleCounter >= 1000) {
			idleCounter = 0;
			charIndex = 0;
			idlePosition = true;
			x = 0;
			y = 0;
		}
	}
	else {
		iShowBMP2(charX, charY, idle, 0);
	}

	shipmove(charX, charY);
	cropgrow(charX, charY);


	if (currentmap == 1){

		if (charX >= 680 && charX <= 684 &&
			charY >= 48 && charY <= 96)
		{
			charX = 2000;
			charY = 2000;// start moving
		}
	}

	else if (currentmap == 2){

		if (charX >= 610 && charX <= 650 &&
			charY >= 100 && charY <= 120)
		{
			charX = 2000;
			charY = 2000;// start moving
		}
	}

	// Start arcade if near machine and press E
	if (currentmap == 2 && isKeyPressed('e')) {
		double dx = charX - 1165;
		double dy = charY - 440;

		if (sqrt(dx * dx + dy * dy) <= 100 && !arcadeOverlay) {
			arcadeOverlay = true;
			arcadeHit = 0;
			arcadeMiss = 0;
			arcadeState = 0;
			arcadeSetColor();
		}
	}

	// Draw worker if active
	if (workerActive && currentmap == 1) {
		iShowBMP2(workerX, workerY, worker[workerIndex], 150);
	}


	// Animate worker every X ms
	workerAnimCounter += 30; // assuming iSetTimer(30, fixedUpdate/movementKey)
	if (workerAnimCounter >= workerAnimSpeed) {
		workerAnimCounter = 0;
		workerIndex++;
		if (workerIndex >= 2) workerIndex = 0;
	}



}

void movementKey() {
	double speed = 1.2;

	if ((isKeyPressed('w') || isSpecialKeyPressed(GLUT_KEY_UP)) && charY + 48 + speed <= 720) {
		if (!isBlocked(charX, charY + speed)) {
			charY += speed;
			charIndex = (charIndex + 1) % 3;
			idlePosition = false;
			x = 0;
			y = 1;
		}
	}
	if ((isKeyPressed('a') || isSpecialKeyPressed(GLUT_KEY_LEFT)) && charX - speed >= 0) {
		if (!isBlocked(charX - speed, charY)) {
			charX -= speed;
			charIndex = (charIndex + 1) % 3;
			idlePosition = false;
			x = -1;
			y = 0;
		}
	}
	if ((isKeyPressed('s') || isSpecialKeyPressed(GLUT_KEY_DOWN)) && charY - speed >= 0) {
		if (!isBlocked(charX, charY - speed)) {
			charY -= speed;
			charIndex = (charIndex + 1) % 3;
			idlePosition = false;
			x = 0;
			y = -1;
		}
	}
	if ((isKeyPressed('d') || isSpecialKeyPressed(GLUT_KEY_RIGHT)) && charX + 48 + speed <= 1280) {
		if (!isBlocked(charX + speed, charY)) {
			charX += speed;
			charIndex = (charIndex + 1) % 3;
			idlePosition = false;
			x = 1;
			y = 0;
		}
	}
}

#endif
