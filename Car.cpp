#include "Car.h"
#include <vector>

// CAR CLASS PROPS
int Car::isEmpty()
{
    if(top==NULL)
        return 1;

    return 0;
}

int Car::isFull(CarNode *p)
{
    if(p==NULL)
        return 1;

    return 0;
}

void Car::push(CarData data)
{
    CarNode *new_car;
    new_car=new CarNode;
    int status=0;

    if(isFull(new_car)==1)
    {
        cout << "	Stack penuh!";
        getch();
    }
    else
    {
        new_car->data.plate_num=data.plate_num;
        new_car->data.type=data.type;
        new_car->data.brand=data.brand;
        new_car->next=top;
        top=new_car;
        status=1;
    }

    if(status==1)
    {
        cout << "\n	Unit Mobil Berhasil Ditambahkan!"<<endl;
        getch();
    }
    else
    {
        cout << "\n	Unit Mobil GAGAL Ditambahkan!"<<endl;
        getch();
    }
}

int Car::pop()
{
    CarNode *t=top;
    CarData c_dt;

    if(isEmpty()==1)
        return 0;
    else
    {
        c_dt=top->data;
        TEMP_CARS_LIST.push_back(c_dt);
        top=top->next;
        delete t;
    }
    return 1;
}

void Car::display()
{
    system("cls");
	welcome();
	header("List Kendaraan");
    cout << endl;
    CarNode *current=top;

    int no=1;

    if(current==NULL)
    {
        cout << "	List kendaraan kosong, tambahkan kendaraan terlebih dahulu! "<<endl;
        getch();
    }
    else
    {
        int count_orders=countNodes();
        cout << "	Jumlah Kendaraan : "<<count_orders<<endl;
        while(current!=NULL)
        {
            cout << "     " << no++ << ". " << endl;
            showCarProperties(current);
            current=(*current).next;
        }
        cout << endl;
    }
}

void Car::showCarProperties(const CarNode *data)
{
    cout << "	Plat Nomor          : "<<data->data.plate_num<<endl;
    cout << "	Brand Mobil         : "<<data->data.brand<<endl;
    cout << "	Tipe                : "<<data->data.type<<endl;
    cout << endl;
}

int Car::countNodes()
{
    CarNode *current=top;

    int counter=0;
    while(current!=NULL)
    {
        counter++;
        current=(*current).next;
    }
    return counter;
}

void Car::pushForm()
{
    system("cls");
	welcome();
	header("Tambah Unit Mobil");
    cout << endl;

    CarData c_dt;

    cout << "	Masukkan plat nomor mobil    : ";
    cin.ignore();
    getline(cin, c_dt.plate_num);

    cout << "	Masukkan tipe mobil          : ";
    getline(cin, c_dt.type);

    cout << "	Masukkan brand mobil         : ";
    getline(cin, c_dt.brand);

    push(c_dt);
}

CarData Car::stackTop()
{
    CarData c_dt;
    if(top)
    {
        c_dt=top->data;
    }
    return c_dt;
}
// CAR CLASS PROPS
