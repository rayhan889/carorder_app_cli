#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include <iostream>
#include <string>
#include <conio.h>
#include "global_function.h"
#include "global_variable.h"
#include "Date.h"

using namespace std;

struct CarNode {
    CarData data;
    CarNode *next;
};

class Car
{
    private:
        CarNode *top;
    public:
        Car()
        {
            top=NULL;
        }
        void pushForm();
        void push(CarData data);
        int pop();
        void display();
        int isEmpty();
        int isFull(CarNode *p);
        int countNodes();
        void showCarProperties(const CarNode *data);
        CarData stackTop();
};

#endif // CAR_H_INCLUDED
