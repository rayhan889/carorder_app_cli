#include "Order.h"
#include "global_variable.h"

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
