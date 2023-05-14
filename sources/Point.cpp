#include "Point.hpp"
#include <cmath>

namespace ariel{
    //cons...
    Point::Point():x_coord(0),y_coord(0){

    }

    Point::Point(double x_coord, double y_coord):x_coord(x_coord),y_coord(y_coord){

    }

    double Point::distance(const Point& other){
        return 0;
    }

    Point Point::moveTowards(const Point& point1, const Point& point2){
        return Point();
    }
        
    void print(){

    };

}