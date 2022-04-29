#ifndef menu_h
#define menu_h

class Plansza
{
private:
	char** mapa;								//WskaŸnik na tablicê dwu wymiarow¹
public:
	
	Plansza();									//Konstruktor który tworzy mapê metod¹ plansza_tworzenie
	void plansza_tworzenie();					//Metoda tworz¹ca planszê
	void plansza_wypisanie(char** plansza);		//Metoda wypisuj¹ca planszê na ekran
	char** get_plansza();
	void setplansza(int, int, char);
	~Plansza();									//Destruktor dealokuj¹cy planszê stworzon¹ dynamicznie
};

class Menu
{
protected:
	static int tryb_gry;
public:
	Menu(int tryb);								//Konstruktor przypisuj¹cy wartoœæ do zmiennej tryb_gry
	void wypisanie_menu();						//Metoda wypisuj¹ca menu na ekran
	void wybranie_trybu_gry();					//Metoda która pobiera od urzytkownika tryb gry w jakim chce zagraæ (tryb_gry seter)
	static int gettryb();
	friend class Czlowiek;
	~Menu();									//Destruktor pusty
};
#endif


