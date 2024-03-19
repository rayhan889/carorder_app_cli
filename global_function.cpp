#include "global_function.h"
#include "global_variable.h"

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

void header(string title)
{
    cout << "                     ====================================" << endl;
	cout << "                     |          " << title << "          |" << endl;
	cout << "                     ====================================" << endl;
}

void dashboardAdmin(const string &admin_name)
{
    system("cls");
    welcome();
    header("Dashboard Admin");
	cout << "                     Selamat Datang - "<< admin_name << endl;
    cout << endl;
	cout << "	1. Menambahkan Data Driver " << endl;
	cout << "	2. Tampilkan Semua Data Driver " << endl;
	cout << "	3. Cari Driver By ID " << endl;
	cout << "	4. Tampilkan Data Driver (Pagination) " << endl;
	cout << "	5. Update Data Driver " << endl;
	cout << "	6. Hapus Data Driver " << endl;
	cout << "	7. Cek Data Order Pelanggan " << endl;
	cout << "	8. Tambah Unit Mobil " << endl;
	cout << "	9. Tampilkan Semua Data Mobil " << endl;
	cout << "	10. Coba hapus mobil " << endl;
	cout << "	11. Exit Program " << endl;
}

void dashboardUser(const string &user_name)
{
    system("cls");
    welcome();
    header("Dashboard User");
	cout << "                     Selamat Datang - "<< user_name << endl;
    cout << endl;
	cout << "	1. Order " << endl;
	cout << "	2. History Order Anda " << endl;
	cout << "	3. Exit Program " << endl;
}

bool isAdmin(string input)
{
    bool found=false;
    for(auto a: ADMINS)
    {
        if(input==a)
        {
            found=true;
            IS_ADMIN_LOGGED_IN=true;
            break;
        }
    }
    return found;
}

string generateDriverID(const string &name, char gender, Date date, int last_digit)
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

    string strFirst=to_string(two_first_digit);
    string strSecond=to_string(third_digit);
    string strThird=to_string(fourth_digit);
    string strFourth=to_string(last_digit);
    id=two_first_digit<10 ? "0"+strFirst+strSecond+strThird+strFourth : strFirst+strSecond+strThird+strFourth;

    return id;
}

string generateOrderID(const string &plate, const string &id_driver, const string &destination)
{
    string finalllllllll_id;
    // ID KE 1 MA 2
    char first_letter=toupper(plate[0]);

    int first_two_digit=0;

    if(isalpha(first_letter))
        first_two_digit=first_letter - 'A' + 1;

    string first_two_digit_str=to_string(first_two_digit);
    string final_first_twooohhhhh=first_two_digit<10 ? "0"+first_two_digit_str : first_two_digit_str;

    // ID KE 3 4 5 6 7
    string five_more_digits_str=id_driver;

    // 2 LAST DIGITS yaituuu ke 8 dan 9
    string last_two_letter_of_destination_str=destination.substr(destination.length()-2);
    char eight_digit_ch=toupper(last_two_letter_of_destination_str[0]);
    char ninth_digit_ch=toupper(last_two_letter_of_destination_str[1]);

    int eight_digit=0;
    int ninth_digit=0;
    int eight_and_ninth_digits=0;

    if(isalpha(eight_digit_ch))
        eight_digit=eight_digit_ch - 'A' + 1;

    if(isalpha(ninth_digit_ch))
        ninth_digit=ninth_digit_ch - 'A' + 1;

    eight_and_ninth_digits=eight_digit+ninth_digit;

    string eight_and_ninth_digits_str=to_string(eight_and_ninth_digits);

    // LASTT DIGIT
    int total_sum_of_post=0;
    string total_sum_of_post_str;
    string last_digit;
    int len=NAME_INPUT.size();
    int post_of_letters_name[len];

    if(NAME_INPUT.size()>0)
    {
        for(int i=0;i<len;++i)
        {
            char uppercase_char=toupper(NAME_INPUT[i]);

            post_of_letters_name[i]=uppercase_char - 'A' + 1;
        }

        for(int i=0;i<len;++i)
        {
            total_sum_of_post+=post_of_letters_name[i];
        }

        total_sum_of_post_str=to_string(total_sum_of_post);

        if(total_sum_of_post>9)
        {
            last_digit=total_sum_of_post_str[total_sum_of_post_str.size()-1];
        }
        else
            last_digit=total_sum_of_post_str;
    }

    finalllllllll_id=first_two_digit_str+five_more_digits_str+eight_and_ninth_digits_str+last_digit;
    return finalllllllll_id;
}

string makeTime()
{
    auto end=chrono::system_clock::now();
    string end_time_str;

    time_t end_time=chrono::system_clock::to_time_t(end);

    return end_time_str=ctime(&end_time);
}
