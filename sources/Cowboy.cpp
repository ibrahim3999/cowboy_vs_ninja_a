#include "Cowboy.hpp"


namespace ariel{

    Cowboy::Cowboy(string name , const Point& location):Character(name,location),amountOfBalls(15){

    }


    void Cowboy::shoot(Character* enemy){

    }

    bool Cowboy::hasbullets(){
        return true;
    }
    
    void Cowboy::reload(){

    }

    Cowboy::~Cowboy(){

    }

    int Cowboy::getAmountOfBalls(){
        return 0;
    }
    


}