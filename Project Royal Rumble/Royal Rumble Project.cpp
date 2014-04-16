#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <direct.h>
#include <windows.h>
#include <string>
#include "GetBeacon.h"
#include "fSize.h"

#define ulong unsigned long
using namespace std;

int main(int argc, char *argv[])
{
	while(1)
	{
	system("TITLE Kingdom Hearts: Birth by Sleep - Mixed Tool 0.5");
	system("color 71");

		int a = 0;
		long ctdsize;
		int s = 0;
		int q =0;
		char Mbeacon[8];
		char tmp[8];
		ulong beacon = 0x0;
		char x[8];
		int detect=0;
		int detect2=0;
		int tmp2, size;
		char *buff;
		char *filenametm2=(char*)malloc(64);
		printf("///////////////////////////////////////////\n");
		printf("/////////////Mixed KH BBS Tool/////////////\n");
		printf("///////////////////////////////////////////\n");
		printf("Programmed by Truthkey/Keytotruth.\n\n");
		printf("WARNING: If you are going to use options 2 or 3 drag first\n the dump to the program.\n\n");

		cout << "Please choose an option:" << endl << "1)Beacon method" << endl << "2)Beacon method + ID hacking"
			 << endl << "3)Scanning (Experimental) [Works!]" << endl << "4)Extracting files from BBS0.dat" << endl;
		cout << "Option:";
		cin >> a;
		cout << endl;

		//Method 1: Typing Beacon manually to hack the codes.
		if (a==1)
		{
			printf("Please input the beacon adress: ");
			cin >> hex >> beacon;
			cout << endl << endl;

			GetBeacon b1;
			b1.calculate_print(beacon);
			
			printf("Codes hacked! Check the file created in the folder you ran this program in!\nPush anything to continue.");
			_getch();
			system("CLS");
		}
		//Method 2: Typing Beacon manually to hack the codes + Reading "Dump.bin" to get character ID.
		else if (a==2)
		{
			FILE *f = fopen(argv[1],"rb");
			size = fSize(f);

			if(f)
			{
			printf("Please input the beacon adress: ");
			cin >> hex >> beacon;
			cout << endl;

			fseek(f, beacon,SEEK_SET);
			fread(&x,1,0x7,f);
			fseek(f,(beacon + 0x180),SEEK_SET);
			fread(&tmp2,1,0x4,f);
			char name[35];

			sprintf_s(name,"Royal Rumble Codes for %s.txt",x);

			GetBeacon b2;
			b2.calculate_print_plus(beacon,name,x,tmp2);

			printf("Codes hacked! Check the file created in the folder you ran this program in!\nPush anything to continue.");
			_getch();
			system("CLS");
			}
			else
			{
				printf("You don't have 'Dump.bin' in this folder or the file doesn't have that name!");
			}
		}
		//Method 3: Type the model name whose codes you want to search for.
		else if (a==3)
		{
			printf("\nInput the name of the character you want to hack:");
			cin >> Mbeacon;

			FILE *f = fopen(argv[1],"rb");
			size = fSize(f);

			if(f)
			{
				for(int i=0x0111FFFF; i<=0x012000000; i+=0x2)
				{
					system("CLS");
					fseek(f,i,SEEK_SET);
					fread(tmp,1,0x7,f);

					if ( tmp == Mbeacon )
					{
						printf("BEACON FOUND!!\n");
						cout << hex << i << endl << endl;
						beacon = i;

						fseek(f, beacon,SEEK_SET);
						fread(&x,1,0x7,f);
						fseek(f,(beacon + 0x180),SEEK_SET);
						fread(&tmp2,1,sizeof(int),f);
						char name[35];

						sprintf_s(name,"Royal Rumble Codes for %s.txt",x);

						GetBeacon b3;
						b3.calculate_print_plus(beacon,name,x,tmp2);
						
						printf("Codes hacked! Check the file created in the folder you ran this program in!\nPush anything to continue.\n");
						_getch();
						break;
					}
				}
			}
			else
			{
				printf("File not opened properly D:");
			}
			fclose(f);
		}
		//Method 4: Extacting BBS0.dat stuff [Experimental]
		else if(a==4)
		{
			FILE *f=fopen("BBS0.DAT", "rb");
			size = fSize(f);
			int current = ftell(f);
			_mkdir("@CTD");
			if(f)
			{
				int i;
			cout << endl << "Extracting files:" << endl;

			for(i=0x28C707F0; i>0x2906AFE0;i+=0x10)
			{
				fseek(f,i,SEEK_SET);
				fread(&detect,1,0x4,f);

				if(detect == 0x44544340)
				{
					int current = (i+0x10);
					sprintf(filenametm2,"@CTD/CTD %d.ctd",s++);
					cout << filenametm2 << endl;
					
					for(q=current;q>0x2906AFE0;q+=0x10)
					{
						fseek(f,q,SEEK_SET);
						fread(&detect2,1,sizeof(int),f);

						if(detect2 == 0x44544340)
						{
							cout << "q: " << hex << q << endl
								 << "i: " << hex << i << endl;
							ctdsize = q-i;
							cout << hex << ctdsize << endl;
							break;
						}
					}
					fseek(f,i,SEEK_SET);
					FILE *fout = fopen(filenametm2,"w");
					fread(buff,1,ctdsize,f);
					fwrite(buff,1,ctdsize,f);
					free(buff);
					fclose(fout);
				}
			}
			}
			else{
				printf("File not correctly opened.");
				_getch();
			}
		
		}
		else{
			printf("Please, choose an option that actually exists.\n\n");
			system("pause");}
		system("CLS");
		}
}
