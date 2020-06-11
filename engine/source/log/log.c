#include "../../include/engine.h"


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
