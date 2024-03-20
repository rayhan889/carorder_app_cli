#ifndef GLOBAL_VARIABLE_H_INCLUDED
#define GLOBAL_VARIABLE_H_INCLUDED
#include <string>
#include <vector>

using namespace std;

struct CarData {
    string plate_num;
    string type;
    string brand;
};

inline string ADMINS[]={"Anies", "Ganjar", "Prabowo"};
inline bool IS_ADMIN_LOGGED_IN=false;
inline string NAME_INPUT;
inline vector<CarData> TEMP_CARS_LIST;

#endif // GLOBAL_VARIABLE_H_INCLUDED
