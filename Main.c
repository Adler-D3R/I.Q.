#include "Headers/S_Scan.h"
#include "Headers/GZ_Scan.h"
#include "Headers/F_Scan.h"
#include "Headers/WR_Scan.h"
#include "Headers/SN_Scan.h"
#include "Headers/QH_Scan"

#include <stdio.h>
#include <string.h>
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
	char auswahl[3];

	printf ("\n");
	printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n", KYEL);
	printf("%s             	       HAUPTMENÜ                      \n", KWHT);
	printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n", KYEL);
	
	printf ("\n");
	
	printf("%s  0. I.Q. Verlassen \n", KYEL);
	printf("%s  1. Port-Scanner \n", KWHT);
	printf("%s  2. Query Header Analysieren \n", KWHT);
	printf("%s  3. Server Info Bekommen \n", KWHT);
	printf("%s  4. Subnetzwerk Scan \n", KWHT);

	printf ("\n  Modul >> ");
	scanf("%2s", auswahl);
	fflush(stdin);

	if(strcmp(auswahl, "0") == 0)
	{
	        printf("\n%s I.Q. schaltet sich ab... \n \n", KYEL);
	        exit(0);
	}
	else if(strcmp(auswahl, "1") == 0)
	{
	        PortScanMenu();
	        HauptMenu();
	}
	else if(strcmp(auswahl, "2") == 0)
	{
	        QH_Scan();
	        HauptMenu();
	}
	else if(strcmp(auswahl, "3") == 0)
	{
	        WR_Scan();
	        HauptMenu();
	}
	else if(strcmp(auswahl, "4") == 0)
	{
	        SN_Scan();
	        HauptMenu();
	}
	else
	{
	        printf("\n%s Bitte wählen Sie eine Modul-Nummer. \n", KRED);
	        HauptMenu();
	}

}

void PortScanMenu()
{
	char p_auswahl[3];

	printf ("\n");
	printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n", KYEL);
	printf("%s             	   PORT SCANNER MENÜ                 \n", KWHT);
	printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n", KYEL);
	
	printf ("\n");
	
	printf("%s  0. Zurück Gehen \n", KYEL);
	printf("%s  1. Schnell Port Scan \n", KWHT);
	printf("%s  2. Gezielter Port Scan \n", KWHT);
	printf("%s  3. Full Port Scan \n", KWHT);
	
	printf ("\n  Modul >> ");
	scanf("%2s", p_auswahl);

	if(strcmp(p_auswahl, "0") == 0)
	{
	        HauptMenu();
	}
	else if(strcmp(p_auswahl, "1") == 0)
	{
	        S_Menu();
	}
	else if(strcmp(p_auswahl, "2") == 0)
	{
	        GZ_Menu();
	}
	else if(strcmp(p_auswahl, "3") == 0)
	{
	        F_Menu();
	}
	else
	{
	        printf("\n%s Bitte wählen Sie eine Modul-Nummer. \n", KRED);
	        PortScanMenu();
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
