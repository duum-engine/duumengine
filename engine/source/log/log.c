#include "../../include/engine.h"


int logtofile(char* string, int type) {
	logptr = fopen("log/log.log", "a+");
	char* typeID;
	switch (type) {
		case INFO:
			typeID = "INFO";
			break;

		case WARN:
			typeID = "WARN";
			break;
			
		case ERROR:
			typeID = "ERROR";
			break;
			
		case SEVERE:
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