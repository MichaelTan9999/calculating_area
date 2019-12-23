//
//  shapes.cpp
//  calculation_review
//
//  Created by Michael Tan on 2019/12/11.
//  Copyright © 2019 MichaelTan9999. All rights reserved.
//

#include <iostream>

using namespace std;

class quadrangle
{
private:
    string name;
    bool correct;
public:
    virtual double area() const = 0;
    virtual void print_question() const = 0;
    void right()
    {
        correct = true;
    }
    void wrong()
    {
        correct = false;
    }
    string get_shape() const
    {
        return name;
    }
    bool performance()
    {
        return correct;
    }
    quadrangle(string n) : name(n){};
    virtual ~quadrangle(){}
};

class parallelogram : public quadrangle
{
public:
    double height, width;

    double area() const override
    {
        return double(height * width);
    }

    parallelogram(double h = 1, double w = 1, string n = "parallelogram") : quadrangle(n)
    {
        height = h;
        width = w;
    }
    
    void print_question() const override
    {
        cout << get_shape() << ": width=" << width << ", height=" << height << ", area=";
    }
};

class diamond : virtual public parallelogram
{
public:
    diamond(double diagonal_1 = 1, double diagonal_2 = 1, string n = "diamond") : parallelogram(diagonal_1, diagonal_2, n){}
    
    double area() const override
    {
        return parallelogram::area() / 2;
    }
    
    void print_question() const override
    {
        cout << get_shape() << ": first diagonal=" << width << ", second diagonal=" << height << ", area=";
    }
    
};

class rectangle : virtual public parallelogram
{
public:
    rectangle(double h = 1, double w = 1, string n = "rectangle") : parallelogram(h, w, n){}
};

class square : public rectangle, public diamond
{
public:
    square(double side = 1, string n = "square") : parallelogram(side, side, n){}
    
    void print_question() const override
    {
        cout << get_shape() << ": side=" << width << ", area=";
    }

    double area() const override
    {
        return rectangle::area();
    }
};

class trapezoid : public quadrangle
{
public:
    double height, upperside, lowerside;

    trapezoid(double h, double uside, double lside, string n = "trapezoid") : quadrangle(n)
    {
        height = h;
        upperside = uside;
        lowerside = lside;
    }
    
    double area() const override
    {
        return (upperside + lowerside) * height / 2;
    }
    
    void print_question() const override
    {
        cout << get_shape() << ": first width=" << upperside <<", second width=" << lowerside <<", height=" << height <<", area=";
    }
};


