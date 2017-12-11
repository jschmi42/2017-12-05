#include <iostream>
#include <fstream>
#include "head.h"
using namespace std;

int main()
{
int i;
ifstream input;
input.open("w7AufgData.txt");

 // funktion wurde in lib.cpp ausgelagert

// wir starten Funktion von hier über ein zuvor erstelltes Objekt namens "att"
ClattToken att;
// starte funktion und gebe ihm den Input mit auf den Weg
att.readDatafile(input);



// sukzessiver Aufruf der in lib gelesenen Werte Nachname, Vorname, Geburtsdatum
    for (i=0;i<att.getAnzahlAtt();i++){
    cout << att.getattValue(i) << endl;
    }






input.close();
}
