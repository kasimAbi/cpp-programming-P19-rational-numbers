#include"Bruch_Rechnen.h"
#include"fehler_abfangen.h"
#include"header.h"

// main
void main(void)
{
	// initialisierungen/ Deklarationen
	int wahl = 0, ok = 0;
	int erste_zaehler = 0, erste_nenner = 0, zweite_zaehler = 0, zweite_nenner = 0;
	Bruch_Rechnen rechnen;
	Rationale_zahlen Bruch_eins;
	Rationale_zahlen Bruch_zwei;
	Rationale_zahlen ergebnis;
	char eingabe[GROESSE];
	// Endlosschleife. endbedingung: wahl = 5
	while (wahl != 5)
	{
		// damit er die while schleife unten ausführt.
		ok = 0;
		// zahlen eingeben
		eingabe_von_zahlen(&erste_zaehler, &erste_nenner, &zweite_zaehler, &zweite_nenner);
		system("cls");
		cout << "ihre Zahlen lauten:\n\n	" << erste_zaehler << "		" << zweite_zaehler << "\n	" << erste_nenner << "		" << zweite_nenner << "\n" << endl;
		// brüche in die jeweiligen strukturen speichern.
		Bruch_eins.zaehler = erste_zaehler;
		Bruch_eins.nenner = erste_nenner;
		Bruch_zwei.zaehler = zweite_zaehler;
		Bruch_zwei.nenner = zweite_nenner;
		// setzt die Brücke in der Klasse gleich.
		rechnen.set_zahlen(Bruch_eins, Bruch_zwei);
		while (ok == 0)
		{
			// menue
			cout << "Geben sie ein, was sie machen moechten mit den Bruechen.\n (1) addition.\n (2) subtraktion.\n (3) multiplikation.\n (4) division.\n (5) Programm beenden.\n" << endl;
			cin >> eingabe;
			// prüft ob zahl gültig
			ok = pruefen_gueltig_integer(eingabe);
			if (ok == 1)
			{
				// wenn ja(1 wird zurückgegeben) setzt er ok wieder zurück um in nächste while schleife rein zu gehen
				ok = 0;
				while (ok == 0)
				{
					// wandelt wahl in integer variable um.
					wahl = wandeln_integer(eingabe);
					// wenn bedingung passt also whal kleienr 5 und größer 0 ist.
					if (wahl >= 1 && wahl <= 4)
					{
						// funktionsaufruf.
						rechnen.rechnen(wahl, ergebnis);
						// um die while schleife zu verlassen.
						ok = 1;
						// ausgeben funktion für ergebnis.
						ausgeben(ergebnis);
					}
					// beendet programm.
					if (wahl == 5)
					{
						cout << "Programm wird nun beendet.\n" << endl;
						// um die while schleife zu verlassen.
						ok = 1;
					}
					// fehlermeldung
					if (wahl > 5 || wahl < 1)
					{
						// fehlermeldung
						cout << "Sie haben etwas falsches eingegeben\nbitte erneut eingeben.\n" << endl;
					}
				}
			}
			else
			{
				// fehlermeldung.
				cout << "Sie haben etwas falsches eingegeben\nbitte erneut eingeben.\n" << endl;
			}
		}
	}
}