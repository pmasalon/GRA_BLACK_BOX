
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <ctime>


using namespace std;

//aby ta gra sie nie "CRASHOWALA" klawisze sterujacie NIE POWINNY byc zatwierdzane klaw enter czyli uzycie cin >> (gryzie sie z uzyciem spacji)
// 
//
//tworzymy funkcje kolorujace tekst w konsoli
void fioletowy()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
}
void niebieski()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
}
void czerwony()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
}



void gra5x5()
{
	//=============================================================================================
	//GRA===
	bool k_gry = 0;
	bool h = 0; //czy h wcisniete
	bool k = 0; // czy k wcisniete
	bool p = 0; // czy p
	int bledy = 0; //licznik bledow
	int petla = 0; // zmienna okreslajaca czy glowna petla trwa

	char tab[7][7]; // utworzenie tablicy dwuwymiarowej
	char tab_gracza[7][7]; // utworzenie tablicy pomocniczej gracza

	//wypełniamy ją aby pozniej moc sprawdzic czy na danym polu ruch juz nie zostal wykonany
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++)
			tab_gracza[i][j] = 'x';
	}
	srand(time(NULL)); //uruchomienie rand

	int ruchy = 0; //zmienna do licznika ruchow
	int wynik = 0; //zmienna przechowujaca wynik
	int atom_x[3]; // tablice dla pozycji atomow
	int atom_y[3];

	int zgodnosc = 0; //losowanie liczb wspl na atomy ze sprawdzeniem czy wspol nie powtarzaja sie
	do {
		zgodnosc = 0;
		for (int i = 0; i < 3; i++)
		{
			atom_x[i] = rand() % 5 + 1;
			atom_y[i] = rand() % 5 + 1;
		}
		for (int i = 0; i <= 1; i++)
			for (int j = 1; j <= 2; j++)
			{
				if (i != j)
				{
					if (atom_x[i] != atom_x[j])
						zgodnosc++;
				}
			}
	} while (zgodnosc != 2);

	char tab_wygranej[7][7]; //tablica pomocnicza do wygrywajacych pol i jej uzupełnienie
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 6; j++)
			for (int k = 0; k < 3; k++)
			{
				if (atom_x[k] == i && atom_y[k] == j)
					tab_wygranej[i][j] = 'O';
			}

	//WSPOLRZEDNE AKTUALNEJ  POZYCJI NA MAPIE
	int x = 0;
	int y = 1;
	//--------------
	do
	{
		system("CLS"); // wyczyszczenie konsoli
		cout << "---------- ooooo   oo      oooo  oooooo oo  oo    ooooo    oooo  oo   oo ----------\n";
		cout << "---------- oo  oo  oo     oo  oo oo     oo oo     oo  oo  oo  oo  oo oo  ----------\n";
		cout << "---------- oooooo  oo     oooooo oo     oooo      oooooo  oo  oo   ooo   ----------\n";
		cout << "---------- oo   oo oo     oo  oo oo     oo oo     oo   oo oo  oo  oo oo  ----------\n";
		cout << "---------- ooooooo oooooo oo  oo oooooo oo  oo    ooooooo  oooo  oo   oo ----------\n\n";
		k = 0; // zmienna okreslajaca czy glowna petla trwa

		//tabela pomocnicza przy testach
		//cout << '[' << atom_x[0] << ']' << '[' << atom_y[0] << ']';
		//cout << '[' << atom_x[1] << ']' << '[' << atom_y[1] << ']';
		//cout << '[' << atom_x[2] << ']' << '[' << atom_y[2] << ']';

		//sprawdzenie pozycji gracza na planszy x  y do testu
		//cout << "\n";
		//cout << x << " " << y;
		//cout << "\n";

		for (int i = 0; i < 43; i++) cout << (char)(254); // ramka na gorze
		cout << "           ";
		for (int l = 0; l < 22; l++) cout << (char)(254);
		cout << "\n";

		for (int i = 0; i < 7; i++) // wypisanie planszy gry i przypisanie danych do tablicy
		{
			fioletowy();
			cout << (char)(197);
			fioletowy();
			for (int j = 0; j < 7; j++)
			{
				if (i == 0 || i == 6 || j == 0 || j == 6) // wyciągniecie if'em ścian
				{
					if (i == 0 || i == 6) // ominiecie naroznikow na planszy (nie sa uzywane w grze)
					{
						if (j == 0 || j == 6)
						{
							cout << "     " << (char)(197);
							continue; //przeskoczenie pętli
						}
					}
					if (tab_gracza[i][j] == 'H' || tab_gracza[i][j] == 'R' || tab_gracza[i][j] == 'T' || tab_gracza[i][j] == 'M')
					{
						if (tab_gracza[i][j] == 'H')
						{
							tab[i][j] = 'H';
							if (i == x && j == y) // czy jest na danych wspolrzednych?
							{
								cout << "  ";
								niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych
								cout << tab[i][j];
								fioletowy(); // powrot do defaultowego koloru gry
								cout << "  ";
								cout << (char)(197);
							}
							else //jezeli nie jest na danych wspolzednych
							{
								cout << "  ";
								czerwony(); // ustawienie koloru ścian na czerwony
								cout << tab[i][j];
								fioletowy(); // powrot do defaultowego koloru gry
								cout << "  " << (char)(197);
							}
						}
						else
							if (tab_gracza[i][j] == 'R')
							{
								tab[i][j] = 'R';
								if (i == x && j == y) // czy jest na danych wspolrzednych?
								{
									cout << "  ";
									niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych
									cout << tab[i][j];
									fioletowy(); // powrot do defaultowego koloru gry
									cout << "  ";
									cout << (char)(197);
								}
								else //jezeli nie jest na danych wspolzednych
								{
									cout << "  ";
									czerwony(); // ustawienie koloru ścian na czerwony
									cout << tab[i][j];
									fioletowy(); // powrot do defaultowego koloru gry
									cout << "  " << (char)(197);
								}
							}
							else
								if (tab_gracza[i][j] == 'M')
								{
									tab[i][j] = 'M';
									if (i == x && j == y) // czy jest na danych wspolrzednych?
									{
										cout << "  ";
										niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych
										cout << tab[i][j];
										fioletowy(); // powrot do defaultowego koloru gry
										cout << "  ";
										cout << (char)(197);
									}
									else //jezeli nie jest na danych wspolzednych
									{
										cout << "  ";
										czerwony(); // ustawienie koloru ścian na czerwony
										cout << tab[i][j];
										fioletowy(); // powrot do defaultowego koloru gry
										cout << "  " << (char)(197);
									}
								}

					}
					else
					{
						tab[i][j] = (char)(254); // przypisanie wartości elementowi w tablicy
						if (i == x && j == y) // czy jest na danych wspolrzednych?
						{
							cout << "  ";
							niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych
							cout << tab[i][j];
							fioletowy();; // powrot do defaultowego koloru gry
							cout << "  ";
							cout << (char)(197);
						}
						else
						{
							cout << "  ";
							czerwony(); // ustawienie koloru ścian na czerwony
							cout << tab[i][j];
							fioletowy(); // powrot do defaultowego koloru gry
							cout << "  " << (char)(197);
						}

					}
				}
				else // ============================================================== ŚRODEK PLANSZY ===================
				{
					if (tab_gracza[i][j] != 'o') // ============================= JEZELI NIE MA NA MIEJSCU 'O' ===========
					{
						tab[i][j] = (char)(4); // przypisanie wartości defaultowej elementowi w tablicy

						if (i == x && j == y) // czy jest na danych wspolrzednych? ============ CZY KOLORUJEMY
						{
							cout << "  ";
							niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych

							if (k_gry == 1)
							{
								if (tab_wygranej[i][j] == 'O')
									cout << tab_wygranej[i][j];
								else cout << tab[i][j];
							}
							else
								if (h == 1) //pokolorowana podpowiedz
								{
									if (tab_wygranej[i][j] == 'O')
									{
										niebieski();
										cout << tab_wygranej[i][j];
									}
									else cout << tab[i][j];
								}
								else
									cout << tab[i][j];
							fioletowy(); // powrot do defaultowego koloru gry
							cout << "  ";
							cout << (char)(197);
						}
						else
						{
							cout << "  ";
							if (k_gry == 1)
							{
								if (tab_wygranej[i][j] == 'O')
								{
									niebieski();
									cout << tab_wygranej[i][j];
								}
								else cout << tab[i][j];
							}
							else
								if (h == 1) //pokolorowana podpowiedz
								{
									if (tab_wygranej[i][j] == 'O')
									{
										niebieski();
										cout << tab_wygranej[i][j];
									}
									else cout << tab[i][j];
								}
								else
									cout << tab[i][j];
							fioletowy(); // powrot do defaultowego koloru gry
							cout << "  ";
							cout << (char)(197);

						}
					}
					else //=============================================================== JEZELI 'O' JEST NA MIEJSCU
					{
						tab[i][j] = 'o';
						if (i == x && j == y) // czy jest na danych wspolrzednych? ====== CZY KOLORUJEMY
						{
							cout << "  ";
							niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych
							if (k_gry == 1)
							{
								fioletowy(); // nie chcemy aby kolorowało aktual wspolrzednych
								if (tab_wygranej[i][j] != 'O')
								{
									bledy++;
									czerwony();
									tab[i][j] = 'X';
									cout << tab[i][j];
								}
								else
									if (tab_wygranej[i][j] == 'O') // wypisanie wyniku
									{
										wynik++;
										niebieski(); //ale kolorujemy poprawnie zaznaczone 'o' gracza
										cout << tab_wygranej[i][j];
									}
							}
							else
								if (h == 1) //pokolorowana podpowiedz nachodzaca na 'o'
								{
									if (tab_wygranej[i][j] == 'O')
									{
										niebieski();
										cout << tab_wygranej[i][j];
									}
									else cout << tab[i][j];
								}
								else
									cout << tab[i][j];
							fioletowy(); // powrot do defaultowego koloru gry
							cout << "  ";
							cout << (char)(197);
						}
						else // brak koloru
						{
							cout << "  ";
							if (k_gry == 1)
							{
								if (tab_wygranej[i][j] != 'O')
								{
									czerwony();
									tab[i][j] = 'X';
									cout << tab[i][j];
									bledy++;
								}
								else
									if (tab_wygranej[i][j] == 'O') // wypisanie wyniku
									{
										niebieski();
										cout << tab_wygranej[i][j];
										wynik++;
									}
							}
							else
								if (h == 1) //niepokolorowana podpowiedz nachodzaca na o
								{
									if (tab_wygranej[i][j] == 'O')
									{
										niebieski();
										cout << tab_wygranej[i][j];

									}
									else cout << tab[i][j];
								}
								else
									cout << tab[i][j];
							fioletowy(); // powrot do defaultowego koloru gry
							cout << "  ";
							cout << (char)(197);

						}
					}
				} // koniec rysowania srodka
			} //koniec petli j
			switch (i)
			{
			case 0: {
				cout << "            H - trafienie";
				break;
			}
			case 1: {
				cout << "            R - odbicie";
				break;
			}
			case 2: {
				cout << "            M - chybienie";
				break;
			}
			case 3: {
				cout << "           ";
				for (int l = 0; l < 22; l++) cout << (char)(254);
				break;
			}
			case 5: {
				cout << "            RUCHY GRACZA: " << ruchy;
				break;
			}
			}
			if (i != 6) cout << "\n\n"; //na koncu planszy nie robimy przerwy
		} //koniec petli i
		cout << "\n";
		for (int i = 0; i < 43; i++) cout << (char)(254);

		if (k_gry == 1)
		{
			cout << "\nWYNIK: " << wynik << " / 3";
			cout << "\nBLEDY: " << bledy;
			cout << "\nZakonczyles gre! Kliknij losowy przycisk aby wyjsc do menu...";
			_getch(); // po wyłapaniu klikniecia zamykamy gre
			k++;
			break;
		}
		if (h == 1) //przerwa i zerowanie h i powrot do tabeli | rozwiazania
		{
			if (p == 1) {
				cout << "\n";
				cout << "Oto rozwiazania. Kliknij losowy przycisk aby wyjsc do menu...";
				_getch(); // po wyłapaniu klikniecia zamykamy gre
				k = 1;
				break;
			}
			else {
				Sleep(3000);
				h = 0;
				continue;
			}
		}
		char znak; //zmienna do wyłapywania znaku z klawiatury

		cout << "\n";
		cout << "\nLEGENDA:\n|w - gora | a - lewo | s - dol | d - prawo|\n";
		cout << "| Aby strzelic wcisnij spacje |\n| Aby zaznaczyc pozycje atomu wcisnij o |\n";
		cout << "| Q - menu glowne | P - rozwiazanie | H - pomoc | K - koniec | ";
		if ((GetAsyncKeyState(VK_SPACE)) & 0x8000) { //czy spacja zostala nacisnieta

			if (tab_gracza[x][y] == 'x')
			{
				//-----------SPRAWDZENIE TRAFIENIA
				if (x == 0 || x == 6) // czy jesteśmy na scianie
				{
					for (int i = 0; i < 3; i++)
					{
						if (y == atom_y[i]) // sprawdzenie czy trafiliśmy atom
						{
							if (tab_gracza[x][y] == 'x') {
								ruchy++;
								tab_gracza[x][y] = 'H';
							}
						}
					}
				}
				else
					if (y == 0 || y == 6) // czy jesteśmy na scianie
					{
						for (int i = 0; i < 3; i++)
						{
							if (x == atom_x[i]) // sprawdzenie czy trafiliśmy atom
							{
								if (tab_gracza[x][y] == 'x') {
									ruchy++;
									tab_gracza[x][y] = 'H';
								}
							}
						}
					}
				//------------SPRAWDZENIE ODBICIA
				if (x == 0 || x == 6) // czy jesteśmy na scianie
				{
					for (int i = 0; i < 3; i++)
					{
						if (y == atom_y[i] + 1 || y == atom_y[i] - 1) // sprawdzenie czy odbiliśy atom
						{
							if (tab_gracza[x][y] == 'x') {
								ruchy++;
								// gra w przypadku gdy jest i 'R' i 'H' pokazuje tylko 'H' 
								// toteż konieczne jest ograniczenie ifem mozliwosci kolejnego nabicia ruchu na tym samym polu
								tab_gracza[x][y] = 'R';
							}
						}

					}
				}
				else
					if (y == 0 || y == 6) // czy jesteśmy na scianie
					{
						for (int i = 0; i < 3; i++)
						{
							if (x == atom_x[i] + 1 || x == atom_x[i] - 1) // sprawdzenie czy trafiliśmy atom
							{
								if (tab_gracza[x][y] == 'x') {
									ruchy++;
									tab_gracza[x][y] = 'R';
								}
							}
						}
					}
				//ani trafienie ani odbicie
				if (x == 0 || x == 6 || y == 0 || y == 6)
				{
					if (tab_gracza[x][y] == 'x') {
						tab_gracza[x][y] = 'M';
						ruchy++;
					}
				}
			}
			continue;
		}

		znak = _getch();
		switch (znak)
		{
		case 'q':
		{
			k++;
			break;
		}
		case 'Q':
		{
			k++;
			break;
		}
		case 'o':
		{
			if (tab_gracza[x][y] == 'x') // ograniczenie aby nie nabijać na jednym wiecej ruchow
			{
				ruchy++; //dodanie ruchu
				tab_gracza[x][y] = 'o';
			}
			break;
		}
		case 'O':
		{
			if (tab_gracza[x][y] == 'x')
			{
				ruchy++; //dodanie ruchu
				tab_gracza[x][y] = 'o';
			}
			break;
		}
		case 'k':
		{
			k_gry = 1;
			break;
		}
		case 'K':
		{
			k_gry = 1;
			break;
		}
		case 'p':
		{
			h = 1;
			p = 1;
			break;
		}
		case 'P':
		{
			h = 1;
			p = 1;
			break;
		}
		case 'h':
		{
			h = 1;
			break;
		}
		case 'H':
		{
			h = 1;
			break;
		}
		case 'd':
		{
			if (x == 0 || x == 6) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (y < 5) y++;
				break;
			}
			else
			{
				if (y < 6) y++;
				break;
			}
		}
		case 'D':
		{
			if (x == 0 || x == 6) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (y < 5) y++;
				break;
			}
			else
			{
				if (y < 6) y++;
				break;
			}
		}
		case 's':
		{
			if (x != 5) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (x < 6) x++;
				break;
			}
			else
			{
				if (y == 0 || y == 6)
					break;
				else x++;
			}
		}
		case 'S':
		{
			if (x != 5) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (x < 6) x++;
				break;
			}
			else
			{
				if (y == 0 || y == 6)
					break;
				else x++;
			}
		}
		case 'a':
			if (x == 0 || x == 6) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (y > 1) y--;
				break;
			}
			else
			{
				if (y > 0) y--;
				break;
			}
		case 'A':
			if (x == 0 || x == 6) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (y > 1) y--;
				break;
			}
			else
			{
				if (y > 0) y--;
				break;
			}
		case 'w':
		{
			if (x != 1) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (x > 0) x--;
				break;
			}
			else
			{
				if (y == 0 || y == 6)
					break;
				else x--;
			}
		}
		case 'W':
		{
			if (x != 1) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (x > 0) x--;
				break;
			}
			else
			{
				if (y == 0 || y == 6)
					break;
				else x--;
			}
		}
		default: break;

		}

	} while (petla == 0);
}
//=============================================================================================================================================================================================================



void gra8x8()
{
	//=============================================================================================
	//GRA===
	bool k_gry = 0;
	bool h = 0; //czy h wcisniete
	bool k = 0; // czy k wcisniete
	bool p = 0; // czy p
	int bledy = 0; //licznik bledow
	int petla = 0; // zmienna okreslajaca czy glowna petla trwa
	char tab[10][10]; // utworzenie tablicy dwuwymiarowej
	char tab_gracza[10][10]; // utworzenie tablicy pomocniczej gracza
	//wypełniamy ją aby pozniej moc sprawdzic czy na danym polu ruch juz nie zostal wykonany
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			tab_gracza[i][j] = 'x';
	}
	srand(time(NULL)); //uruchomienie rand

	int ruchy = 0; //zmienna do licznika ruchow
	int wynik = 0; //zmienna przechowujaca wynik
	int atom_x[5]; // tablice dla pozycji atomow
	int atom_y[5];

	int zgodnosc = 0; //losowanie liczb wspl na atomy ze sprawdzeniem czy wspol nie powtarzaja sie

	zgodnosc = 0;
	for (int i = 0; i < 5; i++)
	{
		atom_x[i] = rand() % 8 + 1;
		atom_y[i] = rand() % 8 + 1;
	}


	char tab_wygranej[10][10]; //tablica pomocnicza do wygrywajacych pol i jej uzupełnienie
	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 9; j++)
			for (int k = 0; k < 5; k++)
			{
				if (atom_x[k] == i && atom_y[k] == j)
					tab_wygranej[i][j] = 'O';
			}

	//WSPOLRZEDNE AKTUALNEJ  POZYCJI NA MAPIE
	int x = 0;
	int y = 1;
	//--------------
	do
	{
		system("CLS"); // wyczyszczenie konsoli
		cout << "---------- ooooo   oo      oooo  oooooo oo  oo    ooooo    oooo  oo   oo ----------\n";
		cout << "---------- oo  oo  oo     oo  oo oo     oo oo     oo  oo  oo  oo  oo oo  ----------\n";
		cout << "---------- oooooo  oo     oooooo oo     oooo      oooooo  oo  oo   ooo   ----------\n";
		cout << "---------- oo   oo oo     oo  oo oo     oo oo     oo   oo oo  oo  oo oo  ----------\n";
		cout << "---------- ooooooo oooooo oo  oo oooooo oo  oo    ooooooo  oooo  oo   oo ----------\n\n";
		k = 0; // zmienna okreslajaca czy glowna petla trwa

		//tabela pomocnicza przy testach
		//cout << '[' << atom_x[0] << ']' << '[' << atom_y[0] << ']';
		//cout << '[' << atom_x[1] << ']' << '[' << atom_y[1] << ']';
		//cout << '[' << atom_x[2] << ']' << '[' << atom_y[2] << ']';
		//cout << '[' << atom_x[3] << ']' << '[' << atom_y[3] << ']';
		//cout << '[' << atom_x[4] << ']' << '[' << atom_y[4] << ']';

		//sprawdzenie pozycji gracza na planszy x  y do testu
		//cout << "\n";
		//cout << x << " " << y;
		//cout << "\n";

		for (int i = 0; i < 61; i++) cout << (char)(254); // ramka na gorze
		cout << "           ";
		for (int l = 0; l < 22; l++) cout << (char)(254);
		cout << "\n";

		for (int i = 0; i < 10; i++) // wypisanie planszy gry i przypisanie danych do tablicy
		{
			fioletowy();
			cout << (char)(197);
			fioletowy();
			for (int j = 0; j < 10; j++)
			{
				if (i == 0 || i == 9 || j == 0 || j == 9) // wyciągniecie if'em ścian
				{
					if (i == 0 || i == 9) // ominiecie naroznikow na planszy (nie sa uzywane w grze)
					{
						if (j == 0 || j == 9)
						{
							cout << "     " << (char)(197);
							continue; //przeskoczenie pętli
						}
					}
					if (tab_gracza[i][j] == 'H' || tab_gracza[i][j] == 'R' || tab_gracza[i][j] == 'M')
					{
						if (tab_gracza[i][j] == 'H')
						{
							tab[i][j] = 'H';
							if (i == x && j == y) // czy jest na danych wspolrzednych?
							{
								cout << "  ";
								niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych
								cout << tab[i][j];
								fioletowy(); // powrot do defaultowego koloru gry
								cout << "  ";
								cout << (char)(197);
							}
							else //jezeli nie jest na danych wspolzednych
							{
								cout << "  ";
								czerwony(); // ustawienie koloru ścian na czerwony
								cout << tab[i][j];
								fioletowy(); // powrot do defaultowego koloru gry
								cout << "  " << (char)(197);
							}
						}
						else
							if (tab_gracza[i][j] == 'R')
							{
								tab[i][j] = 'R';
								if (i == x && j == y) // czy jest na danych wspolrzednych?
								{
									cout << "  ";
									niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych
									cout << tab[i][j];
									fioletowy(); // powrot do defaultowego koloru gry
									cout << "  ";
									cout << (char)(197);
								}
								else //jezeli nie jest na danych wspolzednych
								{
									cout << "  ";
									czerwony(); // ustawienie koloru ścian na czerwony
									cout << tab[i][j];
									fioletowy(); // powrot do defaultowego koloru gry
									cout << "  " << (char)(197);
								}
							}
							else
								if (tab_gracza[i][j] == 'M')
								{
									tab[i][j] = 'M';
									if (i == x && j == y) // czy jest na danych wspolrzednych?
									{
										cout << "  ";
										niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych
										cout << tab[i][j];
										fioletowy(); // powrot do defaultowego koloru gry
										cout << "  ";
										cout << (char)(197);
									}
									else //jezeli nie jest na danych wspolzednych
									{
										cout << "  ";
										czerwony(); // ustawienie koloru ścian na czerwony
										cout << tab[i][j];
										fioletowy(); // powrot do defaultowego koloru gry
										cout << "  " << (char)(197);
									}
								}

					}
					else
					{
						tab[i][j] = (char)(254); // przypisanie wartości elementowi w tablicy
						if (i == x && j == y) // czy jest na danych wspolrzednych?
						{
							cout << "  ";
							niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych
							cout << tab[i][j];
							fioletowy();; // powrot do defaultowego koloru gry
							cout << "  ";
							cout << (char)(197);
						}
						else
						{
							cout << "  ";
							czerwony(); // ustawienie koloru ścian na czerwony
							cout << tab[i][j];
							fioletowy(); // powrot do defaultowego koloru gry
							cout << "  " << (char)(197);
						}

					}
				}
				else // ============================================================== ŚRODEK PLANSZY ===================
				{
					if (tab_gracza[i][j] != 'o') // ============================= JEZELI NIE MA NA MIEJSCU 'O' ===========
					{
						tab[i][j] = (char)(4); // przypisanie wartości defaultowej elementowi w tablicy

						if (i == x && j == y) // czy jest na danych wspolrzednych? ============ CZY KOLORUJEMY
						{
							cout << "  ";
							niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych

							if (k_gry == 1)
							{
								if (tab_wygranej[i][j] == 'O')
									cout << tab_wygranej[i][j];
								else cout << tab[i][j];
							}
							else
								if (h == 1) //pokolorowana podpowiedz
								{
									if (tab_wygranej[i][j] == 'O')
									{
										niebieski();
										cout << tab_wygranej[i][j];
									}
									else cout << tab[i][j];
								}
								else
									cout << tab[i][j];
							fioletowy(); // powrot do defaultowego koloru gry
							cout << "  ";
							cout << (char)(197);
						}
						else
						{
							cout << "  ";
							if (k_gry == 1)
							{
								if (tab_wygranej[i][j] == 'O')
								{
									niebieski();
									cout << tab_wygranej[i][j];
								}
								else cout << tab[i][j];
							}
							else
								if (h == 1) //pokolorowana podpowiedz
								{
									if (tab_wygranej[i][j] == 'O')
									{
										niebieski();
										cout << tab_wygranej[i][j];
									}
									else cout << tab[i][j];
								}
								else
									cout << tab[i][j];
							fioletowy(); // powrot do defaultowego koloru gry
							cout << "  ";
							cout << (char)(197);

						}
					}
					else //=============================================================== JEZELI 'O' JEST NA MIEJSCU
					{
						tab[i][j] = 'o';
						if (i == x && j == y) // czy jest na danych wspolrzednych? ====== CZY KOLORUJEMY
						{
							cout << "  ";
							niebieski(); // kursor (pokolorowanie) na aktualnych wspolrzednych
							if (k_gry == 1)
							{
								fioletowy(); // nie chcemy aby kolorowało aktual wspolrzednych
								if (tab_wygranej[i][j] != 'O')
								{
									bledy++;
									czerwony();
									tab[i][j] = 'X';
									cout << tab[i][j];
								}
								else
									if (tab_wygranej[i][j] == 'O') // wypisanie wyniku
									{
										wynik++;
										niebieski(); //ale kolorujemy poprawnie zaznaczone 'o' gracza
										cout << tab_wygranej[i][j];
									}
							}
							else
								if (h == 1) //pokolorowana podpowiedz nachodzaca na 'o'
								{
									if (tab_wygranej[i][j] == 'O')
									{
										niebieski();
										cout << tab_wygranej[i][j];
									}
									else cout << tab[i][j];
								}
								else
									cout << tab[i][j];
							fioletowy(); // powrot do defaultowego koloru gry
							cout << "  ";
							cout << (char)(197);
						}
						else // brak koloru
						{
							cout << "  ";
							if (k_gry == 1)
							{
								if (tab_wygranej[i][j] != 'O')
								{
									czerwony();
									tab[i][j] = 'X';
									cout << tab[i][j];
									bledy++;
								}
								else
									if (tab_wygranej[i][j] == 'O') // wypisanie wyniku
									{
										niebieski();
										cout << tab_wygranej[i][j];
										wynik++;
									}
							}
							else
								if (h == 1) //niepokolorowana podpowiedz nachodzaca na o
								{
									if (tab_wygranej[i][j] == 'O')
									{
										niebieski();
										cout << tab_wygranej[i][j];

									}
									else cout << tab[i][j];
								}
								else
									cout << tab[i][j];
							fioletowy(); // powrot do defaultowego koloru gry
							cout << "  ";
							cout << (char)(197);

						}
					}
				} // koniec rysowania srodka
			} //koniec petli j
			switch (i)
			{
			case 0: {
				cout << "            H - trafienie";
				break;
			}
			case 1: {
				cout << "            R - odbicie";
				break;
			}
			case 2: {
				cout << "            M - chybienie";
				break;
			}
			case 3: {
				cout << "           ";
				for (int l = 0; l < 22; l++) cout << (char)(254);
				break;
			}
			case 5: {
				cout << "            RUCHY GRACZA: " << ruchy;
				break;
			}
			}
			if (i != 9) cout << "\n\n"; //na koncu planszy nie robimy przerwy
		} //koniec petli i
		cout << "\n";
		for (int i = 0; i < 61; i++) cout << (char)(254);

		if (k_gry == 1)
		{
			cout << "\nWYNIK: " << wynik << " / 5";
			cout << "\nBLEDY: " << bledy;
			cout << "\nZakonczyles gre! Kliknij losowy przycisk aby wyjsc do menu...";
			_getch(); // po wyłapaniu klikniecia zamykamy gre
			k++;
			break;
		}
		if (h == 1) //przerwa i zerowanie h i powrot do tabeli | rozwiazania
		{
			if (p == 1) {
				cout << "\n";
				cout << "Oto rozwiazania. Kliknij losowy przycisk aby wyjsc do menu...";
				_getch(); // po wyłapaniu klikniecia zamykamy gre
				k = 1;
				break;
			}
			else {
				Sleep(3000);
				h = 0;
				continue;
			}
		}
		char znak; //zmienna do wyłapywania znaku z klawiatury

		cout << "\n";
		cout << "\nLEGENDA:\n|w - gora | a - lewo | s - dol | d - prawo|\n";
		cout << "| Aby strzelic wcisnij spacje |\n| Aby zaznaczyc pozycje atomu wcisnij o |\n";
		cout << "| Q - menu glowne | P - rozwiazanie | H - pomoc | K - koniec | ";
		if ((GetAsyncKeyState(VK_SPACE)) & 0x8000) { //czy spacja zostala nacisnieta

			if (tab_gracza[x][y] == 'x')
			{
				//-----------SPRAWDZENIE TRAFIENIA
				if (x == 0 || x == 9) // czy jesteśmy na scianie
				{
					for (int i = 0; i < 5; i++)
					{
						if (y == atom_y[i]) // sprawdzenie czy trafiliśmy atom
						{
							if (tab_gracza[x][y] == 'x') {
								ruchy++;
								tab_gracza[x][y] = 'H';
							}
						}
					}
				}
				else
					if (y == 0 || y == 9) // czy jesteśmy na scianie
					{
						for (int i = 0; i < 5; i++)
						{
							if (x == atom_x[i]) // sprawdzenie czy trafiliśmy atom
							{
								if (tab_gracza[x][y] == 'x') {
									ruchy++;
									tab_gracza[x][y] = 'H';
								}
							}
						}
					}
				//------------SPRAWDZENIE ODBICIA
				if (x == 0 || x == 9) // czy jesteśmy na scianie
				{
					for (int i = 0; i < 5; i++)
					{
						if (y == atom_y[i] + 1 || y == atom_y[i] - 1) // sprawdzenie czy odbiliśy atom
						{
							if (tab_gracza[x][y] == 'x') {
								ruchy++;
								// gra w przypadku gdy jest i 'R' i 'H' pokazuje tylko 'H' 
								// toteż konieczne jest ograniczenie ifem mozliwosci kolejnego nabicia ruchu na tym samym polu
								tab_gracza[x][y] = 'R';
							}
						}

					}
				}
				else
					if (y == 0 || y == 9) // czy jesteśmy na scianie
					{
						for (int i = 0; i < 5; i++)
						{
							if (x == atom_x[i] + 1 || x == atom_x[i] - 1) // sprawdzenie czy trafiliśmy atom
							{
								if (tab_gracza[x][y] == 'x') {
									ruchy++;
									tab_gracza[x][y] = 'R';
								}
							}
						}
					}
				//ani trafienie ani odbicie
				if (x == 0 || x == 9 || y == 0 || y == 9)
				{
					if (tab_gracza[x][y] == 'x') {
						tab_gracza[x][y] = 'M';
						ruchy++;
					}
				}
			}
			continue;
		}

		znak = _getch();
		switch (znak)
		{
		case 'q':
		{
			k++;
			break;
		}
		case 'Q':
		{
			k++;
			break;
		}
		case 'o':
		{
			if (tab_gracza[x][y] == 'x') // ograniczenie aby nie nabijać na jednym wiecej ruchow
			{
				ruchy++; //dodanie ruchu
				tab_gracza[x][y] = 'o';
			}
			break;
		}
		case 'O':
		{
			if (tab_gracza[x][y] == 'x')
			{
				ruchy++; //dodanie ruchu
				tab_gracza[x][y] = 'o';
			}
			break;
		}
		case 'k':
		{
			k_gry = 1;
			break;
		}
		case 'K':
		{
			k_gry = 1;
			break;
		}
		case 'p':
		{
			h = 1;
			p = 1;
			break;
		}
		case 'P':
		{
			h = 1;
			p = 1;
			break;
		}
		case 'h':
		{
			h = 1;
			break;
		}
		case 'H':
		{
			h = 1;
			break;
		}
		case 'd':
		{
			if (x == 0 || x == 9) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (y < 8) y++;
				break;
			}
			else
			{
				if (y < 9) y++;
				break;
			}
		}
		case 'D':
		{
			if (x == 0 || x == 9) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (y < 8) y++;
				break;
			}
			else
			{
				if (y < 9) y++;
				break;
			}
		}
		case 's':
		{
			if (x != 8) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (x < 9) x++;
				break;
			}
			else
			{
				if (y == 0 || y == 9)
					break;
				else x++;
			}
		}
		case 'S':
		{
			if (x != 8) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (x < 9) x++;
				break;
			}
			else
			{
				if (y == 0 || y == 9)
					break;
				else x++;
			}
		}
		case 'a':
			if (x == 0 || x == 9) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (y > 1) y--;
				break;
			}
			else
			{
				if (y > 0) y--;
				break;
			}
		case 'A':
			if (x == 0 || x == 9) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (y > 1) y--;
				break;
			}
			else
			{
				if (y > 0) y--;
				break;
			}
		case 'w':
		{
			if (x != 1) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (x > 0) x--;
				break;
			}
			else
			{
				if (y == 0 || y == 9)
					break;
				else x--;
			}
		}
		case 'W':
		{
			if (x != 1) //sprawdzenie czy kursor nie wejdzie na krawedz planszy
			{
				if (x > 0) x--;
				break;
			}
			else
			{
				if (y == 0 || y == 9)
					break;
				else x--;
			}
		}
		default: break;

		}

	} while (petla == 0);
}



int main()
{
	int end = 0;
	do
	{
		fioletowy(); // kolor czcionki konsoli - fioletowy
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "---------- ooooo   oo      oooo  oooooo oo  oo    ooooo    oooo  oo   oo ----------\n";
		cout << "---------- oo  oo  oo     oo  oo oo     oo oo     oo  oo  oo  oo  oo oo  ----------\n";
		cout << "---------- oooooo  oo     oooooo oo     oooo      oooooo  oo  oo   ooo   ----------\n";
		cout << "---------- oo   oo oo     oo  oo oo     oo oo     oo   oo oo  oo  oo oo  ----------\n";
		cout << "---------- ooooooo oooooo oo  oo oooooo oo  oo    ooooooo  oooo  oo   oo ----------\n";
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------\n";
		//-----------------------------------
		cout << "\n                                " << (char)(175) << (char)(175) << "  1 - ETAP 5x5  " << (char)(174) << (char)(174);
		cout << "\n                                " << (char)(175) << (char)(175) << "  2 - ETAP 8x8  " << (char)(174) << (char)(174);
		cout << "\n                             " << (char)(175) << (char)(175) << "  Q - WYJSCIE Z GRY  " << (char)(174) << (char)(174);
		cout << "\n\n\n";
		char znak;
		znak = _getch();
		switch (znak)
		{
		case '1':
		{
			gra5x5();
			break;
		}
		case '2':
		{
			gra8x8();
			break;
		}
		case 'q':
		{
			end++;
			break;
		}
		case 'Q':
		{
			end++;
			break;
		}
		default: break;
		}
		system("cls");
	} while (end == 0);

}

