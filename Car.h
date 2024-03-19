#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include <iostream>
#include <string>
#include <conio.h>
#include "global_function.h"
#include "Date.h"

using namespace std;

struct CarNode {
    string plate_num;
    string type;
    string brand;
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
        void push(const string &plate_num, const string &type, const string &brand);
        CarNode *pop();
        void display();
        int isEmpty();
        int isFull(CarNode *p);
        int countNodes();
        void showCarProperties(const CarNode *data);
};

#endif // CAR_H_INCLUDED
