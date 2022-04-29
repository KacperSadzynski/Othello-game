#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include"menu.h"
#include"stale.h"
#include"mechanika.h"
#include<iostream>

template<class T>
T suma(T a, T b)
{
	return a + b;
}

int main()
{
	//std::cout << suma(5, 6)<<std::endl;
	//std::cout << suma(5.5, 3.25);

	Plansza p1;
	Menu m1(1);
	m1.wypisanie_menu();
	m1.wybranie_trybu_gry();
	p1.plansza_wypisanie(p1.get_plansza());
	switch (m1.gettryb())
	{
	case 1:			//gra z komputerem
	{
		Czlowiek c1;
		Komputer k1;
		Przebieg_gry prz;
		prz.system_tur(c1, k1, p1);
		break;
	}
	case 2:			//gra z graczem
	{
		Czlowiek c1;
		Czlowiek c2;
		Przebieg_gry prz;
		prz.system_tur(c1, c2, p1);
		break;
	}
	default:		//wyjœcie z gry
	
		printf("\nKoniec gry\n");
		break;
	}
	return 0;
}
