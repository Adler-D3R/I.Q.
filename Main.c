#include "Headers/S_Scan.h"
#include "Headers/GZ_Scan.h"
#include "Headers/F_Scan.h"
#include "Headers/WR_Scan.h"
#include "Headers/SN_Scan.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

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
	
	printf("%s                                       _____ _____               ___      _ _          ______ ___________   \n", KYEL);
	printf("%s                                      |_   _|  _  |             / _ \\    | | |         |  _  \\____ | ___ \\  \n", KYEL);
	printf("%s                                        | | | | | |    ______  / /_\\ \\ __| | | ___ _ __| | | |   / / |_/ /  \n", KYEL);
	printf("%s                                        | | | | | |   |______| |  _  |/ _` | |/ _ \\ '__| | | |   \\ \\    /   \n", KYEL);
	printf("%s                                       _| |_\\ \\/' /_           | | | | (_| | |  __/ |_ | |/ /.___/ / |\\ \\   \n", KYEL);
	printf("%s                                       \\___(_)_/\\_(_)          \\_| |_/\\__,_|_|\\___|_(_)|___/ \\____/\\_| \\_|  \n", KYEL);
	printf("%s                                                                                                            \n", KYEL);
	printf("%s                                                                                                            \n", KYEL);
}

void PortScanMenu();
void TimeoutMenu();
void Uppercase();

void HauptMenu()
{
	int auswahl;

	printf ("\n");
	printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n", KYEL);
	printf("%s             	       HAUPTMENÜ                      \n", KWHT);
	printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n", KYEL);
	
	printf ("\n");
	
	printf("%s  0. I.Q. Verlassen \n", KYEL);
	printf("%s  1. Port-Scanner \n", KWHT);
	printf("%s  2. Server Info Bekommen \n", KWHT);
	printf("%s  3. Subnetzwerk Scan \n", KWHT);

	char term;

	printf ("\n  Modul >> ");

	if(scanf("%3d%c", &auswahl, &term) != 2 || term != '\n')
        {
            HauptMenu();
        }

	switch(auswahl)
	{
		case 0:
			printf("\n%s I.Q. schaltet sich ab... \n \n", KYEL);
			exit(0);
			break;
		case 1:
			PortScanMenu();
			HauptMenu();
			break;
		case 2:
			WR_Scan();
			HauptMenu();
			break;
		case 3:
			SN_Scan();
			HauptMenu();
			break;
		default:
			printf("\n%s Bitte wählen Sie eine Modul-Nummer. \n", KRED);
			HauptMenu();
			break;
	}
}

void PortScanMenu()
{
	int p_auswahl;

	printf ("\n");
	printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n", KYEL);
	printf("%s             	   PORT SCANNER MENÜ                 \n", KWHT);
	printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n", KYEL);
	
	printf ("\n");
	
	printf("%s  0. Zurück Gehen \n", KYEL);
	printf("%s  1. Schnell Port Scan \n", KWHT);
	printf("%s  2. Gezielter Port Scan \n", KWHT);
	printf("%s  3. Full Port Scan \n", KWHT);
	
	char term;

	printf ("\n  Modul >> ");
	if(scanf("%3d%c", &p_auswahl, &term) != 2 || term != '\n')
	{
	    PortScanMenu();
	}

	switch(p_auswahl)
	{
		case 0:
			HauptMenu();
			break;
		case 1:
			S_Menu();
			break;
		case 2:
			GZ_Menu();
			break;
		case 3:
			F_Menu();
			break;
		default:
			printf("\n%s Bitte wählen Sie eine Modul-Nummer. \n", KRED);
			PortScanMenu();
			break;
	}
}

int main(int argc, char *argv[])
{

	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	if(w.ws_row > 25 && w.ws_col > 133)
	{
		Logo();
	}
        else
        {
                printf("\n%s                   ██╗    ██████╗      \n", KYEL);
		printf("%s                   ██║   ██╔═══██╗     \n", KYEL);
		printf("%s                   ██║   ██║   ██║     \n", KYEL);
		printf("%s                   ██║   ██║▄▄ ██║     \n", KYEL);
		printf("%s                   ██║██╗╚██████╔╝██╗  \n", KYEL);
		printf("%s                   ╚═╝╚═╝ ╚══▀▀═╝ ╚═╝  \n", KYEL);
        }

	HauptMenu();
	return 0;
}

int isdigit_str(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9') return 0;
	return 1;
}
