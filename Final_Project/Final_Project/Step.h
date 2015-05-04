//
//  Step.h
//  Final_Project
//
//  Created by Gonzalo Vergara on 5/4/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef Final_Project_Step_h
#define Final_Project_Step_h

class Step{
private:
    double xi = 0;
    double yi = 0;
    double x1 = 0;
    double y1 = 0;
    double a = 0;
    double b = 0;
    double c = 0;
    double th1 = 0;
    double th2 = 0;
    
public:
    Step() {}
    virtual ~Step();
    
    Step(double _xi, double _yi, double _x1, double _y1, double _a, double _b, double _c, double _th1, double _th2) : xi(_xi), yi(_yi), x1(_x1), y1(_y1), a(_a), b(_b), c(_c), th1(_th1), th2(_th2){}
    
    double getXi(){return xi;};
    double getYi(){return yi;}
    double getX1(){return x1;};
    double getY1(){return y1;}
    double getA(){return a;}
    double getB(){return b;}
    double getC(){return c;}
    double getTh1(){return th1;}
    double getTh2(){return th2;}
    
    void setX1(double value){x1 = value;};
    void setY1(double value){y1 = value;};
    void setXi(double value){xi = value;};
    void setYi(double value){yi = value;};
    void setA(double value){a = value;};
    void setB(double value){b = value;};
    void setC(double value){c = value;};
    void setTh1(double value){th1 = value;};
    void setTh2(double value){th2 = value;};
    
    friend std::ostream & operator << (std::ostream & os, Step  & step);
    
};
std::ostream & operator << (std::ostream & os, Step  & step)
{
    os << "xi: " << step.xi << ", yi: " << step.yi;
    os << ", x1: " << step.x1 << ", y1: " << step.y1;
    os << ", a: " << step.a << ", b: " << step.b << ", c: " << step.c;
    os << ", th1: " << step.th1 << ", th2: " << step.th2 << std::endl;
    return os;
}
Step::~Step(){
    xi = yi = x1 = y1 = a = b = c = th1 = th2 =  0;
}

#endif
