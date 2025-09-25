#ifndef ELEMENTS_H
#define ELEMENTS_H
#include "menu.hpp"

void showWater();
void animateWaterfall();
void drawCows();
void animateCows();
void drawShip();
void animateShip();
void drawCropBed();
void animateCropBed();
void cropgrow();
bool flashState = false;   // toggle for flashing
int flashCounter = 0;      // counter for timing

//popUpHud
bool showInventoryHUD = false;
bool inventoryLatch = false;  // prevents repeated toggling while key is held

//redo

// Shop menu toggles and latches
bool showBuyMenu = false;
bool showSellMenu = false;
bool eShopLatch = false;  // single latch for both buy/sell

char worker[2][30] = { "img\\w1.bmp", "img\\w2.bmp" };
char popUpHud[25] = "img\\popuphud.bmp";
char cowRight[4][30] = { "img\\cowR1.bmp", "img\\cowR2.bmp", "img\\cowR3.bmp", "img\\cowR4.bmp" };
char cowLeft[4][30] = { "img\\cowL1.bmp", "img\\cowL2.bmp", "img\\cowL3.bmp", "img\\cowL4.bmp" };
char ship[4][20] = { "img\\s1.bmp", "img\\s2.bmp", "img\\s3.bmp", "img\\s4.bmp" };
char cropBed[6][30] = { "img\\c1.bmp", "img\\c2.bmp", "img\\c3.bmp", "img\\c4.bmp", "img\\c5.bmp", "img\\c6.bmp" };
char shoperkeeper[2][50] = { "img\\shopkeeper1.bmp", "img\\shopkeeper2.bmp" };
char specialCropBed[6][40] = { "img\\cl1.bmp", "img\\cl2.bmp", "img\\cl3.bmp", "img\\cl4.bmp", "img\\cl5.bmp", "img\\cl6.bmp" };

// --- Crop System (indices match images directly) ---
// Seeds
int totalSeeds = 5;   // initial seeds

enum CropState { C_EMPTY = 0, C_GROW1, C_GROW2, C_GROW3, C_READY, C_HARVESTED };
int cropState = C_EMPTY;
int cropX = 560;
int cropY = 340;
bool cropPlanted = false;
int cropGrowthCounter = 0;
bool eLatch = false;
int cropGrowthSpeed = 10;  // normal speed = 1

// --- Special Crop System ---
int specialCropState = C_EMPTY;
bool specialCropPlanted = false;
int specialCropGrowthCounter = 0;
bool specialCropELatch = false;
int specialCropX = 620;  // position on map
int specialCropY = 340;
int specialCropGrowthSpeed = 30; // grows faster


// Worker system
bool workerActive = false;       // Whether worker is spawned
double workerX = 1025;           // Spawn X (changeable)
double workerY = 379;            // Spawn Y (changeable)
int workerIndex = 0;             // Animation frame
int workerAnimCounter = 0;       // Counter for frame switching
const int workerAnimSpeed = 500; // Milliseconds per frame

int workerCost = 2000;           // Cost to spawn worker

// purchase flags (add with other globals)
bool workerOwned = false;         // true once player bought the worker
bool specialCropBought = false;   // true once player bought the special cropbed
int specialCropCost = 1000;       // cost for special cropbed (adjust as needed)


// New variables for rewards
int totalFood = 0;      // total food collected
int totalMoney = 3800;     // total money collected (optional)
int totalMilk = 10; //total milk s
//dokander 
bool shopkeeperActive = true;     // enable/disable
double shopkeeperX = 690;         // default position X
double shopkeeperY = 600;         // default position Y
int shopkeeperIndex = 0;          // animation frame
int shopkeeperAnimCounter = 0;    // counter for animation timing
const int shopkeeperAnimSpeed = 700; // milliseconds per frame




//ship er
int shipX = 470;
int shipY = 0;
int shipIndex = 0;
bool shipMoving = false;
int shipWidth = 250;
int shipHeight = 192;
bool shipout = false;

//gorur
int cow1Index = 0;
int cow1X = 1160;
int cow1Y = 500;
int cow1Direction = -1;
bool cow1Paused = false;
int cow1PauseTime = 0;
int cow1PauseDuration = 0;

int cow2Index = 0;
int cow2X = 1000;
int cow2Y = 430;
int cow2Direction = 1;
bool cow2Paused = false;
int cow2PauseTime = 0;
int cow2PauseDuration = 0;
int currentmap = 1;


//eigula main map er
double moveY = 0;
int waterfall[2];
int map1,map2;
int mapBG;
int shadow;
int currentFrame = 0;   // which waterfall frame is shown
double charX = 738;
double charY = 121;

// --- Time System ---
int gameHour = 6;      // start 6:00 AM
int gameMinute = 0;


void updateTime() {
	gameMinute++;            

	if (gameMinute >= 60) { 
		gameMinute = 0;
		gameHour++;
		if (gameHour >= 24) {
			gameHour = 0;  
		}
	}
}




void drawShip() {
	iShowBMP2(shipX, shipY, ship[shipIndex], 255);



}



void animateShip() {
	
	if (currentmap == 1){

		if (shipX < 0) {
			currentmap = 2;      
			shipMoving = false;  
			shipX = 470;         
			shipY = 0;
			charX = 616;
			charY = 122;
		}
	}

	else if (currentmap == 2){

		if (shipX < 0) {
			currentmap = 1;      
			shipMoving = false; 
			shipX = 470;     
			shipY = 0;
			charX = 685;
			charY = 72;
		}

	}

	if (!shipMoving) return; 

	
	shipIndex++;
	if (shipIndex >= 4) shipIndex = 0;


	shipX -= 10;  
}






void drawCows() {
	// Cow 1
	if (cow1Direction == 1)
		iShowBMP2(cow1X, cow1Y, cowRight[cow1Index], 0);
	else
		iShowBMP2(cow1X, cow1Y, cowLeft[cow1Index], 0);

	// Cow 2
	if (cow2Direction == 1)
		iShowBMP2(cow2X, cow2Y, cowRight[cow2Index], 0);
	else
		iShowBMP2(cow2X, cow2Y, cowLeft[cow2Index], 0);
}

void animateCows() {
	// === Cow 1 ===
	if (cow1Paused) {
		cow1PauseTime += 180;  // since this function is called every 180 ms
		if (cow1PauseTime >= cow1PauseDuration) {
			cow1Paused = false;
			cow1PauseTime = 0;
		}
	}
	else {
		cow1Index++;
		if (cow1Index >= 4) cow1Index = 0;
		cow1X += (cow1Direction * 5);

		if (cow1X >= 1160) {
			cow1Direction = -1;
			cow1Paused = true;
			cow1PauseDuration = (1000 + rand() % 3000); // 1–4 sec pause
		}
		if (cow1X <= 1000) {
			cow1Direction = 1;
			cow1Paused = true;
			cow1PauseDuration = (1000 + rand() % 3000);
		}
	}

	// === Cow 2 ===
	if (cow2Paused) {
		cow2PauseTime += 180;
		if (cow2PauseTime >= cow2PauseDuration) {
			cow2Paused = false;
			cow2PauseTime = 0;
		}
	}
	else {
		cow2Index++;
		if (cow2Index >= 4) cow2Index = 0;
		cow2X += (cow2Direction * 5);

		if (cow2X >= 1160) {
			cow2Direction = -1;
			cow2Paused = true;
			cow2PauseDuration = (1000 + rand() % 3000);
		}
		if (cow2X <= 1000) {
			cow2Direction = 1;
			cow2Paused = true;
			cow2PauseDuration = (1000 + rand() % 3000);
		}
	}


}




void showWater() {

	iShowImage(0, moveY, 1248, 720, mapBG);

	iShowImage(0, moveY + 720, 1248, 720, mapBG);
}



void moveWater() {
	moveY -= .5;   
	if (moveY <= -720) {  
		moveY = 0;
	}
}


void animateWaterfall() {
	currentFrame++;
	if (currentFrame >= 2) currentFrame = 0;
}

void shipmove(double CharX, double CharY){

	if (currentmap == 1){
		if (CharX >= 680 && CharX <= 684 &&
			CharY >= 48 && CharY <= 96)
		{
			shipMoving = true;

		}
	}
	else if (currentmap == 2){

		if (CharX >= 610 && CharX <= 650 &&
			CharY >= 100 && CharY <= 120)
		{
			shipMoving = true;

		}

	}
}

void specialCropGrow(double CharX, double CharY) {
	bool nearBed = (CharX >= specialCropX && CharX <= specialCropX + 48 &&
		CharY >= specialCropY && CharY <= specialCropY + 48);
	bool eDown = isKeyPressed('e');

	if (nearBed && eDown && !specialCropELatch) {
		switch (specialCropState) {
		case C_EMPTY:
			if (totalSeeds > 0) {
				specialCropState = C_GROW1;
				specialCropPlanted = true;
				specialCropGrowthCounter = 0;
				totalSeeds--;
			}
			break;

		case C_READY:
			specialCropState = C_HARVESTED;
			totalFood += 200; // special crop gives double reward
			break;

		case C_HARVESTED:
			specialCropState = C_EMPTY;
			break;

		default:
			break;
		}
		specialCropELatch = true;
	}

	if (!eDown) specialCropELatch = false;
}


void cropgrow(double CharX, double CharY) {
	bool nearBed = (CharX >= cropX && CharX <= cropX + 48 &&
		CharY >= cropY && CharY <= cropY + 48);
	bool eDown = isKeyPressed('e');

	if (nearBed && eDown && !eLatch) {
		switch (cropState) {
		case C_EMPTY:       
			if (totalSeeds > 0) {
				cropState = C_GROW1;
				cropPlanted = true;
				cropGrowthCounter = 0;
				totalSeeds--;
			}
			break;

		case C_READY:       
			cropState = C_HARVESTED;
			totalFood += 100;
			break;

		case C_HARVESTED:   
			cropState = C_EMPTY;
			break;

		default:            
			break;
		}
		eLatch = true;
	}

	if (!eDown) eLatch = false; }

void drawCropBed() {
	// Normal crop
	iShowBMP2(0, 0, cropBed[cropState], 0);

	// Special crop (only if purchased)
	if (specialCropBought) {
		iShowBMP2(0, 0, specialCropBed[specialCropState], 0);
	}
}


void animateSpecialCropBed() {
	if (!specialCropPlanted) return;

	specialCropGrowthCounter += specialCropGrowthSpeed;

	if (specialCropGrowthCounter >= 180) {
		specialCropGrowthCounter = 0;

		if (specialCropState >= C_GROW1 && specialCropState < C_READY) {
			specialCropState++;
		}

		if (specialCropState == C_READY) {
			specialCropPlanted = false;
		}
	}
}



void animateCropBed() {
	if (!cropPlanted) return;

	cropGrowthCounter += cropGrowthSpeed; 

	
	if (cropGrowthCounter >= 180) {
		cropGrowthCounter = 0;

		if (cropState >= C_GROW1 && cropState < C_READY) {
			cropState++; 
		}

		if (cropState == C_READY) {
			cropPlanted = false; 
		}
	}
}



int arcadeHit = 0;
int arcadeMiss = 0;
int arcadeState = 0;
bool arcadeActive = false;
bool arcadeClicked = false;
bool arcadeOverlay = false; 


struct Box {
	int sqX, sqY;
	int r, g, b;
} ABox[5];

int arcadeBoxSize = 100;
int targetR, targetG, targetB;
int arcadeInterval = 3000;

void arcadeSetColor() {
	for (int i = 0; i < 5; i++) {
		ABox[i].r = rand() % 255;
		ABox[i].g = rand() % 255;
		ABox[i].b = rand() % 255;
	}
	int index = rand() % 5;
	targetR = ABox[index].r;
	targetG = ABox[index].g;
	targetB = ABox[index].b;
}


void arcadeSetBox() {
    int startX = 250;   
    int startY = 350;   
    int gap = 130;      

    for (int i = 0; i < 5; i++) {
        ABox[i].sqX = startX + i * gap;
        ABox[i].sqY = startY;
    }
}

void arcadeDraw() {
    
    arcadeSetBox();

    // Draw 5 boxes
    for (int i = 0; i < 5; i++) {
        iSetColor(ABox[i].r, ABox[i].g, ABox[i].b);
        iFilledRectangle(ABox[i].sqX, ABox[i].sqY, arcadeBoxSize, arcadeBoxSize);
    }

    // Target box
    iSetColor(targetR, targetG, targetB);
    iFilledRectangle(550, 200, arcadeBoxSize, arcadeBoxSize);

    // Score
    char txt[50];
    iSetColor(255, 255, 255);
    sprintf_s(txt, "HIT: %d", arcadeHit);
    iText(900, 550, txt, GLUT_BITMAP_TIMES_ROMAN_24);
    sprintf_s(txt, "MISS: %d", arcadeMiss);
    iText(900, 500, txt, GLUT_BITMAP_TIMES_ROMAN_24);

    if (arcadeHit >= 10) arcadeState = 1;
    if (arcadeMiss >= 10) arcadeState = 2;
}


void arcadeTimeHandler() {
	if (!arcadeClicked) {
		arcadeMiss++;
		arcadeSetColor();
	}
	else {
		arcadeClicked = false;
	}
}

void arcadeMouseClick(int mx, int my) {
	for (int i = 0; i < 5; i++) {
		if (mx >= ABox[i].sqX && mx < ABox[i].sqX + arcadeBoxSize &&
			my >= ABox[i].sqY && my < ABox[i].sqY + arcadeBoxSize) {

			if (ABox[i].r == targetR && ABox[i].g == targetG && ABox[i].b == targetB) {
				arcadeHit++;
				arcadeClicked = true;
			}
			else {
				arcadeMiss++;
			}
			arcadeSetColor();
			return;
		}
	}
	arcadeMiss++;
	arcadeSetColor();
}


// New global toggle
bool showWorkerMenu = false;   // <-- add this at the top with other toggles

void shopMenu() {
	if (currentmap != 2) {
		// Only active in market
		showBuyMenu = false;
		showSellMenu = false;
		showWorkerMenu = false;
		eShopLatch = false;
		return;
	}

	// --- Determine zones ---
	bool nearBuy = (charX >= 505 && charX <= 534 &&
		charY >=  278 && charY <= 580);

	bool nearSell = (charX >= 515 && charX <= 1025 &&
		charY >= 522 && charY <= 556);

	bool nearWorker = (charX >= 718 && charX <= 793 &&   // NEW worker zone
		charY >= 278 && charY <= 315);

	bool eDown = isKeyPressed('e');

	// --- Handle Buy menu ---
	if (nearBuy) {
		if (eDown && !eShopLatch) {
			showBuyMenu = !showBuyMenu;
			showSellMenu = false;
			showWorkerMenu = false;
			eShopLatch = true;
		}
	}

	// --- Handle Sell menu ---
	if (nearSell) {
		if (eDown && !eShopLatch) {
			showSellMenu = !showSellMenu;
			showBuyMenu = false;
			showWorkerMenu = false;
			eShopLatch = true;
		}
	}

	// --- Handle Worker menu ---
	if (nearWorker) {
		if (eDown && !eShopLatch) {
			// only open/close the worker menu when near the worker zone
			showWorkerMenu = !showWorkerMenu;
			showBuyMenu = false;
			showSellMenu = false;
			eShopLatch = true;
		}
	}





	// --- Reset latch when 'e' is released ---
	if (!eDown) eShopLatch = false;

	// --- Auto-close menus if out of range ---
	if (!nearBuy) showBuyMenu = false;
	if (!nearSell) showSellMenu = false;
	if (!nearWorker) showWorkerMenu = false;

	// --- Draw menus ---
	if (showBuyMenu) iShowBMP2(0, 0, "img\\buy.bmp", 255);
	if (showSellMenu) iShowBMP2(0, 0, "img\\sell.bmp", 255);
	if (showWorkerMenu) iShowBMP2(0, 0, "img\\worker.bmp", 255); // NEW worker interface
}

// elements.hpp (outside of shopMenu)
void handleBuyMenuClick(int mx, int my) {
	if (!showBuyMenu) return;  // only active when buy menu is open

	// 1) Buy normal seeds (+5 seeds, -100 money)
	if (mx >= 448 && mx <= 798 && my >= 375 && my <= 440) {
		if (totalMoney >= 100) {
			totalSeeds += 5;
			totalMoney -= 100;
		}
		else {
			printf("Not enough money to buy seeds!\n");
		}
	}

	// 2) Buy advanced seeds (+10 seeds, -100 money)
	else if (mx >= 448 && mx <= 793 && my >= 297 && my <= 361) {
		if (totalMoney >= 200) {
			totalSeeds += 10;
			totalMoney -= 200;
		}
		else {
			printf("Not enough money to buy advanced seeds!\n");
		}
	}
}

void handleSellMenuClick(int mx, int my) {
	if (!showSellMenu) return;  // only active when sell menu is open

	// --- Option 1: Sell Food ---
	if (mx >= 449 && mx <= 789 && my >= 380 && my <= 438) {
		if (totalFood > 0) {
			totalFood -= 1;
			totalMoney += 10;
		}
		else {
			printf("No food to sell!\n");
		}
	}
	// --- Option 2: Sell Milk ---
	else if (mx >= 447 && mx <= 796 && my >= 301 && my <= 359) {
		if (totalMilk > 0) {
			totalMilk -= 1;
			totalMoney += 1;
		}
		else {
			printf("No milk to sell!\n");
		}
	}
}

void handleWorkerMenuClick(int mx, int my) {
	if (!showWorkerMenu) return;

	// Worker button region: (left=431, right=825, bottom=377, top=452)
	if (!workerOwned && mx >= 431 && mx <= 825 && my >= 377 && my <= 452) {
		if (totalMoney >= workerCost) {
			totalMoney -= workerCost;
			workerOwned = true;
			workerActive = true;     // mark worker active — but we will only draw it on map 1
			// set spawn position for map 1 (adjust if you want a different map-1 location)
			workerX = 1025;
			workerY = 379;
			printf("Worker purchased. He/She will appear on map 1.\n");
			showWorkerMenu = false;   // close menu after buying
		}
		else {
			printf("Not enough money to buy worker!\n");
		}
	}

	// Special cropbed button region: (left=429, right=824, bottom=290, top=362)
	if (!specialCropBought && mx >= 429 && mx <= 824 && my >= 290 && my <= 362) {
		if (totalMoney >= specialCropCost) {
			totalMoney -= specialCropCost;
			specialCropBought = true;
			printf("Special cropbed purchased. It will be used in map 1.\n");
			showWorkerMenu = false;   // close menu after buying
		}
		else {
			printf("Not enough money to buy special cropbed!\n");
		}
	}
}


// --- Milk Spawn System ---
bool milkAvailable = false;     // whether milk is spawned
int milkSpawnX1 = 1180, milkSpawnY1 = 544;
int milkSpawnX2 = 1219, milkSpawnY2 = 573;

int milkTimer = 0;              // counter for spawn timing
const int milkSpawnInterval = 3600; // ~3600 ticks = 1 in-game hour (adjust if needed)

bool milkLatch = false;         // to avoid multiple adds on holding E


void updateMilkSpawn() {
	// Check if enough time passed
	if (!milkAvailable) {
		milkTimer++;
		if (milkTimer >= milkSpawnInterval) {
			milkAvailable = true;
			milkTimer = 0;
		}
	}
}

void checkMilkPickup(int playerX, int playerY, bool keyE) {
	if (currentmap == 1 && milkAvailable) {
		if (playerX >= milkSpawnX1 && playerX <= milkSpawnX2 &&
			playerY >= milkSpawnY1 && playerY <= milkSpawnY2) {

			if (keyE && !milkLatch) {
				totalMilk += 1;
				milkAvailable = false;  // remove milk until next spawn
				milkLatch = true;
			}
		}
	}

	// Reset latch when E is released
	if (!keyE) {
		milkLatch = false;
	}
}

void drawMilk() {
	if (currentmap == 1 && milkAvailable) {
		// Draw milk sprite on map
		iShowBMP2(1190, 550, "img\\milk.bmp", 0);
		// Make sure you have img\milk.bmp in your project
	}
}



void animateShopkeeper() {
	if (!shopkeeperActive || currentmap != 2) return;

	shopkeeperAnimCounter += 100;  // timer calls this every 100 ms (example)
	if (shopkeeperAnimCounter >= shopkeeperAnimSpeed) {
		shopkeeperAnimCounter = 0;
		shopkeeperIndex++;
		if (shopkeeperIndex >= 2) shopkeeperIndex = 0; // toggle between frames
	}
}


void drawShopkeeper() {
	if (currentmap == 2 && shopkeeperActive) {
		iShowBMP2(shopkeeperX, shopkeeperY, shoperkeeper[shopkeeperIndex], 150);
	}
}

void loadAllImages(){
	char imageSource[50];
	sprintf_s(imageSource, "img//2.png");
	map1 = iLoadImage(imageSource);
	printf("%s\n", imageSource);

	sprintf_s(imageSource, "img//1.png");
	mapBG = iLoadImage(imageSource);
	printf("%s\n", imageSource);

	sprintf_s(imageSource, "img//3.png");
	shadow = iLoadImage(imageSource);
	printf("%s\n", imageSource);

	sprintf_s(imageSource, "img//4.png");
	waterfall[0] = iLoadImage(imageSource);
	printf("%s\n", imageSource);

	sprintf_s(imageSource, "img//5.png");
	waterfall[1] = iLoadImage(imageSource);
	printf("%s\n", imageSource);

	sprintf_s(imageSource, "img//6.png");
	map2 = iLoadImage(imageSource);
	printf("%s\n", imageSource);

}



#endif