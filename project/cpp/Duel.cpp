#include <iostream>
#include "../headers/Challenge.hpp"
#include "../headers/Duel.hpp"
#include <iomanip>
#include <limits>
using namespace std;


void Duel::duel(Challenge& s) {

	string word(s.getWord().size(), '?');
	string guess;


	while (s.getHealth() > 0 && !s.getSuccessful()) {
		system("cls");
		std::cout << "YOU'VE GOT " << s.getHealth() << " HP LEFT" << endl;
		std::cout << "THE WORD IS " << word << endl;
		std::cout << "MAKE YOUR GUESS" << endl;
		std::cin >> guess;

		if (guess.size() > s.getWord().size() || guess.size() < s.getWord().size()) {

			system("cls");
			std::cout << "GUESS CANNOT BE LARGER OR SHORTER THAN WORD" << endl;
			system("pause");

			continue;
		}



		for (int i = 0; i < guess.size(); i++) {
			if (guess.at(i) == s.getWord().at(i)) word.at(i) = guess.at(i);
		}










		if (guess == s.getWord()) s.setSuccessful(true); else s.setHealth((s.getHealth() - 1));


	}

	system("cls");
	std::cout << (s.getSuccessful() ? " YOU WON," : " YOU LOST,") << " WORD IS " << s.getWord() << endl;
	system("pause");

}
