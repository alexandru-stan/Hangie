#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <string>
#include <ctime>
using namespace std;

class Challenge {
private:
    string word{ "" };
    int date{0};
    int health{ 0 };
    bool successful{ false };

public:
    Challenge(std::string wordp, int datep, int healthp, bool successfullp)
        : word(wordp), date(datep), health(healthp), successful(successfullp) {
    };

    Challenge() {};

    string getWord() { return word; }
    int getDate() { return date; }
    int getHealth() { return health; }
    bool getSuccessful() { return successful; }
    void setWord(string word) { this->word = word; }
    void setDate(int date) { this->date = date; }
    void setHealth(int health) { this->health = health; }
    void setSuccessful(bool successful) { this->successful = successful; }
};

#endif // CHALLENGE_H