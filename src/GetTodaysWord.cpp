#include <string>
#include <iostream>
#include <sstream>
//#include <cpr/cpr.h>
#include "headers/GetTodaysWord.hpp"
#include <algorithm>
//#include "../../data/sqlite/sqlite3.h";
//#include <sqlite3.h>
using namespace std;

    

     string GetTodaysWord::return_word() {
        return fetch_word();
    }

      
    
     string GetTodaysWord::fetch_word() {
   
      

         sqlite3* db;
        int db_connection_result = open_db_connection(&db);

        if (db_connection_result) {
            cout << "db connection has failed" << endl;
        }
        else {
            //cout << "db connection has succeeded" << endl;
            string word = fetch_db_word(&db);

            return word;
        }







       


    };


  
     int GetTodaysWord::open_db_connection(sqlite3 **db) {

         int connection_fail = sqlite3_open("data\\hangie.db", db);
         return connection_fail;
     }
     
     string GetTodaysWord::fetch_db_word(sqlite3** db) {

         const char* sql = "SELECT word FROM words WHERE used = false  ORDER BY random() LIMIT 1";
         sqlite3_stmt* stmt;
         int rc = sqlite3_prepare_v2(*db, sql, -1, &stmt, NULL);
         const unsigned char* text;
         if (rc != SQLITE_OK) {
             printf("error occurred: %s", sqlite3_errmsg(*db));
         }
         else {
             sqlite3_step(stmt);
             int NoOfCols = sqlite3_column_count(stmt);
             const  char* colName = sqlite3_column_name(stmt, 0);
              text = sqlite3_column_text(stmt, 0);
              //cout << text << endl;
              string res(text, text + 5);
              //cout << res << endl;
              sqlite3_finalize(stmt);
              return res;

         }

        
               

         

     }