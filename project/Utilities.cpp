#include <ctime>
#include <iostream>
#include <cstring>
#include <time.h>
class Utilities {
	
public:
	static bool isWordUpdated(string date) {

	

		
		time_t nowTimestamp =   std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		time_t storageTimestamp = static_cast<time_t>(std::stoll(date));
		struct tm* now = (struct tm*)malloc(sizeof(struct tm));
		struct tm* storage = (struct tm*)malloc(sizeof(struct tm));

		localtime_s(now,&nowTimestamp);
		localtime_s(storage, &storageTimestamp);

	
		//struct tm* storageTm = localtime(&storageTimestamp);
	
		
	
		
		
		cout << "NOW IS " << now->tm_mday << "." << now->tm_mon << "." << now-> tm_year << endl;
		cout << "STORAGE IS " << storage->tm_mday << "." << storage->tm_mon << "." << storage->tm_year << endl;

		/*return ( (nowTm -> tm_year == storageTm -> tm_year)
					&& 
						(nowTm -> tm_mon == storageTm -> tm_mon)
					&&
						(nowTm -> tm_mday == storageTm -> tm_mday)
			);*/
		return false;

	}
};