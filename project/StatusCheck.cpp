#include "nlohmann/json.hpp"
#include "filesystem"
#include "iostream"
using namespace nlohmann;
using namespace std;
// statuscheck will return true only if health != 0 and successful is false, meaning user can play today.
class StatusCheck{

public:
	static bool status_check(int health, bool successful) {

		//cout << "ADDRESS OF HEALTH INSIDE IS " << &health << endl;

	return ((health >  0) && !successful);


}
};