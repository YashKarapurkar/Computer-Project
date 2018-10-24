#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include "login.cpp" // Has user credentials access class and functions
#include "shop_list.cpp" // Has the car class

using namespace std;

char username_glo[20];

int main()
{

    void main_menu();

    char username[20], password[20], ch='y';
    ifstream fin("secure.dat", ios::in|ios::binary);
    
    int dec, ret, ext = 0;
    car car_adder;

    while(true)
    {
        ext = 0;
        system("pause");
        system("clear");
        cout<<"\t\t<<Welcome to Auto-Expo 2018>>\n";
        cout<<"\t\t1. Have an account? - LOG-IN\n";
        cout<<"\t\t2. Join Us! - SIGN-UP\n";
        cout<<"\t\t3. Add Cars\n";
        cout<<"\t\t4. Exit\n";
        cout<<"\t\tInput: \n";
        cin>>dec;
        ofstream fout("cars.DB", ios::app|ios::binary);
        //system("pause");

        switch(dec)
        {
            case 1:
            //system("clear");
            cout<<"\t\t<<Log - In>>\n";
            cout<<"\t\tUsername: ";
            cin>>username;
            cout<<"\t\tPassword: ";
            cin>>password;

            ret = verify(username, password);

            if(ret == 2)
            {
                strcpy(username_glo, username);
                main_menu();
            }
            else if(ret == 1)
            {
                cout<<"\t\tWrong Credentials!\n";
                //system("pause");
                //system("clear");
            }
            break;
            
            case 2:
            signup();
            break;

            case 3:
            system("clear");
            cout<<"\t\t<<Car Adder Menu>>\n";
            car_adder.get_data();
            
            fout.write((char*)&car_adder, sizeof(car_adder));
            fout.close();
            break;

            case 4:
            ext = 1;
            break;

            default:
            cout<<"\t\tWrong option!\n";
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
        cout<<"\t\t<<Main Menu>>\n";
        cout<<"\t\t1. Shop\n";
        cout<<"\t\t2. Your Orders\n";
        cout<<"\t\t3. Exit\n";
        cout<<"\t\tInput: ";
        cin>>dec;

        switch(dec)
        {
            case 1:
            cout<<"\t\t<<Shop>>\n";
            shop_list(username_glo);
            break;

            case 2:
            cout<<"\t\t<<Orders>>";
            order_list(username_glo);
            break;

            case 3:
            ext = 1;
            break;

            default:
            cout<<"\t\tWrong Option!\n";
        }

        if(ext == 1)
        {
            break;
        }
    }
}