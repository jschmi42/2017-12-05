#include <iostream>
#include <fstream>
#include <string.h>
#include "head.h"
using namespace std;


int ClattToken::readDatafile(ifstream &input) {


    char zeichen;
    char puffer[100];
    int counter;
    enum zustandsmeldung {
        zwischendenZeilen, nachErstemDoppelpunkt,nacherstemKomma,nachErstemPunkt, nachZweitemDoppelpunkt
    };

    zustandsmeldung zustandsmeldung;
    //reset enum
    zustandsmeldung = zwischendenZeilen;


    for (counter=0, zustandsmeldung=zwischendenZeilen, anzahlAtt=0;;){
    input.get(zeichen);
    if (input.eof()) return 0;


        switch(zeichen){

        case ':':
            // was passiert bei :
            // wir bearbeiten gerade einen Attributnamen
        if (zustandsmeldung==zwischendenZeilen){

            puffer[counter] = '\0';
            //cout << "Name des Attributs: " << puffer << endl;
            counter=0;
            zustandsmeldung=nachErstemDoppelpunkt;
        }
        else  {

            puffer[counter] = '\0';
            //cout << "Name des Attributs: " << puffer << endl;
            counter=0;
            zustandsmeldung=nachZweitemDoppelpunkt;
        }

        break;



          case ',':
        // was passiert bei ,
        // wir verarbeiten gerade den namen und sind nach dem vornamen und vor dem nachnamen
            puffer[counter] = '\0';
            // bereite array für pointer auf nachnamenwert von anzahlAtt
            attValue[anzahlAtt] = new char[counter+1];
            // kopiere puffer in dem für die stelle im array reservierten Nachnamenwertvvariable hinein
            strcpy(attValue[anzahlAtt],puffer);

            counter=0;
            anzahlAtt++;

            if (zustandsmeldung==nachErstemDoppelpunkt) zustandsmeldung=nacherstemKomma;
        break;

        case ' ':
        // was passiert bei space?
        // space ist nicht sinnstiftend und kann einfach ausgelassen werden, muss aber auf das Space nach dem Komma achten

        break;

        case '.':
            // was passiert bei .?
        if (zustandsmeldung==nacherstemKomma)
        {
          // . dient als begrenzer zwischen den attribut1 und attriibut 2 - demnach kann attribut wert hier herausgelesen werden
            // VORNAME AUSLESEN
            puffer[counter] = '\0';
            attValue[anzahlAtt] = new char[counter+1];
            strcpy(attValue[anzahlAtt],puffer);
            counter=0;
            anzahlAtt++;
            // wenn erstes attribut eingelesen wurde, setze zustand auf 2
            zustandsmeldung=nacherstemKomma;
        }
        else if (zustandsmeldung==nachZweitemDoppelpunkt) {
        // . MUSS abgegrenzt werden von den Punkten in der Datumsangabe
        puffer[counter] = zeichen;
        counter++;

        }


        break;




        case '\n':
        // ich erreiche eine neue Zeile - der nächste Punkt dient also wieder der ABgrenzung zwischen Attributnamen
        // reset zustand
            // GEBURTSDATUM AUSLESEN
        puffer[counter] = '\0';
        attValue[anzahlAtt] = new char[counter+1];
        strcpy(attValue[anzahlAtt],puffer);
        counter=0;
        //Wichtig!!! Zähle attribut aanschließnd langsam herauf - ABER UR EINMAL PRO WIEDERHOLENDE LINE
        anzahlAtt++;
        zustandsmeldung=zwischendenZeilen;
        break;

        default:


        // was passiert normalerweise - fülle das array mit den datenwerten auf und zähle einen weiter
        puffer[counter]=zeichen;
        counter++;

        break;

        }



    }





}
