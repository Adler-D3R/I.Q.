RED="\e[31m"
GREEN="\e[32m"
NORMAL="\e[0m"

echo -ne '\n'
echo -e " ${GREEN}Installieren von Abhängigkeiten...${ENDCOLOR}"
sudo apt-get install gcc curl libcurl-dev libcurl4-openssl-dev libcurl4-gnutls-dev php php-cli arp-scan -y
echo -e " ${GREEN}Alle Abhängigkeiten wurden erfolgreich installiert.${ENDCOLOR}"
