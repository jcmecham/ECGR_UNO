#ifndef GAME_STATE_H
#define GAME_STATE_H

/**
 * Enumerated value indicating turn direction.
 */
enum TurnDirection {RIGHT, LEFT};

/**
 * @class GameState
 * 
 * @brief  The game state class is used to store various variables concerning 
 * the curent state of the game.
 */
class GameState{
    public:
    /// number of players in the game
    int numPlayers;
    /// index of the current player
    int currentPlayerIndex;
    /// number of cards the player can play this turn
    /// (usually 1 or 0. 0 in the cases when the last card was a skip or draw 2)
    int numCardsToPlay;
    /// number of cards to draw this turn (usually 0. 2 when last card was draw 2)
    int numCardsToDraw;
    /// indicates whether the index of the next player is determined by incrementing
    /// or decrementing. Toggled by the reverse card.
    TurnDirection turnDirection;
    /// Constructor. Passed the number of players for the current game.
    GameState(int n);
    /// Used to update the next turn.
    void nextTurn();
    // used to setNumCardsToDraw;
    void setNumCardsToDraw(int num);
    //reverse turn direction
    void reverse();
    //skip next player

    /// Used to indicate if the player's turn should be skipped
    bool skipTurn = false;
};


#endif