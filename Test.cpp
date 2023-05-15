#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/SmartTeam.hpp"
#include "sources/Team2.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/YoungNinja.hpp"
using namespace ariel;
using namespace std;
TEST_CASE("Character Test") {
    Character character("John", Point(0, 0));

    SUBCASE("Getter Functions") {
        CHECK(character.getName() == "John");
        CHECK(character.getLocation() == Point(0, 0));
        CHECK(character.getHealth() == 0);
    }

    SUBCASE("Hit Function") {
        character.hit(10);
        CHECK(character.getHealth() == -10);
    }

    SUBCASE("Print Function") {
      string expectedOutput = "Name: John, Health: 0, Location: (0, 0), Alive: true";
        CHECK(character.print() == expectedOutput);
    }
}
TEST_CASE("Cowboy Test") {
    SUBCASE("Constructor and Getter Functions") {
        Point location(10, 20);
        ariel::Cowboy cowboy("John", location);

        CHECK(cowboy.getName() == "John");
        CHECK(cowboy.getLocation() == location);
        CHECK(cowboy.getHealth() == 0);
        CHECK(cowboy.getAmountOfBalls() == 0);
    }

    SUBCASE("Shoot and Has Bullets") {
        Point location(10, 20);
        ariel::Cowboy cowboy("John", location);

        CHECK_FALSE(cowboy.hasBullets());

        // Reload bullets
        cowboy.reload();
        CHECK(cowboy.hasBullets());

        // Create an enemy character
        Character enemy("Enemy", location);
        cowboy.shoot(&enemy);
        CHECK(enemy.getHealth() == -10);
    }
}

TEST_CASE("Ninja Test") {
    SUBCASE("Constructor and Getter Functions") {
        Point location(10, 20);
        Ninja ninja("Hanzo", location);

        CHECK(ninja.getName() == "Hanzo");
        CHECK(ninja.getLocation() == location);
        CHECK(ninja.getHealth() == 0);
        CHECK(ninja.getSpeed() == 0);
    }

    SUBCASE("Move and Slash") {
        Point location1(10, 20);
        Point location2(15, 25);
        Ninja ninja("Hanzo", location1);

        // Create another character
        Character enemy("Enemy", location2);
        enemy.setHealth(100);
       
        CHECK(ninja.distance(location2) == 5.0);

        // Move to the enemy
        ninja.move(&enemy);
        CHECK(ninja.getLocation() == location2);

        // Slash the enemy
        ninja.slash(&enemy);
        CHECK(enemy.getHealth() == 90);
    }

    SUBCASE("Setter and Getter Functions") {
        Point location(10, 20);
        Ninja ninja("Hanzo", location);

        ninja.setSpeed(50);
        CHECK(ninja.getSpeed() == 50);
    }
}
TEST_CASE("OldNinja Test") {
    SUBCASE("Constructor and Inheritance") {
        ariel::Point location(10, 20);
        ariel::OldNinja oldNinja("Hattori", location);

        CHECK(oldNinja.getName() == "Hattori");
        CHECK(oldNinja.getLocation() == location);
        CHECK(oldNinja.getHealth() == 0);
        CHECK(oldNinja.getSpeed() == 0);
    }
}
TEST_CASE("Point Test") {
    SUBCASE("Constructor and Getter") {
        ariel::Point point(3.5, 2.8);

        CHECK(point.getX_coord() == 3.5);
        CHECK(point.getY_coord() == 2.8);
    }

    SUBCASE("Distance Calculation") {
        ariel::Point point1(1.0, 2.0);
        ariel::Point point2(4.0, 6.0);

        CHECK(point1.distance(point2) == doctest::Approx(5.0).epsilon(0.0001));
    }

    SUBCASE("Move Towards Calculation") {
        ariel::Point point1(1.0, 1.0);
        ariel::Point point2(4.0, 5.0);
        ariel::Point targetPoint = point1.moveTowards(point1, point2);

        CHECK(targetPoint.getX_coord() == 2.0);
        CHECK(targetPoint.getY_coord() == 3.0);
    }

    SUBCASE("Equality Comparison") {
        ariel::Point point1(2.0, 3.0);
        ariel::Point point2(2.0, 3.0);
        ariel::Point point3(4.0, 6.0);

        CHECK(point1 == point2);
        CHECK(!(point1 == point3));
    }
}
TEST_CASE("SmartTeam Test") {
    SUBCASE("Constructor and Add Character") {
        SmartTeam smartTeam;

        CHECK(smartTeam.getTeamSize() == 0);

        ariel::Character* character = new ariel::Character("Character1", ariel::Point(1.0, 1.0));
        smartTeam.add(character);

        CHECK(smartTeam.getTeamSize() == 1);
    }

    SUBCASE("Remove Character") {
        ariel::SmartTeam smartTeam;

        ariel::Character* character1 = new ariel::Character("Character1", ariel::Point(1.0, 1.0));
        ariel::Character* character2 = new ariel::Character("Character2", ariel::Point(2.0, 2.0));

        smartTeam.add(character1);
        smartTeam.add(character2);

        CHECK(smartTeam.getTeamSize() == 2);

        smartTeam.remove(character1);

        CHECK(smartTeam.getTeamSize() == 1);
    }

    SUBCASE("Print Team") {
        ariel::SmartTeam smartTeam;

        ariel::Character* character1 = new ariel::Character("Character1", ariel::Point(1.0, 1.0));
        ariel::Character* character2 = new ariel::Character("Character2", ariel::Point(2.0, 2.0));

        smartTeam.add(character1);
        smartTeam.add(character2);

    }
}TEST_CASE("Team Test") {
    SUBCASE("Constructor and Add Character") {
        ariel::Team team;

        CHECK(team.getTeamSize() == 0);

        ariel::Character* character = new ariel::Character("Character1", ariel::Point(1.0, 1.0));
        team.add(character);

        CHECK(team.getTeamSize() == 1);
    }

    SUBCASE("Remove Character") {
        ariel::Team team;

        ariel::Character* character1 = new ariel::Character("Character1", ariel::Point(1.0, 1.0));
        ariel::Character* character2 = new ariel::Character("Character2", ariel::Point(2.0, 2.0));

        team.add(character1);
        team.add(character2);

        CHECK(team.getTeamSize() == 2);

        team.remove(character1);

        CHECK(team.getTeamSize() == 1);
    }

    SUBCASE("Attack Team") {
        ariel::Team team1;
        ariel::Team team2;

        ariel::Character* character1 = new ariel::Character("Character1", ariel::Point(1.0, 1.0));
        ariel::Character* character2 = new ariel::Character("Character2", ariel::Point(2.0, 2.0));

        team1.add(character1);
        team2.add(character2);

        CHECK(character1->getHealth() == 100);
        CHECK(character2->getHealth() == 100);

        team1.attack(&team2);

        CHECK(character1->getHealth() == 90);
        CHECK(character2->getHealth() == 90);
    }

    SUBCASE("Still Alive") {
        ariel::Team team;

        ariel::Character* character1 = new ariel::Character("Character1", ariel::Point(1.0, 1.0));
        ariel::Character* character2 = new ariel::Character("Character2", ariel::Point(2.0, 2.0));

        team.add(character1);
        team.add(character2);

        CHECK(team.stillAlive() == 2);

        character1->setHealth(0);

        CHECK(team.stillAlive() == 1);
    }

    SUBCASE("Print Team") {
        ariel::Team team;

        ariel::Character* character1 = new ariel::Character("Character1", ariel::Point(1.0, 1.0));
        ariel::Character* character2 = new ariel::Character("Character2", ariel::Point(2.0, 2.0));

        team.add(character1);
        team.add(character2);

    }
}
TEST_CASE("Team2 Test") {
    SUBCASE("Constructor and Add Character") {
        ariel::Team2 team;

        CHECK(team.getTeamSize() == 0);

        ariel::Character* character = new ariel::Character("Character1", ariel::Point(1.0, 1.0));
        team.add(character);

        CHECK(team.getTeamSize() == 1);
    }

    SUBCASE("Remove Character") {
        ariel::Team2 team;

        ariel::Character* character1 = new ariel::Character("Character1", ariel::Point(1.0, 1.0));
        ariel::Character* character2 = new ariel::Character("Character2", ariel::Point(2.0, 2.0));

        team.add(character1);
        team.add(character2);

        CHECK(team.getTeamSize() == 2);

        team.remove(character1);

        CHECK(team.getTeamSize() == 1);
    }

    SUBCASE("Attack Team") {
        Team2 team1;
        Team2 team2;

        Character* character1 = new Character("Character1", Point(1.0, 1.0));
        Character* character2 = new Character("Character2", Point(2.0, 2.0));

        team1.add(character1);
        team2.add(character2);

        CHECK(character1->getHealth() == 100);
        CHECK(character2->getHealth() == 100);

        team1.attack(&team2);

        CHECK(character1->getHealth() == 90);
        CHECK(character2->getHealth() == 90);
    }

    SUBCASE("Still Alive") {
        Team2 team;

        Character* character1 = new Character("Character1", Point(1.0, 1.0));
        Character* character2 = new Character("Character2", Point(2.0, 2.0));

        team.add(character1);
        team.add(character2);

        CHECK(team.stillAlive() == 2);

        character1->setHealth(0);

        CHECK(team.stillAlive() == 1);
    }

    SUBCASE("Print Team") {
        Team2 team;

        Character* character1 = new Character("Character1", Point(1.0, 1.0));
        Character* character2 = new Character("Character2", Point(2.0, 2.0));

        team.add(character1);
        team.add(character2);

    }
}
TEST_CASE("TrainedNinja Test") {
    SUBCASE("Constructor and Getters") {
        Point location(1.0, 1.0);
        TrainedNinja ninja("Ninja1", location);

        CHECK(ninja.getName() == "Ninja1");
        CHECK(ninja.getLocation() == location);
        CHECK(ninja.getSpeed() == 0);
    }

    SUBCASE("Move and Slash") {
        ariel::Point location1(1.0, 1.0);
        ariel::Point location2(2.0, 2.0);
        ariel::TrainedNinja ninja("Ninja1", location1);

        ariel::Character* enemy = new ariel::Character("Enemy", location2);

        ninja.move(enemy);
        CHECK(ninja.getLocation() == location2);

        enemy->setHealth(50);
        ninja.slash(enemy);
        CHECK(enemy->getHealth() == 40);
    }

    SUBCASE("Setter and Getters") {
        ariel::Point location(1.0, 1.0);
        ariel::TrainedNinja ninja("Ninja1", location);

        ninja.setSpeed(10);
        CHECK(ninja.getSpeed() == 10);
    }
}
TEST_CASE("YoungNinja Test") {
    SUBCASE("Constructor and Getters") {
        ariel::Point location(1.0, 1.0);
        ariel::YoungNinja ninja("Ninja1", location);

        CHECK(ninja.getName() == "Ninja1");
        CHECK(ninja.getLocation() == location);
        CHECK(ninja.getSpeed() == 0);
    }

    SUBCASE("Move and Slash") {
        ariel::Point location1(1.0, 1.0);
        ariel::Point location2(2.0, 2.0);
        ariel::YoungNinja ninja("Ninja1", location1);

        ariel::Character* enemy = new ariel::Character("Enemy", location2);

        ninja.move(enemy);
        CHECK(ninja.getLocation() == location2);

        enemy->setHealth(50);
        ninja.slash(enemy);
        CHECK(enemy->getHealth() == 40);
    }

    SUBCASE("Setter and Getters") {
        ariel::Point location(1.0, 1.0);
        ariel::YoungNinja ninja("Ninja1", location);

        ninja.setSpeed(10);
        CHECK(ninja.getSpeed() == 10);
    }
}




