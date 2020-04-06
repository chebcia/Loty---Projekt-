#include "Lista.h"

void stworzPlikiIZapisz(Lista *phead) {
	if (phead) {
		Lista *przechowywatorGlowy = phead;
		while (przechowywatorGlowy) {
			std::ofstream outfile(przechowywatorGlowy->parametryLotu.symbolLotu + ".txt", std::ofstream::out);
			outfile << przechowywatorGlowy->parametryLotu;
			outfile << "lista pasazerow:\n";
			inorder(przechowywatorGlowy->korzen, outfile);
			outfile << std::endl << "Liczba pasazerow w liscie: " << przechowywatorGlowy->parametryLotu.liczbaPasazerow << std::endl;
			przechowywatorGlowy = przechowywatorGlowy->nastepnyElement;
			outfile.close();
		}
	}
	else {
		std::cout << "Przekazano pusta liste\n";
	}
}
void usunListe(Lista *glowka) {
	Lista *nastepny;
	while (glowka != nullptr) {
		nastepny = glowka->nastepnyElement;
		usunDrzewo(glowka->korzen);
		delete glowka;
		glowka = nastepny;
	}
}
Lista * wczytajzpliku(const std::string &nazwaPliku) {
	std::fstream plik(nazwaPliku);

	if (plik.good()) {
		if (plik.peek() != std::ifstream::traits_type::eof()) {
			Lista *pHead = nullptr;
			ParametryLotu parametrylotu;
			std::string data;
			std::string nazwisko;
			int miejsce;
			while (plik >> parametrylotu.symbolLotu >> parametrylotu.lotnisko >> data >> nazwisko >> miejsce) {

				parametrylotu.data_lotu = convertStringToTime(data);
				Pasazer pasazer;
				pasazer.nazwisko_pasazera = nazwisko;
				pasazer.nr_miejsca = miejsce;
				pHead = dodawaniedolisty(pHead, parametrylotu, pasazer);

				std::cout << parametrylotu;
				std::cout << pasazer << std::endl;
			}
			plik.close();
			return pHead;
		}
		else
		{
			plik.close();
			std::cout << "Plik jest pusty" << std::endl;
			system("pause");
			exit(0);
		}
	}
	else std::cout << "plik nie istnieje" << std::endl;
}


Lista * dodawaniedolisty(Lista * pHead, ParametryLotu & parametryLotu, Pasazer & pasazer)
{
	if (!pHead)
	{
		auto *pNowy = new Lista{ nullptr, dodawaniedodrzewa(nullptr, pasazer),parametryLotu };
		pNowy->parametryLotu.liczbaPasazerow = 1;
		pHead = pNowy;
	}
	else
	{
		Lista *przechowywatorglowy = pHead;
		Lista* temp = przechowywatorglowy;
		while (temp->nastepnyElement != nullptr) {
			if (przechowywatorglowy->parametryLotu == parametryLotu) {
				przechowywatorglowy->korzen = dodawaniedodrzewa(przechowywatorglowy->korzen,
					pasazer);
				przechowywatorglowy->parametryLotu.liczbaPasazerow++;
				return pHead;
			}
			temp = przechowywatorglowy;
			if (!przechowywatorglowy->nastepnyElement) break;
			przechowywatorglowy = przechowywatorglowy->nastepnyElement;
		}
		Lista *nowyElement = new Lista{ nullptr, dodawaniedodrzewa(nullptr, pasazer),  parametryLotu };
		nowyElement->parametryLotu.liczbaPasazerow = 1;
		przechowywatorglowy->nastepnyElement = nowyElement;
	}
	return pHead;
}