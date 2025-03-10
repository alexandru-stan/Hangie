#ifndef GET_TODAYS_WORD_HPP
#define GET_TODAYS_WORD_HPP
#include <string>
#include "../../data/sqlite/sqlite3.h";

class GetTodaysWord {
public:
    static std::string return_word();

private:

    static std::string fetch_word();

};

#endif

