#include "card.h"
#include "colors.h"
#include <iostream>
#include <vector>

void clearTerminal(){
    for(int i = 0; i < 100; i++){
        cout << endl;
    }
}

void renderDiscard(vector<Card*> discard){
    for(int i = 0; i <= 7; i++){
        
        cout << discard.at(discard.size() - 1)->render(i) << RESETTEXT<< endl;
    }
   
}

Color Card::getColor() const{
    return color;
}
    
int Card::getNumber() const{
    return number;
}

void Card::setColor(Color c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}

NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string NumberCard::render(int line) const{
    stringstream ss;
    string colorString;
    string println;
    
    
    switch(color){
        case RED:
        colorString = SetBackRED;
        break;
        case BLUE:
        colorString = SetBackBLU;
        break;
        case GREEN:
        colorString = SetBackGRN;
        break;
        case YELLOW:
        colorString = SetBackYEL;
        break;
        default:
        break;
    }
   
    switch(line){
        case 0:
        println = "             ";
        return colorString + println;
        
        break;
        case 1:println = "             ";
            return colorString + println;
            break;
        case 2: 
            switch(color){
            case RED:
                println =  "     RED     ";
                return colorString + println;
                break;
            case BLUE:
                println =  "     BLUE    ";
                return colorString + println;
                break;
            case GREEN:
                println =  "    GREEN    ";
                return colorString + println;
                break;
            case YELLOW:
                println =  "   YELLOW    ";
                return colorString + println;
                break;
            default:
                println =  "             ";
                return colorString + println;
                
                break;
            }
        case 3:
            ss << colorString << "      " <<  number << "      " << RESETTEXT;
            return ss.str();
            break;
        case 4: println =  "             ";
            return colorString + println;
            break;
        case 5: println =  "             ";
            return colorString + println;
            break;
        case 6: println =  "             ";
            return colorString + println;
            break;
        case 7: println =  "             ";
            return colorString + println;
            break;
        default:
            return " ";
    }
}

bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.setNumCardsToDraw(0);
        return true;
    } else {
        return false;
    }
}

WildCard::WildCard(){
    number = 69;
}

string WildCard::render(int line) const{
    stringstream ss;
    string colorString;
    string println;
    
    if(colorSet){
        
        switch(color){
        case RED:
        colorString = SetBackRED;
        break;
        case BLUE:
        colorString = SetBackBLU;
        break;
        case GREEN:
        colorString = SetBackGRN;
        break;
        case YELLOW:
        colorString = SetBackYEL;
        break;
        default:
        colorString = SetBackRED;
        break;
        }
   
        switch(line){
        case 0:
        println = "             ";
        return colorString + println;
        
        break;
        case 1:println = "             ";
            return colorString + println;
            break;
        case 2: 
            println =  "     WILD    ";
            return colorString + println;
            break;
        case 3:println =  "             ";
            return colorString + println;
            break;
        case 4: println =  "             ";
            return colorString + println;
            break;
        case 5: println =  "             ";
            return colorString + println;
            break;
        case 6: println =  "             ";
            return colorString + println;
            break;
        case 7: println =  "             ";
            return colorString + println;
            break;
        default:
            return " ";
        }
    }else{
        string space = " ";
        string reset = RESETTEXT;
        colorString = SetBackWHT + space + reset;
        string l = "             ";
        string topbottomline = SetBackWHT + l+ reset;
        switch(line){
        case 0:
            return topbottomline;
            break;
        case 1:println = "           ";
            return colorString + println + colorString;
            break;
        case 2: 
            println =  "   WILD    ";
            
            return colorString + println + colorString;
            break;
        case 3:
            ss << colorString << "   " << SetBackRED << "  "<< SetBackBLU << "  "<<RESETTEXT<< "    "<<colorString;
            return ss.str();
            break;
        case 4: 
            ss << colorString << "   " << SetBackYEL << "  "<< SetBackGRN << "  "<<RESETTEXT<< "    "<<colorString;
            return ss.str();
            break;
        case 5: println =  "           ";
            return colorString +println + colorString;
            break;
        case 6: println =  "           ";
            return colorString +println + colorString;
            break;
        case 7: 
            return topbottomline;
            break;
        default:
            return " ";
        }
    }
    
    
}

bool WildCard::play(Card* discard, GameState &gameState){
    string selectedColor;
    vector<Card*> temp = {discard};
    do{
    gameState.setNumCardsToDraw(0);
    clearTerminal();
    renderDiscard(temp);
    cout << "Pick a color"<<endl;
    cout <<"0: " <<SetForeRED << "RED" << RESETTEXT<<endl;
    cout <<"1: " <<SetForeBLU << "BLUE" << RESETTEXT<<endl;
    cout <<"2: " <<SetForeYEL << "YELLOW" << RESETTEXT<<endl;
    cout <<"3: " <<SetForeGRN << "GREEN" << RESETTEXT<<endl;
    cin >> selectedColor;
    try{
        int temp = stoi(selectedColor);
        switch(temp){
            case 0:
            color = Color::RED;
            colorSet = true;
            return true;
            break;
            case 1:
            setColor(Color::BLUE);
            colorSet = true;
            cout <<"You've Selected BLUE";
            return true;
            break;
            case 2:
            setColor(Color::YELLOW);
            colorSet = true;
            cout <<"You've Selected YELLOW";
            return true;
            break;
            case 3:
            setColor(Color::GREEN);
            colorSet = true;
            cout <<"You've Selected GREEN";
            return true;
            break;
            
        }
        
    }catch(...){
        cout <<"oops something went wrong";
    }
    }while(true);
    
    
    return true;
}


Draw2::Draw2(Color c){
    color = c;
    number = 11;
}

string Draw2::render(int line) const{
    stringstream ss;
    string colorString;
    string println;
    
    
    switch(color){
        case RED:
        colorString = SetBackRED;
        break;
        case BLUE:
        colorString = SetBackBLU;
        break;
        case GREEN:
        colorString = SetBackGRN;
        break;
        case YELLOW:
        colorString = SetBackYEL;
        break;
        default:
        break;
    }
   
    switch(line){
        case 0:
        println = "             ";
        return colorString + println;
        
        break;
        case 1:println = "             ";
            return colorString + println;
            break;
        case 2: 
            switch(color){
            case RED:
                println =  "     RED     ";
                return colorString + println;
                break;
            case BLUE:
                println =  "     BLUE    ";
                return colorString + println;
                break;
            case GREEN:
                println =  "    GREEN    ";
                return colorString + println;
                break;
            case YELLOW:
                println =  "   YELLOW    ";
                return colorString + println;
                break;
            default:
                println =  "             ";
                return colorString + println;
                
                break;
            }
        case 3:
            ss << colorString << "   " <<  "Draw +2" << "   " << RESETTEXT;
            return ss.str();
            break;
        case 4: println =  "             ";
            return colorString + println;
            break;
        case 5: println =  "             ";
            return colorString + println;
            break;
        case 6: println =  "             ";
            return colorString + println;
            break;
        case 7: println =  "             ";
            return colorString + println;
            break;
        default:
            return " ";
    }
}

bool Draw2::play(Card* discard, GameState &gameState){
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.setNumCardsToDraw(2);
        return true;
    } else {
        return false;
    }
}

Reverse::Reverse(Color c){
    color = c;
    number = 12;
}

string Reverse::render(int line) const{
    stringstream ss;
    string colorString;
    string println;
    
    
    switch(color){
        case RED:
        colorString = SetBackRED;
        break;
        case BLUE:
        colorString = SetBackBLU;
        break;
        case GREEN:
        colorString = SetBackGRN;
        break;
        case YELLOW:
        colorString = SetBackYEL;
        break;
        default:
        break;
    }
   
    switch(line){
        case 0:
        println = "             ";
        return colorString + println;
        
        break;
        case 1:println = "             ";
            return colorString + println;
            break;
        case 2: 
            switch(color){
            case RED:
                println =  "     RED     ";
                return colorString + println;
                break;
            case BLUE:
                println =  "     BLUE    ";
                return colorString + println;
                break;
            case GREEN:
                println =  "    GREEN    ";
                return colorString + println;
                break;
            case YELLOW:
                println =  "   YELLOW    ";
                return colorString + println;
                break;
            default:
                println =  "             ";
                return colorString + println;
                
                break;
            }
        case 3:
            ss << colorString << "   " <<  "Reverse"  << "   " << RESETTEXT;
            return ss.str();
            break;
        case 4: println =  "             ";
            return colorString + println;
            break;
        case 5: println =  "             ";
            return colorString + println;
            break;
        case 6: println =  "             ";
            return colorString + println;
            break;
        case 7: println =  "             ";
            return colorString + println;
            break;
        default:
            return " ";
    }
}

bool Reverse::play(Card* discard, GameState &gameState){
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.reverse();
        return true;
    } else {
        return false;
    }
    
}

Skip::Skip(Color c){
    color = c;
    number = 13;
    
}

string Skip::render(int line) const{
    stringstream ss;
    string colorString;
    string println;
    
    
    switch(color){
        case RED:
        colorString = SetBackRED;
        break;
        case BLUE:
        colorString = SetBackBLU;
        break;
        case GREEN:
        colorString = SetBackGRN;
        break;
        case YELLOW:
        colorString = SetBackYEL;
        break;
        default:
        break;
    }
   
    switch(line){
        case 0:
        println = "             ";
        return colorString + println;
        
        break;
        case 1:println = "             ";
            return colorString + println;
            break;
        case 2: 
            switch(color){
            case RED:
                println =  "     RED     ";
                return colorString + println;
                break;
            case BLUE:
                println =  "     BLUE    ";
                return colorString + println;
                break;
            case GREEN:
                println =  "    GREEN    ";
                return colorString + println;
                break;
            case YELLOW:
                println =  "   YELLOW    ";
                return colorString + println;
                break;
            default:
                println =  "             ";
                return colorString + println;
                
                break;
            }
        case 3:
            ss << colorString << "    " <<  "Skip"  << "     " << RESETTEXT;
            return ss.str();
            break;
        case 4: println =  "             ";
            return colorString + println;
            break;
        case 5: println =  "             ";
            return colorString + println;
            break;
        case 6: println =  "             ";
            return colorString + println;
            break;
        case 7: println =  "             ";
            return colorString + println;
            break;
        default:
            return " ";
    }
}

bool Skip::play(Card* discard, GameState &gameState){
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.skipTurn = true;
        return true;
    } else {
        return false;
    }
}

WildPlus4Card::WildPlus4Card(){
    number = 69;
}
string WildPlus4Card::render(int line) const{
    stringstream ss;
    string colorString;
    string println;
    
    if(colorSet){
        
        switch(color){
        case RED:
        colorString = SetBackRED;
        break;
        case BLUE:
        colorString = SetBackBLU;
        break;
        case GREEN:
        colorString = SetBackGRN;
        break;
        case YELLOW:
        colorString = SetBackYEL;
        break;
        default:
        colorString = SetBackRED;
        break;
        }
   
        switch(line){
        case 0:
        println = "             ";
        return colorString + println;
        
        break;
        case 1:
            println =  "             ";
            return colorString + println;
            break;
        case 2: 
            println =  "   WILD +4   ";
            return colorString + println;
            break;
        case 3:
            println =  "             ";
            return colorString + println;
            break;
        case 4: println =  "             ";
            return colorString + println;
            break;
        case 5: println =  "             ";
            return colorString + println;
            break;
        case 6: println =  "             ";
            return colorString + println;
            break;
        case 7: println =  "             ";
            return colorString + println;
            break;
        default:
            return " ";
        }
    }else{
        string space = " ";
        string reset = RESETTEXT;
        colorString = SetBackWHT + space + reset;
        string l = "             ";
        string topbottomline = SetBackWHT + l+ reset;
        switch(line){
        case 0:
            return topbottomline;
            break;
        case 1:println = "           ";
            return colorString + println + colorString;
            break;
        case 2: 
            println =  "  WILD +4  ";
            
            return colorString + println + colorString;
            break;
        case 3:
            ss << colorString << "   " << SetBackRED << "  "<< SetBackBLU << "  "<<RESETTEXT<< "    "<<colorString;
            return ss.str();
            break;
        case 4: 
            ss << colorString << "   " << SetBackYEL << "  "<< SetBackGRN << "  "<<RESETTEXT<< "    "<<colorString;
            return ss.str();
            break;
        case 5: println =  "           ";
            return colorString +println + colorString;
            break;
        case 6: println =  "           ";
            return colorString +println + colorString;
            break;
        case 7: 
            return topbottomline;
            break;
        default:
            return " ";
        }
    }
    
    
}

bool WildPlus4Card::play(Card* discard, GameState &gameState){
    gameState.skipTurn = true;
    gameState.setNumCardsToDraw(4);
    string selectedColor;
    vector<Card*> temp = {discard};
    do{
    
    clearTerminal();
    renderDiscard(temp);
    cout << "Pick a color"<<endl;
    cout <<"0: " <<SetForeRED << "RED" << RESETTEXT<<endl;
    cout <<"1: " <<SetForeBLU << "BLUE" << RESETTEXT<<endl;
    cout <<"2: " <<SetForeYEL << "YELLOW" << RESETTEXT<<endl;
    cout <<"3: " <<SetForeGRN << "GREEN" << RESETTEXT<<endl;
    cin >> selectedColor;
    try{
        int temp = stoi(selectedColor);
        switch(temp){
            case 0:
            color = Color::RED;
            colorSet = true;
            return true;
            break;
            case 1:
            setColor(Color::BLUE);
            colorSet = true;
            cout <<"You've Selected BLUE";
            return true;
            break;
            case 2:
            setColor(Color::YELLOW);
            colorSet = true;
            cout <<"You've Selected YELLOW";
            return true;
            break;
            case 3:
            setColor(Color::GREEN);
            colorSet = true;
            cout <<"You've Selected GREEN";
            return true;
            break;
            
        }
        
    }catch(...){
        cout <<"oops something went wrong";
    }
    }while(true);
    
    
    return true;
}