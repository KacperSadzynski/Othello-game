#ifndef mechanika_h
#define mechanika_h
#include"menu.h"
bool czy_dozwolony_ruch(char kolor, int wiersz, int kolumna, char** plansza);			//Funkcja sprawdza czy w danych koordynatach jest mo�na wykona� ruch zgodnie z zasadami gry
bool czy_bierka_w_pionie(char kolor, int wiersz, char** plansza);						//Funkcja pomocnicza do funkcji czy_dozwolony_ruch, sprawdza warunek ruchu w pionie
bool czy_bierka_w_poziomie(char kolor, int kolumna, char** plansza);					//Funkcja pomocnicza do funkcji czy_dozwolony_ruch, sprawdza warunek ruchu w poziomie
bool czy_bierka_na_ukos_lewy(char kolor, int wiersz, int kolumna, char** plansza);		//Funkcja pomocnicza do funkcji czy_dozwolony_ruch, sprawdza warunek ruchu na ukos lewy
bool czy_bierka_na_ukos_prawy(char kolor, int wiersz, int kolumna, char** plansza);		//Funkcja pomocnicza do funkcji czy_dozwolony_ruch, sprawdza warunek ruchu na ukos prawy
void polaczenie_bierek(int wiersz, int kolumna,char** plansza, char kolor);				//Funkcja kt�ra przejmuje bierki przeciwnika zgodnie z zasadmi gry
bool wygrana(char** plansza);															//Funkcja sprawdzaj�ca warunek zwyci�stwa

class Gracz
{
protected:
	char kolor_twoich_bierek;
	static int nr_tury;
public:
	
	Gracz();											//konstruktor domy�lny ustala kolor dla gracza funkcj�
	virtual void ruch(Plansza &p) = 0;					//Metoda virtualna kt�ra obs�uguje ruch gracza (cz�owieka lub komputera)
	void losowanie_koloru_bierek();						//Metoda kt�ra losuje kolor bierek dla gracza
	char getkolor() { return kolor_twoich_bierek; }
	void setkolor(char k) { kolor_twoich_bierek = k; }
	static int getnr_tury() { return nr_tury; }
	void setnr_tury(int a) { nr_tury = a; }
};

class Komputer:public Gracz
{
public:
	Komputer();											//konstruktor domy�lny ustala kolor dla gracza funkcj�
	void ruch(Plansza &p);								//Metoda kt�ra obs�uguje ruch Komputera
	char getkolor() { return kolor_twoich_bierek; }
};

class Czlowiek:public Gracz
{
public:
	Czlowiek();											//konstruktor domy�lny ustala kolor dla gracza funkcj�	
	void ruch(Plansza& p);								//Metoda kt�ra obs�uguje ruch Cz�owieka
	char getkolor() { return kolor_twoich_bierek; }
};

class Przebieg_gry
{
private:
	
public:
	void tura(Gracz& g1, Gracz& g2,Plansza &p);			//Metoda wykonuj�ca jedn� tur� w zale�no�ci od tego jaki jest nr tury wykonuje j� dla gracza 1 lub gracza 2
	void system_tur(Gracz& g1, Gracz& g2, Plansza& p);	//Metoda wywo�uj�ca metod� "tura" dop�ki nie zostanie spe�niony warunek zwyci�stwa (posiada r�wnie� system wczytania gry)
	void kto_wygral(Gracz& g1, Gracz& g2, Plansza& p);	//Metoda sprawdzaj�ca kt�ry gracz wygra�
	void zapis_gry(int nr,Plansza& p);					//Metoda kt�ra zapisuje (co tur�) stan gry do pliku zapis.txt
	void wyczysc_zapis_gry();							//Metoda kt�ra czy�ci zapis je�li gra doprowadzona by�a do ko�ca poprawnie
	bool czy_plik_jest_pusty();							//Metoda pomocnicza sprawdzaj�ca czy plik z zapisem posiada jakie� dane
	void wczytaj_zapis_gry(Gracz& g1, Plansza& p);		//Metoda kt�ra pobiera zapis gry z pliku zapis.txt
};

#endif


