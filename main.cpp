#include "vld.h"
#include "Pasazer.h"
#include "Drzewo.h"
#include "Lista.h"

/** Funcja odczytująca argumenty
@param ile ile jest parametrów funkcji
@param argumenty argumenty przekazywaną w linii komend
@param ETYKIETA_INPUT
@param arg przechowuje dany argument
*/

bool odczytaj_argumenty(int ile, char ** argumenty, std::string & inputFile )
{
	const std:: string ETYKIETA_INPUT ("-i");
	bool inOK = false;
	
	
	for (int i = 0; i < ile-1; i++)
	{
		std::string arg(argumenty[i]);
          if (arg == ETYKIETA_INPUT)
		{
			  inputFile = argumenty[i + 1];
			  inOK = true;
		}
	}
	return inOK;
}


int main(int ile, char** argumenty) {
	std::string inFile = "";
	if (odczytaj_argumenty(ile,argumenty,inFile))
	{
		Lista *pHead = wczytajzpliku(inFile);
		stworzPlikiIZapisz(pHead);
		usunListe(pHead);
		system("pause");
	}
	else
	{

		std::cout << "podaj dobre argumenty";
	}
	system("pause");
}