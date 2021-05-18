RED="\e[31m"
GREEN="\e[32m"
NORMAL="\e[0m"

echo ''
echo -ne ' Installieren von Abhängigkeiten [                    ] [0%] (GCC)\r'
sudo apt-get install gcc -y &> /dev/null
echo -ne ' Installieren von Abhängigkeiten [====                ] [20%] (LIBCURL-DEV)\r'
sudo apt-get install libcurl-dev -y &> /dev/null
echo -ne ' Installieren von Abhängigkeiten [========            ] [40%] (LIBCURL4-OPENSSL-DEV)\r'
sudo apt-get install libcurl4-openssl-dev -y &> /dev/null
echo -ne ' Installieren von Abhängigkeiten [============        ] [60%] (LIBCURL4-GNUTLS-DEV)  \r'
sudo apt-get install libcurl4-gnutls-dev -y &> /dev/null
echo -ne ' Installieren von Abhängigkeiten [================    ] [80%] (ARP-SCAN)              \r'
sudo apt-get install arp-scan -y &> /dev/null
echo -ne ' Installieren von Abhängigkeiten [====================] [100%] (DONE)                  \r'
echo -ne '\n'
echo -e " ${GREEN}Alle Abhängigkeiten wurden erfolgreich installiert.${ENDCOLOR}"
