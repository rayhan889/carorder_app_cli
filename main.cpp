#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
#include "Driver.h"
#include "Order.h"
#include "Car.h"
#include "global_variable.h"

using namespace std;

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
                                    int status=0;
                                    status=c.pop();
                                    if(status==0)
                                    {
                                        cout << "	Unit mobil sedang kosong!" << endl;
                                        getch();
                                    }
                                    else
                                    {
                                        cout << "	Berhasil mengeluarkan mobil!" << endl;
                                        getch();
                                    }
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
