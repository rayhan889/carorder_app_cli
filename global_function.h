#ifndef GLOBAL_FUNCTION_H_INCLUDED
#define GLOBAL_FUNCTION_H_INCLUDED
#include <string>
#include <iostream>
#include <conio.h>
#include <chrono>
#include <ctime>
#include "Date.h"

using namespace std;

// FUNCTION PROPS
void welcome();
void header(string);
void dashboardAdmin(const string &admin_name);
void dashboardUser(const string &user_name);
bool isAdmin(string);
string generateDriverID(const string &name, char gender, Date date, int last_digit);
string generateOrderID(const string &plate, const string &id_driver, const string &destination);
string makeTime();
// FUNCTION PROPS

#endif // GLOBAL_FUNCTION_H_INCLUDED
