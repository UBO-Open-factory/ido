/*
 *          Programme de test de la fonction d'envoi des fichiers
 *          
 *     Auteur   : Laurent Marchal
 *     
 *     Date     : juin 2021
 *     
 *     Version  : 1.0
 *     
 *     Fonctionnalités :
 *     
 *        Mise en place du programme et préparation de la RTC pour 
 *        pouvoir l'utiliser ultérieurement
 * 
 * 
 * 
 *  Cablage
 * 
 *        ESP Fire Beetle
 * 
 *            SDA   ================  SDA
 *            SCL   ================  SCL
 *            3V3   ================  3V3
 *            GND   ================  GND
 *                            nc  ==  32k
 *                            nc  ==  SQW
 */




//Libraries
#include "uof_rtc.h"


void setup() {
 //Init Serial USB
 Serial.begin(115200);
 while (!Serial) {
  delay(10);
 }
 Serial.println(F("Initialize System"));
 Wire.begin();
}


void loop() {

  // définit a date RTC à 21 avril 2025
  uof_set_date(21,04,25);

  // définre l'heure à 13h 45min 21sec
  uof_set_time (13,45,21);

  // lit la date de la RTC et place dans Jour, Mois et Année
  uof_get_date(&Jour, &Mois, &Annee);

  // Lit l'heure dans la RTC et plce dans Heure, Minute et Seconde
  uof_get_time (&Heure, &Minute, &Seconde);

  // affiche la date connue dans Jour, Mois et Année au format jj/mm/aa
  uof_affiche_date();
  Serial.println ("");
  // affiche l'heure connue dans Heure, Minute et Seconde au format hh:mm:ss
  uof_affiche_time();
  Serial.println ("");

  // calcule la veille du jour passé en argument
  veille_de(&Jour, &Mois, &Annee);

  // affiche la date connue dans Jour, Mois et Année au format jj/mm/aa
  uof_affiche_date();
  Serial.println ("");


  while (true) {
    ;
  }


}
