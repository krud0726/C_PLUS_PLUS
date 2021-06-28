//
// Created by User on 2021-06-28.
//
#include "shape.h"
#include <iostream>
#include <map>
using namespace std;

unique_ptr<Rectangle> make_rectangle(){
    // 포인터 변수 선언
    unique_ptr<Rectangle> rec(new Rectangle);
    // 입력 받기
    cin >> rec->width >> rec->height;
    rec->area = (rec->width) * (rec->height);

    return rec;
}


unique_ptr<Circle> make_circle(){
    unique_ptr<Circle> cir(new Circle);

    cin >> cir->radius;
    cir->area = static_cast<double>((cir->radius)*(cir->radius)*3.14);

    return cir;

}

Command getCommand(const string& command)
{

    if(command == "rect")
    {
        return RECT;
    }
    else if(command == "circle")
    {
        return CIRCLE;
    }
    else if(command == "print")
    {
        return PRINT;
    }
    else if(command == "sum")
    {
        return SUM;
    }
    else if(command == "sort")
    {
        return SORT;
    }
    else if(command == "clear")
    {
        return CLEAR;
    }
    else if(command == "quit")
    {
        return QUIT;
    }
    else
    {
        return INVALID;
    }

}