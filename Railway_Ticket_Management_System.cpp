// #include<iostream>
// #include<string>
// #include<fstream>
// #include <iomanip>

// using namespace std;

// //information taking class
// class traveler_information
// {
//     public:
//     //variable declaration
//     string passenger_name,tem;
//     string gender;
//     int age,w=0;
//     static int male,female;
//     long long int phonenumber;
//     string journey_date;
//     string from;
//     string to;
//     string departToDestiny;
//     string matchcity;
//     int distance,train_class;
//     int time,seat_no,cheak;
//     float total_amount;
//     static long int pnr_number;

//     //passenger detail taking function
//         void personal_information()
//         {
//                 cout<<endl<<"Passenger's name : ";
//                 getline(cin>>ws, passenger_name);

//                 cout<<"Gender : ";
//                 getline(cin, gender);

//                 cout<<"Age : ";
//                 cin>>age;

//                 cout<<"Mobile number : ";
//                 cin>>phonenumber;

//                 cout<<"Journey date : ";
//                 cin>>journey_date;

//                 if(gender=="male")
//                 male++;
//                 else if(gender=="female")
//                 female++;

//         cout<<"Select your train class : "<<endl;
//         cout<<"press \"1\" for \"First class\""<<endl;
//         cout<<"press \"2\" for \"Second class\""<<endl;
//         cout<<"press \"3\" for \"First class A.C\""<<endl;
//         cout<<"press \"4\" for \"Second class A.C\""<<endl;
//         cout<<"press \"5\" for \"1 Tier sleeper class\""<<endl;
//         cout<<"press \"6\" for \"2 Tier sleeper class\""<<endl;
//         cout<<"press \"7\" for \"3 Tier sleeper class\""<<endl;
//         cin>>train_class;

//         switch(train_class)
//         {
//             case 1:
//             {
//             cout<<"Class : First class"<<endl;
//             break;
//             }
//             case 2:
//             {
//             cout<<"Class : Second class"<<endl;
//             break;
//             }
//             case 3:
//             {
//             cout<<"Class : First class A.C"<<endl;
//             break;
//             }
//             case 4:
//             {
//             cout<<"Class : Second class A.C"<<endl;
//             break;
//             }
//             case 5:
//             {
//             cout<<"Class : 1 Tier sleeper class"<<endl;
//             break;
//             }
//             case 6:
//             {
//             cout<<"Class : 2 Tier sleeper class"<<endl;
//             break;
//             }
//             case 7:
//             {
//             cout<<"Class : 3 Tier sleeper class"<<endl;
//             break;
//             }
//         }
//         }

//       void taking_placedetail()
//         {
//             cout<<"Enter City name(First later of the city must be capital latter) : "<<endl;
//             cout<<endl<<"From : ";
//             cin>>from;
//             cout<<"To : ";
//             cin>>to;
//             departToDestiny =from+"-"+to;
//         }

//         void check_place()
//         {
//               fstream listfile;
//             listfile.open("city_data.txt");

//             while(listfile>>matchcity)
//             {
//                 if(matchcity==departToDestiny)
//                 {
//                     cout<<matchcity<<endl;
//                     listfile>>distance;
//                     total_amount=distance*0.70;
//                     listfile>>time;
//                     w++;
//                     break;
//                 }
//             }
//             if(w==0){
//                 cout<<"Train is not available of this route..."<<endl;
//             }
//             listfile.close();
//         }

// void seat()
//     {
//     reenter:
//     cout<<"Enter the seat number : ";
//     cin>>seat_no; 
//     fstream seatcheak;
//     seatcheak.open("seatnumber.txt");
//     while(seatcheak>>cheak)
//     {
//         if(cheak==seat_no){
//             cout<<"This seat is already booked...\nRe-enter the seat number..."<<endl;
//             goto reenter;
//         }
//     }
//     cout<<"Your desire seat is allocated to you...\nEnjoy your journey..."<<endl;

//     fstream seatnumber;
//     seatnumber.open("seatnumber.txt",ios::app);
//     seatnumber<<" "<<seat_no;
//     seatnumber.close();
//     }
//     static void showpnrnumber()
//      {
//         ofstream pnr_details("hello.txt",ios::app);
//         pnr_number++;
//         pnr_details<<"PNR NO : "<<pnr_number<<endl;
        
//         cout<<endl;
//      }

//     void print_file()
//     {
//  fstream out;
//  out.open("hello.txt",ios::app);
//  out<<endl;
//  for (int i = 0; i < 85; i++)
//  {
//     out<<"*";
//  }
//             out  << endl;
//             out << "*                             INDIAN RAILWAY LIMITED                                *" << endl;
//             for (int i = 0; i < 85; i++)
//                 {
//                     out<<"*";
//                 }
//             out << endl;
//             out << "*                                  TRAIN TICKET                                     *" << endl;
//             for (int i = 0; i < 85; i++)
//                 {
//                     out<<"*";
//                 }
//             out << endl;

//             out <<"* Passenger Name "<<"   : "<<left<<setw(62)<<passenger_name<<"*"<<endl;
//             out << "* Phone number   "<<"   : "<<setw(15)<<phonenumber;
//             out << "\t\t\t\tDeparture City "<<"   : "<<setw(12)<<from<<"*"<<endl;
//             out << "* Destination City "<<" : "<<setw(15)<<to;
//             out << "\t\t\t\tDistance"<<"          : "<<setw(4)<<distance<<"Km      *"<<endl;
//             out << "* Time"<<"              : "<<setw(2)<<time<<"Hr           ";    
//             out << "\t\t\t\tJourney Date "<<"     : "<<setw(12)<<journey_date<<"*"<<endl;
//             out << "* Journey Time "<<"     : "<<setw(15)<<time;
//             out << "\t\t\t\tAge"<<"               : "<<setw(12)<<age<<"*"<< endl;
//             out << "* Gender"<<"            : "<<setw(62)<<gender<<"*"<<endl;
//             out << "* PNR No."<<"           : "<<setw(62)<<pnr_number<<"*"<<endl;
//             out << "* Seat Number "<<"      : "<<setw(62)<<seat_no <<"*"<<endl;
//             out<<"*\t\t\t\t\t\t\tYour final price is"<<" : "<<"Rs. "<<setw(6)<<total_amount;
//             for (int i = 0; i < 24; i++)
//             {
//                out<<" ";
//             }
            
//             out<<"*"<<endl;
//             for (int i = 0; i < 85; i++)
//                 {
//                     out<<"*";
//                 }
//             out <<endl;
//        }  
    
    
//     void file__end()
//     {
//             fstream file;
//         //file ending formating 
//         file.open("hello.txt", ios::app);
//         for (int i = 0; i < 92; i++)
//         {
//             file<<"-";
//         }
//         file<<endl;
//         for (int i = 0; i < 92; i++)
//         {
//             file<<"-";
//         }
//         file<<endl;
//         file.close();
//     }
// };

// long int traveler_information :: pnr_number=301618087;
// int traveler_information::male=0;
// int traveler_information::female=0;

// int main()
// {
//     string date;
//     string day;
//      cout<<"Enter date(dd/mm/yyyy) : ";
//         cin>>date;
//         cout<<"Enter day : ";
//         cin>>day;
//         fstream file;
//         file.open("hello.txt", ios::app);
//         file<<endl<<"Date : "<<date<<endl;
//         file<<"Day : "<<day<<endl;
//         file.close();

// traveler_information information;

// information.personal_information();
// information.taking_placedetail();
// information.check_place();
// information.seat();
// information.showpnrnumber();
// information.print_file();
// information.file__end();

// }

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;

class traveler_information
{
public:
    string passenger_name;
    string gender;
    int age, w = 0;
    static int male, female;
    long long int phonenumber;
    string journey_date;
    string from;
    string to;
    string departToDestiny;
    string matchcity;
    int distance, train_class;
    int time, seat_no, cheak;
    float total_amount;
    static long int pnr_number;

    void personal_information()
    {
        cout << endl
             << "Passenger's name: ";
        getline(cin >> ws, passenger_name);

        cout << "Gender: ";
        getline(cin, gender);

        cout << "Age: ";
        cin >> age;

        cout << "Mobile number: ";
        cin >> phonenumber;

        cout << "Journey date: ";
        cin >> journey_date;

        if (gender == "male")
            male++;
        else if (gender == "female")
            female++;

        cout << "Select your train class:" << endl;
        cout << "Press \"1\" for \"First class\"" << endl;
        cout << "Press \"2\" for \"Second class\"" << endl;
        cout << "Press \"3\" for \"First class A.C\"" << endl;
        cout << "Press \"4\" for \"Second class A.C\"" << endl;
        cout << "Press \"5\" for \"1 Tier sleeper class\"" << endl;
        cout << "Press \"6\" for \"2 Tier sleeper class\"" << endl;
        cout << "Press \"7\" for \"3 Tier sleeper class\"" << endl;
        cin >> train_class;

        switch (train_class)
        {
        case 1:
        {
            cout << "Class: First class" << endl;
            break;
        }
        case 2:
        {
            cout << "Class: Second class" << endl;
            break;
        }
        case 3:
        {
            cout << "Class: First class A.C" << endl;
            break;
        }
        case 4:
        {
            cout << "Class: Second class A.C" << endl;
            break;
        }
        case 5:
        {
            cout << "Class: 1 Tier sleeper class" << endl;
            break;
        }
        case 6:
        {
            cout << "Class: 2 Tier sleeper class" << endl;
            break;
        }
        case 7:
        {
            cout << "Class: 3 Tier sleeper class" << endl;
            break;
        }
        }
    }

    void taking_placedetail()
    {
        cout << "Enter City name (First letter of the city must be capital letter): " << endl;
        cout << endl
             << "From: ";
        cin >> from;
        cout << "To: ";
        cin >> to;
        departToDestiny = from + "-" + to;
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
        cout << "Enter the seat number: ";
        cin >> seat_no;
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
        pnr_details << "PNR NO: " << pnr_number << endl;

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

        out << "* Passenger Name " << "   : " << left << setw(62) << passenger_name << "*" << endl;
        out << "* Phone number   " << "   : " << setw(15) << phonenumber;
        out << "\t\t\t\tDeparture City " << "   : " << setw(12) << from << "*" << endl;
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
    string animation = "|/-\\";
    int animationIndex = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << "Processing " << animation[animationIndex] << " ";
        (chrono::milliseconds(200));
        cout << "\b";
        animationIndex = (animationIndex + 1) % 4;
    }
}

int main()
{
    string date;
    string day;
    cout << "Enter date (dd/mm/yyyy): ";
    cin >> date;
    cout << "Enter day: ";
    cin >> day;

    fstream file;
    file.open("hello.txt", ios::app);
    file << endl
         << "Date: " << date << endl;
    file << "Day: " << day << endl;
    file.close();

    traveler_information information;

    information.personal_information();
    information.taking_placedetail();
    information.check_place();

    cout << "\nProcessing the request..." << endl;
    loadingAnimation();
    cout<<endl;
    information.seat();
    information.showpnrnumber();
    information.print_file();
    information.file__end();

    cout << "Ticket booked successfully! Please check the 'hello.txt' file for the ticket details." << endl;

    return 0;
}
