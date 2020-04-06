#include "ParametryLotu.h"

bool operator==(const ParametryLotu &p1, const ParametryLotu &p2) { 
	return p1.lotnisko == p2.lotnisko && p1.symbolLotu == p2.symbolLotu; 

}
std::ostream & operator<<(std::ostream & os, const std::tm & t)
{
	os << t.tm_year << "-" << t.tm_mon << "-" << t.tm_mday;
	return os;
}
std::ostream &operator<<(std::ostream &os, const ParametryLotu &parametryLotu) {
	os << "Symbol lotu: " << parametryLotu.symbolLotu << std::endl;
	os << "lotnisko: " << parametryLotu.lotnisko << std::endl;
	os << "data lotu: " << parametryLotu.data_lotu << std::endl;
	
	return os;
}

	






