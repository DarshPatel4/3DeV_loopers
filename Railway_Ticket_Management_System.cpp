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
    long int mobile_number;
    int age;
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
     }
     void putdata(){
        ofstream detail("hello.txt");
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
    int distance,time;
    readlist.open("city_data.txt");
    while(readlist>>match_city)
   {
    if (match_city==departToDestiny){
        cout << match_city <<endl;
        readlist >> distance;
        cout << "Distance is :"<<distance<< endl;
        readlist >> time;
        cout << "Time : " << time << "hours"<< endl;
        cout << "Fare: Rs. " << calculateFare(distance) << endl;
        readlist.close();
    }
   }
        cout << "Fare: Rs. " << calculateFare(distance) << endl;

}





