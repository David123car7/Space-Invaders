#include "uiController.h"
#include <raylib.h>


void UIController::DisplayUI(){
	DrawText(scoreText.c_str(), scorePosition.x, scorePosition.y, 100, WHITE);
	DrawText(livesText.c_str(), livesPosition.x, livesPosition.y, 100, WHITE);
}
