#include <string>
#include <iomanip>
#include <sstream>
#ifndef STRUCT_PASAZER
#define STRUCT_PASAZER
/**
@param nazwisko_pasazera nazwisko pasazera
@param nr_miejsca  numer miejsca, gdzie siedzi dany pasazer
*/
struct Pasazer
{
	std::string nazwisko_pasazera;
	int nr_miejsca;
	/** Funcja do wy�wietlania struktury pasa�er
@param os strumie�
@param p zmienna o strukturze Pasazer
@return os zwracamy strumie�
*/
	friend std::ostream & operator<<(std::ostream & os, const Pasazer & p);
	
};
/** Funcja konwertuj�ca ci�g znak�w na czas
@param str string wej�ciowy
@param ss strumie�, kt�ry dzielimy tak jak wska�emy w funkcji get_time
@return tm
*/
std::tm convertStringToTime(const std::string & str);
#endif