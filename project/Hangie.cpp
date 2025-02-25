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
//using namespace nlohmann;
//using namespace std;

int main() {
	//json j_string(json::value_t::string);
	//string todaysWord = GetTodaysWord::return_word();
	//std::cout  << todaysWord << endl;
	//std::cout  << "Current Path: " << std::filesystem::current_path() << std::endl;
	//std::ifstream jsonFileStream("../../../hangie.json");
	//std::ofstream jsonOut("../../../try.json");
	//json j = json::parse(jsonFileStream);
	//jsonOut << std::setw(4) << j;
	//std::cout << std::setw(4) << j << endl;
	//std::cout << ((j["health"] != 0) ? " u alive" : "u dead ")
	//std::cout << j["word"].get<std::string>() << flush;




	std::ifstream jsonFileStream("../../../hangie.json");
	json j = json::parse(jsonFileStream);

	int health = j["health"].get<int>();
	bool successful = j["successful"].get<bool>();
	bool availability = StatusCheck::status_check(health, successful);
	time_t parsedDate = Utilities::parseDate(j["date"].get<string>());
	if (availability) {



		Challenge ch = Challenge(

			j["word"].get<string>(),
			j["date"].get<string>(),
			health,
			successful


		);

		
	

		//cout << dateJson << endl;

		//auto tm = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		//cout << std::chrono::system_clock::now() << endl;
		//cout << std::put_time(std::localtime(&tm), "%d.%m.%Y") << endl;
		////cout << ()  << endl;



	}
	else {
		cout << "You've already played today, please come back tomorrow" << endl;

	}



	return 0;
};