#include "Character.hpp"
#include <iostream>
using namespace  std;


namespace ariel{

    class Cowboy : public Character{

        public:
            Cowboy(string ,const Point&);
            ~Cowboy();
            void shoot(Character * enemy);// reduce 10 health from other character ...
            bool hasbullets();// reutrn true if the cowboy have bullets in the weapon
            void reload(); // reload balls to the weapon

            //getter 

            int getAmountOfBalls();// amount balls

        private:
            int amountOfBalls;

    };

}