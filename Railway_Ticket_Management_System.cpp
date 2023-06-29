#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>
#include <ctime>
#include <unistd.h>
#include<windows.h>
#include<stdio.h>

using namespace std;
void loadingAnimation();
void loadingPage();
// Information taking class
class traveler_information
{
public:
    // Variable declaration
    string passenger_name, tem,gender;
    int age, w = 0;
    static int male, female;
    long long int phonenumber;
    string journey_date, from,to,departToDestiny,matchcity;
    int distance, train_class,time, seat_no, cheak;
    float total_amount;
    static long int pnr_number;

    // Passenger detail taking function
    void personal_information()
    {
        cout << endl << "Passenger's name : ";
        getline(cin >> ws, passenger_name);

        cout << "Gender : ";
        getline(cin, gender);

        cout << "Age : ";
        cin >> age;

        label_1:
        cout << "Mobile number : ";
        cin >> phonenumber;
        if (phonenumber>9999999999 || phonenumber<1000000000){
            cout<<"Invalid mobile no."<<endl;
            goto label_1;
        }

        cout << "Journey date : ";
        cin >> journey_date;

        if (gender == "male")
            male++;
        else if (gender == "female")
            female++;

        cout << "Choose Your Train class.... " << endl;
        cout << "press [1] for \"First class General\"" << endl;
        cout << "press [2] for \"Second class General\"" << endl;
        cout << "press [3] for \"First class A.C\"" << endl;
        cout << "press [4] for \"Second class A.C\"" << endl;
        cout << "press [5] for \"Tier[1] sleeper class\"" << endl;
        cout << "press [6] for \"Tier[2] sleeper class\"" << endl;
        //cout << "press [7] for \"Tier[3] sleeper class\"" << endl;
        cout << "Select Your Train Class Type : ";
        cin >> train_class;

        switch (train_class)
        {
            case 1:
                {
                    cout << "Class : First class" << endl;
                    break;
                }
            case 2:
                {
                    cout << "Class : Second class" << endl;
                    break;
                }
            case 3:
                {
                    cout << "Class : First class A.C" << endl;
                    break;
                }
            case 4:
                {
                    cout << "Class : Second class A.C" << endl;
                    break;
                }
            case 5:
                {
                    cout << "Class : 1 Tier sleeper class" << endl;
                    break;
                }
            case 6:
                {
                    cout << "Class : 2 Tier sleeper class" << endl;
                    break;
                }
            case 7:
                {
                    cout << "Class : 3 Tier sleeper class" << endl;
                    break;
                }
        }
    }

    void taking_placedetail()
    {
        cout << "Enter City name(First letter of the city must be a capital letter) : " << endl;
        cout << endl << "From : ";
        cin >> from;
        cout << "To : ";
        cin >> to;
        cout<<endl;
        departToDestiny = from + "-" + to;
        loadingAnimation();
    }

    void check_place()
    {
        fstream listfile;
        listfile.open("city_data.txt");

        while (listfile >> matchcity)
        {
            if (matchcity == departToDestiny)
            {
                cout << matchcity << endl;
                listfile >> distance;
                total_amount = distance * 0.70;
                listfile >> time;
                w++;
                break;
            }
        }
        if (w == 0)
        {
            cout << "Train is not available on this route..." << endl;
        }
        listfile.close();
    }

    void seat()
    {
        reenter:
        cout << "Enter the seat number : ";
        cin >> seat_no;
        loadingAnimation();
        fstream seatcheak;
        seatcheak.open("seatnumber.txt");
        while (seatcheak >> cheak)
        {
            if (cheak == seat_no)
            {
                cout << "This seat is already booked...\nRe-enter the seat number..." << endl;
                goto reenter;
            }
        }
        cout << "Your desired seat is allocated to you...\nEnjoy your journey..." << endl;

        fstream seatnumber;
        seatnumber.open("seatnumber.txt", ios::app);
        seatnumber << " " << seat_no;
        seatnumber.close();
    }

    static void showpnrnumber()
    {
        ofstream pnr_details("hello.txt", ios::app);
        pnr_number++;
        pnr_details << "PNR NO : " << pnr_number << endl;

        cout << endl;
    }

    void print_file()
    {
        fstream out;
        out.open("hello.txt", ios::app);
        out << endl;
        for (int i = 0; i < 85; i++)
        {
            out << "*";
        }
        out << endl;
        out << "*                             INDIAN RAILWAY LIMITED                                *" << endl;
        for (int i = 0; i < 85; i++)
        {
            out << "*";
        }
        out << endl;
        out << "*                                  TRAIN TICKET                                     *" << endl;
        for (int i = 0; i < 85; i++)
        {
            out << "*";
        }
        out << endl;

        out << "* Passenger Name " << "   : " << left << setw(62) << passenger_name << "*"<< endl;
        out << "* Phone number   " << "   : " << setw(15) << phonenumber;
        out << "\t\t\t\tDeparture City " << "   : " << setw(12) << from << "*"<< endl;
        out << "* Destination City " << " : " << setw(15) << to;
        out << "\t\t\t\tDistance" << "          : " << setw(4) << distance << "Km      *" << endl;
        out << "* Time" << "              : " << setw(2) << time << "Hr           ";
        out << "\t\t\t\tJourney Date " << "     : " << setw(12) << journey_date << "*" << endl;
        out << "* Journey Time " << "     : " << setw(15) << time;
        out << "\t\t\t\tAge" << "               : " << setw(12) << age << "*" << endl;
        out << "* Gender" << "            : " << setw(62) << gender << "*" << endl;
        out << "* PNR No." << "           : " << setw(62) << pnr_number << "*" << endl;
        out << "* Seat Number " << "      : " << setw(62) << seat_no << "*" << endl;
        out << "*\t\t\t\t\t\t\tYour final price is" << " : " << "Rs. " << setw(6) << total_amount;
        for (int i = 0; i < 24; i++)
        {
            out << " ";
        }

        out << "*" << endl;
        for (int i = 0; i < 85; i++)
        {
            out << "*";
        }
        out << endl;
    }

    void file__end()
    {
        fstream file;
        //file ending formatting
        file.open("hello.txt", ios::app);
        for (int i = 0; i < 92; i++)
        {
            file << "-";
        }
        file << endl;
        for (int i = 0; i < 92; i++)
        {
            file << "-";
        }
        file << endl;
        file.close();
    }
};

long int traveler_information::pnr_number = 301618087;
int traveler_information::male = 0;
int traveler_information::female = 0;

void loadingAnimation()
{
    cout << "Loading ";
    for (int i = 0; i < 10; i++)
    {
        cout << ".";
        cout.flush();
        for (int j = 0; j < 1000000000; j++);
    }
    cout << endl;
}

void loadingPage(){
 system("COLOR 0e");
    system("cls");
    int bar1=177 , bar2=219;
    cout<<"\n\n\n\t\t\tLoading....."<<endl;
    cout<<"\t\t\t";
    for(int i=0;i<25;i++)
        cout<<(char)bar1;
    cout<<"\r";
    cout<<"\t\t\t";
    for(int i=0;i<25;i++){
        cout<<(char)bar2;
        Sleep(200);
    }
    system("cls");
}

int main()
{
    cout<<"\t\t-------------------------------------------------"<<endl ;
    cout<<"\t\t|\tWELCOME TO THE TICKET BOOKING SYSTEM\t|"<<endl;
    cout<<"\t\t-------------------------------------------------"<<endl<<endl;
    cout<<"YOU WILL BE REDIRECTED TO THE BOOKING SYSTEM IN FEW SECONDS..."<<endl<<endl;
    cout<<"Please wait...";
    sleep(3);
    loadingPage();
    cout<<endl;
    string date;
    string day;
    cout<<"THANKS FOR BEING PATIENCE :)"<<endl<<endl;
    cout << "Enter date (dd/mm/yyyy) : ";
    cin >> date;
    cout << "Enter day : ";
    cin >> day;
    fstream file;
    file.open("hello.txt", ios::app);
    file << endl << "Date : " << date << endl;
    file << "Day : " << day << endl;
    file.close();

    traveler_information information;

    information.personal_information();
    information.taking_placedetail();
    information.check_place();
    information.seat();
    information.showpnrnumber();

    cout << "Generating ticket..." << endl;
    loadingAnimation();
    cout<<"Check 'hello.txt' to see your ticket..."<<endl;
    

    information.print_file();
    information.file__end();

    return 0;
}
