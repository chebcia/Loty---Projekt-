
#include "Drzewo.h"
#include "ParametryLotu.h"

#ifndef STRUCT_LISTA
#define STRUCT_LISTA

/** 
@param nastepnyElement wskaznik do nastêpnego elementu
@param korzen korzen drzewa
@param parametryLotu parametryLotu
*/
struct Lista
{
    Lista* nastepnyElement;
    Drzewo* korzen;
    ParametryLotu parametryLotu;
	
/** Funcja do wyœwietlania danych ze struktury tm - opisuj¹cej datê

/*
@param os os to jest strumieñ ostreamowy
@param t zmienna czasu
@return os zwracamy strumieñ os
*/
friend std::ostream &operator<<(std::ostream &os, const std::tm &t); 
};


/** Funkcja tworzy pliki. Jako parametr przyjmuje g³owê listy. Sprawdzamy czy przekazana lista istnieje.
@param  pHead g³owa listy
@param  przechowywatorg³owy dajemy g³owê do przechowywatora, ¿eby nie niszczyæ listy i móc swobodnie j¹ iterowaæ
@param  outfile stworzono strumieñ outfile do wyœwietlania
*/
void stworzPlikiIZapisz(Lista * phead);

/** Funkcja usuwa listê.
@param  glowka g³owa listy
@param  *nastêpny wskaŸnik na nastêpny element
*/
void usunListe(Lista * glowka);

/** Funkcja wczytaj¹ca dane z pliku.
@param  pHead g³owa listy ustawiona na nullptr
@param  parametrylotu zmienna o strukturze parametry lotu
@param data data lotu
@param nazwisko nazwisko pasa¿era
@param miejsce miejsce pasa¿era
*/

Lista * wczytajzpliku(const std::string & nazwaPliku);
/** Funkcja dodaj¹ca do listy
@param  pNowy wskaŸnik na element, którego jeszcze nie by³o
@param  przechowywatorglowy przechowuje pHead
@param temp kopia przechowywatoraglowy po to, aby lista mog³a wejœæ do ostatniej iteracji
@param nowyElement jeœli nie ma symbolu lotu tworzymy nowe drzewo
@return pHead zwraca pHead
*/
Lista* dodawaniedolisty(Lista *pHead, ParametryLotu &parametryLotu, Pasazer &pasazer);


#endif