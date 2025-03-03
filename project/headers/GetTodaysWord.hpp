#ifndef GET_TODAYS_WORD_HPP
#define GET_TODAYS_WORD_HPP
#include <string>

class GetTodaysWord {
public:
    static std::string return_word();

private:

    static std::string make_http_request();

};

#endif

