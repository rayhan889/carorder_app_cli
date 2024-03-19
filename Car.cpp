#include "Car.h"

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

void Car::push(const string &plate_num, const string &type, const string &brand)
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
        new_car->plate_num=plate_num;
        new_car->type=type;
        new_car->brand=brand;
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

CarNode *Car::pop()
{
    CarNode *t=top;
    CarNode *x=NULL;

    if(isEmpty()==1)
        return x;
    else
    {
        x->brand=top->brand;
        x->plate_num=top->plate_num;
        x->type=top->type;
        x->next=NULL;
        top=top->next;
        delete t;
    }
    return x;
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
    cout << "	Plat Nomor          : "<<data->plate_num<<endl;
    cout << "	Brand Mobil         : "<<data->brand<<endl;
    cout << "	Tipe                : "<<data->type<<endl;
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

    string plate_num, type, brand;

    cout << "	Masukkan plat nomor mobil    : ";
    cin.ignore();
    getline(cin, plate_num);

    cout << "	Masukkan tipe mobil          : ";
    getline(cin, type);

    cout << "	Masukkan brand mobil         : ";
    getline(cin, brand);

    push(plate_num, type, brand);
}
// CAR CLASS PROPS
