#include "Driver.h"

// DRIVER CLASS PROPS

string Driver::incDuplicate(const string &id)
{
    DriverNode *current = head;
    string new_id;
    //cout << "\nID : " << id << " duplicate.." << endl;
    int max_num = stoi(id);
    string temp_str=to_string(max_num);
    int length_of_str_num = temp_str.length();

    while (current != NULL)
    {
        int current_num = stoi((*current).id);
        if ((current_num-max_num)==1)
        {
            max_num = current_num;
        }
        current = (*current).next;
    }
    int inc_num = max_num + 1;

    //cout << "After Increment ID : " << inc_num << endl;
    string inc_str_num = to_string(inc_num);

    if (length_of_str_num == 4)
        return new_id = "0" + inc_str_num;
    else
        return new_id = inc_str_num;
}


DriverNode *Driver::searchOne(const string &id)
{
    DriverNode *current=head;
    while(current!=NULL)
    {
        if((*current).id==id)
            return current;
        current=(*current).next;
    }

    return NULL;
};

void Driver::displayOne(DriverNode *data)
{
    system("cls");
	welcome();
	header("Data Driver");
    cout << endl;
    showDriverProperties(data);
    cout << "	Ketik enter untuk kembali!";
    getch();
}

void Driver::createNode(const string &name, const string &address, char gender, const Date &birthdate)
{
    DriverNode *new_node, *found_node;
    string coded_id;
    string new_inc_id;

    new_node=new DriverNode;
    tail=head;

    coded_id=generateDriverID(name, gender, birthdate, 0);
    found_node=searchOne(coded_id);

    if(found_node!=NULL)
    {
        new_inc_id=incDuplicate((*found_node).id);
        //cout<<"\nNew ID after increment : "<<new_inc_id<<endl;
    }

    (*new_node).id=found_node!=NULL ? new_inc_id : coded_id;
    (*new_node).name=name;
    (*new_node).address=address;
    (*new_node).gender=gender;
    (*new_node).birthdate=birthdate;
    (*new_node).next=NULL;

    if(head==NULL)
        head=new_node;
    else
    {
        while((*tail).next!=NULL)
        {
            tail=(*tail).next;
        }
        (*tail).next=new_node;
    }
}

void Driver::addForm()
{
    system("cls");
	welcome();
	header("Tambah Data Driver");
    cout << endl;
    string name, address;
    char gender;
    Date birthdate;

    cout << "	Masukkan nama                : ";
    cin.ignore();
    getline(cin, name);

    cout << "	Masukkan alamat              : ";
    getline(cin, address);

    cout << "	Masukkan jenis kelamin (L/P) : ";
    scanf("%c", &gender);

    cout << "	Masukkan tgl lahir           : ";
    scanf("%d %d %d", &birthdate.day, &birthdate.month, &birthdate.year);

    createNode(name, address, gender, birthdate);

    cout << endl;
    cout << "	Berhasil menambahkan data!!";
    getch();
}

void Driver::showDriverProperties(const DriverNode *data)
{
    cout << "	ID                  : "<<data->id<<endl;
    cout << "	Nama                : "<<data->name<<endl;
    cout << "	Alamat              : "<<data->address<<endl;
    cout << "	Jenis Kelamin (L/P) : "<<data->gender<<endl;
    cout << "	Tanggal Lahir       : "<<data->birthdate.day<<" "<<data->birthdate.month<<" "<<data->birthdate.year;
    cout << endl;
}

void Driver::displayAll()
{
    system("cls");
	welcome();
	header("List Driver");
    cout << endl;
    DriverNode *current=head;
    int no=1;

    if(current==NULL)
    {
        cout << "	List driver kosong, tambahkan driver terlebih dahulu! "<<endl;
        getch();
    }
    else
    {
        int count_driver=countNodes();
        cout << "	Jumlah Driver Terdaftar : "<<count_driver<<endl;
        while(current!=NULL)
        {
            cout << "     " << no++ << ". " << endl;
            showDriverProperties(current);
            cout << endl;
            current=(*current).next;
        }
        cout << endl;
    }
}

void Driver::paginate()
{
    DriverNode *current=head;
    int option;

    if(current!=NULL)
    {
        do
        {
            system("cls");
            welcome();
            header("List Driver(Pagination Mode)");
            cout << endl;
            showDriverProperties(current);

            cout << "	1. Next " << endl;
            cout << "	2. Previous " << endl;
            cout << "	3. Kembali " << endl;
            cout << "	Masukkan pilihanmu : ";
            scanf("%d", &option);

            switch(option)
            {
                case 1:
                    if((*current).next!=NULL)
                        current=(*current).next;
                    else
                        current=head;
                    break;
                case 2:
                    if(current!=head)
                    {
                        struct DriverNode *prev=head;
                        while((*prev).next!=current)
                            prev=(*prev).next;
                        current=prev;
                    }
                    else
                        current=tail;
                    break;
                case 3:
                    break;
                default:
                    printf("\nInvalid choice...");
            }
        }while(option!=3);
    }
    else
    {
        cout << "	List driver kosong, tambahkan driver terlebih dahulu! "<<endl;
        getch();
    }
}

void Driver::updateForm()
{
    DriverNode *current=head;

    if(current==NULL)
    {
        cout << "	List driver kosong, tambahkan driver terlebih dahulu! "<<endl;
        getch();
    }
    else
    {
        string id_input;
        DriverNode *found_node;
        system("cls");
        welcome();
        header("Update Data Driver");
        cout << endl;

        displayAll();

        cout << "	Masukkan ID Driver : ";
        cin.ignore();
        getline(cin, id_input);

        found_node=searchOne(id_input);

        if(found_node!=NULL)
        {
            int option;
            cout << "	Update Driver dengan ID : "<<(*found_node).id<<endl;

            do
            {
                cout << endl;
                cout << "	1. Ubah Nama " << endl;
                cout << "	2. Ubah Alamat " << endl;
                cout << "	3. Ubah Jenis Kelamin " << endl;
                cout << "	4. Ubah Tanggal Lahir " << endl;
                cout << "	5. Kembali " << endl;
                cout << endl;
                cout << "	Masukkan opsi : ";
                scanf("%d", &option);

                switch(option)
                {
                    case 1:
                        {
                            string input_name;
                            cout << "\n	Input Nama : ";
                            cin.ignore();
                            getline(cin, input_name);
                            updateNode(1, input_name, found_node);
                            break;
                        }
                    case 2:
                        {
                            string input_address;
                            cout << "\n	Input Alamat : ";
                            cin.ignore();
                            getline(cin, input_address);
                            updateNode(2, input_address, found_node);
                            break;
                        }
                    case 3:
                        {
                            char input_gender;
                            cout << "\n	Input Gender (L/P) : ";
                            scanf("%c", &input_gender);
                            updateNode(3, input_gender, found_node);
                            break;
                        }
                    case 4:
                        {
                            Date input_birthdate;
                            cout << "\n	Input Tanggal Lahir : ";
                            scanf("%d %d %d", &input_birthdate.day, &input_birthdate.month, &input_birthdate.year);
                            updateNode(4, input_birthdate, found_node);
                            break;
                        }
                    case 5:
                        break;
                    default:
                        cout << "\n	Invalid choice! ";
                        break;
                }
            }while(option!=5);
        }
        else
        {
            cout << endl;
            cout << "	Driver tidak ditemukan! "<<endl;
            getch();
        }
    }

}

template <typename T>
void Driver::updateNode(int option, T new_value, DriverNode *old_node)
{
    int status=0;

    if(option==1)
    {
        if constexpr (is_same_v<T, string>)
        {
            (*old_node).name=new_value;
            status=1;
        }
    }
    else if(option==2)
    {
        if constexpr (is_same_v<T, string>)
        {
            (*old_node).address=new_value;
            status=1;
        }
    }
    else if(option==3)
    {
        if constexpr (is_same_v<T, char>)
        {
            (*old_node).gender=new_value;
            status=1;
        }
    }
    else if(option==4)
    {
        if constexpr (is_same_v<T, Date>)
        {
            int day=new_value.day;
            int month=new_value.month;
            int year=new_value.year;

            (*old_node).birthdate.day=day;
            (*old_node).birthdate.month=month;
            (*old_node).birthdate.year=year;
            status=1;
        }
    }

    if(status==1)
        cout << "\n	Data Driver BERHASIL Ter-update! " << endl;
    else
        cout << "\n	Data Driver GAGAL Ter-update! " << endl;
}

void Driver::deleteNode(const string &id)
{
    DriverNode *current, *p;
    current=head;
    bool flag=false;
    p=NULL;

    while(current!=NULL && (*current).id!=id)
    {
        p=current;
        current=(*current).next;
    }

    if(current!=NULL)
    {
        (*p).next=(*current).next;
        flag=true;
        delete current;
    }

    if(!flag)
        cout << "\n	Data Driver GAGAL Dihapus! " << endl;
    else
        cout << "\n	Data Driver BERHASIL Dihapus! " << endl;
}

int Driver::countNodes()
{
    DriverNode *current=head;

    int counter=0;
    while(current!=NULL)
    {
        counter++;
        current=(*current).next;
    }
    return counter;
}
// DRIVER CLASS PROPS
