#define _CRT_SECURE_NO_WARNINGS
#include "mechanika.h"
#include "stale.h"
#include "menu.h"
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<fstream>
bool czy_dozwolony_ruch(char kolor,int wiersz, int kolumna, char** plansza)
{
	bool flaga = false;
	int pomw = wiersz;
	int pomk = kolumna;
	if (plansza[wiersz][kolumna] != ' ')
	{
		return false;
	}
	else
	{
		if (czy_bierka_w_pionie(kolor, kolumna, plansza))
		{
			//printf("%d %d ", wiersz + 1, kolumna + 1);
			while (pomw > 0)
			{
				
				pomw -= 1;
				if (plansza[pomw][kolumna] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
				{
					break;
				}
				if (plansza[pomw][kolumna] != kolor && plansza[pomw][kolumna] != ' ')	//sprawdzam czy pomiedzy s¹ bierki przeciwnika
				{
					flaga = true;
					if (pomw == 0)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
					{
						flaga = false;
					}
				}
				else
				{
					flaga = false;
					break;
				}
			}
			if (flaga == true)
			{
				return true;
			}
			pomw = wiersz;
			while (pomw < 7)
			{
				pomw += 1;
				if (plansza[pomw][kolumna] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
				{
					break;
				}
				if (plansza[pomw][kolumna] != kolor && plansza[pomw][kolumna] != ' ')	//sprawdzam czy pomiedzy s¹ bierki przeciwnika
				{
					flaga = true;
					if (pomw == 7)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
					{
						flaga = false;
					}
				}
				else
				{
					flaga = false;
					break;
				}
			}
			if (flaga == true)
			{
				return true;
			}
		}
		if (czy_bierka_w_poziomie(kolor, wiersz, plansza))
		{
			//printf("%d %d ", wiersz+1,kolumna+1);
			while (pomk > 0) //w lewo
			{
				pomk -= 1;
				if (plansza[wiersz][pomk] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
				{
					break;
				}
				if (plansza[wiersz][pomk] != kolor && plansza[wiersz][pomk] != ' ')
				{
					flaga = true;
					if (pomk == 0)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
					{
						flaga = false;
					}
				}
				else
				{
					flaga = false;
					break;
				}
			}
			if (flaga == true)
			{
				return true;
			}
			pomk = kolumna;
			while (pomk < 7)	//w prawo
			{
				pomk += 1;
				if (plansza[wiersz][pomk] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
				{
					break;
				}
				if (plansza[wiersz][pomk] != kolor && plansza[wiersz][pomk] != ' ')	//sprawdzanie czy pomiedzy s¹ same bierki przeciwnego koloru
				{
					flaga = true;
					if (pomk == 7)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
					{
						flaga = false;
					}
				}
				else
				{
					flaga = false;
					break;
				}
			}
			if (flaga == true)
			{
				return true;
			}
		}
		if (czy_bierka_na_ukos_lewy(kolor,wiersz,kolumna,plansza))
		{
			pomw = wiersz;
			pomk = kolumna;
			while (pomk > 0 && pomw > 0)	//w górê
			{
				pomk -= 1;
				pomw -= 1;
				if (plansza[pomw][pomk] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
				{
					break;
				}
				if (plansza[pomw][pomk] != kolor && plansza[pomw][pomk] != ' ')//sprawdzanie czy pomiedzy s¹ same bierki przeciwnego koloru
				{
					flaga = true;
					if (pomw == 0 || pomk == 0)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
					{
						flaga = false;
					}
				}
				else
				{
					flaga = false;
					break;
				}
			}
			if (flaga == true)
			{
				return true;
			}
			pomw = wiersz;
			pomk = kolumna;
			while (pomk < 7 && pomw < 7)	//w dó³
			{
				pomk += 1;
				pomw += 1;
				if (plansza[pomw][pomk] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
				{
					break;
				}
				if (plansza[pomw][pomk] != kolor && plansza[pomw][pomk] != ' ')	//sprawdzanie czy pomiedzy s¹ same bierki przeciwnego koloru
				{
					flaga = true;
					if (pomw == 7 || pomk == 7)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
					{
						flaga = false;
					}
				}
				else
				{
					flaga = false;
					break;
				}
			}
			if (flaga == true)
			{
				return true;
			}
		}
		if (czy_bierka_na_ukos_prawy(kolor, wiersz, kolumna, plansza))
		{
			pomw = wiersz;
			pomk = kolumna;
			while (pomw > 0 && pomk < 7)	//w górê
			{
				pomw -= 1;
				pomk += 1;
				if (plansza[pomw][pomk] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
				{
					break;
				}
				if (plansza[pomw][pomk] != kolor && plansza[pomw][pomk] != ' ')//sprawdzanie czy pomiedzy s¹ same bierki przeciwnego koloru
				{
					flaga = true;
					if (pomw == 0 || pomk == 7)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
					{
						flaga = false;
					}
				}
				else
				{
					flaga = false;
					break;
				}
			}
			if (flaga == true)
			{
				return true;
			}
			pomw = wiersz;
			pomk = kolumna;
			while (pomw < 7 && pomk > 0)	//w dó³
			{
				pomw += 1;
				pomk -= 1;
				if (plansza[pomw][pomk] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
				{
					break;
				}
				if (plansza[pomw][pomk] != kolor && plansza[pomw][pomk] != ' ')	//sprawdzanie czy pomiedzy s¹ same bierki przeciwnego koloru
				{
					flaga = true;
					if (pomw == 7 || pomk == 0)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
					{
						flaga = false;
					}
				}
				else
				{
					flaga = false;
					break;
				}
			}
			if (flaga == true)
			{
				return true;
			}
		}
	}
	return false;
}

bool czy_bierka_w_pionie(char kolor,int kolumna, char** plansza)
{
	for (int i = 0; i < wymiar_mapy; ++i)
	{
		if (plansza[i][kolumna] == kolor)
		{
			return true;
		}
	}
	return false;
}
bool czy_bierka_w_poziomie(char kolor, int wiersz, char** plansza)
{
	for (int i = 0; i < wymiar_mapy; ++i)
	{
		if (plansza[wiersz][i] == kolor)
		{
			return true;
		}
	}
	return false;
}
bool czy_bierka_na_ukos_lewy(char kolor, int wiersz, int kolumna, char** plansza)
{
	int w = wiersz;
	int k = kolumna;
	
	while (w > 0 && k > 0)
	{
		w = w - 1;
		k = k - 1;
		if (plansza[w][k] == kolor)
		{
			return true;
		}
	}
	w = wiersz;
	k = kolumna;
	while (w < 7 && k < 7)
	{
		w = w + 1;
		k = k + 1;
		if (plansza[w][k] == kolor)
		{
			return true;
		}
	}
	return false;
}
bool czy_bierka_na_ukos_prawy(char kolor, int wiersz, int kolumna, char** plansza)
{
	int w = wiersz;
	int k = kolumna;
	while (w > 0 && k < 7)
	{
		w = w - 1;
		k = k + 1;
		if (plansza[w][k] == kolor)
		{
			return true;
		}
	}
	w = wiersz;
	k = kolumna;
	while (w < 7 && k > 0)
	{
		w = w + 1;
		k = k - 1;
		if (plansza[w][k] == kolor)
		{
			return true;
		}
	}
	return false;
}

void polaczenie_bierek(int wiersz,int kolumna, char** plansza, char kolor)
{
	bool flaga = false;
	int w = wiersz;
	int k = kolumna;
	while (w > 0)	//sprawdzanie w pionie w górê
	{
		w -= 1;
		if (plansza[w][kolumna] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
		{
			break;
		}
		if (plansza[w][kolumna] != kolor && plansza[w][kolumna] != ' ')	//sprawdzam czy pomiedzy s¹ bierki przeciwnika
		{
			flaga = true;
			if (w == 0)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
			{
				flaga = false;
			}
		}
		else
		{
			flaga = false;
			break;
		}
	}
	if (flaga == true)		//zmienianie koloru bierek
	{
		while (w < 7)	
		{
			w += 1;
			if (plansza[w][kolumna] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec 
			{
				break;
			}
			else
			{
				plansza[w][kolumna] = kolor;
			}
		}	
	}
	flaga = false;
	w = wiersz;
	while (w < 7)  //sprawdzanie w pionie w dó³
	{
		w += 1;
		if (plansza[w][kolumna] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec 
		{
			break;
		}
		if (plansza[w][kolumna] != kolor && plansza[w][kolumna] != ' ')	//sprawdzam czy pomiedzy s¹ bierki przeciwnika
		{
			flaga = true;
			if (w == 7)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
			{
				flaga = false;
			}
		}
		else
		{
			flaga = false;
			break;
		}
	}
	if (flaga == true)		//zmienianie koloru bierek
	{
		while (w > 0)			
		{
			w -= 1;
			if (plansza[w][kolumna] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
			{
				break;
			}
			else
			{
				plansza[w][kolumna] = kolor;
			}
		}
	}
	flaga = false;
	while (k > 0)	//sprawdzanie w poziomie w lewo
	{
		k -= 1;
		if (plansza[wiersz][k] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
		{
			break;
		}
		if (plansza[wiersz][k] != kolor && plansza[wiersz][k] != ' ')
		{
			flaga = true;
			if (k == 0)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
			{
				flaga = false;
			}
		}
		else
		{
			flaga = false;
			break;
		}
	}
	if (flaga == true)		//zmienianie koloru bierek
	{
		while (k < 7)
		{
			k += 1;
			if (plansza[wiersz][k] == kolor)
			{
				break;
			}
			else
			{
				plansza[wiersz][k] = kolor;
			}
		}
	}
	flaga = false;
	k = kolumna;
	while (k < 7)	//sprawdzanie w poziomie w prawo
	{
		k += 1;
		if (plansza[wiersz][k] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
		{
			break;
		}
		if (plansza[wiersz][k] != kolor && plansza[wiersz][k] != ' ')	//sprawdzanie czy pomiedzy s¹ same bierki przeciwnego koloru
		{
			flaga = true;
			if (k == 7)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
			{
				flaga = false;
			}
		}
		else
		{
			flaga = false;
			break;
		}
	}
	if (flaga == true)
	{
		while (k > 0)
		{
			k -= 1;
			if (plansza[wiersz][k] == kolor)
			{
				break;
			}
			else
			{
				plansza[wiersz][k] = kolor;
			}
		}
	}
	w = wiersz;
	k = kolumna;
	flaga = false;
	while (k > 0 && w > 0)	//sprawdzanie na ukos lewy w górê
	{
		k -= 1;
		w -= 1;
		if (plansza[w][k] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
		{
			break;
		}
		if (plansza[w][k] != kolor && plansza[w][k] != ' ')
		{
			flaga = true;
			if (w == 0 || k == 0)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
			{
				flaga = false;
			}
		}
		else
		{
			flaga = false;
			break;
		}
	}
	if (flaga == true)
	{
		while (k < 7 && w < 7)
		{
			k += 1;
			w += 1;
			if (plansza[w][k] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
			{
				break;
			}
			else
			{
				plansza[w][k] = kolor;
			}
		}
	}
	w = wiersz;
	k = kolumna;
	flaga = false;
	while (k < 7 && w < 7)		//sprawdzanie na ukos lewy w dó³
	{
		k += 1;
		w += 1;
		if (plansza[w][k] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
		{
			break;
		}
		if (plansza[w][k] != kolor && plansza[w][k] != ' ')	//sprawdzanie czy pomiedzy s¹ same bierki przeciwnego koloru
		{
			flaga = true;
			if (w == 7 || k == 7)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
			{
				flaga = false;
			}
		}
		else
		{
			flaga = false;
			break;
		}
	}
	if (flaga == true)
	{
		while (k > 0 && w > 0)
		{
			k -= 1;
			w -= 1;
			if (plansza[w][k] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
			{
				break;
			}
			else
			{
				plansza[w][k] = kolor;
			}
		}
	}
	w = wiersz;
	k = kolumna;
	flaga = false;
	while (w > 0 && k < 7)			//sprawdzanie na ukos prawy w górê
	{
		w -= 1;
		k += 1;
		if (plansza[w][k] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
		{
			break;
		}
		if (plansza[w][k] != kolor && plansza[w][k] != ' ')
		{
			flaga = true;
			if (w == 0 || k == 7)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
			{
				flaga = false;
			}
		}
		else
		{
			flaga = false;
			break;
		}
	}
	if (flaga == true)
	{
		while (w < 7 && k > 0)
		{
			w += 1;
			k -= 1;
			if (plansza[w][k] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
			{
				break;
			}
			else
			{
				plansza[w][k] = kolor;
			}
		}
	}
	w = wiersz;
	k = kolumna;
	flaga = false;
	while (w < 7 && k > 0)		//sprawdzanie na ukos prawy w dó³
	{
		w += 1;
		k -= 1;
		if (plansza[w][k] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
		{
			break;
		}
		if (plansza[w][k] != kolor && plansza[w][k] != ' ')	//sprawdzanie czy pomiedzy s¹ same bierki przeciwnego koloru
		{
			flaga = true;
			if (w == 7 || k == 0)		//jeœli jest to ostatni rz¹d to false poniewa¿ koñczy siê tablica(napotykamy bierke przeciwnika)
			{
				flaga = false;
			}
		}
		else
		{
			flaga = false;
			break;
		}
	}
	if (flaga == true)
	{
		while (w > 0 && k < 7)
		{
			w -= 1;
			k += 1;
			if (plansza[w][k] == kolor)	//sprawdzanie czy trafilem na swoja bierkê jeœli tak to koniec sprawdzania
			{
				break;
			}
			else
			{
				plansza[w][k] = kolor;
			}
		}
	}
}

bool dozwolony1 = true;
bool dozwolony2 = true;
bool wygrana(char** plansza)
{
	if (dozwolony1 == false && dozwolony2 == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Gracz::nr_tury = 0;
static char pom;
int licznik = 0;

void Gracz::losowanie_koloru_bierek()
{
	srand(time(NULL));
	if (licznik == 0)
	{
		int losowa = rand() % 2;
		if (losowa == 0)
		{
			kolor_twoich_bierek = 'c';
			pom = kolor_twoich_bierek;
			licznik++;
		}
		else
		{
			kolor_twoich_bierek = 'b';
			pom = kolor_twoich_bierek;
			licznik++;
		}
	}
	else if(pom=='c')
	{
		kolor_twoich_bierek = 'b';
	}
	else
	{
		kolor_twoich_bierek = 'c';
	}
}

Gracz::Gracz() :kolor_twoich_bierek('Q')
{
	losowanie_koloru_bierek();
}

Komputer::Komputer()
	:Gracz()
{
	
}

Czlowiek::Czlowiek()
	:Gracz()
{
	
}
int licz = 0;								//zmienna pomocnicza do warunku zwyciestwa
bool czy_bylem_w_poprzedniej_turze = false;	//zmienna pomocnicza do warunku zwyciestwa

void Czlowiek::ruch(Plansza& p)				//metoda obs³uguj¹ca ruch cz³owieka
{
	dozwolony1 = true;
	if (Menu::gettryb() == 2)		//wariant gdy graj¹ dwie osoby (warunek zwyciestwa)
	{
		dozwolony2 = true;
	}
	nr_tury++;
	int dozwolone_ruchy[wymiar_mapy][wymiar_mapy] = { 0 };
	for (int i = 0; i < wymiar_mapy; ++i)
	{
		for (int j = 0; j < wymiar_mapy; ++j)
		{
			if (czy_dozwolony_ruch(kolor_twoich_bierek, i, j, p.get_plansza()))
			{
				dozwolone_ruchy[i][j] = 1;
			}
			else
			{
				dozwolone_ruchy[i][j] = 0;
			}
		}
	}
	bool znalazl = false;
	for (int i = 0; i < wymiar_mapy; ++i)
	{
		for (int j = 0; j < wymiar_mapy; ++j)
		{
			if (dozwolone_ruchy[i][j] == 1)
			{
				znalazl = true;
				break;
			}
		}
		if (znalazl == true)
			break;
	}
	if (znalazl == true)
	{
		//for (int i = 0; i < wymiar_mapy; ++i)		//mapka z dozwolonymi ruchami do testów
		//{
		//	for (int j = 0; j < wymiar_mapy; ++j)
		//	{
		//		printf("%d ", dozwolone_ruchy[i][j]);
		//	}
		//	printf("\n");
		//}
		czy_bylem_w_poprzedniej_turze = false;
		int wiersz, kolumna;
		printf("Wprowadz wspolrzedne pola\n");
		int licznik = 0;
		do
		{
			if (licznik != 0)
			{
				printf("Ruch niemozliwy do wykonania, sprobuj ponownie.\n");
			}
			printf("Wprowadz wiersz:");
			wiersz = wczytanie_liczby_calkowitej(1, wymiar_mapy);
			printf("Wprowadz kolumne:");
			kolumna = wczytanie_liczby_calkowitej(1, wymiar_mapy);
			licznik++;
		} while (dozwolone_ruchy[wiersz - 1][kolumna - 1] == 0);//sprawdzanie w tabeli z dozwolonymi ruchami czy ruch okreslony takimi koordynatami mo¿na wykonaæ
		p.setplansza(wiersz, kolumna, kolor_twoich_bierek);
		polaczenie_bierek(wiersz-1, kolumna-1, p.get_plansza(), kolor_twoich_bierek);
		p.plansza_wypisanie(p.get_plansza());
	}
	else
	{
		printf("\nNie ma zadnych dozwolonych ruchow\n");
		Sleep(1000);
		dozwolony1 = false;
		if (Menu::gettryb() == 2)	//wariant gdy graj¹ dwie osoby (warunek zwyciestwa)
		{
			if (licz != 0 && czy_bylem_w_poprzedniej_turze == true)
			{
				dozwolony2 = false;
			}
			licz++;
			czy_bylem_w_poprzedniej_turze = true;
		}
	}
}

void Komputer::ruch(Plansza& p)		//metoda symulujaca ruch komputera
{
	dozwolony2 = true;
	nr_tury++;
	printf("Ruch komputera\n");
	Sleep(1000);
	
	int dozwolone_ruchy[wymiar_mapy][wymiar_mapy] = { 0 };
	for (int i = 0; i < wymiar_mapy; ++i)
	{
		for (int j = 0; j < wymiar_mapy; ++j)
		{
			if (czy_dozwolony_ruch(kolor_twoich_bierek,i, j, p.get_plansza()))
			{
				dozwolone_ruchy[i][j] = 1;
			}
			else
			{
				dozwolone_ruchy[i][j] = 0;
			}
		}
	}
	
	int x, y;
	bool znalazl = false;
	for (int i = 0; i < wymiar_mapy; ++i)
	{
		for (int j = 0; j < wymiar_mapy; ++j)
		{
			if (dozwolone_ruchy[i][j] == 1)
			{
				x = i;
				y = j;
				znalazl = true;
				break;
			}
		}
		if (znalazl == true)
			break;
	}
	if (znalazl == true)
	{
		p.setplansza(x+1, y+1, kolor_twoich_bierek); //uwaga na indeksy
		polaczenie_bierek(x, y, p.get_plansza(), kolor_twoich_bierek);
		p.plansza_wypisanie(p.get_plansza());
	}
	else
	{
		printf("\nKomputer nie ma zadnych dozwolonych ruchow\n");
		Sleep(1000);
		dozwolony2 = false;
	}
}

void  Przebieg_gry::tura(Gracz& g1, Gracz& g2,Plansza &p)
{
	if (g1.getnr_tury() % 2 == 0)
	{
		if (g1.getkolor() == 'c')
		{
			printf("Gracz 1:\n");
			printf("Kolor bierek: Czarny\n");
			g1.ruch(p);
		}
		else
		{
			printf("Gracz 2:\n");
			printf("Kolor bierek: Czarny\n");
			g2.ruch(p);

		}
	}
	else
	{
		if (g1.getkolor() == 'b')
		{
			printf("Gracz 1:\n");
			printf("Kolor bierek: Bialy\n");
			g1.ruch(p);
		}
		else
		{
			printf("Gracz 2:\n");
			printf("Kolor bierek: Bialy\n");
			g2.ruch(p);
		}
	}
	zapis_gry(g1.getnr_tury(), p);
}

void Przebieg_gry::kto_wygral(Gracz& g1, Gracz& g2, Plansza& p)
{
	int biale = 0;
	int czarne = 0;
	char** wsk = p.get_plansza();
	for (int i = 0; i < wymiar_mapy; ++i)
	{
		for (int j = 0; j < wymiar_mapy; ++j)
		{
			if (wsk[i][j] == 'b')
			{
				biale++;
			}
			if (wsk[i][j] == 'c')
			{
				czarne++;
			}
		}
	}
	if (czarne > biale)
	{
		printf("Wygraly Czarne wynikiem - Czarne: %d Biale: %d\n", czarne, biale);
	}
	else if (biale > czarne)
	{
		printf("Wygraly Biale wynikiem - Czarne: %d Biale: %d\n", czarne, biale);
	}
	else
	{
		printf("\nRemis wynikiem - Czarne: %d Biale: %d\n", czarne, biale);
	}
}

void Przebieg_gry::system_tur(Gracz& g1, Gracz& g2, Plansza &p)
{
	if (g1.getnr_tury() == 0 && czy_plik_jest_pusty() == false)
	{
		printf("Czy chcesz wczytac zapisana gre?\n");
		printf("1:TAK\n");
		printf("2:NIE\n");
		printf("Wprowadz liczbe:");
		int w = wczytanie_liczby_calkowitej(1, 2);
		if (w == 1)
		{
			wczytaj_zapis_gry(g1,p);		//skopiowanie mapy i nr tury z pliku
			p.plansza_wypisanie(p.get_plansza());
			if (g1.getnr_tury() % 2 == 0)		
			{
				g1.setkolor('c');
				g2.setkolor('b');
			}
			else
			{
				g1.setkolor('b');
				g2.setkolor('c');
			}
		}
	}
	do
	{
		Przebieg_gry::tura(g1, g2, p);
	} while (wygrana(p.get_plansza()) == false);
	printf("\nKoniec Gry\n");
	Przebieg_gry::wyczysc_zapis_gry();
	Przebieg_gry::kto_wygral(g1, g2, p);
}

void  Przebieg_gry::zapis_gry(int nr, Plansza& p)
{
	FILE* stream;
	if (fopen_s(&stream, "zapis.txt", "w") != NULL)		//otwarcie pliku
	{
		fprintf(stderr, "Blad otwarcia pliku (%d): %s\n", errno, strerror(errno));
	}
	else
	{
		fprintf(stream,"%d\n", nr);
		for (int i = 0; i < wymiar_mapy; i++)
		{
			for (int j = 0; j < wymiar_mapy; j++)
			{
				fprintf(stream, "%c", p.get_plansza()[i][j]);
			}
			fprintf(stream, "\n");
		}
	}
	fclose(stream);
}

void  Przebieg_gry::wyczysc_zapis_gry()		//wyczyszczenie zapisu gry
{
	FILE* stream;
	if (fopen_s(&stream, "zapis.txt", "w") != NULL)		//otwarcie pliku
	{
		fprintf(stderr, "Blad otwarcia pliku (%d): %s\n", errno, strerror(errno));
	}
	fclose(stream);
}

bool Przebieg_gry::czy_plik_jest_pusty()
{
	FILE* stream;
	if (fopen_s(&stream, "zapis.txt", "r") != NULL)	//otwarcie pliku
	{
		//fprintf(stderr, "Blad otwarcia pliku (%d): %s\n", errno, strerror(errno));
		fopen_s(&stream, "zapis.txt", "w");		//w przypadku gdy program nie znajdzie pliku sam go tworzy i zostawio go pustego
		fclose(stream);
		return true;
	}
	else
	{
		int zmienna;
		int licz = 0;
		while (!feof(stream))
		{
			if (licz > 0)
			{
				fclose(stream);
				return false;
			}
			fscanf_s(stream, "%d", &zmienna);
			licz++;
		}
	}
	fclose(stream);
	return true;
}

void Przebieg_gry::wczytaj_zapis_gry(Gracz& g1, Plansza& p)
{
	FILE* stream;
	if (fopen_s(&stream, "zapis.txt", "r") != NULL)		//otwarcie pliku
	{
		fprintf(stderr, "Blad otwarcia pliku (%d): %s\n", errno, strerror(errno));
	}
	else
	{
		int zmienna;
		char enter;
		char z;
		fscanf_s(stream, "%d", &zmienna);
		g1.setnr_tury(zmienna);
		fscanf_s(stream, "%c", &enter);
		for (int i = 0; i < wymiar_mapy; i++)
		{
			for (int j = 0; j < wymiar_mapy; j++)
			{
				fscanf_s(stream, "%c", &z);
				p.get_plansza()[i][j] = z;
			}
			fscanf_s(stream, "%c", &enter);
		}
		fclose(stream);
	}
}