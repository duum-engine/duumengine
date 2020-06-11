#include "../../include/engine.h"

FILE *logptr;

int initLog() {
	logptr = fopen("log/log.log", "w+");
	fclose(logptr);
	

	time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );


	char time[30];
	sprintf(time, "Current day is: %d/%d/%d", timeinfo->tm_mday, timeinfo->tm_mon, (timeinfo->tm_year + 1900));
	logtofile(time, INFO);
}