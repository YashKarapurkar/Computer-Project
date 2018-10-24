#include<fstream>
#include<iostream>

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

void shop_list()
{
    int dec;
    char ch;
    car car_reader;
    ifstream fin("car.DB", ios::in|ios::binary);
    cout<<"\t\tModel\n";
    while(fin.read((char*)&car_reader, sizeof(car_reader)))
    {
        cout<<"\t\t"<<car_reader.index<<". "<<car_reader.modelName<<endl;
    }
    cout<<"\t\tInput: ";
    cin>>dec;
    fin.close();

    ifstream fin2("car.DB", ios::in|ios::binary);

    while(fin2.read((char*)&car_reader, sizeof(car_reader)))
    {
        if(dec == car_reader.indx())
        {
            car_reader.display();
            cout<<"\t\tBuy Now!(y/n): ";
            cin>>ch;
        }
    }
}