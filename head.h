#include <iostream>
#include <fstream>

using namespace std;



class ClattToken
   {
private:
    // WIR MÜSSEN DIE anzahl der attribute speichern, um die jeweiligen
   int anzahlAtt;

char *attValue[100];

public:

int readDatafile(ifstream &input);

// getter-methode holt attributwwerte je nach ID (Auslese-Iteration)
                // counter wird in variable id gespeichert und dann innerhaalb der funktion weiterinterpretiert
char *getattValue(int id) {return attValue[id];}

// get Anzahl variable
int  getAnzahlAtt() {return anzahlAtt;}



   };
