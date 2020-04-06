#include "Pasazer.h"

std::ostream &operator<<(std::ostream &os, const Pasazer &p) {
	os << p.nr_miejsca << " " << p.nazwisko_pasazera;
	return os;
}

struct std::tm convertStringToTime(const std::string &str) {
	std::tm tm;
	std::istringstream ss(str);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	tm.tm_year = tm.tm_year + 1900;
	tm.tm_mon = tm.tm_mon + 1;
	return tm;
}
