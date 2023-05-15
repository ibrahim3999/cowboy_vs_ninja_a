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
        
    void Point::print(){

    };

    bool Point::operator==(const Point& other) const {
            return x_coord == other.x_coord && y_coord == other.y_coord;
        
    }
    double  Point::getX_coord(){
        return x_coord;
    }
    double  Point::getY_coord(){
        return y_coord;
    }

}