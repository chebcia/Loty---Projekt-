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
	/** Funcja do wyœwietlania struktury pasa¿er
@param os strumieñ
@param p zmienna o strukturze Pasazer
@return os zwracamy strumieñ
*/
	friend std::ostream & operator<<(std::ostream & os, const Pasazer & p);
	
};
/** Funcja konwertuj¹ca ci¹g znaków na czas
@param str string wejœciowy
@param ss strumieñ, który dzielimy tak jak wska¿emy w funkcji get_time
@return tm
*/
std::tm convertStringToTime(const std::string & str);
#endif