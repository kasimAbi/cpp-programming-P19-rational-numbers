#include"Bruch_Rechnen.h"
#include"fehler_abfangen.h"
#include"header.h"

// zahlen in klasse gleichsetzen
void Bruch_Rechnen::set_zahlen(Rationale_zahlen& Bruch_eins, Rationale_zahlen& Bruch_zwei)
{
	// werte gleich 0 setzen von klasse.
	ergebnis.wert = 0;
	ergebnis.nenner = 0;
	ergebnis.zaehler = 0;
	// zahlen von klasse mit main gleichsetzen.
	zahlen_eins = Bruch_eins;
	zahlen_zwei = Bruch_zwei;
}

// br�che rechnen.
void Bruch_Rechnen::rechnen(int wahl, Rationale_zahlen& ergebnis_von_main)
{
	// ausw�hlen.
	switch (wahl)
	{
	case 1:
		// addition.
		// nenner gleichnamig machen.
		nenner_gleichnamig_machen();
		addition();
		break;
	case 2:
		// subtraktion.
		// nenner gleichnamig machen.
		nenner_gleichnamig_machen();
		subtraktion();
		break;
	case 3:
		// mal rechenn
		multiplikation();
		break;
	case 4:
		// teilen.
		division();
		break;
	}
	// bruch k�rzen. ergebnis.
	ergebnis_kuerzen();
	// zum ausgeben. wird so gesehen zum main zur�ckgeliefert.
	ergebnis_von_main = ergebnis_bekommen();
}

// addition.
void Bruch_Rechnen::addition(void)
{
	// nenner gleichnamig setzen.
	nenner_gleichnamig_machen();
	// zaehler von zahl 1 und zahl 2 zsm addieren.
	ergebnis.zaehler = zahlen_eins.zaehler + zahlen_zwei.zaehler;
	// nenner bleibt gleich.
	ergebnis.nenner = zahlen_eins.nenner;
	// ergebnis k�rzen.
	ergebnis_kuerzen();
}
// subtraktion.
void Bruch_Rechnen::subtraktion(void)
{
	// nenner gleichnamig machen.
	nenner_gleichnamig_machen();
	// subtrahiert z�hler von zahl 1 und zahl 2.
	ergebnis.zaehler = zahlen_eins.zaehler - zahlen_zwei.zaehler;
	// nenner bleibt gleich.
	ergebnis.nenner = zahlen_eins.nenner;
	// ergebnis k�rzen.
	ergebnis_kuerzen();
}
// multiplikation.
void Bruch_Rechnen::multiplikation(void)
{
	int vz = 0; //vorzeichen.
	// z�hler * z�hler.
	ergebnis.zaehler = zahlen_eins.zaehler * zahlen_zwei.zaehler;
	if (ergebnis.zaehler < 0)
	{
		// z�hler positiv machen
		ergebnis.zaehler *= -1;
		// vz gucken ob vorzeichen - wert ist. wenn ja wird die variable auf 1 gemacht. f�r sp�ter if abfrage.
		vz = 1;
	}
	// nenner * nenner.
	ergebnis.nenner = zahlen_eins.nenner * zahlen_zwei.nenner;
	// ergebnis k�rzen.
	ergebnis_kuerzen();
	// wenn ergebnis wert gr��er 0 ist, dann setzt er die zahl wieder auf - variable.
	if (vz == 1 && ergebnis.wert != 0)
	{
		ergebnis.wert *= -1;
	}
	// ansonsten wenn = 0 ist dann z�hler.
	if (vz == 1 && ergebnis.wert == 0)
	{
		ergebnis.zaehler *= -1;
	}
}
// division.
void Bruch_Rechnen::division(void)
{
	// z�hler von zahl 1 * nenner von zahl 2.
	ergebnis.zaehler = zahlen_eins.zaehler * zahlen_zwei.nenner;
	// z�hler von zahl 2 * nenner von zahl 1.
	ergebnis.nenner = zahlen_eins.nenner * zahlen_zwei.zaehler;
	// ergebnis k�rzen.
	ergebnis_kuerzen();
}
// nenner gleichnamig machen f�r + und - rechnung
void Bruch_Rechnen::nenner_gleichnamig_machen(void)
{
	// Initialisierungen/ Deklarationen.
	int index = 0, zwischenspeicher = 0, zwischenspeicher2 = 0;
	int kgV = 0;
	// soll kgV finden. 1000 ist abbruchbedingung damit es nciht unendlich lange dauert.
	for (index = 1; index < 1000; index++)
	{
		// vergleicht ob beide nenner duch idnex teilbar sind. wenn ja haben wir unseren kgV.
		if (index % zahlen_eins.nenner == 0 && index % zahlen_zwei.nenner == 0)
		{
			kgV = index;
			// abbruchbedingung erf�llen.
			index = 1000;
		}
	}
	// setzt nenner gleichnamig. kgV ist orientierungszahl.
	for (index = 1; index <= kgV; index++)
	{
		// zwischenspeicher f�r beide nenner.
		zwischenspeicher = zahlen_eins.nenner * index;
		zwischenspeicher2 = zahlen_zwei.nenner * index;
		// wenn nenner von zahl 1 wert kgV erreicht hat, rechnet er nenner und z�hler mit der selben zahl.
		if (zwischenspeicher == kgV)
		{
			zahlen_eins.nenner *= index;
			zahlen_eins.zaehler *= index;
		}
		// das gleiche f�r zahl 2 nenner.
		if (zwischenspeicher2 == kgV)
		{
			zahlen_zwei.nenner *= index;
			zahlen_zwei.zaehler *= index;
		}
		// wenn beide nenner gleich sind setzt er index f�r abbruchbedingung.
		if (zahlen_eins.nenner == zahlen_zwei.nenner)
		{
			index = kgV + 1;
		}
	}
}
// ergebnis k�rzen.
void Bruch_Rechnen::ergebnis_kuerzen(void)
{
	// Initialisierungen/ Deklarationen
	int kleinere_zahl = 0, index = 0, ok = 0;
	// kontrolliert ob nenner oder z�hler gr��er ist. zum k�rzen gleich.
	if (ergebnis.zaehler < ergebnis.nenner)
	{
		kleinere_zahl = ergebnis.zaehler;
		if (kleinere_zahl < 0)
		{
			ok = 1;
		}
	}
	else
	{
		// wenn nenner kleiner z�hler ist, dann setzt er ok auf 1. damit es unten in die entsprechende abfrage geht.
		kleinere_zahl = ergebnis.nenner;
		ok = 1;
	}
	// k�rzt zahl soweit es geht.
	for (index = fabs(kleinere_zahl); index >= 2; index--)
	{
		if (fabs(ergebnis.zaehler % index) == 0 && fabs(ergebnis.nenner % index) == 0)
		{
			ergebnis.zaehler /= index;
			ergebnis.nenner /= index;
		}
	}
	// wenn nenner und z�hler minuswerte sind dann ist der bruch positiv.
	if (ergebnis.zaehler < 0 && ergebnis.nenner < 0)
	{
		ergebnis.zaehler *= -1;
		ergebnis.nenner *= -1;
	}
	// oben wird ok nciht = 1 gesetzt wegen den minus werten.
	if (ergebnis.zaehler > ergebnis.nenner)
	{
		ok = 1;
	}
	// anschlie�end wird der echte bruch geerechnet. also z.B.: 13/6 ist= 2 (1/6).
	if (ok == 1)
	{
		// wert darf nciht - zahl sein.
		ergebnis.wert = ergebnis.zaehler / ergebnis.nenner;
		if (ergebnis.wert > 0)
		{
			// z�hler ausrechnen wenn man wert ausgerechnet hat.
			ergebnis.zaehler = ergebnis.zaehler - ergebnis.wert * ergebnis.nenner;
		}
		else
		{
			// wenn das der fall sein sollte(wert kleienr 0) dann wir er = 0 gesetzt.
			ergebnis.wert = 0;
		}
	}
}
// gibt ergebnis zur�ck f�rs ausgeben.
Rationale_zahlen Bruch_Rechnen::ergebnis_bekommen(void)
{
	return ergebnis;
}