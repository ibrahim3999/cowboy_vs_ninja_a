#include "Character.hpp"

namespace ariel{

    Character::Character(){

    }

    Character::Character(string name , const Point &location):name(name),location(location){

    }

    bool Character::isAlive(){
        return true;
    }
    double Character::distance (const Point& point1){
        return 0;
    }
   
    //setter

    void setHealth(int health){

    }


    //getter
    Point Character::getLoction(){
        return location;
    }

    string Character::getName(){
        return name;
        
    }
    int Character::getHealth(){
        return health;
    }


}
           
           
           
        
        