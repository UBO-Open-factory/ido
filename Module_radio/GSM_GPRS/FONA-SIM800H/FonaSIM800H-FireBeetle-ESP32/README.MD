#README FONA SIM800H MiniGSM
***

**_Les codes suivant utilise un module Fona miniGSM SIM800H et un [FireBeetle ESP-32](https://wiki.dfrobot.com/FireBeetle_ESP32_IOT_Microcontroller(V3.0)__Supports_Wi-Fi_&_Bluetooth__SKU__DFR0478)._**

NOTA : La Numérotation des codes corresponds a l'ordre dans le quelle nos test on été réaliser.


####01_test_liaison_serie :
*  tester les commande AT via la zone de siasie du moniteur serie
* tester le port Serial2 du FireBeetle ESP-32.

####02_test_input_output :
* test des liaison serie par SerialSoftware (code 04a). _!!!attention il n'y a pas de loopback avec cette bibliothéque d'où l'utilisatin d'une arduino (code 04b) uno pour avoir un retour sur le port serie_
  * ###### 04a_test_input_output_FireBeetle_ESP-32
  * ###### 04b_test_liaison_serie_arduino_uno

####03_on_off :
* tester une commande manuel de marche/arret du module FONA MniGSM via FireBeetle ESP-32.

####04_connection_reseau_GSM :
* ajoute au programe precedent une commande de connection au réseau GSM 
* ajoute une verification de la connection au reseau GSM.

####05_connection_reseau_GSM_automatiser :
* ajoute l'automatisation de la procedure precedente de connection au reseau GSM.

####06_envoie_http_automatiser :
_!!!Atention programe non finit_
* ajoute et automatise la procedure d'envoie HTTP(GPRS) au programme precedente de connection au reseau GSM.
