#pragma once

#include <string>
#include "Other/constants.h"
#include "raylib.h"

class UIController{
	private:
	Vector2 scorePosition;
	Vector2 livesPosition;
	std::string scoreText;
	std::string livesText;

	public:
	UIController():
		scorePosition{0,0},
		livesPosition{0,0},
		scoreText{""},
		livesText{""} {}

	UIController(float scorePosX, float scorePosY, float livesPosX, float livesPosY):
		scorePosition{scorePosX, scorePosY},
		livesPosition{livesPosX, livesPosY},
		scoreText{""},
		livesText{""} {}
	
	public:

	void SetScoreText(std::string value) {scoreText = value;}
	void SetLivesText(std::string value) {livesText = value;}
	void DisplayUI(int size);
};
