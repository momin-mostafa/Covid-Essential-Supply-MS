#include <bits/stdc++.h>
#include "split.h"
#define BUF_LEN 256
#define FILE "data.txt"
using namespace std;
class Essentials
{
private:
    float mask_price = 3.5;
    float sanitizer_price = 1.5;
    float gloves_price = 2.5;
    int input;
    int total_mask;
    float total_sanitizer;
    int total_gloves;
    int cost_total_mask;
    float cost_total_sanitizer;
    int cost_total_gloves;
    int mask;
    float sanitizer;
    int gloves;
    double price_of_mask;
    char familymember_name[100];

public:
    bool flag;
    Essentials() {}
    void in_is_input(int in);
    void list_expense(Essentials p1);
    void reset(Essentials p1);
    void family_usage(Essentials p1);
    void stock_check(Essentials p1);
    void re_supply(Essentials p1);
    void getdata(Essentials p1);
    void update_usage();
    void first_time(Essentials p1);
};
///////////////////////////////////function prototype///////////////////////////////////
void gui(int input, Essentials p1);
void starline(char a = '-', int b = 70);
void user_in(int &input, Essentials p1);
void ask_the_user(int input, Essentials p1);
string get_time();
void current_date(int &day, int &month, int &year);
void compare(int array1[3], int array2[3]);
void update_date();
void first_time(int input, Essentials p1);
void critical_warning(int input, Essentials p1);
void exit_critical_warning();
////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Essentials person1;
    int input;
    person1.in_is_input(input);
    first_time(input, person1);

    return 0;
}
//////////////////////////////////function Defination//////////////////////////////////
void starline(char a, int b)
{
    cout << " ";
    for (int i = 0; i <= b; i++)
    {
        cout << a;
    }
    cout << endl;
}
void gui(int input, Essentials p1)
{
    system("clear");
    // system("color 3f");
    cout << "                   COVID Essential Supplies Management System       " << endl;
    starline('=', 70);
    cout << "           1) List & Expense." << endl;
    starline();
    cout << "           2) Reset List & Expense." << endl;
    starline();
    cout << "           3) Family's Usage." << endl;
    starline();
    cout << "           4) Stock Check." << endl;
    starline();
    cout << "           5) Re-Supply." << endl;
    starline('=', 70);
    cout << "           0) EXIT" << endl;
    starline('=', 70);
    cout << endl;
    cout << "           Enter option number : ";
    cin >> input;
    user_in(input, p1);
}
void user_in(int &input, Essentials p1)
{
    switch (input)
    {
    case 0:
        exit_critical_warning();
        break;
    case 1:
        p1.list_expense(p1);
        break;
    case 2:
        p1.reset(p1);
        break;
    case 3:
        p1.family_usage(p1);
        break;
    case 4:
        p1.stock_check(p1);
        break;
    case 5:
        p1.getdata(p1);
        break;

    default:
        gui(input, p1);
        break;
    }
}
void ask_the_user(int input, Essentials p1)
{
    char temp;
    cout << "\t Do you want to continue ? (y/n) : ";
    cin >> temp;
    if (temp == 'Y' || temp == 'y')
    {
        gui(input, p1);
    }
    else
    {
        exit(0);
    }
}
string return_time()
{
    char buffer[BUF_LEN] = {0};
    time_t now = time(&now);
    struct tm *ptm = gmtime(&now);
    strftime(buffer, BUF_LEN, "%d/%m/%Y", ptm);
    return buffer;
}
string get_time() //dep
{
    char buffer[BUF_LEN] = {0};
    time_t now = time(&now);
    struct tm *ptm = gmtime(&now);
    strftime(buffer, BUF_LEN, "%d/%m/%Y", ptm);
    return buffer;
}
void current_date(int &day, int &month, int &year)
{
    string time = get_time();
    vector<string> splitted_time = split(time, '/');
    day = stoi(splitted_time[0]);
    month = stoi(splitted_time[1]);
    year = stoi(splitted_time[2]);
}
void compare(int array1[3], int array2[3])
{
    bool flag = false;
    if (array1[0] > array2[0])
        if (array1[1] >= array2[1])
            if (array1[2] >= array2[2])
                flag = true;

    //test
    // if (flag == true)
    // {
    //     cout << "array1 is greater than array 2" << endl;
    // }
    // else
    // {
    //     cout << "array2 is greater than array 1" << endl;
    // }

    // return flag;
}
void update_date()
{
    int array[3];
    ifstream ifile;
    ifile.open("date.txt");
    int a, b, c;
    int temp_count;
    ifile >> a >> b >> c >> temp_count;
    ++temp_count;
    ifile.close();
    ofstream ofile;
    ofile.open("date.txt", ios::trunc);
    current_date(array[0], array[1], array[2]);
    ofile << array[0] << ' ' << array[1] << ' ' << array[2] << ' ' << temp_count;
}
void first_time(int input, Essentials p1)
{

    ifstream ifile;
    ifile.open("data.txt");
    if (ifile)
    {
        // gui(input, p1);
        p1.flag = false;
        critical_warning(input, p1);
    }
    else
    {
        ofstream ofile;
        ofile.open(FILE, ios::trunc);
        ofile << "0 0 0";
        ofile.close();
        ofstream o_file;
        o_file.open("total_usage.txt", ios::trunc);
        o_file << "0 0 0";
        o_file.close();
        p1.flag = true;
        p1.getdata(p1);
    }
}
void critical_warning(int input, Essentials p1)
{
    int critical1 = 10, critical2 = 50, critical3 = 10;
    ifstream ifile;
    ifile.open("data.txt");
    int temp1, temp2, temp3;
    ifile >> temp1 >> temp2 >> temp3;
    ifile.close();
    if (temp1 < critical1 || temp2 < critical2 || temp3 < critical3)
    {
        cout << "looks like you are running low on supply. please check stock & resupply" << endl;
        ask_the_user(input, p1);
    }
    else
    {
        gui(input, p1);
    }
}
void exit_critical_warning()
{
    int critical1 = 10, critical2 = 50, critical3 = 10;
    ifstream ifile;
    ifile.open("data.txt");
    int temp1, temp2, temp3;
    ifile >> temp1 >> temp2 >> temp3;
    ifile.close();
    if (temp1 < critical1 || temp2 < critical2 || temp3 < critical3)
    {
        cout << "looks like you are running low on supply. please check stock & resupply" << endl;
    }
    exit(0);
}
//////////////////////////////Class function/////////////////////////////////////
void Essentials::stock_check(Essentials p1)
{
    ifstream ifile;
    ifile.open(FILE);
    ifile >> total_mask >> total_sanitizer >> total_gloves;
    system("clear");
    cout << "\tRemaining stock:" << endl;
    starline('=');
    cout << "\tMask : " << total_mask << " piece" << endl;
    starline();
    cout << "\tsanitizer (ml): " << total_sanitizer << " ml" << endl;
    starline();
    cout << "\tGolves : " << total_gloves << " piece" << endl;
    starline('=');
    ifile.close();
    ask_the_user(input, p1);
}

void Essentials::getdata(Essentials p1)
{
    system("clear");
    starline('=');
    cout << "\t\t\t\tWELCOME" << endl;
    starline();
    cout << "Enter Mask: ";
    cin >> mask;
    cout << "Enter Sanitizer(ml): ";
    cin >> sanitizer;
    cout << "Enter Gloves: ";
    cin >> gloves;
    ifstream ifile;
    ifile.open(FILE);
    ifile >> total_mask >> total_sanitizer >> total_gloves;
    total_mask += mask;
    total_sanitizer += sanitizer;
    total_gloves += gloves;
    ifile.close();
    ofstream ofile;
    ofile.open(FILE);
    ofile << total_mask << " " << total_sanitizer << " " << total_gloves << '\n';
    ofile.close();
    if (flag == true)
    {
        gui(input, p1);
    }

    stock_check(p1);
}

void Essentials::family_usage(Essentials p1)
{
    cout << "Enter the ammount of mask you have used today : ";
    cin >> mask;
    cout << "Enter the ammount of sanitizer you have used today(ml) : ";
    cin >> sanitizer;
    cout << "Enter the ammount of gloves you have used today : ";
    cin >> gloves;
    //input total
    ifstream ifile;
    ifile.open(FILE);
    ifile >> total_mask >> total_sanitizer >> total_gloves;
    ifile.close();
    //aeta bad daoa hoise stock theke
    total_mask -= mask;
    total_sanitizer -= sanitizer;
    total_gloves -= gloves;
    ofstream ofile;
    //
    //stock ta update korse
    ofile.open(FILE, ios::trunc);
    ofile << total_mask << " " << total_sanitizer << " " << total_gloves;
    ofile.close();
    update_usage();
    stock_check(p1);
    //
}

void Essentials::update_usage()
{
    //update 30days.txt
    ifstream ifile;
    ifile.open("total_usage.txt");
    ifile >> cost_total_mask >> cost_total_sanitizer >> cost_total_gloves;
    ifile.close();
    // add total usage.
    cost_total_mask = cost_total_mask + mask;
    cost_total_sanitizer = cost_total_sanitizer + sanitizer;
    cost_total_gloves = cost_total_gloves + gloves;
    //costing part(save)
    ofstream ofile;
    ofile.open("total_usage.txt", ios::trunc);
    ofile << cost_total_mask << " " << cost_total_sanitizer << " " << cost_total_gloves;
    ofile.close();
}

void Essentials::list_expense(Essentials p1)
{
    int c_m = 1, c_s = 1, c_g = 1;
    int total;
    ifstream ifile;
    ifile.open("total_usage.txt");
    ifile >> c_m >> c_s >> c_g;
    ifile.close();
    cost_total_mask = c_m * mask_price;
    cost_total_sanitizer = c_s * sanitizer_price;
    cost_total_gloves = c_g * gloves_price;
    int day, month, year;
    system("clear");
    cout << " \t\t\t" << get_time() << endl;
    starline('=');
    cout << "\tTotal cost till now: " << endl;
    starline('=');
    cout << "\t\tMask : " << cost_total_mask << " Taka"
         << "(used " << c_m << " mask)" << endl;
    starline();
    cout << "\t\tSanitizer : " << cost_total_sanitizer << " Taka"
         << "(used " << c_s << " ml sanitizer)" << endl;
    starline();
    cout << "\t\tGloves : " << cost_total_gloves << " Taka"
         << "(used " << c_g << " gloves)" << endl;
    starline('=');
    ask_the_user(input, p1);
}

void Essentials::reset(Essentials p1)
{
    ofstream ofile;
    ofile.open("total_usage.txt", ios::trunc);
    ofile << '0' << ' ' << '0' << ' ' << '0';
    ofile.close();
    cout << "your record is cleared." << endl;
    ask_the_user(input, p1);
}

void Essentials::in_is_input(int in)
{
    input = in;
}
