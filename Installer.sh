RED="\e[31m"
GREEN="\e[32m"
NORMAL="\e[0m"

echo ''
echo -ne ' Installieren von Abhängigkeiten [                    ] [0%] (GCC)\r'
sudo apt-get install gcc -y &> /dev/null
echo -ne ' Installieren von Abhängigkeiten [====                ] [20%] (CURL-AND-LIBCURL-DEV)\r'
sudo apt-get install curl libcurl-dev -y &> /dev/null
echo -ne ' Installieren von Abhängigkeiten [========            ] [40%] (LIBCURL4-OPENSSL-DEV-AND-GNUTLS)\r'
sudo apt-get install libcurl4-openssl-dev libcurl4-gnutls-dev -y &> /dev/null
echo -ne ' Installieren von Abhängigkeiten [============        ] [60%] (PHP&PHP-CLI)                 \r'
sudo apt-get install php php-cli -y &> /dev/null
echo -ne ' Installieren von Abhängigkeiten [================    ] [80%] (ARP-SCAN)                    \r'
sudo apt-get install arp-scan -y &> /dev/null
echo -ne ' Installieren von Abhängigkeiten [====================] [100%] (DONE)                       \r'
echo -ne '\n'
echo -e " ${GREEN}Alle Abhängigkeiten wurden erfolgreich installiert.${ENDCOLOR}"
