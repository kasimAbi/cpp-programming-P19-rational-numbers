#pragma once
#include"fehler_abfangen.h"
#include"header.h"

#ifndef Bruch_Rechnen_h
#define Bruch_Rechnen_h
// Klasse machen.
class Bruch_Rechnen
{
private:
	Rationale_zahlen zahlen_eins;
	Rationale_zahlen zahlen_zwei;
	Rationale_zahlen ergebnis;

	// für +/- nenner gleichnamig machen
	void nenner_gleichnamig_machen(void);
	void ergebnis_kuerzen(void);

	void addition(void);
	void subtraktion(void);
	void multiplikation(void);
	void division(void);
public:
	void set_zahlen(Rationale_zahlen& Bruch_eins, Rationale_zahlen& Bruch_zwei);
	void rechnen(int, Rationale_zahlen& ergebnis);
	Rationale_zahlen ergebnis_bekommen(void);
};

#endif // !Bruch_Rechnen_h
