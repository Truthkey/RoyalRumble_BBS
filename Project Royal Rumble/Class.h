#include <iostream>
#include <stdio.h>
 
using namespace std;

class B
{
private:
	char Mbeacon[8];
	char tmp[8];
	unsigned long beacon;
	char x[8];
	int tmp2;
    void Scan(FILE *g);
};

void B::Scan(FILE *g)
{
    printf("\nInput the name of the character you want to hack:");
			cin >> Mbeacon;
			if(g)
			{
				for(int i=0x0111FFFF; i<0x012000000; i+=0x2)
				{
					fseek(g,i,SEEK_SET);
					cout << "Current offset:" << hex << i;
					fread(tmp,1,0x7,g);
					cout << "			" << ((i/0x01200000)*100) << endl;

					int result;
					result = strcmp( tmp , Mbeacon );

					if ( result == 0 )
					{
						printf("BEACON FOUND!!\n");
						cout << hex << i << endl << endl;
						beacon = i;

						fseek(g, beacon,SEEK_SET);
						fread(&x,1,0x7,g);
						fseek(g,(beacon + 0x180),SEEK_SET);
						fread(&tmp2,1,sizeof(int),g);
						char name[35];

						sprintf(name,"Royal Rumble Codes for %s.txt",x);

						ofstream myfile;
						myfile.open (name);
						myfile << "_C0 Beacon Hacked" << endl;
						myfile << "_L 0x0" << hex << (beacon + 0x10C) << " 0x00000002" << endl;
						myfile << "_L 0x0" << hex << (beacon + 0x160) << " 0x00000089" << endl;
						myfile << "_L 0x2" << hex << (beacon + 0x164) << " 0x43b70000" << endl;
						myfile << "_L 0x0" << hex << (beacon + 0x1A8) << " 0x000000XX" << endl;
						myfile << "Character ID for Target/Camera mod:" << hex << (tmp2 - 0x1) << endl;
						myfile << "Character hacked:" << x << endl << endl;
						myfile << "Add the digit for the character you want to target in the XX" << endl << endl;
						myfile << "///This part will only work if the character you hacked was the first in the dump///" << endl;
						myfile << "_C0 Camera Mod + Camera point to" << endl;
						myfile << "_L 0x0" << hex << (beacon - 0x398) << " 0x000000XX" << endl;
						myfile << "_L 0x0" << hex << (beacon - 0x394) << " 0x000000XX" << endl;
						myfile.close();
						printf("Codes hacked! Check the file created in the folder you ran this program in!\n");
						system("pause");
						system("CLS");
						break;
					}
				}
			}
			else
			{
				printf("File not opened properly D:");
			}
			fclose(f);
    return;
}