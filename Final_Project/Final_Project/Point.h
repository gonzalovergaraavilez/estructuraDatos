//
//  Point.h
//  Final_Project
//
//  Created by Gonzalo Vergara on 5/4/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef Final_Project_Point_h
#define Final_Project_Point_h

class Point{
private:
    double x = 0;
    double y = 0;
    int z = 0;
    int s = 1;
    double x_new = 0;
    double y_new = 0;
    int z_new = 0;
    int s_new = 1;
public:
    Point() {}
    virtual ~Point();
    
    Point(double _x, double _y) : x(_x), y(_y){}
    
    double getX(){return x;};
    double getY(){return y;}
    double getXN(){return x_new;};
    double getYN(){return y_new;}
    void setX(double value){x = value;};
    void setY(double value){y = value;};
    void setXN(double value){x_new = value;};
    void setYN(double value){y_new = value;};
    
    friend std::ostream & operator << (std::ostream & os, Point  & point);
    
};
std::ostream & operator << (std::ostream & os, Point  & point)
{
    os << "Punto en x: " << point.x << ", y: " << point.y << std::endl;
    os << "Nuevas coordenadas x: " << point.x_new << ", y: " << point.y_new << std::endl;
    return os;
}
Point::~Point(){
    x = y = z = s = x_new = y_new = z_new = s_new =  0;
}


#endif
