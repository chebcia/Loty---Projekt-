
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
@param korzen jeœli korzenia nie ma to drzewo jest puste i nie ma pasa¿era, tworzymy element lewy i prawy liœæ, nastêpny elementy ustawiamy na nullptr
@param przechowywatorkorzenia wskaŸnik do przechowywania korzenia
*/
Drzewo * dodawaniedodrzewa(Drzewo * korzen, Pasazer & ktos);
/** Funcja usuwaj¹ca drzewo
@param korzen korzeñ drzewa
*/
void usunDrzewo(Drzewo *& korzen);
/** Funcja wypisuj¹ca do pliku rekurencyjnie drzewa wartoœci
@param node  liœæ drzewa
@param lewylisc lewa strona drzewa
@param prawylisc prawa strona drzewa
*/
void inorder(Drzewo * node, std::ofstream & outfile);
#endif

