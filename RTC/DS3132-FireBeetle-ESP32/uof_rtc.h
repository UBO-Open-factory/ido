


//
//
//  fonctions de RTC pour l'UOF
//
//
//    void uof_set_date(byte j, byte m, byte a)
//    void uof_set_time (byte h, byte m,byte s)
//    void uof_get_date(*Jour, *Mois, *Annee)
//    void uof_get_time (*Heure, *Minute, *Seconde)
//    void uof_affiche_date()
//    void uof_affiche_time()
//    void veille_de(int *jj, int *mm, int *aa)

//
//
//
//
//
//
//





#include <Wire.h>//https://www.arduino.cc/en/reference/wire
#include <DS3231.h>//https://github.com/NorthernWidget/DS3231



//Variables
byte Annee ;
byte Mois ;
byte Jour ;
byte DoW ;
byte Heure ;
byte Minute ;
byte Seconde ;
bool Century  = false;
bool h12 ;
bool PM ;


//Objects
DS3231 horloge;


//
//  
//
void uof_set_date(byte j, byte m, byte a) {
  horloge.setYear(a);
  horloge.setMonth(m);
  horloge.setDate(j);
}

void uof_set_time (byte h, byte m,byte s) {
  horloge.setHour(h);
  horloge.setMinute(m);
  horloge.setSecond(s);
}



void uof_get_date(byte *Jour, byte *Mois, byte*Annee) {
  *Annee = horloge.getYear();
  *Mois = horloge.getMonth(Century);
  *Jour = horloge.getDate();
}

void uof_get_time (byte *Heure, byte *Minute, byte *Seconde) {
  *Heure = horloge.getHour(h12, PM);
  *Minute = horloge.getMinute();
  *Seconde = horloge.getSecond();
}



void uof_affiche_date() {
  Serial.print(Jour);
  Serial.print ("/");
  Serial.print(Mois);
  Serial.print ("/");
  Serial.print(Annee);
}

void uof_affiche_time() {
  Serial.print(Heure);
  Serial.print (":");
  Serial.print(Minute);
  Serial.print (":");
  Serial.print(Seconde);
}


void veille_de(int *jj, int *mm, int *aa) {
  //
  //  *jj : pointe vers un int représentant le jour du mois
  //  *mm : pointe vers un int représentant le mois de l'année
  //  *aa : pointe vers un int représentant l'année
  //
  //  La fonction calcule la date du jour précédent (la veille)
  //  et modifie les 3 valeurs (jj, mm et aa) en conséquence
  //
  //  Prend en compte les mois à 28, 29, 30 et 31 jours
  //
  //  
  *jj = *jj-1;
  if (*jj == 0) {
    *jj=31; // pour le moment, avant de avois si c'est un mois à 28, 29, 30 ou 31jours 
    *mm=*mm-1;
    if (*mm == 0) {
      *mm=12;
      *aa = *aa -1;
    }
    if (*mm==4 or *mm == 6 or *mm == 9 or *mm == 11) {
      *jj = 30;
    }
    if (*mm == 2) {
      if ((*aa % 4) == 0) {
        *jj=29;
      } else {
        *jj=28;
      }
    }
  }
}
