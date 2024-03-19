#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
#include "Driver.h"
#include "global_variable.h"

using namespace std;

struct OrderNode {
    string id;
    string nama;
    DriverNode *driver;
    string destination;
    string order_time;
    OrderNode *next;
};

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

int main()
{
    Driver d;
    Car c;
    Order o(&d, &c);
    int option;

    do
    {
        system("cls");
        welcome();
        cout << "	1. Admin Dashboard" << endl;
        cout << "	2. Pesan Go-car" << endl;
        cout << "	0. Exit" << endl;
        cout << endl;
        cout << "	Masukkan pilihanmu : ";
        cin >> option;

        switch(option)
        {
            case 1:
                {
                    system("cls");
                    welcome();
                    header("Admin Login");
                    printf("	Masukkan nama anda : ");
                    cin.ignore();
                    getline(cin, NAME_INPUT);

                    if(isAdmin(NAME_INPUT))
                    {
                        do
                        {
                            dashboardAdmin(NAME_INPUT);
                            cout << "	Masukkan pilihanmu : ";
                            cin >> option;

                            switch(option)
                            {
                            case 1:
                                d.addForm();
                                break;
                            case 2:
                                {
                                    d.displayAll();
                                    cout << "	Ketik enter untuk kembali!" << endl;
                                    getch();
                                }
                                break;
                            case 3:
                                {
                                    int count_nodes=d.countNodes();
                                    if(count_nodes==0)
                                    {
                                        cout << "	List driver kosong, tambahkan driver terlebih dahulu! "<<endl;
                                        getch();
                                    }
                                    else
                                    {
                                        struct DriverNode *found_driver;
                                        string id;
                                        cout << "	Masukkan ID Driver : ";
                                        cin.ignore(); getline(cin, id);
                                        found_driver=d.searchOne(id);
                                        if(found_driver==NULL)
                                        {
                                            cout << "\n	Driver dengan ID : "<<id<<" tidak ditemukan!!";
                                            getch();
                                        }
                                        else
                                            d.displayOne(found_driver);
                                    }
                                    break;
                                }
                            case 4:
                                d.paginate();
                                break;
                            case 5:
                                {
                                    d.updateForm();
                                    break;
                                }
                            case 6:
                                {
                                    int count_nodes=d.countNodes();
                                    if(count_nodes==0)
                                    {
                                        cout << "	List driver kosong, tambahkan driver terlebih dahulu! "<<endl;
                                        getch();
                                    }
                                    else
                                    {
                                        struct DriverNode *found_driver;
                                        string id;
                                        d.displayAll();
                                        cout << "	Masukkan ID Driver : ";
                                        cin.ignore(); getline(cin, id);
                                        found_driver=d.searchOne(id);
                                        if(found_driver==NULL)
                                        {
                                            cout << "\n	Driver dengan ID : "<<id<<" tidak ditemukan!!";
                                            getch();
                                        }
                                        else
                                        {
                                            char y_n='N';
                                            cout << "\n	Yakin ingin menghapus? (Y/N) : ";
                                            cin>>y_n;
                                            if(y_n=='Y' || y_n=='y')
                                                d.deleteNode((*found_driver).id);
                                            else if(y_n=='N' || y_n=='n')
                                                cout << "\n	Data driver tidak jadi dihapus! ";
                                            else
                                                cout << "\n	Invalid choice! ";
                                            getch();
                                        }
                                    }
                                    break;
                                }
                            case 7:
                                o.showFirstOrder();
                                break;
                            case 8:
                                c.pushForm();
                                break;
                            case 9:
                                {
                                    c.display();
                                    cout << "	Ketik enter untuk kembali!" << endl;
                                    getch();
                                    break;
                                }
                            case 10:
                                {
                                    CarNode *car=NULL;
                                    car=c.pop();
                                    if(car==NULL)
                                    {
                                        cout << "	Gagal mengeluarkan mobil!" << endl;
                                        getch();
                                    }
                                    else
                                        c.showCarProperties(car);
                                    break;
                                }
                            default:
                                printf("Invalid Choice...");
                            }
                        }while(option!=11);
                    }
                    break;
                }
                case 2:
                    {
                        system("cls");
                        welcome();
                        header("User Login");
                        printf("	Masukkan nama anda : ");
                        cin.ignore();
                        getline(cin, NAME_INPUT);

                        if(!NAME_INPUT.empty())
                        {
                            IS_ADMIN_LOGGED_IN=false;
                            do
                            {
                                dashboardUser(NAME_INPUT);
                                cout << "	Masukkan pilihanmu : ";
                                cin >> option;

                                switch(option)
                                {
                                    case 1:
                                        o.paginateAllDrivers();
                                        break;
                                    case 2:
                                        {
                                            o.display();
                                            cout << "	Ketik enter untuk kembali!" << endl;
                                            getch();
                                            break;
                                        }
                                    case 3:
                                        break;
                                }
                            }while(option!=3);
                        }
                        break;
                    }
        }
    }while(option!=0);

    return 0;
}

// ORDER CLASS PROPS
void Order::showOrderProperties(const OrderNode *data)
{
    cout << "	ID                  : "<<data->id<<endl;
    cout << "	Nama Pelanggan      : "<<data->nama<<endl;
    cout << "	Tujuan              : "<<data->destination<<endl;
    cout << "	Nama Driver         : "<<data->driver->name<<endl;
    cout << "	Waktu Order         : "<<data->order_time<<endl;
    cout << endl;
}

void Order::enqueue(const string &name, DriverNode *driver, const string &destination)
{
    string coded_id;
    OrderNode *new_node;
    new_node=new OrderNode;
    if(new_node==NULL)
        cout << "\n	Antrian Penuh" << endl;
    else
    {
        coded_id=generateOrderID("L 1234 MM", (*driver).id, destination);

        new_node->id=coded_id;
        new_node->nama=NAME_INPUT;
        new_node->driver=driver;
        new_node->destination=destination;
        new_node->order_time=makeTime();
        new_node->next=NULL;

        if(front==NULL)
            front=rear=new_node;
        else
        {
            rear->next=new_node;
            rear=new_node;
        }

        system("cls");
        welcome();
        header("Rangkuman Order");
        cout << endl;
        showOrderProperties(new_node);

        cout << "\n	Order Berhasil Dilakukan!"<<endl;
        getch();
    }
}

int Order::dequeue()
{
    OrderNode *p;
    if(front==NULL)
        return 0;
    else
    {
        p=front;
        front=front->next;
        delete p;
    }
    return 1;
}

void Order::orderForm(DriverNode *driver)
{
    string input_destination;

    cout << "\n	Masukkan Tujuan Anda : ";
    cin.ignore();
    getline(cin, input_destination);

    enqueue(NAME_INPUT, driver, input_destination);
}

void Order::paginateAllDrivers()
{
    DriverNode *current=getDriverClassHead();
    int option;

    if(current!=NULL)
    {
        do
        {
            system("cls");
            welcome();
            header("Pilih Driver Anda");
            cout << endl;
            getDriverProperties(current);

            cout << "	1. Next " << endl;
            cout << "	2. Previous " << endl;
            cout << "	3. Order " << endl;
            cout << "	4. Kembali " << endl;
            cout << "	Masukkan pilihanmu : ";
            scanf("%d", &option);

            switch(option)
            {
                case 1:
                    if((*current).next!=NULL)
                        current=(*current).next;
                    else
                        current=getDriverClassHead();
                    break;
                case 2:
                    if(current!=getDriverClassHead())
                    {
                        struct DriverNode *prev=getDriverClassHead();
                        while((*prev).next!=current)
                            prev=(*prev).next;
                        current=prev;
                    }
                    else
                        current=getDriverClassTail();
                    break;
                case 3:
                    {
                        if(getAmountOfCars()<1)
                        {
                            cout << "	Tidak dapat melakukan order, kendaraan sedang tidak tersedia...";
                            getch();
                        }
                        else
                            orderForm(current);
                        break;
                    }
                case 4:
                    break;
                default:
                    printf("\nInvalid choice...");
            }
        }while(option!=4);
    }
    else
    {
        cout << "	List driver kosong. "<<endl;
        getch();
    }
}

void Order::showFirstOrder()
{
    OrderNode *current=front;
    int option;
    char y_n;

    if(current!=NULL)
    {
        do
        {
            system("cls");
            welcome();
            header("List Order(Pagination Mode)");
            cout << endl;
            if(current!=NULL)
            {
                showOrderProperties(current);
            }
            else
            {
                cout << "	Tidak ada pesanan yang tersedia..." << endl;
            }

            if(current!=NULL)
            {
                cout << "	1. Approve " << endl;
                cout << "	2. Reject " << endl;
            }
            cout << "	3. Kembali " << endl;
            cout << "	Masukkan pilihanmu : ";
            scanf("%d", &option);

            switch(option)
            {
                case 1:
                    {
                        int status=0;
                        cout << "	Approve pesanan? (Y/N)";
                        cin >> y_n;

                        if(y_n=='Y'||y_n=='y')
                            status=dequeue();
                        else
                        {
                            cout << "	Approving dibatalkan" << endl;
                            getch();
                        }

                        if(status==1)
                        {
                             cout << "	Pesanan BERHASIL di approve" << endl;
                             getch();
                        }
                        else
                        {
                            cout << "	Pesanan GAGAL di approve" << endl;
                             getch();
                        }
                        break;
                    }
                case 2:
                    {
                        int status=0;
                        cout << "	Decline pesanan? (Y/N)";
                        cin >> y_n;

                        if(y_n=='Y'||y_n=='y')
                            status=dequeue();
                        else
                        {
                            cout << "	Decline dibatalkan" << endl;
                            getch();
                        }

                        if(status==1)
                        {
                             cout << "	Pesanan BERHASIL di decline" << endl;
                             getch();
                        }
                        else
                        {
                            cout << "	Pesanan GAGAL di decline" << endl;
                             getch();
                        }
                        break;
                    }
                case 3:
                    break;
                default:
                    printf("\nInvalid choice...");
            }
            current=front;
        }while(option!=3);
    }
}

void Order::display()
{
    system("cls");
	welcome();
	header("Pesanan Anda");
    cout << endl;
    OrderNode *current=front;
    int no=1;

    if(current==NULL)
    {
        cout << "	Pesanan anda kosong, buat pesanan terlebih dahulu! "<<endl;
        getch();
    }
    else
    {
        int count_orders=countNodes();
        cout << "	Jumlah Pesanan : "<<count_orders<<endl;
        while(current!=NULL)
        {
            cout << "     " << no++ << ". " << endl;
            showOrderProperties(current);
            current=(*current).next;
        }
        cout << endl;
    }
}

int Order::countNodes()
{
    OrderNode *current=front;

    int counter=0;
    while(current!=NULL)
    {
        counter++;
        current=(*current).next;
    }
    return counter;
}
// ORDER CLASS PROPS

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
