#include <iostream>
#include "GetTodaysWord.cpp"
#include "StatusCheck.cpp"
#include "Hangie.h"
#include "nlohmann/json.hpp"
#include "filesystem"
#include "ctime"
#include "Challenge.hpp"
#include <typeinfo>
#include <time.h>
#include "Utilities.cpp"
#include "Duel.cpp"
#include <cstring>

using namespace nlohmann;
using namespace std;

int main() {

	std::ifstream jsonFileStream("../../../hangie.json");
	json j = json::parse(jsonFileStream);
	bool upToDate = Utilities::UpToDate(j["date"].get<int>());








	if (!upToDate) {
	

		cout << "YOU'RE NOT UP TO DATE , WILL REQUEST A NEW WORD" << endl;
		j["word"] = GetTodaysWord::return_word();
		j["date"] = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		j["health"] = 5;
		j["successful"] = false;

		ofstream out("../../../hangie.json");
		out << setw(2) << j << endl;

	}
	



	bool availability = StatusCheck::status_check((j["health"].get<int>()), (j["successful"].get<bool>()));




	if (availability) {



		Challenge ch = Challenge(

			j["word"].get<string>(),
			j["date"].get<int>(),
			j["health"].get<int>(),
			j["successful"].get<bool>()


		);

		
		
			Duel::duel(ch);
		
			std::ofstream out("../../../hangie.json");
			j["successful"] = ch.getSuccessful();
			j["health"] = ch.getHealth();
			
			out << setw(2) <<  j << std::endl;

	}
	else {
		cout << "You've already played today, please come back tomorrow" << endl;
		system("pause");

	}



	return 0;
};