#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include "login.cpp"

using namespace std;

class car
{
	public:
	char modelName[30], engine[10], horsePower[20];
	int cost;

    void get_data()
    {
        cout<<"Model Name: ";
        cin>>modelName;
        cout<<"Engine: ";
        cin>>engine;
        cout<<"Horse Power: ";
        cin>>
    }
};

int main()
{
    char username[20], password[20];
    ifstream fin("secure.dat", ios::in|ios::binary);
    ofstream fout("cars.DB", ios::app|ios::binary);
    int dec, ret;
    car car_adder, reader;

    while(true)
    {
        system("pause");
        system("clear");
        cout<<"<<Welcome to Auto-Expo 2018>>\n";
        cout<<"1. Have an account? - LOG-IN\n";
        cout<<"2. Join Us! - SIGN-UP\n";
        cout<<"3. Add Cars\n";
        cout<<"4. Exit\n";
        cout<<"Input: \n";
        cin>>dec;
        //system("pause");

        switch(dec)
        {
            case 1:
            //system("clear");
            cout<<"<<Log - In>>\n";
            cout<<"Username: ";
            cin>>username;
            cout<<"Password: ";
            cin>>password;

            ret = verify(username, password);

            if(ret == 2)
            {
                main_menu();
            }
            else if(ret == 1)
            {
                cout<<"Wrong Credentials!\n";
                //system("pause");
                //system("clear");
            }
            break;
            
            case 2:
            signup();
            break;

            case 3:
            cout<<"<<Car Adder Menu>>\n";
            cout<<"Car Name: ";
            cin>>car_adder.car_name;
            cout<<"Cost: ";
            cin>>car_adder.cost;
            fout.write((char*)&car_adder, sizeof(car_adder));
            fout.close();

            case 4:
            break;

            default:
            cout<<"Wrong option!\n";
        }
    }
    return 0;
}

void main_menu()
{
    while(true)
    {
        system("pause");
        system("clear");
        cout<<"<<Main Menu>>\n";
        cout<<"1. Shop\n";
        cout<<"2. Your Orders\n";
    }
}