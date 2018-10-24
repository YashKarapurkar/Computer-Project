#include<fstream>
#include<string.h>

using namespace std;

class file_reader
{
	public:
	char username[20], password[20];
};

class order
{
	public:
	int ord[5];
};

/*int main()
{
	ofstream fout("secure.dat", ios::out|ios::binary);
	file_reader id;

	strcpy(id.username, "admin");
	strcpy(id.password, "admin");

	fout.write((char*)&id, sizeof(id));
	fout.close();
	return 0;
}*/

int main()
{
	ofstream fout("cars.DB", ios::out|ios::binary);
	fout.close();
	return 0;
}

