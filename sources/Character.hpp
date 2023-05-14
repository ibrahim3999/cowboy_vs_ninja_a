#pragma once 
#include "Point.hpp"
#include <string>
using namespace  std;
namespace ariel{

    class Character{
        
        private:
            Point location;
            string name;
            int health;
        
        public:
            Character();
            Character(string name , const Point& point1);

            //setter 
            void setHealth();

            //getter
            Point getLoction();
            string getName();
            int getHealth();

            bool isAlive();// return true if Characater health>0
            double distance (const Point& point1);// distance between 2 characters
            virtual void hit(int num); // reduce the health of the character 
            virtual string print();// print: name , health ,location , isAlive() 
            ~Character();



    };
}