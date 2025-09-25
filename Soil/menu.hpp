#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
#include "elements.hpp"
int game_page = 0;
int hover = 0;
extern std::string playerName;
extern int score;
extern int totalMoney;



struct ScoreEntry {
	std::string name;
	int score;
};





void saveScoreAndQuit() {
	score = totalMoney; // final score = money at quit

	std::ofstream file("scores.txt", std::ios::app); // append mode
	if (file.is_open()) {
		file << playerName << " " << score << "\n";
		file.close();
	}

	exit(0); // quit the game
}


void drawLeaderboard() {
	iShowBMP(0, 0, "img\\leaderboard.bmp");  // leaderboard background

	std::ifstream file("scores.txt");
	if (!file.is_open()) {
		iSetColor(255, 0, 0); // red for error
		iText(100, 500, "Failed to open scores.txt", GLUT_BITMAP_TIMES_ROMAN_24);
		return;
	}

	std::vector<std::pair<std::string, int>> scores;
	std::string name;
	int score;

	// Read all scores
	while (file >> name >> score) {
		scores.push_back({ name, score });
	}
	file.close();

	// Sort all scores in descending order
	std::sort(scores.begin(), scores.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
		return a.second > b.second;
	});

	// Take top 5 scores
	if (scores.size() > 5) {
		scores = std::vector<std::pair<std::string, int>>(scores.begin(), scores.begin() + 5);
	}

	// Display top 5 scores with ranking
	iSetColor(255, 255, 255);  // white text
	int y = 590;
	char buf[200];
	for (size_t i = 0; i < scores.size(); i++) {
		// Format: "#1 Name: Alice   Score: 120"
		sprintf_s(buf, sizeof(buf), "#%d Name: %s                 Score: %d", i + 1, scores[i].first.c_str(), scores[i].second);
		iText(430, y, buf, GLUT_BITMAP_TIMES_ROMAN_24);
		y -= 35;  // spacing between entries
	}
}



void menu(){
	if (game_page == 0)
	{
		//Menu
		iShowBMP(0, 0, "img\\menu.bmp");
	}



	

	if (game_page == 2){

		drawLeaderboard();

	}


}

void mouseClick(int mx, int my)
{
	if (game_page == 0)
	{
		if (mx >= 500 && mx <= 780 && my >= 334 && my <= 390)
		{
			game_page++;
		}
	}

	if (game_page == 0)
	{
		if (mx >= 500 && mx <= 780 && my >= 253 && my <= 310)
		{
			game_page += 2;
		}
	}

	if (game_page == 0)
	{
		if (mx >= 500 && mx <= 780 && my >= 174 && my <= 230)
		{
			saveScoreAndQuit();
		}
	}
}


void escape()
{
	if (game_page == 1 || game_page == 2)
	{
		if (isKeyPressed(GLUT_KEY_ESC))
		{
			game_page = 0;
		}
	}
}

void mouseHover(int mx, int my){

	if (mx >= 500 && mx <= 780 && my >= 334 && my <= 390)
	{
		hover = 1;
	}

	else if (mx >= 500 && mx <= 780 && my >= 253 && my <= 310)
	{
		hover = 2;
	}

	else if (mx >= 500 && mx <= 780 && my >= 174 && my <= 230)
	{
		hover = 3;
	}

	else
		hover = 0;
}
void menuChange(){

	if (hover == 1 && game_page == 0)
	{
		iShowBMP2(499, 331, "img\\menu_button1.bmp", 0);
	}
	else if (hover == 2 && game_page == 0){
		iShowBMP(499, 251, "img\\menu_button2.bmp");
	}
	else if (hover == 3 && game_page == 0){
		iShowBMP(499, 171, "img\\menu_button3.bmp");
	}

}



#endif