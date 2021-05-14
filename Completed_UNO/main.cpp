#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "game_state.h"
#include "card.h"
#include "colors.h"

using namespace std;

/**
 * Function to clear the terminal by inserting many new line characters.
 */
void clearTerminal();

/**
 * Function to populate the deck with cards.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 */
void buildDeck(vector<Card*>& deck);

/**
 * Function to shuffle the deck.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 */
 void shuffleDeck(vector<Card*>&);

/**
 * Function to draw a card from the deck to either the hand or discard pile.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 * @param target A vector representing the structure that the card being drawn 
 * from the deck is being drawn to. This can be either a hand or the discard
 * pile
 */
void drawCards(vector<Card*>& deck, vector<Card*>& target, int);

/**
 * Function to draw 7 cards to each player's hand at the beginning of the game.
 * 
 * @param deck A vector reference of Card pointers representing the deck.
 * @param hands A vector of vector of Card pointers representing each player 
 * and their hands. The indicies of the first vector represents a player, and 
 * the indicies of the vector at that index is each individual card within the
 * player's hand.
 */
void populateHands(vector<Card*>& deck, vector<vector<Card*>>& hands);

/** 
 * Renders the cards in he hand vector passed.
 * 
 * @param hand A vector containing Card pointers
 */
void renderHand(vector<Card*> hand);

/**
 * Renders the top card of the passed discard vector.
 * 
 * @param hand A vector containing Card pointers
 */
void renderDiscard(vector<Card*>);

/**
 * Passed references to the deck, hand, and discard vectors and a reference to 
 * the game state. This function will resolve the turn for the current player
 * (whose index is stored in the game state). TakeTurn will query the user for
 * input, draw cards if the previous card was a draw 2 card, or skip the current
 * players turn (see numCardsToPlay in GameState).
 * 
 * @param deck A vector reference of Card pointers representing the deck
 * @param hand A vector reference of Card pointers representing a single player's hand
 * @param discard A vector reference of Card pointers representing the discard pile
 * @param gameState A reference of the game state object
 */
void takeTurn(vector<Card*>& deck, vector<Card*>& hand, vector<Card*>& discard, GameState& gameState);

int getPlayers();

bool checkHands( vector<vector<Card*>> hands);

int main(){
    srand(time(0));
    const int NUM_PLAYERS = getPlayers();
    GameState gameState(NUM_PLAYERS);
    
    Card* TopCard;
    
    vector<Card*> deck;
    vector<Card*> discard;
    
    
    
    vector<vector<Card*>> hands(NUM_PLAYERS);
    
    buildDeck(deck);
    shuffleDeck(deck);
    populateHands(deck, hands);
    
    
    drawCards(deck, discard, 1);
    
    //if topcard starts as wild, pick a random color
    if(discard.at(0)->getNumber()==69){
        // cout << "WILDBABBBBBYYYY"<<endl;
        int t = rand() % 4;
        discard.at(0)->setColor((Color)t);
        discard.at(0)->colorSet = true;
        
        
        // cout << discard.at(0)->getColor()<<endl;
    }
    
    
    while(checkHands(hands)){
        //if deck is empty
        cout << "another turn"<<endl;
        
        if(deck.size()==0){
            
           
            
            // grab top card
            TopCard = discard.at(discard.size() - 1);
            discard.pop_back();

            //deep copy discard pile back into deck vector
            
            deck = discard;

            // shuffle discard pile
            shuffleDeck(deck);

            // empty discard
            discard.clear();
            
            //add top card back to discard pile
            
            discard.push_back(TopCard);

            
            
        }
        
        takeTurn(deck, hands.at(gameState.currentPlayerIndex), discard, gameState);
    }
    
    clearTerminal();
    cout<<"Player "<< gameState.currentPlayerIndex<<" Wins!!!!"<<endl;
    
    return 0;
}

int getPlayers(){
    int playerAmount;
    cout << "How many players?" << endl;
  do {
    cin >> playerAmount;

    if (!cin) { //if input is not int ask again
      cout << "Please enter a number" << endl;
      clearTerminal();
    } else if (playerAmount < 2) {
      // if the number of players is less than 2 ask again
      cout << "The minimum number of players required is 2" << endl;
    } else if (playerAmount > 10) {
      // if the number of players is greater than 10 ask again
        cout << "The maximum number of players is 10" << endl;
        clearTerminal();
    } else { //if input is number break
      break;
    }
  }
  while (true);
  return playerAmount;
}


bool checkHands( vector<vector<Card*>> hands){
    for(int i =0; i < hands.size();i++){
        
        if(hands.at(i).size() ==0){
            return false;
        }
    }
    
    
    return true;
}

void buildDeck(vector<Card*> &deck){
    // Create Number Cards
    for(int c = RED; c < NUM_COLORS; c++){
        for(int n = 0; n < 1; n++){
            Card* temp = new NumberCard((Color)c, n);
            deck.push_back(temp);
            deck.push_back(temp);
        }
    }
    // //adds normal wildcards to the deck.
    Card* wild1 = new WildCard();
    Card* wild2 = new WildCard();
    Card* wild3 = new WildCard();
    Card* wild4 = new WildCard();
    deck.push_back(wild1);
    deck.push_back(wild2);
    deck.push_back(wild3);
    deck.push_back(wild4);
    
    
    Card* wild10 = new WildPlus4Card();
    Card* wild20 = new WildPlus4Card();
    Card* wild30 = new WildPlus4Card();
    Card* wild40 = new WildPlus4Card();
    deck.push_back(wild10);
    deck.push_back(wild20);
    deck.push_back(wild30);
    deck.push_back(wild40);
    
    //adds Draw 2 cards to deck,
    for(int c = RED; c < NUM_COLORS; c++){
        Card* temp = new Draw2((Color)c);
        deck.push_back(temp);
        deck.push_back(temp);
    }
    
    //adds reverse cards cards to deck,
    for(int c = RED; c < NUM_COLORS; c++){
        Card* temp = new Reverse((Color)c);
        deck.push_back(temp);
        deck.push_back(temp);
    }
    
    
    //adds skip cards to deck    
    for(int c = RED; c < NUM_COLORS; c++){
        Card* temp = new Skip((Color)c);
        deck.push_back(temp);
        deck.push_back(temp);
    }
    
}

void shuffleDeck(vector<Card*> &deck){
    
    for(int i = 0; i < 1000; i++){
        
        if(!deck.size()==0){
        int idx1 = rand() % deck.size();
       
        int idx2 = rand() % deck.size();
        
        Card* temp = deck.at(idx1);
        
        deck.at(idx1) = deck.at(idx2);
        
        deck.at(idx2) = temp;
        }
        
    }
}
void drawCards(vector<Card*> &deck, vector<Card*> &target, int numToDraw){
    for(int i = 0; i < numToDraw; i++){
        if(deck.size() > 0){
            
            
            target.push_back(deck.at(deck.size() - 1));
            deck.pop_back();
        } else {
            
            //TODO reshuffle discard pile
            cout << "WARNING: Deck out of cards" << endl;
        }
    }
}

void populateHands(vector<Card*> &deck, vector<vector<Card*>> &hands){
    for(int i = 0; i < hands.size(); i++){
        drawCards(deck, hands.at(i), 7);
    }
}

void renderHand(vector<Card*> hand){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                // switch(hand.at(j)->getColor()){
                //     case RED:
                //     cout << SetBackRED;
                //     break;
                //     case BLUE:
                //     cout << SetBackBLU;
                //     break;
                //     case GREEN:
                //     cout << SetBackGRN;
                //     break;
                //     case YELLOW:
                //     cout << SetBackYEL;
                //     break;
                //     default:
                //     break;
                // }
                
                cout <<  hand.at(j)->render(i) <<RESETTEXT<< " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}



void takeTurn(vector<Card*> &deck, vector<Card*> &hand, vector<Card*> &discard, GameState &gameState){
    clearTerminal();

    cout<< "--TOP CARD---"<< endl;
   
    renderDiscard(discard);
    
    cout <<endl << "Player " << gameState.currentPlayerIndex << "'s turn." << endl;
    
    // TODO: Draw cards if necessary (draw 2 card)
    drawCards(deck, hand, gameState.numCardsToDraw);
    gameState.numCardsToDraw = 0; // reset cards to draw back to 0
    
    renderHand(hand);
    
    // loop for number of cards to play (0 if previously played card was a "skip" or "draw 2")
    //for(int j = 0; j < gameState.numCardsToPlay; j++){
    if(!gameState.skipTurn){
        // Collect user input
        cout << "What would you like to do?" << endl;
        int i;
        for(i = 0; i < hand.size(); i++){
            cout << i << ": Play Card" << endl;
        }
        cout << i << ": Draw a Card" << endl;
        int input;
        cin >> input;
        
        
        // Evaluate user input
        if(input < i){
            // Play card at index input
            if(hand.at(input)->play(discard.at(discard.size()-1), gameState)){
                Card* temp;
                temp = hand.at(input);
                discard.push_back(temp);
                hand.erase(hand.begin() + input); // Remove card in hand at position "input"
            } else {
                cout << "Improper choice" << endl;
                takeTurn(deck, hand, discard, gameState);
                return;
            }
        }else if(input == i){
            drawCards(deck, hand, 1);
        }
    }else{
        gameState.skipTurn = false;
    }
    
    // update variables for next turn
    gameState.nextTurn();
}