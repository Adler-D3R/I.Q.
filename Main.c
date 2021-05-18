#include "Headers/S_Scan.h"
#include "Headers/GZ_Scan.h"
#include "Headers/F_Scan.h"
#include "Headers/WR_Scan.h"
#include "Headers/SN_Scan.h"

#include<stdio.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define KBLK  "\x1B[30m"

void Logo()
{
	printf("\n");
	printf("                     %s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n", KBLK);
	printf("                     %s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n", KBLK);
	printf("                     %s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n", KBLK);
	printf("                     %s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s/#%s@@@@@\n", KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s///%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s(%s@@@@@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s//////%s@@@%s/%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s@@##%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s/////////%s@@@%s/(%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s////////////%s@@@%s**%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s@@@@#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s/////////////**%s@@@%s**%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s///////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s////////////******%s@@@%s**#%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s///////////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s///////////***%s@@@@@%s/%s@@@@%s(*/%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s*****//////////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s//////////******%s@@@@@@@@@@@%s/*/%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s*********/////////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s////////**********#%s@@@@@%s*&%s@@@@@%s**%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s**%s@@@@@%s**************////////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s@@@@@@@@@@@@@@@@@&%s********#%s@@@@@%s*#%s@@@@@%s**%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s&**%s@@@@@@%s#***********(%s@@@@@@@@@@@@@\n", KBLK, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf(" %s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&%(@@@@@@%s*********%s@@@@@%s*%s@@@@@@%s**#%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s#***********%s@@@@@@&#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("   %s@@@@%ss&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%s#@@@@@&%s********%s@@@@@@@@@@@@@%s**%s@@@@@@@@@@@%s&*%s@@@@@@@@@@@%s&**********/%s@@@@@@,%s&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%s.@@@@\n", KBLK, KWHT, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK, KWHT, KBLK);
	printf("     %s@@@@*%s&&&&&&&&&&&&&&&&&&&&&&&%s&&&%s&&&&&&&%s@@@@@@%s********#%s@@@/@@@@@@@@@%s*%s@@@@@@@@@@@@@@@@@@@%s**********%s@@@@@@@%s&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%s@@@@\n", KBLK, KWHT, KWHT, KWHT, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK, KWHT, KBLK);
	printf("      %s*@@@@.%s&&&&&&&&&&&&%s.@@@@@@@@@@@@@@*%s&&&&&&%s@@@@@@&%s********%s@@@@@@@@@@@@@@@@@@@@@@@@@@@%s*********/%s@@@@@@(%s&&&&&&%s/@@@@@@@@@@@@@%s&&&&&&&&&&&&&&&%s@@@@@\n", KBLK, KWHT, KBLK, KWHT, KBLK, KYEL, KBLK, KYEL, KBLK, KWHT, KBLK, KWHT, KBLK);
	printf("        %s%@@@@%s&&&&&&&&&&&%s@@@@@@@@@@@@@@@#%s&&&&&&&&&%s/@@@@@@%s********#%s@@@@@@@@@@@@@@@@@@@@%s/********%s@@@@@@@%s&&&&&&&&&&%s@@@@@@@@@@@@@@@@%s&&&&&&&&&&&%s@@@@@\n", KBLK, KWHT, KBLK, KWHT, KBLK, KYEL, KBLK, KYEL, KBLK, KWHT, KBLK, KWHT, KBLK);
	printf("          %s@@@@@%s&&&&&&&&%s.@@@@@@@@@@@@@@@#%s&&&&&@*&&&&&&%s@@@@@@&%s********%s@@@@@@@@@@@@@@%s&*******/%s@@@@@@&%s&&&&&&&&&&&&&%s@@@@@@@@@@@@@@@@&%s&&&&&&&&%s&@@@@\n", KBLK, KWHT, KBLK, KWHT, KBLK, KYEL, KBLK, KYEL, KBLK, KWHT, KBLK, KWHT, KBLK);
	printf("            %s@@@@@%s&&&&&&&%s@@@@@@@@@@@@%s&&%s@#%s&&&&&%s@@@@@%s&&&&&&%s&@@@@@@%s*********%s@@@@@@@@%s,******%s@@@@@@@.%s&&&&&&%s@@@@@%s&&&&&%s@@%s&&%s#@@@@@@@@@@@@%s&&&&&&%s(@@@@\n", KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KYEL, KBLK, KYEL, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK);
	printf("              %s@@@@@%s&&&&&%s@@@@@@@@@@@@%s&&&&&&&&&%s@@@@@@@@.%s&&&&&%s.@@@@@@&%s**,,,,,,%(%s(,,,***%s@@@@@@@%s&&&&&&%s@@@@@@@@@%s&&&&&&&&&%s@@@@@@@@@@@@%s&&&&&%s,@@@@\n", KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KYEL, KYEL, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK);
	printf("                %s@@@@&%s&&&&%s@@@@@@@@@@@%s&&&&&&&&&%s@@@@@@@@@@@@%s&&&&&&%s@@@@@@@%s*,,,,,,,,,%s@@@@@@@/%s&&&&&%s.@@@@@@@@@@@@%s&&&&&&&&&%s@@@@@@@@@@@%s&&&&&%s@@@@@\n", KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KYEL, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK);
	printf("                 %s/@@@@(%s&&&%s @@@@@@@@@/%s&&%s*%s&&&&&%s@@@@@@@@@@@@@%s&&&&&&&&%s#@@@@@@&%s,,*%s@@@@@@@%s&&&&&&&&&%s@@@@@@@@@@@@.%s&&&&&%s@%s&&%s@@@@@@@@@@(%s&&&&%s@@@@@\n", KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KYEL, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK);
	printf("                   %s&@@@@,%s&&&&%s@@@@@@@&%s&&%s@@*%s&&&%s@@@@@@@@@@@@@%s&&&&&&&&&&&&%s@@@@@@@@@@@%s&&&&&&&&&&&&%s(@@@@@@@@@@@(%s&&&%s@@(%s&&%s@@@@@@@@#%s&&&&%s@@@@@\n", KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK);
	printf("                     %s@@@@@%s&&&&&&%s@@@@@%s&&%s@@@@/%s&%s@@@@@@@@@@@@%s&&&&&&&%s@@@@@@@@@@@@@@@@@@@@@@%s&&&&&&&&&%s@@@@@@@@@@@%s&%s@@@@&%s&&%s*@@@@@@%s&&&&&%s@@@@@\n", KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK);
	printf("                     %s@@@@@@@%s&&&&&&&&%s@%s&&%s@@@@@@@@@@@@@@@%s&&&&&&&&%s@@@@@@@@@@&((%@@@@@@@@@@@@*%s&&&&&&&&%s@@@@@@@@@@@@@@@%s&&%s@@.%s&&&&&&%s@@@@@@@\n", KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK, KWHT, KBLK);
	printf("                     %s@@@@@@@@@@%s&&&&&&&&&&&%s,#&&//%s&&&&&&&&&&&%s@@@@@%s********(@@@@%s#*********%s@@@@*%s&&&&&&&&&&&%s#&@@&#,%s&&&&&&&&&&%s@@@@@@@@@@\n", KBLK, KWHT, KBLK, KWHT, KBLK, KYEL, KYEL, KBLK, KWHT, KBLK, KWHT, KBLK);
	printf("                     %s@@@@@%s//%s@@@@@@@%s&&&&&&&&&&&&&&&&&&&&%s&@@@@@%s*******&@/**%s@@@@%s************(%s@@@@@@%s&&&&&&&&&&&&&&&&&&&%s@@@@@@@@%s/#%s@@@@@\n", KBLK, KYEL, KBLK, KWHT, KBLK, KYEL, KBLK, KYEL, KBLK, KWHT, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s//////%s@@@@@@@@@@%(**#&@@@@@@@@@%s*******@&**/%s@@@@@@@@@@@@%s***@&*******&%s@@@@@@@@@@@@@@@@@@@@@@@@@%s%////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s///////******&%s@@@@@@@@@@%s**********@/***%s@@@@@@@@@@@@@@@@@@@@%s/**@@*********&%s@@@@@@@@@@@@@%s&***///////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s////////*********************(@***%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s*#@&**********************////////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s/////////****************%@**/%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s&*****************/////////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s//////////***********@&**%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s&************//////////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s///////////******@@**%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s&*******///////////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s////////////(%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s#**////////////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s/////////%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s(//////////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@%s////%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s///////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@@@@@@@@%s(/%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s////#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@@@%s&//%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s//#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s#%s@@@@@\n", KBLK, KYEL, KBLK, KYEL, KBLK);
	printf("                     %s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n", KBLK);
	printf("                     %s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n", KBLK);
	printf("                     %s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n", KBLK);
	printf("\n \n ");
	
	printf ("%s                                      _____ _____                       ___      _ _          ______ _____ _____  \n ", KYEL);
	printf ("%s                                     |_   _|  _  |               ____  / _ \\    | | |         | ___ \\  _  |  __ \\ \n ", KYEL);
	printf ("%s                                       | | | | | |    ______    / __ \\/ /_\\ \\ __| | | ___ _ __| |_/ / | | | |  \\/ \n ", KYEL);
	printf ("%s                                       | | | | | |   |______|  / / _` |  _  |/ _` | |/ _ \\ '__|    /| | | | | __  \n ", KYEL);
	printf ("%s                                      _| |_\\ \\/' /_           | | (_| | | | | (_| | |  __/ |  | |\\ \\\\ \\_/ / |_\\ \\ \n ", KYEL);
	printf ("%s                                      \\___(_)_/\\_(_)           \\ \\__,_\\_| |_/\\__,_|_|\\___|_|  \\_| \\_|\\___/ \\____/ \n ", KYEL);
	printf ("%s                                                                \\____/                                            \n ", KYEL);
	printf ("%s                                                                                                                  \n\n\n ", KYEL);
}

void PortScanMenu();
void TimeoutMenu();
void Uppercase();

void HauptMenu()
{
	int auswahl;

	printf ("\n");
	printf("%s ==================================================\n", KYEL);
	printf("%s             	       HAUPTMENÜ                      \n", KWHT);
	printf("%s ==================================================\n", KYEL);
	
	printf ("\n");
	
	printf("%s  0. I.Q. Verlassen \n", KYEL);
	printf("%s  1. Port-Scanner \n", KWHT);
	printf("%s  2. Server Info Bekommen \n", KWHT);
	printf("%s  3. Subnetzwerk Scan \n", KWHT);
	
	printf ("\n  Modul >> ");
	scanf("%d", &auswahl);
	
	if (auswahl == 0)
	{
		printf("\n%s I.Q. schaltet sich ab... \n", KYEL);
		exit(0);
	}
	else if (auswahl == 1)
	{
		PortScanMenu();
		HauptMenu();
	}
	else if (auswahl == 2)
	{
		WR_Scan();
		HauptMenu();
	}
	else if (auswahl == 3)
	{
		SN_Scan();
		HauptMenu();
	}
	else
	{
		printf("\n%s Bitte wählen Sie eine Modul-Nummer.", KRED);
		HauptMenu();
	}
}

void PortScanMenu()
{
	int p_auswahl;

	printf ("\n");
	printf("%s ==================================================\n", KYEL);
	printf("%s             	   PORT SCANNER MENÜ                 \n", KWHT);
	printf("%s ==================================================\n", KYEL);
	
	printf ("\n");
	
	printf("%s  0. Zurück Gehen \n", KYEL);
	printf("%s  1. Schnell Port Scan \n", KWHT);
	printf("%s  2. Gezielter Port Scan \n", KWHT);
	printf("%s  3. Full Port Scan \n", KWHT);
	
	printf ("\n  Modul >> ");
	scanf("%d", &p_auswahl);
	
	if (p_auswahl == 0)
	{
		HauptMenu();
	}
	else if (p_auswahl == 1)
	{
		S_Menu();
	}
	else if (p_auswahl == 2)
	{
		GZ_Menu();
	}
	else if (p_auswahl == 3)
	{
		F_Menu();
	}
	else
	{
		printf("\n%s Bitte wählen Sie eine Modul-Nummer.", KRED);
		HauptMenu();
	}
}

int main(int argc, char *argv[])
{
	Logo();
	HauptMenu();
	return 0;
}

int isdigit_str(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9') return 0;
	return 1;
}
