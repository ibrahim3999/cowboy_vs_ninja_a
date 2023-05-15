#pragma once
#include <iostream>
namespace ariel {

    class Point {

    private:
        double x_coord;
        double y_coord;

    public:
        Point();

        Point(double x_coord, double y_coord);

        double distance(const Point& other);//return the distance stance between 2 points 
        
        Point moveTowards(const Point& point1, const Point& point2);// return the closet point 
        
        void print() ;//printf Point 

        bool operator==(const Point& other) const ;

        //getter and setter
        double getX_coord();
        double getY_coord();

        
    };
}


