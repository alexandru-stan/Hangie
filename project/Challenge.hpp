#include <string>

#include <ctime>
using namespace std;

class Challenge {
private:
	string word;
	time_t date;
	int health;
	bool successful;

public:
	Challenge(string word, time_t date, int health) {};
	string getWord() { return word; }
	time_t getDate() { return date };
	int getHealth() { return health };
	bool getSuccessful() { return successful };
	void setWord(string word) { this->word = word };
	void setDate(time_t date) {this->date = date };
	void setHealth(int health) { this->health = health };
	void setSuccessful(bool successful) { this->successful = successful };


};