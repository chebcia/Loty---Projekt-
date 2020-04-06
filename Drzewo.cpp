#include "Drzewo.h"

void inorder(Drzewo *node, std::ofstream &outfile) {  
	if (!node) 
		return;
	inorder(node->lewylisc, outfile);         
	outfile << node->pasazerPrzechowywanyWDrzewie << std::endl; 
	inorder(node->prawylisc, outfile);        
}
void usunDrzewo(Drzewo *&korzen) {
	if (korzen)
	{
		usunDrzewo(korzen->lewylisc);
		usunDrzewo(korzen->prawylisc);
		delete korzen;
		korzen = nullptr;
	}
}

Drzewo * dodawaniedodrzewa(Drzewo * korzen, Pasazer &ktos)
{
	if (!korzen) 
	{
		korzen = new Drzewo;
		korzen->lewylisc = nullptr;
		korzen->prawylisc = nullptr;
		korzen->pasazerPrzechowywanyWDrzewie = ktos;
	}
	else {
		Drzewo *przechowywatorkorzenia = korzen;
		while (przechowywatorkorzenia) {
			if (ktos.nr_miejsca < przechowywatorkorzenia->pasazerPrzechowywanyWDrzewie.nr_miejsca) 
			{
				if (przechowywatorkorzenia->lewylisc) 
					przechowywatorkorzenia = przechowywatorkorzenia->lewylisc;
				else {
					przechowywatorkorzenia->lewylisc = new Drzewo{ ktos, nullptr, nullptr };
					przechowywatorkorzenia = nullptr;

				}
			}
			else 
			{
				if (przechowywatorkorzenia->prawylisc)
					przechowywatorkorzenia = przechowywatorkorzenia->prawylisc;
				else {
					przechowywatorkorzenia->prawylisc = new Drzewo{ ktos, nullptr, nullptr };
					przechowywatorkorzenia = nullptr;
				}
			}
		}
	}
	return korzen;
}




