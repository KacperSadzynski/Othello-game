#ifndef mechanika_h
#define mechanika_h
#include"menu.h"
bool czy_dozwolony_ruch(char kolor, int wiersz, int kolumna, char** plansza);			//Funkcja sprawdza czy w danych koordynatach jest mo¿na wykonaæ ruch zgodnie z zasadami gry
bool czy_bierka_w_pionie(char kolor, int wiersz, char** plansza);						//Funkcja pomocnicza do funkcji czy_dozwolony_ruch, sprawdza warunek ruchu w pionie
bool czy_bierka_w_poziomie(char kolor, int kolumna, char** plansza);					//Funkcja pomocnicza do funkcji czy_dozwolony_ruch, sprawdza warunek ruchu w poziomie
bool czy_bierka_na_ukos_lewy(char kolor, int wiersz, int kolumna, char** plansza);		//Funkcja pomocnicza do funkcji czy_dozwolony_ruch, sprawdza warunek ruchu na ukos lewy
bool czy_bierka_na_ukos_prawy(char kolor, int wiersz, int kolumna, char** plansza);		//Funkcja pomocnicza do funkcji czy_dozwolony_ruch, sprawdza warunek ruchu na ukos prawy
void polaczenie_bierek(int wiersz, int kolumna,char** plansza, char kolor);				//Funkcja która przejmuje bierki przeciwnika zgodnie z zasadmi gry
bool wygrana(char** plansza);															//Funkcja sprawdzaj¹ca warunek zwyciêstwa

class Gracz
{
protected:
	char kolor_twoich_bierek;
	static int nr_tury;
public:
	
	Gracz();											//konstruktor domyœlny ustala kolor dla gracza funkcj¹
	virtual void ruch(Plansza &p) = 0;					//Metoda virtualna która obs³uguje ruch gracza (cz³owieka lub komputera)
	void losowanie_koloru_bierek();						//Metoda która losuje kolor bierek dla gracza
	char getkolor() { return kolor_twoich_bierek; }
	void setkolor(char k) { kolor_twoich_bierek = k; }
	static int getnr_tury() { return nr_tury; }
	void setnr_tury(int a) { nr_tury = a; }
};

class Komputer:public Gracz
{
public:
	Komputer();											//konstruktor domyœlny ustala kolor dla gracza funkcj¹
	void ruch(Plansza &p);								//Metoda która obs³uguje ruch Komputera
	char getkolor() { return kolor_twoich_bierek; }
};

class Czlowiek:public Gracz
{
public:
	Czlowiek();											//konstruktor domyœlny ustala kolor dla gracza funkcj¹	
	void ruch(Plansza& p);								//Metoda która obs³uguje ruch Cz³owieka
	char getkolor() { return kolor_twoich_bierek; }
};

class Przebieg_gry
{
private:
	
public:
	void tura(Gracz& g1, Gracz& g2,Plansza &p);			//Metoda wykonuj¹ca jedn¹ turê w zale¿noœci od tego jaki jest nr tury wykonuje j¹ dla gracza 1 lub gracza 2
	void system_tur(Gracz& g1, Gracz& g2, Plansza& p);	//Metoda wywo³uj¹ca metodê "tura" dopóki nie zostanie spe³niony warunek zwyciêstwa (posiada równie¿ system wczytania gry)
	void kto_wygral(Gracz& g1, Gracz& g2, Plansza& p);	//Metoda sprawdzaj¹ca który gracz wygra³
	void zapis_gry(int nr,Plansza& p);					//Metoda która zapisuje (co turê) stan gry do pliku zapis.txt
	void wyczysc_zapis_gry();							//Metoda która czyœci zapis jeœli gra doprowadzona by³a do koñca poprawnie
	bool czy_plik_jest_pusty();							//Metoda pomocnicza sprawdzaj¹ca czy plik z zapisem posiada jakieœ dane
	void wczytaj_zapis_gry(Gracz& g1, Plansza& p);		//Metoda która pobiera zapis gry z pliku zapis.txt
};

#endif


