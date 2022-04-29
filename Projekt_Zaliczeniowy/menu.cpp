#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>
#include "stale.h"

void Plansza::plansza_tworzenie()
{
	char** plansza = new char* [wymiar_mapy];   //alokacja tablicy dwu-wymiarowej dynamicznej
	if (plansza == NULL)
	{
		fprintf(stderr, "Blad alokacji tablicy (%d): %s\n", errno, strerror(errno));
		delete[] plansza;
		exit(0);
	}
	for (int i = 0; i < wymiar_mapy; ++i)
	{
		plansza[i] = new char[wymiar_mapy];  
		if (plansza[i] == NULL)
		{
			fprintf(stderr, "Blad alokacji tablicy (%d): %s\n", errno, strerror(errno));
			for (int j = 0; j < i; ++j)
			{
				delete[] plansza[j];
			}
			delete[] plansza;
			exit(0);
		}

	}
	for (int i = 0; i < wymiar_mapy; ++i)							//wype³nienie tablicy spacjami
	{
		for (int j = 0; j < wymiar_mapy; ++j)
		{
			plansza[i][j] = ' ';
		}
	}
	
	plansza[3][3] = 'b';			//pozycja startowa do gry
	plansza[4][4] = 'b';
	plansza[3][4] = 'c';
	plansza[4][3] = 'c';

	mapa = plansza;
}

Plansza::Plansza() :mapa(NULL)
{
	plansza_tworzenie();
}

Plansza::~Plansza()
{
	for (int i = 0; i < wymiar_mapy; ++i)
	{
		delete[] mapa[i];
	}
	delete mapa;
}

char**Plansza::get_plansza()
{
	return mapa;
}

void Plansza::plansza_wypisanie(char** plansza)
{
	system("cls");
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
	int licznik = -1;
	printf("   1   2   3   4   5   6   7   8  \n");
	for (int i = 0; i < wymiar_mapy*2+1; ++i)				//wypisanie planszy
	{
		if (i == 0)
		{
			printf(" %c%c%c%c%c", 218, 196, 196, 196, 194);
		}
		else if (i % 2 == 1)
		{
			printf("%d", licznik + 2);
			printf("%c",179);
			licznik++;
			
		}
		else if (i % 2 == 0 && i != 16)
		{
			printf(" %c", 195);
		}
		else
		{
			printf(" %c%c%c%c%c", 192, 196, 196, 196, 193);
		}
		for (int j = 0; j < wymiar_mapy; ++j)
		{
			if (i == 0 && j < 6)
			{
				printf("%c%c%c%c", 196, 196, 196, 194);
			}
			else if (j == 7 && i == 0)
			{
				printf("%c%c%c%c", 196, 196, 196, 191);
			}
			else if (i % 2 == 1)
			{
				printf(" %c %c",plansza[licznik][j], 179);				//miejsce na wpisanie
			}
			else if (i != 0 && i % 2 == 0 && i != 16 && j != 7)
			{
				printf("%c%c%c%c", 196, 196, 196, 197);
			}
			else if (i != 16 && j == 7)
			{
				printf("%c%c%c%c", 196, 196, 196, 180);
			}
			else if (i == 16 && j != 1 && j != 7)
			{
				printf("%c%c%c%c", 196, 196, 196, 193);
			}
			else if (i == 16 && j == 7)
			{
				printf("%c%c%c%c", 196, 196, 196, 217);
			}
		}
		printf("\n");
	}
	printf("\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}

void Plansza::setplansza(int w, int k, char kolor)
{
	mapa[w - 1][k - 1] = kolor;
}

void Menu::wypisanie_menu()
{
	printf("\nGra Reversi:\n\n");
	printf("Wcisnij 1 aby grac z komputerem\n");
	printf("Wcisnij 2 aby grac z graczem\n");
	printf("Wcisnij 3 aby wyjsc z gry\n");
}

void Menu::wybranie_trybu_gry()
{
	int wybor = wczytanie_liczby_calkowitej(1, 3);
	tryb_gry = wybor;
}

int Menu::tryb_gry;

Menu::Menu(int tryb)
{
	tryb_gry = tryb;
}

Menu::~Menu()
{

}

int Menu::gettryb()
{
	return tryb_gry;
}

