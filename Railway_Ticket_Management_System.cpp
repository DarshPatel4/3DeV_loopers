#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>
using namespace std;
class file_formating;

                   //information taking class
class traveler_information
{
    public:
    //variable declaration
    string passenger_name,tem;
    string gender;
    int age;
    static int male,female;
    long int phonenumber;
    string journey_date;
    string from;
    string to;
    string departToDestiny;
    string matchcity;
    int distance,train_class;
    int time,seat_no,cheak;
    float total_amount;
  

    //passenger detail taking function
        void personal_information()
        {
                cout<<endl<<"Enter passenger's name:";
                getline(cin>>ws, passenger_name);

                cout<<"Enter passenger's gender:";
                cin>>gender;

                cout<<"Enter passenger's age:";
                cin>>age;

                cout<<"Enter phone number:";
                cin>>phonenumber;

                cout<<"Enter jouney date:";
                cin>>journey_date;

                if(gender=="male")
                male++;
                else if(gender=="female")
                female++;

                cout<<"select your train class : "<<endl;
        cout<<"press \"1\" for \"frist class\""<<endl;
        cout<<"press \"2\" for \"second class\""<<endl;
        cout<<"press \"3\" for \"frist class A.C\""<<endl;
        cout<<"press \"4\" for \"second class A.C\""<<endl;
        cout<<"press \"5\" for \"1 tire sleeper class\""<<endl;
        cout<<"press \"6\" for \"2 tire sleeper class\""<<endl;
        cout<<"press \"7\" for \"3 tire sleeper class\""<<endl;
        cin>>train_class;

        switch(train_class)
        {
            case 1:
            {
            cout<<"Class : frist class"<<endl;
            break;
            }
            case 2:
            {
            cout<<"Class : second class"<<endl;
            break;
            }
            case 3:
            {
            cout<<"Class : frist class A.C"<<endl;
            break;
            }
            case 4:
            {
            cout<<"Class : Second class A.C"<<endl;
            break;
            }
            case 5:
            {
            cout<<"Class : 1 tire sleeper class"<<endl;
            break;
            }
            case 6:
            {
            cout<<"Class : 2 tire sleeper class"<<endl;
            break;
            }
            case 7:
            {
            cout<<"Class : 3 tire sleeper class"<<endl;
            break;
            }
        }
        }

      void taking_placedetail()
        {
            cout<<endl<<"From:";
            cin>>from;
            cout<<"To:";
            cin>>to;
            departToDestiny =from+"-"+to;
        }


        void check_place()
        {
              fstream listfile;
            listfile.open("city_data.txt");

            while(listfile>>matchcity)
            {
                if(matchcity==departToDestiny)
                {
                    cout<<matchcity<<endl;
                    listfile>>distance;
                    total_amount=distance*0.70;
                    listfile>>time;
                    break;
                }

            }
            
            listfile.close();
        }


void seat()
    {
    reenter:
    cout<<"Enter the seat number: ";
    cin>>seat_no; 
    fstream seatcheak;
    seatcheak.open("seatnumber.txt");
    while(seatcheak>>cheak)
    {
        if(cheak==seat_no){
            cout<<"seat is already booked"<<endl;
            goto reenter;
        }
    }
    cout<<"seat is allocated"<<endl;

    fstream seatnumber;
    seatnumber.open("seatnumber.txt",ios::app);
    seatnumber<<" "<<seat_no;
    seatnumber.close();
    }


    void print_file()
    {
 fstream out;
 out.open("hello.txt",ios::app);
 for (int i = 0; i < 78; i++)
 {
    cout<<"*";
 }
            out  << endl;
            out << "*                             GUJRAT RAILWAY                                 *" << endl;
            for (int i = 0; i < 78; i++)
                {
                    cout<<"*";
                }
            out << endl;
            out << "*                              TRAIN TICKET                                  *" << endl;
            for (int i = 0; i < 78; i++)
                {
                    cout<<"*";
                }
            out << endl;
            out <<"*Passenger Name "<<"    :"<<left<<setw(25)<<passenger_name<<endl;
            out << "*Phone number   "<<"    :"<<setw(15)<<phonenumber;
            out << "*\t\t\t\tDeparture City "<<"    :"<<setw(15)<<from<<endl;
            out << "*Destination City "<<"  :"<<setw(15)<<to;
            out << "*\t\t\t\tDistance"<<"           :"<<setw(3)<<distance<<"Km"<<endl;
            out << "*Time"<<"               :"<<setw(2)<<time<<"Hr           ";    
            out << "*\t\t\t\tJourney Date "<<"      :"<<setw(15)<<journey_date<<endl;
            out << "*Journey Time "<<"      :"<<setw(15)<<time;
            out << "*\t\t\t\tAge"<<"                :"<<setw(15)<<age<< endl;
            out << "*Gender"<<"             :"<<setw(15)<<gender<<endl;
            out << "*Seat Number "<<"       :"<<seat_no << endl<<endl;
            out<<"*\t\t\t\t\t\tYour final price is"<<" :"<<total_amount<<"Rs"<<endl;
            for (int i = 0; i < 78; i++)
                {
                    cout<<"*";
                }
            out <<endl<<endl;
       }        
    
    void file__end()
    {
            fstream file;
        //file ending formating 
        file.open("hello.txt", ios::app);
        for (int i = 0; i < 92; i++)
        {
            file<<"-";
        }
        file<<endl;
        file.close();
    }
};
int traveler_information::male=0;
int traveler_information::female=0;

int main()
{
    string date;
    string day;
     cout<<"Enter date as 'dd/mm/yyyy':";
        cin>>date;
        cout<<"Enter day:";
        cin>>day;
        fstream file;
        file.open("hello.txt", ios::app);
        file<<endl<<"Date:"<<date<<endl;
        file<<"Day:"<<day<<endl<<endl;
        file.close();

traveler_information information;
information.personal_information();
information.taking_placedetail();
information.check_place();
information.seat();
information.print_file();

}
