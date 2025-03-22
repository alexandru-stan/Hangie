#include <iostream>
#include "headers/Challenge.hpp"
#include "headers/Duel.hpp"
#include <iomanip>
#include <limits>
#include "headers/Hangie.h"
using namespace std;


void Duel::duel(Challenge& s) {

	string word(s.getWord().size(), '?');
	string guess;


	while (s.getHealth() > 0 && !s.getSuccessful()) {
		system("cls");

		std::cout << "------ HANGIE " << Hangie_VERSION_MAJOR << "." << Hangie_VERSION_MINOR << " ------" << endl;
		std::cout << "TIENES " << s.getHealth() << " INTENTOS RESTANTES" << endl;
		std::cout << "LA PALABRA ES " << word << endl;
		std::cout << "ADIVINA:" << endl;
		std::cin >> guess;

		if (guess.size() > s.getWord().size() || guess.size() < s.getWord().size()) {

			system("cls");
			std::cout << "LA PALABRA INTRODUCIDA DEBE TENER 5 CARACTERES" << endl;
			system("pause");

			continue;
		}



		for (int i = 0; i < guess.size(); i++) {
			if (guess.at(i) == s.getWord().at(i)) word.at(i) = guess.at(i);
		}










		if (guess == s.getWord()) s.setSuccessful(true); else s.setHealth((s.getHealth() - 1));


	}

	system("cls");
	std::cout << (s.getSuccessful() ? "YOU WON," : "YOU LOST,") << " WORD IS " << s.getWord() << endl;
	system("pause");

}
