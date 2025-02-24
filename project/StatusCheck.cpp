#include "nlohmann/json.hpp"
#include "filesystem"
#include "iostream"
using namespace nlohmann;
using namespace std;
// statuscheck will return true only if health != 0 and successful is false, meaning user can play today.
class StatusCheck{

public:
	static bool status_check() {

	std::ifstream jsonFileStream("../../../hangie.json");
	json j = json::parse(jsonFileStream);
	return ((j["health"] > 0) && !j["successful"]);


}
};