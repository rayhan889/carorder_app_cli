#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED
#include <string>
#include <iostream>
#include <string>
#include <conio.h>
#include "Driver.h"
#include "Car.h"
#include "global_function.h"
#include "Date.h"

using namespace std;

using namespace std;

struct OrderNode {
    string id;
    string nama;
    DriverNode *driver;
    string destination;
    string order_time;
    OrderNode *next;
};

class Order
{
    private:
        OrderNode *front, *rear;
        Driver *driver;
        Car *car;
    public:
        Order(Driver *d, Car *c)
        {
            front=rear=NULL;
            driver=d;
            car=c;
        }
        DriverNode *getDriverClassHead()
        {
            return driver->getHead();
        }
        DriverNode *getDriverClassTail()
        {
            return driver->getTail();
        }
        int getAmountOfCars()
        {
            return car->countNodes();
        }
        void getDriverProperties(DriverNode *data)
        {
            if(driver)
                 driver->showDriverProperties(data);
            else
                cout << "	Class Driver tidak terinisialisasi " << endl;
        }
        void enqueue(const string &name, DriverNode *driver, const string &destination);
        void orderForm(DriverNode *driver);
        void paginateAllDrivers();
        void showOrderProperties(const OrderNode *data);
        void showFirstOrder();
        int countNodes();
        void history();
        int dequeue();
        void display();
};

#endif // ORDER_H_INCLUDED
