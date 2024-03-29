#ifndef F_SCAN_HEADER
#define F_SCAN_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define KBLK  "\x1B[30m"

int F_Scan_V(char *ip, int e_port, int l_port)
{
    struct addrinfo hts;
    struct addrinfo *ant;
    struct addrinfo *rcd;

    memset(&hts, 0, sizeof(hts));
    hts.ai_family = AF_INET;
    hts.ai_socktype = SOCK_STREAM;

    int p_total = l_port - e_port + 1;
    int p_geschlossen = p_total;
    int ret = 0, status = 0;
    char port[6] = { 0 };
    
    int offen_ports[150];
    int p_offen = 0;

    struct timeval timeout;
    socklen_t len = sizeof(timeout);

    timeout.tv_sec = 0;
    timeout.tv_usec = 150000; // 150 ms
    
    struct servent *sp;
    
    printf("\n%s ────────────────────────────────────────────────── \n", KYEL);
    printf(" %s Scan-Typ : Full Scan \n", KWHT);
    printf(" %s Scan Ziel : %s \n", KWHT, ip);
    printf(" %s Starting Port : %d \n", KWHT, e_port);
    printf(" %s Lätzte Port : %d \n", KWHT, l_port);
    printf("%s ────────────────────────────────────────────────── \n \n", KYEL, KWHT);

    for (int i = e_port; i <= l_port; i++)
    {
        sprintf(port, "%d", i);
        
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        
        printf("%s [%02d:%02d:%02d]", KYEL, tm.tm_hour, tm.tm_min, tm.tm_sec);
        
        printf("%s Scannen von Port %s \n", KWHT, port);
        
        if ((ret = getaddrinfo(ip, port, &hts, &ant)) != 0)
        {
            fprintf(stderr, "\n %sGetAddrInfo Fehler: %s\n", KRED, gai_strerror(ret));
            return -1;
        }

        for (rcd = ant; rcd != NULL; rcd = rcd->ai_next)
        {
            status = socket(rcd->ai_family, rcd->ai_socktype, rcd->ai_protocol);
            if (status == -1) continue; 
            
            int s_port = atoi( port );
            
            sp = getservbyport( htons(s_port), NULL );

            setsockopt(status, SOL_SOCKET, SO_SNDTIMEO, &timeout, len);
            if (connect(status, rcd->ai_addr, rcd->ai_addrlen) != -1)
            {
                if (sp)
                {
                    Uppercase(sp->s_name);
                    printf("%s [%02d:%02d:%02d]", KYEL, tm.tm_hour, tm.tm_min, tm.tm_sec);
                    printf(" %s%s OFFEN [%s] \n", KGRN, port, sp->s_name);
                    
                    p_offen = p_total - p_geschlossen;
                    offen_ports[p_offen] = s_port;
                    
                    p_geschlossen--;                
                    close(status);
                    break;
                }
                else
                {
                    printf("%s [%02d:%02d:%02d]", KYEL, tm.tm_hour, tm.tm_min, tm.tm_sec);
                    printf(" %s%s OFFEN \n", KGRN, port);
                                        
                    p_offen = p_total - p_geschlossen;
                    offen_ports[p_offen] = s_port;
                    
                    p_geschlossen--;                
                    close(status);
                    break;
                }
            }
            close(status);
        }
    }
    
    p_offen = p_total - p_geschlossen;
    
    if(p_offen == 0)
    {
        printf("\n%s %d gescannt : Kein geöffneter Port wird erkannt. \n", KRED, p_total);
    }
    else
    {
        printf("\n%s %d Port(s) gescannt : %d offen, %d geschlossen. \n \n", KGRN, p_total, p_offen, p_geschlossen);
        
        int a;
        printf(" %sOffen Port(s) : %s\n", KYEL, KWHT);
        
        for(a = 0; a < p_offen; a++){
            
            sp = getservbyport( htons(offen_ports[a]), NULL );
            Uppercase(sp->s_name);
            
            if (a + 1 == p_offen)
            {
                printf("   └──%d [%s] \n", offen_ports[a], sp->s_name);
            }
            else
            {
                printf("   ├──%d [%s] \n", offen_ports[a], sp->s_name);
            }   
        }
    }
    
    char g_otp[3];
    
    printf("\n %3sSpeichern ? [J/N] >> ", KYEL);
    scanf("%2s", &g_otp);
    fflush(stdin);

    if( strcmp ("J", g_otp) == 0 || strcmp ("j", g_otp) == 0)
    {
        char otp[100];
        sprintf(otp, "%s.txt", ip);
    
        FILE *f = fopen(otp, "w");
        
        if (f == NULL)
        {
            printf("%s Fehler beim Speichern der Ausgabe.\n", KRED);
            exit(1);
        }
        
        fprintf(f, "%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n", KYEL);
        fprintf(f, "%s                   FULL SCAN SUB-MODUL              \n", KWHT);
        fprintf(f, "%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n", KYEL);

        fprintf(f, "\n%s ────────────────────────────────────────────────── \n", KYEL);
        fprintf(f, " %s Scan-Typ : Full Scan \n", KWHT);
        fprintf(f, " %s Scan Ziel : %s \n", KWHT, ip);
        fprintf(f, " %s Starting Port : %d \n", KWHT, e_port);
        fprintf(f, " %s Lätzte Port : %d \n", KWHT, l_port);
        fprintf(f, "%s ────────────────────────────────────────────────── \n \n", KYEL, KWHT);
        
        if(p_offen == 0)
        {
            fprintf(f, "%s %d gescannt : Kein geöffneter Port wird erkannt. \n", KRED, p_total);
        }
        else
        {
            fprintf(f, "%s %d Port(s) gescannt : %d offen, %d geschlossen. \n \n", KGRN, p_total, p_offen, p_geschlossen);
            
            int a;
            fprintf(f, "%s Offen Port(s) : %s\n", KYEL, KWHT);
            
            for(a = 0; a < p_offen; a++){
                
                sp = getservbyport( htons(offen_ports[a]), NULL );
                Uppercase(sp->s_name);
                
                if (a + 1 == p_offen)
                {
                    fprintf(f, "   └──%d [%s] \n", offen_ports[a], sp->s_name);
                }
                else
                {
                    fprintf(f, "   ├──%d [%s] \n", offen_ports[a], sp->s_name);
                }   
            }
        }
        
        fclose(f);
        
        printf("\n %sAusgabe gespeichert als : %s \n", KWHT, otp);
    }

    freeaddrinfo(ant);
    return 0;
}

int F_Scan_NV(char *ip, int e_port, int l_port)
{
    struct addrinfo hts;
    struct addrinfo *ant;
    struct addrinfo *rcd;

    memset(&hts, 0, sizeof(hts));
    hts.ai_family = AF_INET;
    hts.ai_socktype = SOCK_STREAM;

    int p_total = l_port - e_port + 1;
    int p_geschlossen = p_total;
    int ret = 0, status = 0;
    char port[6] = { 0 };
    
    int offen_ports[150];
    int p_offen = 0;

    struct timeval timeout;
    socklen_t len = sizeof(timeout);

    timeout.tv_sec = 0;
    timeout.tv_usec = 150000; // 150 ms
    
    struct servent *sp;
    
    printf("\n%s ────────────────────────────────────────────────── \n", KYEL);
    printf(" %s Scan-Typ : Full Scan \n", KWHT);
    printf(" %s Scan Ziel : %s \n", KWHT, ip);
    printf(" %s Starting Port : %d \n", KWHT, e_port);
    printf(" %s Lätzte Port : %d \n", KWHT, l_port);
    printf("%s ────────────────────────────────────────────────── \n \n", KYEL, KWHT);

    for (int i = e_port; i <= l_port; i++)
    {
        sprintf(port, "%d", i);
        
        if ((ret = getaddrinfo(ip, port, &hts, &ant)) != 0)
        {
            fprintf(stderr, "\n %sGetAddrInfo Fehler: %s\n", KRED, gai_strerror(ret));
            return -1;
        }

        for (rcd = ant; rcd != NULL; rcd = rcd->ai_next)
        {
            status = socket(rcd->ai_family, rcd->ai_socktype, rcd->ai_protocol);
            if (status == -1) continue; 
            
            int s_port = atoi( port );
            
            sp = getservbyport( htons(s_port), NULL );

            setsockopt(status, SOL_SOCKET, SO_SNDTIMEO, &timeout, len);
            if (connect(status, rcd->ai_addr, rcd->ai_addrlen) != -1)
            {
                if (sp)
                {
                    Uppercase(sp->s_name);
                    printf(" %s[+] %s OFFEN [%s] \n", KGRN, port, sp->s_name);
                    
                    p_offen = p_total - p_geschlossen;
                    offen_ports[p_offen] = s_port;
                    
                    p_geschlossen--;                
                    close(status);
                    break;
                }
                else
                {
                    printf(" %s[+] %s OFFEN \n", KGRN, port);
                                        
                    p_offen = p_total - p_geschlossen;
                    offen_ports[p_offen] = s_port;
                    
                    p_geschlossen--;                
                    close(status);
                    break;
                }
            }
            close(status);
        }
    }
    
    p_offen = p_total - p_geschlossen;
    
    if(p_offen == 0)
    {
        printf("\n%s %d gescannt : Kein geöffneter Port wird erkannt. \n", KRED, p_total);
    }
    else
    {
        printf("\n%s %d Port(s) gescannt : %d offen, %d geschlossen. \n \n", KGRN, p_total, p_offen, p_geschlossen);
        
        int a;
        printf(" %sOffen Port(s) : %s\n", KYEL, KWHT);
        
        for(a = 0; a < p_offen; a++){
            
            sp = getservbyport( htons(offen_ports[a]), NULL );
            Uppercase(sp->s_name);
            
            if (a + 1 == p_offen)
            {
                printf("   └──%d [%s] \n", offen_ports[a], sp->s_name);
            }
            else
            {
                printf("   ├──%d [%s] \n", offen_ports[a], sp->s_name);
            }   
        }
    }
    
    char g_otp[3];
    
    printf("\n %3sSpeichern ? [J/N] >> ", KYEL);
    scanf("%2s", &g_otp);
    fflush(stdin);

    if( strcmp ("J", g_otp) == 0 || strcmp ("j", g_otp) == 0)
    {
        char otp[100];
        sprintf(otp, "%s.txt", ip);
    
        FILE *f = fopen(otp, "w");
        
        if (f == NULL)
        {
            printf("%s Fehler beim Speichern der Ausgabe.\n", KRED);
            exit(1);
        }
        
        fprintf(f, "%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n", KYEL);
        fprintf(f, "%s                   FULL SCAN SUB-MODUL              \n", KWHT);
        fprintf(f, "%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n", KYEL);

        fprintf(f, "\n%s ────────────────────────────────────────────────── \n", KYEL);
        fprintf(f, " %s Scan-Typ : Full Scan \n", KWHT);
        fprintf(f, " %s Scan Ziel : %s \n", KWHT, ip);
        fprintf(f, " %s Starting Port : %d \n", KWHT, e_port);
        fprintf(f, " %s Lätzte Port : %d \n", KWHT, l_port);
        fprintf(f, "%s ────────────────────────────────────────────────── \n \n", KYEL, KWHT);
        
        if(p_offen == 0)
        {
            fprintf(f, "%s %d gescannt : Kein geöffneter Port wird erkannt. \n", KRED, p_total);
        }
        else
        {
            fprintf(f, "%s %d Port(s) gescannt : %d offen, %d geschlossen. \n \n", KGRN, p_total, p_offen, p_geschlossen);
            
            int a;
            fprintf(f, "%s Offen Port(s) : %s\n", KYEL, KWHT);
            
            for(a = 0; a < p_offen; a++){
                
                sp = getservbyport( htons(offen_ports[a]), NULL );
                Uppercase(sp->s_name);
                
                if (a + 1 == p_offen)
                {
                    fprintf(f, "   └──%d [%s] \n", offen_ports[a], sp->s_name);
                }
                else
                {
                    fprintf(f, "   ├──%d [%s] \n", offen_ports[a], sp->s_name);
                }   
            }
        }
        
        fclose(f);
        
        printf("\n %sAusgabe gespeichert als : %s \n", KWHT, otp);
    }

    freeaddrinfo(ant);
    return 0;
}

int F_Menu()
{
    printf("\n");
    
    printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n", KYEL);
    printf("%s                   FULL SCAN SUB-MODUL              \n", KWHT);
    printf("%s ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n \n", KYEL);

    char g_ip[100];
    char g_verbose[3];
    int g_e_port = 0;
    int g_l_port = 0;

    printf("%s IP Adresse >> ", KWHT);
    scanf("%99s", &g_ip);
    fflush(stdin);
    
    int e_port = 1;
    int l_port = 65536;
    
    printf("%s Verbose [J/N] >> ", KWHT);
    scanf("%2s", &g_verbose);
    fflush(stdin);
    
    if( strcmp (g_verbose, "J") == 0 || strcmp (g_verbose, "j") == 0)
    {
        F_Scan_V(g_ip, e_port, l_port);
    }
    else
    {
        F_Scan_NV(g_ip, e_port, l_port);
    }

    return 0;
}

#endif
