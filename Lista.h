
#include "Drzewo.h"
#include "ParametryLotu.h"

#ifndef STRUCT_LISTA
#define STRUCT_LISTA

/** 
@param nastepnyElement wskaznik do nast�pnego elementu
@param korzen korzen drzewa
@param parametryLotu parametryLotu
*/
struct Lista
{
    Lista* nastepnyElement;
    Drzewo* korzen;
    ParametryLotu parametryLotu;
	
/** Funcja do wy�wietlania danych ze struktury tm - opisuj�cej dat�

/*
@param os os to jest strumie� ostreamowy
@param t zmienna czasu
@return os zwracamy strumie� os
*/
friend std::ostream &operator<<(std::ostream &os, const std::tm &t); 
};


/** Funkcja tworzy pliki. Jako parametr przyjmuje g�ow� listy. Sprawdzamy czy przekazana lista istnieje.
@param  pHead g�owa listy
@param  przechowywatorg�owy dajemy g�ow� do przechowywatora, �eby nie niszczy� listy i m�c swobodnie j� iterowa�
@param  outfile stworzono strumie� outfile do wy�wietlania
*/
void stworzPlikiIZapisz(Lista * phead);

/** Funkcja usuwa list�.
@param  glowka g�owa listy
@param  *nast�pny wska�nik na nast�pny element
*/
void usunListe(Lista * glowka);

/** Funkcja wczytaj�ca dane z pliku.
@param  pHead g�owa listy ustawiona na nullptr
@param  parametrylotu zmienna o strukturze parametry lotu
@param data data lotu
@param nazwisko nazwisko pasa�era
@param miejsce miejsce pasa�era
*/

Lista * wczytajzpliku(const std::string & nazwaPliku);
/** Funkcja dodaj�ca do listy
@param  pNowy wska�nik na element, kt�rego jeszcze nie by�o
@param  przechowywatorglowy przechowuje pHead
@param temp kopia przechowywatoraglowy po to, aby lista mog�a wej�� do ostatniej iteracji
@param nowyElement je�li nie ma symbolu lotu tworzymy nowe drzewo
@return pHead zwraca pHead
*/
Lista* dodawaniedolisty(Lista *pHead, ParametryLotu &parametryLotu, Pasazer &pasazer);


#endif