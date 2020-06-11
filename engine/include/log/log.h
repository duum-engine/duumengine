#pragma once
#define LOG_LOG_H

enum level {
	INFO,
	WARN,
	ERROR,
	SEVERE
};

int logtofile(char* string, int type);
