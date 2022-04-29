#ifndef menu_h
#define menu_h

class Plansza
{
private:
	char** mapa;								//Wska�nik na tablic� dwu wymiarow�
public:
	
	Plansza();									//Konstruktor kt�ry tworzy map� metod� plansza_tworzenie
	void plansza_tworzenie();					//Metoda tworz�ca plansz�
	void plansza_wypisanie(char** plansza);		//Metoda wypisuj�ca plansz� na ekran
	char** get_plansza();
	void setplansza(int, int, char);
	~Plansza();									//Destruktor dealokuj�cy plansz� stworzon� dynamicznie
};

class Menu
{
protected:
	static int tryb_gry;
public:
	Menu(int tryb);								//Konstruktor przypisuj�cy warto�� do zmiennej tryb_gry
	void wypisanie_menu();						//Metoda wypisuj�ca menu na ekran
	void wybranie_trybu_gry();					//Metoda kt�ra pobiera od urzytkownika tryb gry w jakim chce zagra� (tryb_gry seter)
	static int gettryb();
	friend class Czlowiek;
	~Menu();									//Destruktor pusty
};
#endif


