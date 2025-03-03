#include <string>
#include <iostream>
#include <sstream>
#include <cpr/cpr.h>
#include "../headers/GetTodaysWord.hpp"
using namespace std;


     string GetTodaysWord::return_word() {
        return make_http_request();
    }


    
     string GetTodaysWord::make_http_request() {
    
        cpr::Response r = cpr::Get(cpr::Url{ "https://random-word-api.herokuapp.com/word?lang=es" });
        
        string response = r.text;
        response.erase(0,2);
        response.erase((response.length() - 2), 2);
        
        cout << response << endl;

        return response;


    };



