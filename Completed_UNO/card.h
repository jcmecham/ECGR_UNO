#ifndef CARD_H
#define CARD_H

#include <sstream>
#include "game_state.h"

using namespace std;

/**
 * Enumeration to represent UNO card colors.
 */
enum Color{RED, BLUE, GREEN, YELLOW, NUM_COLORS};

/**
 * @class Card
 * 
 * @brief An abstract class used to describe a generic UNO card.
 */
class Card{
    protected:
    Color color;
    int number;
    //used for wild cards
    
    
    public:
    bool colorSet = false;
    /**
     * Accessor for card color.
     * 
     * @return The enumerated color type
     */
    Color getColor() const;
    
    /**
     * Accessor for card number.
     * 
     * @return integer value of the card.
     */
    int getNumber() const;
    
    /**
     * Mutator for card color.
     * 
     * @param c The enumerated color type for the card.
     */
    void setColor(Color c);
    
    /**
     * Mutator for card number.
     * 
     * @param n The integer value for the card.
     */
    void setNumber(int n);
    
    
    virtual string render(int line) const = 0;
    virtual bool play(Card* discard, GameState& gameState) = 0;
};

/**
 * @class NumberCard
 * 
 * @brief An abstract class used to describe a "normal" UNO card. This class
 * represents the generic UNO card that diplays a number and color.
 */
class NumberCard : public Card{
    public:
    /**
     * Constructor for the NumberCard class.
     * 
     * @param c The enumeratorated color type for the card.
     * @param n The integer value of the card's number.
     */
    NumberCard(Color c, int n);
    
    /**
     * Returns the ascii string with the rendering of the cards image at a 
     * specificed "line" number. To print a card, this function must be called
     * 7 times, with a new line character follwing each call. To print multiple
     * cards, this function must be called for each card before inserting the 
     * newline character and incrementing the line number.
     * 
     * @param line The line number of the card's image to be rendered.
     */
    string render(int) const;
    
    /**
     * The function to play a the card. This function evaluates the top card of
     * the discard pile for a match and if valid, will alter the state of the 
     * game accordingly. If not valid, the function will not alter the game 
     * state and return false.
     * 
     * @param discard A pointer to the card that is on top of the discard pile.
     * @param gameState A reference to the game state object.
     * @return A boolean value representing if the card played was valid 
     * according to the top card of the discard pile.
     */
    bool play(Card*, GameState&);
};



class WildCard : public Card{
    public:
    
  
    WildCard();
    

    string render(int) const;
    

    bool play(Card*, GameState&);
    
};



class Draw2 : public Card{
    public:
    
 
    Draw2(Color c);

    string render(int) const;

    bool play(Card*, GameState&);
    
};

class Reverse: public Card{
      public:
    

    Reverse(Color c);
    

    string render(int) const;

    bool play(Card*, GameState&);
    
    
    
};


class Skip: public Card{
    public:
    

    Skip(Color c);
    

    string render(int) const;
    

    bool play(Card*, GameState&);
    
};

class WildPlus4Card : public Card{
    public:
    

    WildPlus4Card();
    

    string render(int) const;
    

    bool play(Card*, GameState&);
    
};


#endif