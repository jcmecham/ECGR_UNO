#include "game_state.h"

GameState::GameState(int n){
    
    numPlayers = n;
    currentPlayerIndex = 0;
    numCardsToPlay = 1;
    numCardsToDraw = 0;
    turnDirection = LEFT;
}

void GameState::nextTurn(){
    if(turnDirection == LEFT){
        currentPlayerIndex++;
        if(currentPlayerIndex >= numPlayers){
            currentPlayerIndex = 0;
        }
    } else {
        currentPlayerIndex--;
        if(currentPlayerIndex < 0)
            currentPlayerIndex = numPlayers - 1;
    }
}


void GameState::setNumCardsToDraw(int num){
    numCardsToDraw = num;
}
void GameState::reverse(){
   if(turnDirection == LEFT){
        turnDirection = RIGHT;
    } else {
        turnDirection = LEFT;
    }
}

