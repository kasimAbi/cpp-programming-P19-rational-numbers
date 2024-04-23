#pragma once

#pragma comment(lib, "FehlerAbfangen.lib")
#include"fehler_abfangen.h"
#include"Bruch_Rechnen.h"

// struktur
struct Rationale_zahlen
{
	int zaehler;
	int nenner;
	int wert;
};
// funktionsdeklaration
void ergebnis_ausgeben(Rationale_zahlen);
void eingabe_von_zahlen(int*, int*, int*, int*);
void ausgeben(Rationale_zahlen);