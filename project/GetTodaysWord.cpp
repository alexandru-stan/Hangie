#include <string>
#include <iostream>
#include <sstream>
#include <cpr/cpr.h>
using namespace std;

class GetTodaysWord {
public:
    static string return_word() {
        return make_http_request();
    }

private:
    
    static string make_http_request() {
    
        cpr::Response r = cpr::Get(cpr::Url{ "https://random-word-api.herokuapp.com/word" });
        
        string response = r.text;
        response.erase(0,2);
        response.erase((response.length() - 2), 2);
        return response;


    };

};


