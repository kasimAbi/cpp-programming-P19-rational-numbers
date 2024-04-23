#include"Bruch_Rechnen.h"
#include"fehler_abfangen.h"
#include"header.h"

// zahlen eingeben.
void eingabe_von_zahlen(int* erste_zaehler, int* erste_nenner, int* zweite_zaehler, int* zweite_nenner)
{
	// Deklarationen/ Initialisierungen
	int ok = 0;
	char eingabe[GROESSE];
	while (ok == 0)
	{
		// zahl 1 zaehler einegben:
		cout << "Geben sie fuer die erste Zahl den Zaehler ein: " << endl;
		cin >> eingabe;
		system("cls");
		// �berpr�ft ob die zahl g�ltig ist.
		ok = pruefen_gueltig_integer(eingabe);
		if (ok != 0)
		{
			ok = wandeln_integer(eingabe);
		}
		if (ok != 0)
		{
			// wenn ja also ok = 1 dann wandelt er die zahl um (atoi- Befehl)
			*erste_zaehler = wandeln_integer(eingabe);
			// setzt ok = 0 f�r die n�chste zahl.
			ok = 0;
			while (ok == 0)
			{
				// fordert nenner f�r zahl 1 auf.
				cout << "Geben sie fuer die erste Zahl den Nenner ein: " << endl;
				cin >> eingabe;
				system("cls");
				// �berpr�ft ob die zahl eine zahl ist
				ok = pruefen_gueltig_integer(eingabe);
				if (ok != 0)
				{
					ok = wandeln_integer(eingabe);
				}
				if (ok >= 1)
				{
					// wenn ja dann wieder atoi- Befehl einsetzen
					*erste_nenner = wandeln_integer(eingabe);
					// f�r n�chste zahl
					ok = 0;
					while (ok == 0)
					{
						// f�r zahl 2 z�hler
						cout << "Geben sie fuer die zweite Zahl den Zaehler ein: " << endl;
						cin >> eingabe;
						system("cls");
						// pr�ft die zahl
						ok = pruefen_gueltig_integer(eingabe);
						if (ok != 0)
						{
							ok = wandeln_integer(eingabe);
						}
						if (ok != 0)
						{
							// wenn g�ltig dann atoi- Befhel
							*zweite_zaehler = wandeln_integer(eingabe);
							// f�r eingabe von n�chste zahl
							ok = 0;
							while (ok == 0)
							{
								// aufforderung f�r letzte zahl (zahl 2 nenner)
								cout << "Geben sie fuer die zweite Zahl den Nenner ein: " << endl;
								cin >> eingabe;
								system("cls");
								// pr�ft zahl
								ok = pruefen_gueltig_integer(eingabe);
								if (ok != 0)
								{
									ok = wandeln_integer(eingabe);
								}
								if (ok >= 1)
								{
									// wenn g�ltig: atoi- Befehl
									*zweite_nenner = wandeln_integer(eingabe);
								}
								else
								{
									// ansonsten erneut eingeben (zahl 2 nenner)
									system("cls");
									cout << "Sie haben etwas falsches eingegeben\nbitte erneut eingeben.\nIm Nenner sind keine negativen Werte erlaubt." << endl;
									cout << "Es darf keine 0 sein.\n" << endl;
									ok = 0;
								}
							}
						}
						else
						{
							// ansonsten erneut eingeben (zahl 2 z�hler)
							system("cls");
							cout << "Sie haben etwas falsches eingegeben\nbitte erneut eingeben." << endl;
							cout << "Es darf keine 0 sein.\n" << endl;
						}
					}
				}
				else
				{
					// ansonsten erneut eingeben (zahl 1 nenner)
					system("cls");
					cout << "Sie haben etwas falsches eingegeben\nbitte erneut eingeben.\nIm Nenner sind keine negativen Werte erlaubt." << endl;
					cout << "Es darf keine 0 sein.\n" << endl;
					ok = 0;
				}
			}
		}
		else
		{
			// ansonsten erneut eingeben (zahl 1 z�hler)
			system("cls");
			cout << "Sie haben etwas falsches eingegeben\nbitte erneut eingeben." << endl;
			cout << "Es darf keine 0 sein.\n" << endl;
		}
	}
}

void ausgeben(Rationale_zahlen ergebnis)
{
	// wenn ergebnis wert ungleich 0.
	if (ergebnis.wert != 0)
	{
		// wenn z�hler ungleich 0.
		if (ergebnis.zaehler != 0)
		{
			if (ergebnis.zaehler < 0 || ergebnis.nenner < 0)
			{
				cout << "Ihr Ergebnis lautet:\n\n - " << ergebnis.wert << " (" << fabs(ergebnis.zaehler) << "/" << fabs(ergebnis.nenner) << ")\n\n" << endl;
			}
			// wenn nciht.
			else
			{
				cout << "Ihr Ergebnis lautet:\n\n" << ergebnis.wert << " (" << ergebnis.zaehler << "/" << ergebnis.nenner << ")\n\n" << endl;
			}
		}
		// wenn z�hler 0.
		else
		{
			cout << "Ihr Ergebnis lautet: " << ergebnis.wert << endl;
		}
	}
	// wenn ergebnis wert einen wert von 0 hat.
	else
	{
		// gleiche wie oben nur wert wird nciht ausgegeben.
		if (ergebnis.zaehler != 0)
		{
			if (ergebnis.zaehler < 0 || ergebnis.nenner < 0)
			{
				cout << "Ihr Ergebnis lautet:\n\n - " << " (" << fabs(ergebnis.zaehler) << "/" << fabs(ergebnis.nenner) << ")\n\n" << endl;
			}
			else
			{
				cout << "Ihr Ergebnis lautet:\n\n" << " (" << ergebnis.zaehler << "/" << ergebnis.nenner << ")\n\n" << endl;
			}
		}
		else
		{
			cout << "Ihr Ergebnis lautet: " << ergebnis.wert << endl;
		}
	}
}