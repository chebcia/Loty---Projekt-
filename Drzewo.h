
#include <iostream>
#include <fstream>
#include "Pasazer.h"
#ifndef STRUCT_DRZEWO
#define STRUCT_DRZEWO 
/**
@param pasazerPrzechowywanyWDrzewie zmienna stuktury pasazer zawieraja informacje o pasazerze
@param  lewylisc wskaznik na lewa strone drzewa
@param prawylisc wskaznik na prawa strone drzewa
*/
struct Drzewo
{
	Pasazer pasazerPrzechowywanyWDrzewie;
	Drzewo *lewylisc;
	Drzewo *prawylisc;
};

/** Funcja dodaje elementy do drzewa
@param korzen je�li korzenia nie ma to drzewo jest puste i nie ma pasa�era, tworzymy element lewy i prawy li��, nast�pny elementy ustawiamy na nullptr
@param przechowywatorkorzenia wska�nik do przechowywania korzenia
*/
Drzewo * dodawaniedodrzewa(Drzewo * korzen, Pasazer & ktos);
/** Funcja usuwaj�ca drzewo
@param korzen korze� drzewa
*/
void usunDrzewo(Drzewo *& korzen);
/** Funcja wypisuj�ca do pliku rekurencyjnie drzewa warto�ci
@param node  li�� drzewa
@param lewylisc lewa strona drzewa
@param prawylisc prawa strona drzewa
*/
void inorder(Drzewo * node, std::ofstream & outfile);
#endif

