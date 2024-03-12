#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>

using namespace std;

string admins[]={"Anies", "Ganjar", "Prabowo"};

struct Date {
    int day;
    int month;
    int year;
};

struct DriverNode {
    string id;
    string name;
    string address;
    char gender;
    Date birthdate;
    DriverNode *next;
};

struct OrderNode {
    string id;
    string nama;
    DriverNode driver;
    string plate_num;
    string destination;
};

class Driver
{
    private:
        struct DriverNode *head, *tail;
    public:
        Driver()
        {
            head=NULL;
            tail=NULL;
        }
        void createNode(const string &name, const string &address, char gender, const Date &birthdate);
        void addForm();
        void display();
        void displayOne(struct DriverNode *data);
        struct DriverNode *searchOne(const string &id);
        string incDuplicate(const string &id);
        void paginate();
        int countNodes();
        void updateForm();
        void deleteNode(const string &id);
        template <typename T>
        void updateNode(int option, T new_value, struct DriverNode *old_node);
};

// FUNCTION PROPS
void welcome();
void dashboardAdmin(const string &admin_name);
void dashboardUser(const string &user_name);
bool isAdmin(string);
string hashID(const string &name, char gender, struct Date date, int last_digit);
string concatenateInts(int, int, int, int);
// FUNCTION PROPS

int main()
{
    Driver d;
    int option;
    string name_input;

    welcome();

    printf("	Masukkan nama anda : ");
    getline(cin, name_input);
    if(isAdmin(name_input))
    {
        do
        {
            dashboardAdmin(name_input);
            printf("\n	Masukkan opsi : ");
            scanf("%d", &option);

            switch(option)
            {
            case 1:
                d.addForm();
                break;
            case 2:
                {
                    d.display();
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
                        d.display();
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
                exit(0);
                break;
            default:
                printf("Invalid Choice...");
            }
        }while(option!=7);
    }
    else
    {
        do
        {
            dashboardUser(name_input);
            printf("\n	Masukkan opsi : ");
            scanf("%d", &option);

        }while(option!=3);
    }
    return 0;
}

void welcome(){
    system("cls");
    cout << endl;
	cout << "                           ========================" << endl;
	cout << "                 ===========================================" << endl;
	cout << "        ==============================================================" << endl;
	cout << "============================= APLIKASI ONLINE DRIVER  =========================== " << endl;
	cout << "                            Created By Rayhan Atmadja" << endl;
	cout << "                     Project Praktikum Struktur Data TIC23" << endl;
	cout << "===============================================================================" << endl;
	cout << "===============================================================================" << endl;
	cout << endl;
}

void dashboardAdmin(const string &admin_name)
{
    system("cls");
    welcome();
    cout << "                     ====================================" << endl;
	cout << "                     |           Dashboard Admin         |" << endl;
	cout << "                     ====================================" << endl;
	cout << "                     Selamat Datang - "<< admin_name << endl;
    cout << endl;
	cout << "	1. Menambahkan Data Driver " << endl;
	cout << "	2. Tampilkan Semua Data Driver " << endl;
	cout << "	3. Cari Driver By ID " << endl;
	cout << "	4. Tampilkan Data Driver (Pagination) " << endl;
	cout << "	5. Update Data Driver " << endl;
	cout << "	6. Hapus Data Driver " << endl;
	cout << "	7. Exit Program " << endl;
}

void dashboardUser(const string &user_name)
{
    system("cls");
    welcome();
    cout << "                     ====================================" << endl;
	cout << "                     |           Dashboard User          |" << endl;
	cout << "                     ====================================" << endl;
	cout << "                     Selamat Datang - "<< user_name << endl;
    cout << endl;
	cout << "	1. Order " << endl;
	cout << "	2. History Order Anda " << endl;
	cout << "	3. Exit Program " << endl;
}

bool isAdmin(string input)
{
    bool found=false;
    for(auto a: admins)
    {
        if(input==a)
        {
            found=true;
            break;
        }
    }
    return found;
}

string concatenateInts(int first, int second, int third, int fourth)
{
    string strFirst=to_string(first);
    string strSecond=to_string(second);
    string strThird=to_string(third);
    string strFourth=to_string(fourth);
    string result=first<10 ? "0"+strFirst+strSecond+strThird+strFourth : strFirst+strSecond+strThird+strFourth;

    return result;
}

string hashID(const string &name, char gender, struct Date date, int last_digit)
{
    char first_letter='\0';
    char last_letter='\0';
    int first_post=0;
    int last_post=0;
    string id;

    for(size_t i=0;i<name.length();++i)
    {
        char current_char=name[i];

        if(isalpha(current_char))
        {
            if(first_letter=='\0')
                first_letter=tolower(current_char);

            last_letter=tolower(current_char);
        }
    }

    if(first_letter!='\0')
        first_post=first_letter-'a'+1;
    else
        printf("\nNo alphabetic found in string");

    if(last_letter!='\0')
        last_post=last_letter-'a'+1;
    else
        printf("\nNo alphabetic found in string");

    // TAKE LAST DIGIT ONLY BOSKU
    int day_last_digit=date.day%10;
    int month_last_digit=date.month%10;
    int year_last_digit=date.year%10;

    int two_first_digit=last_post > first_post ? (last_post-first_post) : (first_post-last_post);
    int third_digit=gender=='L' ? 1 : gender=='l' ? 1 : gender=='P' ? 0 : gender=='p' ? 0 : -1;
    int fourth_digit=((day_last_digit+month_last_digit)+year_last_digit)%9;
    id=concatenateInts(two_first_digit, third_digit, fourth_digit, last_digit);

    return id;
}

// DRIVER CLASS PROPS

string Driver::incDuplicate(const string &id)
{
    struct DriverNode *current = head;
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


struct DriverNode *Driver::searchOne(const string &id)
{
    struct DriverNode *current=head;
    while(current!=NULL)
    {
        if((*current).id==id)
            return current;
        current=(*current).next;
    }

    return NULL;
};

void Driver::displayOne(struct DriverNode *data)
{
    system("cls");
	welcome();
	cout << "                     ====================================" << endl;
	cout << "                     |             Data Driver           |" << endl;
	cout << "                     ====================================" << endl;
    cout << endl;
    cout << "	ID                  : "<<(*data).id<<endl;
    cout << "	Nama                : "<<(*data).name<<endl;
    cout << "	Alamat              : "<<(*data).address<<endl;
    cout << "	Jenis Kelamin (L/P) : "<<(*data).gender<<endl;
    cout << "	Tanggal Lahir       : "<<(*data).birthdate.day<<" "<<(*data).birthdate.month<<" "<<(*data).birthdate.year<<endl;
    cout << endl;
    cout << "	Ketik enter untuk kembali!";
    getch();
}

void Driver::createNode(const string &name, const string &address, char gender, const Date &birthdate)
{
    struct DriverNode *new_node, *found_node;
    string coded_id;
    string new_inc_id;

    new_node=new DriverNode;
    tail=head;

    coded_id=hashID(name, gender, birthdate, 0);
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
	cout << "                     ====================================" << endl;
	cout << "                     |          Tambah Data Driver       |" << endl;
	cout << "                     ====================================" << endl;
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

void Driver::display()
{
    system("cls");
	welcome();
	cout << "                     ====================================" << endl;
	cout << "                     |             List Driver           |" << endl;
	cout << "                     ====================================" << endl;
    cout << endl;
    struct DriverNode *current=head;
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
            cout << "	ID                  : "<<(*current).id<<endl;
            cout << "	Nama                : "<<(*current).name<<endl;
            cout << "	Alamat              : "<<(*current).address<<endl;
            cout << "	Jenis Kelamin (L/P) : "<<(*current).gender<<endl;
            cout << "	Tanggal Lahir       : "<<(*current).birthdate.day<<" "<<(*current).birthdate.month<<" "<<(*current).birthdate.year;
            cout << endl;
            current=(*current).next;
        }
        cout << endl;
    }
}

void Driver::paginate()
{
    struct DriverNode *current=head;
    int option;

    if(current!=NULL)
    {
        do
        {
            system("cls");
            welcome();
            cout << "                     ====================================" << endl;
            cout << "                     |    List Driver (Pagination Mode)  |" << endl;
            cout << "                     ====================================" << endl;
            cout << endl;
            cout << "	ID                  : "<<(*current).id<<endl;
            cout << "	Nama                : "<<(*current).name<<endl;
            cout << "	Alamat              : "<<(*current).address<<endl;
            cout << "	Jenis Kelamin (L/P) : "<<(*current).gender<<endl;
            cout << "	Tanggal Lahir       : "<<(*current).birthdate.day<<" "<<(*current).birthdate.month<<" "<<(*current).birthdate.year<<endl;

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
    struct DriverNode *current=head;

    if(current==NULL)
    {
        cout << "	List driver kosong, tambahkan driver terlebih dahulu! "<<endl;
        getch();
    }
    else
    {
        string id_input;
        struct DriverNode *found_node;
        system("cls");
        welcome();
        cout << "                     ====================================" << endl;
        cout << "                     |          Update Data Driver       |" << endl;
        cout << "                     ====================================" << endl;
        cout << endl;

        display();

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
                            struct Date input_birthdate;
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
void Driver::updateNode(int option, T new_value, struct DriverNode *old_node)
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
    struct DriverNode *current, *p;
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
    struct DriverNode *current=head;

    int counter=0;
    while(current!=NULL)
    {
        counter++;
        current=(*current).next;
    }
    return counter;
}
// DRIVER CLASS PROPS

// ORDER CLASS PROPS
// ORDER CLASS PROPS
