#include "../../include/engine.h"


//logtofile is a function that takes a string e.g "hello there" and a type of log, e.g INF or SVR
//an example usage would be logtofile("hello there", INF);


int logtofile(char* string, int type) {
	logptr = fopen("log/log.log", "a+");
	char* typeID;
	switch (type) {
		case INF:
			typeID = "INFO";
			break;

		case WRN:
			typeID = "WARN";
			break;
			
		case ERR:
			typeID = "ERROR";
			break;
			
		case SVR:
			typeID = "SEVERE";
			break;
	}

	time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );


	fprintf(logptr, "%d:%d:%d [%s] %s\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, typeID, string);
	fclose(logptr);
}
