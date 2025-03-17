#ifndef GET_TODAYS_WORD_HPP
#define GET_TODAYS_WORD_HPP
#include <string>
#include <sqlite3.h>


class GetTodaysWord {
public:
    static std::string return_word();

private:

    static std::string fetch_word();
    static int open_db_connection(sqlite3** db);
    static std::string fetch_db_word(sqlite3** db);
};

#endif

