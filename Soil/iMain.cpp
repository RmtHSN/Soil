#include "iGraphics.h"
#include <time.h>
#include <stdlib.h>
#include "menu.hpp"
#include "movement.hpp"
#include "elements.hpp"
#include<iostream>
std::string playerName = "";
int score = 0;


const int SCREEN_WIDTH = 1248;
const int SCREEN_HEIGHT = 720;






void iDraw()
{
	iClear();

	//Main menu functions
	menu();
	menuChange();






	if (game_page == 1)
	{
		if (currentmap == 1){
			// Draw the water layer (animated)
			showWater();

			// Draw the land layer (fixed foreground)
			iShowImage(0, 0, 1248, 720, map1);

			iShowImage(0, 0, 1248, 720, waterfall[currentFrame]);

			drawCows();

			drawShip();

			drawCropBed();
			movementDraw();
			// Show clock (top-right corner)
			


		}


		else if (currentmap == 2){
			showWater();
			iShowImage(0, 0, 1248, 720, map2);
			
			drawShip();
			drawShopkeeper();
			movementDraw();
			shopMenu();  // handles both buy and sell menus
			


			// Show arcade overlay if active
			if (arcadeOverlay) {
				// Background window
				iSetColor(50, 50, 50);
				iFilledRectangle(200, 150, 800, 450);

				// White border
				iSetColor(255, 255, 255);
				iRectangle(200, 150, 800, 450);

				if (arcadeState == 0) {
					arcadeDraw(); // draws the mini-game
				}
				else if (arcadeState == 1) {
					iText(550, 400, "YOU WIN!", GLUT_BITMAP_TIMES_ROMAN_24);
					totalMoney += 100;
					arcadeOverlay = false; // close overlay after reward
				}
				else if (arcadeState == 2) {
					iText(550, 400, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);
					arcadeOverlay = false; // close overlay
				}
			}



		}
		// Show clock (top-right corner)
		char timeText[50];
		sprintf_s(timeText, "Time: %02d:%02d", gameHour, gameMinute);
		iSetColor(0, 0, 0);
		iText(1100, 686, timeText, GLUT_BITMAP_HELVETICA_18);

		if (showInventoryHUD) {
			iShowBMP2(0, 0, popUpHud, 255);


			iSetColor(255, 255, 255);
			char buf[20];

			//iText(350, 320, "Money:", GLUT_BITMAP_HELVETICA_18);
			iSetColor(0,0,0);
			sprintf_s(buf, "%d", totalMoney);
			iText(470, 437, buf, GLUT_BITMAP_TIMES_ROMAN_24);


			//iText(470, 437, "Food:", GLUT_BITMAP_HELVETICA_18);
			sprintf_s(buf, "%d", totalFood);
			iText(470, 364, buf, GLUT_BITMAP_TIMES_ROMAN_24);

			//iText(470, 437, "Milk:", GLUT_BITMAP_HELVETICA_18);
			sprintf_s(buf, "%d", totalMilk);
			iText(470, 291, buf, GLUT_BITMAP_TIMES_ROMAN_24);

			
			//iText(350, 290, "Seed:", GLUT_BITMAP_HELVETICA_18);
			sprintf_s(buf, "%d", totalSeeds);
			iText(470, 221, buf, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}





void iMouseMove(int mx, int my)
{
	

}

void iPassiveMouseMove(int mx, int my)
{
	mouseHover(mx, my);
}

void iMouse(int button, int state, int mx, int my)
{

	if (arcadeOverlay && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		arcadeMouseClick(mx, my);
	}


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{	

		mouseClick(mx, my);

		printf("%d %d \n\n", mx, my);
		
	}
	if (showBuyMenu && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		handleBuyMenuClick(mx, my);
	}
	if (showSellMenu && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		handleSellMenuClick(mx, my);
	}
	if (showWorkerMenu && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		handleWorkerMenuClick(mx, my);
	}


	// --- Milk system update ---
	updateMilkSpawn();
	checkMilkPickup(charX, charY, isKeyPressed('e'));


	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}

}

// Special Keys:
// GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
// GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT

void fixedUpdate()
{
	
	escape();

	if (game_page == 1)
	{
		movementKey();
	}
	
	if (isKeyPressed('i') != 0) {
		showInventoryHUD = true;
	}
	else {
		showInventoryHUD = false;
	}

	
	if (isKeyPressed('i')) {
		if (!inventoryLatch) {  // only trigger once per press
			showInventoryHUD = !showInventoryHUD;  // toggle HUD on/off
			inventoryLatch = true;
		}
	}
	else {
		inventoryLatch = false;  // reset latch when key is released
	}


	if (isKeyPressed(' ')) {
		// Playing the audio once
		mciSendString("play ggsong from 0", NULL, 0, NULL);
	}


}


int main()
{

	std::cout << "Enter your player name: ";
	std::getline(std::cin, playerName);
	// Opening/Loading the audio files
	mciSendString("open \"Audios//background.mp3\" alias bgsong", NULL, 0, NULL);
	//mciSendString("open \"Audios//gameover.mp3\" alias ggsong", NULL, 0, NULL);

	// Playing the background audio on repeat
	mciSendString("play bgsong repeat", NULL, 0, NULL);

	// If the use of an audio is finished, close it to free memory
	// mciSendString("close bgsong", NULL, 0, NULL);
	// mciSendString("close ggsong", NULL, 0, NULL);


	iSetTimer(30, moveWater);  // call moveWater every 30ms (~33fps)
	iSetTimer(180, animateWaterfall);
	iSetTimer(200, animateCows);
	iSetTimer(200, animateShip); // 200ms per frame
	iSetTimer(1000, animateCropBed);
	iSetTimer(1000, animateSpecialCropBed);
	iSetTimer(1000, updateTime); // calls updateTime every real second


	iSetTimer( 20, menuChange);
	iSetTimer( 100, movementKey);
	iSetTimer(100, animateShopkeeper);
	iInitialize(SCREEN_WIDTH, SCREEN_HEIGHT, "Project Title");

	loadAllImages();
	showWater();
	srand(time(NULL));

	iStart();
	return 0;
}