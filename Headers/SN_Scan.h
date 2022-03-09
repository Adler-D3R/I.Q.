#ifndef SN_SCAN_HEADER
#define SN_SCAN_HEADER

#include <stdio.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define KBLK  "\x1B[30m"


void SN_Scan()
{
  printf("\n%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n", KYEL);
  printf("%s                   SUBNETZWERK SCAN                \n", KWHT);
  printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n \n", KYEL);
  
  printf("%s  Lokale IP A.     MAC Adresse        Hostname \n", KYEL);
  
  system("echo '\033[0;37m'");
  system("printf '   ' && sudo arp-scan -x --localnet | awk 1 ORS='\n   '");
  
  char g_otp[3];
	
  printf("\n %3sSpeichern ? [J/N] >> ", KYEL);
  scanf("%2s", &g_otp);

  if( strcmp ("J", g_otp) == 0 || strcmp ("j", g_otp) == 0)
  {
	char otp[100];
	sprintf(otp, "Subnetzwerk-Scan.txt");
	
	FILE *f = fopen(otp, "w");
		
	if (f == NULL)
	{
		printf("%s Fehler beim Speichern der Ausgabe.\n", KRED);
		exit(1);
	}
	
	fprintf(f, "\n%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n", KYEL);
	fprintf(f, "%s                   SUBNETZWERK SCAN                \n", KWHT);
	fprintf(f, "%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n \n", KYEL);
	
	fprintf(f, "%s  Lokale IP A.     MAC Adresse        Hostname \n", KYEL);
	fprintf(f, "\n%s   ", KWHT);
	
	fclose(f);

	system("printf '   ' && sudo arp-scan -x --localnet | awk 1 ORS='\n   ' >> Subnetzwerk-Scan.txt");
		
	printf("\n %sAusgabe gespeichert als : %s \n", KWHT, otp);
  }
  
}

#endif
