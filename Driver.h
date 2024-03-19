#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED
#include <iostream>
#include <string>
#include <conio.h>
#include "global_function.h"
#include "Date.h"

using namespace std;

struct DriverNode {
    string id;
    string name;
    string address;
    char gender;
    Date birthdate;
    DriverNode *next;
};

class Driver
{
    private:
        DriverNode *head, *tail;
    public:
        Driver()
        {
            head=NULL;
            tail=NULL;
        }
        DriverNode *getHead() const
        {
            return head;
        }
        DriverNode *getTail() const
        {
            return tail;
        }
        void createNode(const string &name, const string &address, char gender, const Date &birthdate);
        void addForm();
        void displayAll();
        void showDriverProperties(const DriverNode *data);
        void displayOne(DriverNode *data);
        DriverNode *searchOne(const string &id);
        string incDuplicate(const string &id);
        void paginate();
        int countNodes();
        void updateForm();
        void deleteNode(const string &id);
        template <typename T>
        void updateNode(int option, T new_value, DriverNode *old_node);
};

#endif // DRIVER_H_INCLUDED
