#include <iostream>
#include <fstream>

using namespace std;

#define ulong unsigned long

class GetBeacon{
private:
	//Required variables.
	ulong beacon;
	char name[35];
	char x[8];
	int tmp2;
public:
	//Objects to call.
	void calculate_print(ulong beacon);
	void calculate_print_plus(ulong beacon,char name[35],char x[8], int tmp2);
};

void GetBeacon::calculate_print(ulong beacon)
{
	ofstream myfile;
	myfile.open ("Royal Rumble Codes.txt");
	myfile << "_C0 Beacon Hacked" << endl;
	myfile << "_L 0x" << hex << (beacon + 0x10C) << " 0x00000002" << endl;
	myfile << "_L 0x" << hex << (beacon + 0x160) << " 0x00000089" << endl;
	myfile << "_L 0x" << hex << (beacon + 0x164) << " 0x43b70000" << endl;
	myfile << "_L 0x" << hex << (beacon + 0x1A8) << " 0x000000XX" << endl;
	myfile.close();
}

void GetBeacon::calculate_print_plus(ulong beacon,char name[35],char x[8], int tmp2)
{
	ofstream myfile;
	myfile.open (name);
	myfile << "_C0 Beacon Hacked" << endl;
	myfile << "_L 0x0" << hex << (beacon + 0x10C) << " 0x00000002" << endl;
	myfile << "_L 0x0" << hex << (beacon + 0x160) << " 0x00000089" << endl;
	myfile << "_L 0x2" << hex << (beacon + 0x164) << " 0x43b70000" << endl;
	myfile << "_L 0x0" << hex << (beacon + 0x1A8) << " 0x000000XX" << endl;
	myfile << "Character ID for Target mod:" << hex << (tmp2 - 0x1) << endl;
	myfile << "Character used:" << x << endl << endl;
	myfile.close();
}