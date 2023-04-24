#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to store city information
struct City {
    string name;
    int distance=0;
    int time=0;
};
class Passanger_Data{
    public:
    string name,gender;
    long long int mobile_number;
    int age,date,train_class;;
    static long int pnr_number;
    void getdata()
     {
        static long int pnr_number;
       
        cout<<"Name (fristname middlename surname) : "<<endl;
        getline(cin, name);
        cout<<"Mobile number:"<<endl;
        cin>>mobile_number;
        cout<<"Gender (Male/Female/Other) : "<<endl;
        cin >> gender;
        cout<<"Age : ";
        cin>>age; 
        cout<<"enter date like this\"dd/mm/yy\""<<endl;
        cin>>date;
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
            cout<<"Class : econd class A.C"<<endl;
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
     void putdata(){
        ofstream detail("hello.txt");
        string quota;
        for (int i = 0; i < 45; i++)
        {
            detail<<"*";
        }
        detail << endl;
        detail<< "Gujarat Railway Private Limited"<<endl;
        for (int i = 0; i < 45; i++)
        {
            detail<<"*";
        }
        detail << endl;
        detail<<"Name : "<<name<<endl;
        detail<<"Mobile number : "<<mobile_number<<endl;
        detail<<"Gender : "<<gender<<endl;
        void number_gender()
     {
           if(gender==("male" || "Male"))
           {
               m++;
           }
           else if(gender==("female"||"Female")){
            f++;
           }
           else if (gender==("Other"||"other"))
           {
            o++;
           }
           
     }
     void printstatic_data()
     {
        cout<<"Male   : "<<m<<endl;
        cout<<"Female : "<<f<<endl;
        cout<<"Other : "<<o<<endl;
        
     }
        detail<<"Age : "<<age<<endl;
        detail<<"date of journey:"<<date<<endl;
     }

      static void showpnrnumber()
     {
        ofstream pnr_details("hello.txt",ios::app);
        pnr_details<<endl;
        pnr_details<<"PNR NO:"<<pnr_number<<endl;
        pnr_number++;
        
        for(int j=0;j<45;j++)
        {
            pnr_details<<"*";
        }
     }
     
};
// Function to calculate fare based on distance
float calculateFare(int distance) {
    return distance * 0.55 ; // Fare in rupees
}
float calculateFare(int distance,float x){
    return distance * 0.95;
}

long int Passanger_Data :: pnr_number=301618087;
int main()

 {
    string departToDestiny;
    string list,match_city;
    
    Passanger_Data D;
    D.getdata();
    D.putdata();
    //D.showpnrnumber();

    // Get departure city name from user
    cout << "Enter departure to destination city: ";
    cin >> departToDestiny;

    fstream readlist;
    int distance,time,w=0;
    readlist.open("city_data.txt");
    while(readlist>>match_city)
   {
    if (match_city==departToDestiny){
        cout << match_city <<endl;
        readlist >> distance;
        cout << "Distance is :"<<distance<< endl;
        readlist >> time;
        cout << "Time : " << time << "hours"<< endl;
        string quota;
        cout<<"select your quota \"general/tatkal\"";
        cin>>quota;
        if(quota=="tatkal"){
            cout << "Fare: Rs. " << calculateFare(distance, 0.95) << endl;
        } else if (quota=="general"){
                cout << "Fare: Rs. " << calculateFare(distance) << endl;
        }
        w++;
        readlist.close();
    }
   }
if(w==0){
    cout << "No train is available for this route."<< endl;
}

}





/*
#include<iostream>
#include<fstream>
using namespace std;
class ticket
{
     string frist_name,middle_name,surname,gender,sit_coatch;
     char a,b;
     long int mobile_number,date;
     int age,train_class,sit_number;
     static long int pnr_number;
     static int m,f,A,C;
     public:
     void getdata()
     {
        cout<<"enter your name like this:\n\"fristname middlename surname\" "<<endl;
        cin>>frist_name>>middle_name>>surname;
        cout<<"enter your mobile number:"<<endl;
        cin>>mobile_number;
        cout<<"enter your gender"<<endl;
        cin>>gender;
        cout<<"enter the age"<<endl;
        cin>>age;
        cout<<"enter date like this\"dd/mm/yy\""<<endl;
        cin>>date;
        cout<<"select your train class"<<endl;
        cout<<"press \"1\" for \"frist class\""<<endl;
        cout<<"press \"2\" for \"second class\""<<endl;
        cout<<"press \"3\" for \"frist class A.C\""<<endl;
        cout<<"press \"4\" for \"second class A.C\""<<endl;
        cout<<"press \"5\" for \"1 tire sleeper class\""<<endl;
        cout<<"press \"6\" for \"2 tire sleeper class\""<<endl;
        cout<<"press \"7\" for \"3 tire sleeper class\""<<endl;
        cin>>train_class;
     }
     void putdata()
     {
        cout<<"name:"<<frist_name<<" "<<middle_name<<" "<<surname<<endl;
        cout<<"mobile number:"<<mobile_number<<endl;
        cout<<"gender:"<<gender<<endl;
        cout<<"age:"<<age<<endl;
        cout<<"date of journey:"<<date<<endl;
        switch(train_class)
        {
            case 1:
            {
            cout<<"your class is: frist class"<<endl;
            break;
            }
            case 2:
            {
            cout<<"your class is: second class"<<endl;
            break;
            }
            case 3:
            {
            cout<<"your class is: frist class A.C"<<endl;
            break;
            }
            case 4:
            {
            cout<<"your class is: econd class A.C"<<endl;
            break;
            }
            case 5:
            {
            cout<<"your class is: 1 tire sleeper class"<<endl;
            break;
            }
            case 6:
            {
            cout<<"your class is: 2 tire sleeper class"<<endl;
            break;
            }
            case 7:
            {
            cout<<"your class is: 3 tire sleeper class"<<endl;
            break;
            }
        }
     }
     static void showpnrnumber()
     {
        for(int j=0;j<50;j++)
        {
            cout<<"-";
        }
        cout<<endl;
        cout<<"PNR NO:"<<pnr_number<<endl;
        pnr_number++;
     }
     void tiketprice(int f)
     {
        string dastination_city,c,quota;
        int distance_dastination,time_dastination,w=0;
        cout<<"enter the dastination & bording city like this\"dastination city-bording city\""<<endl;
        cin>>c;
        fstream kholo;
        kholo.open("hello.txt");
        while(kholo>>dastination_city)
        {
              if(c==dastination_city)
              {
                kholo>>distance_dastination;
                kholo>>time_dastination;
                for(int j=0;j<50;j++)
                {
                    cout<<"-";
                }
                cout<<endl;
                cout<<"select your quota \"genral/tatkal\"";
                cin>>quota;
                if(quota=="tatkal")
                {
                    cout<<"your total final ticket price is"<<(distance_dastination*4)*f<<endl;
                    cout<<"your trip is from:"<<c<<endl;
                }
                else
                {
                    cout<<"your total final ticket price is"<<(distance_dastination*2)*f<<endl;
                    cout<<"your trip is from:"<<c<<endl;
                }
                for(int j=0;j<50;j++)
                {
                    cout<<"-";
                }
                cout<<endl;
                cout<<"time:"<<time_dastination<<"hr"<<endl;
                w++;
              }
        }
        if(w==0)
        {
            cout<<"train is not aviable for this rout"<<endl;
        }
     }
      void number_gender()
     {
           if(gender=="male")
           {
               m++;
           }
           else{
            f++;
           }
     }
     void number_adult()
     {
         if(age<=18)
         {
            A++;
         }
         else
         {
            C++;
         }
     }
     void printstatic_data()
     {
        cout<<"total number of male is:"<<m<<endl;
        cout<<"total number of female is:"<<f<<endl;
        cout<<"ADULT:"<<A<<endl;
        cout<<"CHILD:"<<C<<endl;
     }
     void getticket()
     {
        cout<<"enter your prefered coach number \"from D1 TO D10\""<<endl;
        cin>>sit_coatch;
        cout<<"enter your prefered sit number\"from 1 TO 100\""<<endl;
        cin>>sit_number;
        fstream lakho;
        lakho.open("sitnumber.txt");
        
     }
};
long int ticket :: pnr_number=8301618087;
int ticket :: m=0;
int ticket :: f=0;
int ticket :: A=0;
int ticket :: C=0;
int main()
{
    int passenger_number;
    cout<<"how many passanger "<<endl;
    cin>>passenger_number;
    ticket t1[passenger_number],t2;
    for(int i=1;i<=passenger_number;i++)
    {
        cout<<"enter passanger no:"<<i<<"detail"<<endl;
        t1[i].getdata();
        t1[i].number_gender();
        t1[i].number_adult();
    }
    for(int j=0;j<50;j++)
        {
            cout<<"-";
        }
        cout<<endl;
    t2.tiketprice(passenger_number);
    for(int j=0;j<50;j++)
        {
            cout<<"-";
        }
        cout<<endl;
        cout<<endl;
    for(int i=1;i<=passenger_number;i++)
    {
         for(int j=0;j<50;j++)
        {
            cout<<"-";
        }
        cout<<endl;
        cout<<"passanger no:"<<i<<endl;
        t1[i].showpnrnumber();
        t1[i].putdata();
    }
    t2.printstatic_data();
    return 0;
}
*/