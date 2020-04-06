
#include <ctime>
#include<string>
#ifndef STRUCT_PARAMETRY_LOTU
#define STRUCT_PARAMETRY_LOTU 

/** 
@param symbolLotu symbol lotu
@param  lotnisko lotnisko
@param data_lotu data lotu
@param liczbaPasazerow liczba Pasazerow
*/

struct ParametryLotu {
	std::string symbolLotu;
	std::string lotnisko;
	struct std::tm data_lotu;
	int liczbaPasazerow;
	/** Funcja do wy�wietlania danych ze struktury tm - opisuj�cej dat�

/*
@param os os to jest strumie� ostreamowy
@param t zmienna czasu
@return os zwracamy strumie� os
*/

	friend std::ostream& operator<<(std::ostream & os, const std::tm & t);
	/** Funcja zwraca czy lotnisko i symbol lotu jest takie same
@param p1 parametry pierwszego lotu
@param p2 parametry drugiego lotu
*/
	friend bool operator==(const ParametryLotu &p1, const ParametryLotu &p2);
	/* Funckja nadpisuje operator <<
@param os os to jest strumie� ostreamowy
@param parametryLotu parametry lotu
@return os zwracamy strumie� os
*/
	friend std::ostream& operator<<(std::ostream &os, const ParametryLotu &parametryLotu);
};
#endif