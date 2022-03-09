#ifndef WR_SCAN_HEADER
#define WR_SCAN_HEADER

#include <stdio.h>
#include <curl/curl.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define KBLK  "\x1B[30m"


void WR_Scan()
{
  CURL *curl;
  CURLcode res;
  
  char ip[100];
  char querylink[150];
  
  printf("\n%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n", KYEL);
  printf("%s                 SERVER INFO SUB-MODUL              \n", KWHT);
  printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n \n", KYEL);

  printf("%s  IP Adresse / Server >> ", KWHT);
  scanf("%99s", ip);
  fflush(stdin);
  
  printf("\n");
  
  //====================================================================================================
  //                                      ALLGEMEINE INFORMATIONEN
  //====================================================================================================
  
  printf(" %s────────────────────────────────────────────────── \n", KYEL);
  printf(" %s              ALLGEMEINE INFORMATIONEN             \n", KWHT);
  printf(" %s────────────────────────────────────────────────── \n \n%s", KYEL, KWHT);
  
  //IP ADRESSE
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=query&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" IP Adresse : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  
  //REVERSE
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=reverse&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Reverse DNS : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  //MOBILE
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=mobile&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Mobile : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  //MOBILE
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=proxy&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Proxy : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  //HOSTING
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=hosting&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Hosting : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  //====================================================================================================
  //                                     FIRMA INFORMATIONEN 
  //====================================================================================================
  
  printf("\n%s ────────────────────────────────────────────────── \n", KYEL);
  printf("%s                 FIRMA INFORMATIONEN                 \n", KWHT);
  printf("%s ────────────────────────────────────────────────── \n \n%s", KYEL, KWHT);

  //ORGANISATION
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=org&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Organisation : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  
  //INTERNETDIENSTANBIETER
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=isp&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Internetdienstanbieter : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  //AUTONOMES SYSTEM
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=as&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Autonomes System : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  //AUTONOMES SYSTEM NAME
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=asname&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Autonomes System Name : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  //====================================================================================================
  //                                     LOKALISIERUNGSINFORMATIONEN 
  //====================================================================================================
  
  printf("\n%s ────────────────────────────────────────────────── \n", KYEL);
  printf("%s             LOKALISIERUNGSINFORMATIONEN            \n", KWHT);
  printf("%s ────────────────────────────────────────────────── \n \n%s", KYEL, KWHT);

  //KONTINENT
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=continent&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Kontinent : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  
  //KONTINENTCODE
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=continentCode&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Kontinent Code : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }


  //LAND
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=country&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Land : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  
  //LANDCODE
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=countryCode&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Land Code : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  
  //REGION
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=regionName&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Region : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  
  //REGIONCODE
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=region&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Region Code : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  
  //STADT
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=city&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Stadt : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  
  //ZIP
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=zip&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" ZIP Code : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  
  //ZEITZONE
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=timezone&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Zeitzone : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  
  //BREITENGRAD
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=lat&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Breitengrad : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
  }
  
  
  //LÄGENGRAD
  curl = curl_easy_init();
  if(curl) {
  
    //Query
    sprintf(querylink, "http://ip-api.com/csv/%s?fields=lon&lang=de", ip);
  
    curl_easy_setopt(curl, CURLOPT_URL, querylink);

    /* LIBCURL Redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Query --> Res */
    printf(" Lägengrad : ");
    res = curl_easy_perform(curl);
    
    /* Fehler Überprüfung ? */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
              curl_easy_strerror(res));

    /* Cleanup */
    curl_easy_cleanup(curl);
    
    char g_otp[3];
    
    printf("\n %3sSpeichern ? [J/N] >> ", KYEL);
    scanf("%2s", &g_otp);
    fflush(stdin);

    if( strcmp ("J", g_otp) == 0)
    {
    	char otp[100];
	sprintf(otp, "%s.txt", ip);
	
	FILE *f = fopen(otp, "w");
		
	if (f == NULL)
	{
		printf("%s Fehler beim Speichern der Ausgabe.\n", KRED);
		exit(1);
	}
	
	  fprintf(f, "\n%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n", KYEL);
  	  fprintf(f, "%s                 SERVER INFO SUB-MODUL              \n", KWHT);
  	  fprintf(f, "%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n \n", KYEL);

	  fprintf(f, " %s────────────────────────────────────────────────── \n", KYEL);
	  fprintf(f, " %s              ALLGEMEINE INFORMATIONEN             \n", KWHT);
	  fprintf(f, " %s────────────────────────────────────────────────── \n \n%s", KYEL, KWHT);
	  
	  //IP ADRESSE
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=query&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " IP Adresse : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  
	  //REVERSE
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=reverse&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Reverse DNS : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  //MOBILE
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=mobile&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Mobile : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  //MOBILE
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=proxy&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Proxy : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  //HOSTING
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=hosting&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Hosting : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  //====================================================================================================
	  //                                     FIRMA INFORMATIONEN 
	  //====================================================================================================
	  
	  fprintf(f, "\n%s ────────────────────────────────────────────────── \n", KYEL);
	  fprintf(f, "%s                 FIRMA INFORMATIONEN                 \n", KWHT);
	  fprintf(f, "%s ────────────────────────────────────────────────── \n \n%s", KYEL, KWHT);

	  //ORGANISATION
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=org&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Organisation : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  
	  //INTERNETDIENSTANBIETER
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=isp&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Internetdienstanbieter : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  //AUTONOMES SYSTEM
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=as&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Autonomes System : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  //AUTONOMES SYSTEM NAME
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=asname&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Autonomes System Name : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  //====================================================================================================
	  //                                     LOKALISIERUNGSINFORMATIONEN 
	  //====================================================================================================
	  
	  fprintf(f, "\n%s ────────────────────────────────────────────────── \n", KYEL);
	  fprintf(f, "%s             LOKALISIERUNGSINFORMATIONEN            \n", KWHT);
	  fprintf(f, "%s ────────────────────────────────────────────────── \n \n%s", KYEL, KWHT);

	  //KONTINENT
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=continent&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Kontinent : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  
	  //KONTINENTCODE
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=continentCode&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Kontinent Code : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }


	  //LAND
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=country&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Land : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  
	  //LANDCODE
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=countryCode&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Land Code : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  
	  //REGION
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=regionName&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Region : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  
	  //REGIONCODE
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=region&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Region Code : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  
	  //STADT
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=city&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Stadt : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  
	  //ZIP
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=zip&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " ZIP Code : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  
	  //ZEITZONE
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=timezone&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Zeitzone : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  
	  //BREITENGRAD
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=lat&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Breitengrad : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	  }
	  
	  
	  //LÄGENGRAD
	  curl = curl_easy_init();
	  if(curl) {
	  
	    //Query
	    sprintf(querylink, "http://ip-api.com/csv/%s?fields=lon&lang=de", ip);
	  
	    curl_easy_setopt(curl, CURLOPT_URL, querylink);

	    /* LIBCURL Redirection */
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    /* Query --> Res */
	    fprintf(f, " Lägengrad : ");
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	    res = curl_easy_perform(curl);

	    
	    /* Fehler Überprüfung ? */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() Fehler: %s\n",
		      curl_easy_strerror(res));

	    /* Cleanup */
	    curl_easy_cleanup(curl);
	}
		
	fclose(f);
		
	printf("\n %sAusgabe gespeichert als : %s \n", KWHT, otp);
    }
  }
}

#endif
