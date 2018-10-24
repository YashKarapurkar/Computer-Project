#include<fstream>
#include<iostream>
#include<string.h>

using namespace std;

class car
{
public:
    int index;
	char modelName[30], engine[50];
    int horsePower;
	float cost;

    void get_data()
    {
        cout<<"\t\tIndex No: ";
        cin>>index;
        cout<<"\t\tModel Name: ";
        cin>>modelName;
        cout<<"\t\tEngine: ";
        cin>>engine;
        cout<<"\t\tHorse Power: ";
        cin>>horsePower;
        cout<<"\t\tCost(In Dollars): ";
        cin>>cost;
    }

    void display()
    {
        cout<<"\t\tIndex No: "<<index<<endl;
        cout<<"\t\tModel Name: "<<modelName<<endl;
        cout<<"\t\tEngine: "<<engine<<endl;
        cout<<"\t\tHorse Power: "<<horsePower<<endl;
        cout<<"\t\tCost: "<<cost<<" Million $"<<endl<<endl;
    }

    int indx()
    {
        return index;
    }
};

class ord_read
{
    public:
    char username[20];
    int product_no;
};

void shop_list(char username[20])
{
    int dec;
    char ch;
    car car_reader;
    ifstream fin("car.DB", ios::in|ios::binary);
    cout<<"\t\tModel\n";
    while(fin)
    {
        fin.read((char*)&car_reader, sizeof(car_reader));
        cout<<"\t\t"<<car_reader.index<<". "<<car_reader.modelName<<endl;
    }
    cout<<"\t\tInput: ";
    cin>>dec;
    fin.close();

    ord_read user;
    strcpy(user.username, username);
    user.product_no = dec;

    ifstream fin2("car.DB", ios::in|ios::binary);

    while(fin2.read((char*)&car_reader, sizeof(car_reader)))
    {
        if(dec == car_reader.indx())
        {
            car_reader.display();
            cout<<"\t\tBuy Now!(y/n): ";
            cin>>ch;
            if(ch == 'y' || ch == 'Y')
            {
                ofstream fout("order_list.od", ios::app|ios::binary);
                fout.write((char*)&user, sizeof(user));
                fout.close();
            }
            break;
        }
    }
}

void order_list(char username[20])
{
    ifstream fin("order_list", ios::in|ios::binary);
    ifstream fin2("car.DB", ios::in|ios::binary);
    ord_read reader;
    car car_info;
    while(fin.read((char*)&reader, sizeof(reader)))
    {
        if(strcmp(username, reader.username) == 0)
        {
            while(fin2.read((char*)&car_info, sizeof(car_info)))
            {
                if(reader.product_no == car_info.index)
                {
                    car_info.display();
                    //system("pause");
                    //system("clear");
                }
            }
        }
    }
}