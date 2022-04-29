#include "stale.h"
#include <stdio.h>

int wczytanie_liczby_calkowitej(int min, int max)
{
	int liczba;
	while (scanf_s("%d", &liczba) != 1 || liczba<min || liczba>max || getchar() != '\n')
	{
		printf("Bledna liczba, wprowadz ponownie:");
		while (getchar() != '\n') { ; }
	}
	return liczba;
}