#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<syslog.h>

int main(int argc, char* argv[])
{
	openlog("writer", LOG_PID, LOG_USER);

	if (argc != 3) {
		syslog(LOG_ERR, "Need two arguments.");
		return 1;
	}

	FILE *f = fopen(argv[1], "wb");
	if (f == NULL) {
		syslog(LOG_ERR, "Cannot create file.");
		return 1;
	}

	fwrite(argv[2], 1, strlen(argv[2]), f);
	syslog(LOG_DEBUG, "Writing %s to %s", argv[1], argv[2]);
	
	fclose(f);
	closelog();

	return 0;
}

