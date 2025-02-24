#include <iostream>
#include "GetTodaysWord.cpp"
#include "StatusCheck.cpp"
#include "Hangie.h"
#include "nlohmann/json.hpp"
#include "filesystem"

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


	bool is = StatusCheck::status_check();
	std::cout << (StatusCheck::status_check()) << flush;


	return 0;
}