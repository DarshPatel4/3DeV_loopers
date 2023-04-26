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
       
        cout<<"Name (firstname middlename surname) : "<<endl;
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
    int distance,time,Train_time,w=0;
    readlist.open("city_data.txt");
    while(readlist>>match_city)
   {
    if (match_city==departToDestiny){
        cout << match_city <<endl;
        readlist >> distance;
        cout << "Distance is :"<<distance<< endl;
        readlist >> time;
        cout << "Time : " << time << "hours"<< endl;
        readlist>> Train_time;
        cout << "Train time : "<<Train_time<< ":00 PM"<<endl;
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
