#include <ctime>
#include <iostream>
#include <cstring>
#include <time.h>
class Utilities {
	
public:
	static bool UpToDate(int date) {

	

		
		time_t nowTimestamp =   std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		time_t storageTimestamp = static_cast<time_t>(date);
		struct tm* now = (struct tm*)malloc(sizeof(struct tm));
		struct tm* storage = (struct tm*)malloc(sizeof(struct tm));

		localtime_s(now,&nowTimestamp);
		localtime_s(storage, &storageTimestamp);

	
		//struct tm* storageTm = localtime(&storageTimestamp);
	
		
	
		
		
		//cout << "NOW IS " << now->tm_mday << "." << now->tm_mon << "." << now-> tm_year << endl;
		//cout << "STORAGE IS " << storage->tm_mday << "." << storage->tm_mon << "." << storage->tm_year << endl;

		return ( (now -> tm_year == storage -> tm_year)
					&& 
						(now -> tm_mon == storage -> tm_mon)
					&&
						(now -> tm_mday == storage -> tm_mday)
			);
		return false;

	}
};