#include "uiController.h"
#include <raylib.h>


void UIController::DisplayUI(int size){
	DrawText(scoreText.c_str(), scorePosition.x, scorePosition.y, size, WHITE);
	DrawText(livesText.c_str(), livesPosition.x, livesPosition.y, size, WHITE);
}
