#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include "login.cpp"

using namespace std;

class car
{
public:
    int index;
	char modelName[30], engine[10];
    int horsePower;
	float cost;

    void get_data()
    {
        cout<<"Index No: ";
        cin>>index;
        cout<<"Model Name: ";
        cin>>modelName;
        cout<<"Engine: ";
        cin>>engine;
        cout<<"Horse Power: ";
        cin>>horsePower;
        cout<<"Cost(In Dollars): ";
        cin>>cost;
    }

    void display()
    {
        cout<<"Index No: "<<index<<endl;
        cout<<"Model Name: "<<modelName<<endl;
        cout<<"Engine: "<<engine<<endl;
        cout<<"Horse Power: "<<horsePower<<endl;
        cout<<"Cost: "<<cost<<" Million $"<<endl<<endl;
    }

    int indx()
    {
        return index;
    }
};

int main()
{

    void main_menu();

    char username[20], password[20];
    ifstream fin("secure.dat", ios::in|ios::binary);
    ofstream fout("cars.DB", ios::app|ios::binary);
    int dec, ret, ext = 0;
    car car_adder, reader;

    while(true)
    {
        ext = 0;
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
            car_adder.get_data();
            fout.write((char*)&car_adder, sizeof(car_adder));
            fout.close();

            case 4:
            ext = 1;
            break;

            default:
            cout<<"Wrong option!\n";
        }

        if(ext == 1)
        {
            break;
        }
    }
    return 0;
}

void main_menu()
{
    int dec, ext=0;
    while(true)
    {
        ext = 0;
        system("pause");
        system("clear");
        cout<<"<<Main Menu>>\n";
        cout<<"1. Shop\n";
        cout<<"2. Your Orders\n";
        cout<<"3. Exit\n";
        cout<<"Input: ";
        cin>>dec;

        switch(dec)
        {
            case 1:
            cout<<"Shop";
            break;

            case 2:
            cout<<"Orders";
            break;

            case 3:
            ext = 1;
            break;

            default:
            cout<<"Wrong Option!\n";
        }

        if(ext == 1)
        {
            break;
        }
    }
}