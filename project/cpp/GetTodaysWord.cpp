#include <string>
#include <iostream>
#include <sstream>
#include <cpr/cpr.h>
#include "../headers/GetTodaysWord.hpp"
#include <algorithm>
#include "../../data/sqlite/sqlite3.h";
using namespace std;


     string GetTodaysWord::return_word() {
        return fetch_word();
    }

      
    
     string GetTodaysWord::fetch_word() {
    
         cout << "hello world" << endl;


         //if (connection_fail) {
             //cerr << "DB CONNECTION ERROR" << endl;
         //}
         //else {
             //cout << "db connection success" << endl;
         //}*/



       
         return "pastel";


    };



