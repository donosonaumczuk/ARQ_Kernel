#include <syscall.h>
#include <string.h>
#include <system.h>

void	getTimeString(unsigned char *time){
	int hour =	getTime(2);
	int min = 	getTime(1);
	int sec =	getTime(0);
	time[0] = (unsigned char)('0' + (int)hour/10);
	time[1] = (unsigned char)('0' + (int)hour%10);
	time[2] = ':';
	time[3] = (unsigned char)('0' + (int)min/10);
	time[4] = (unsigned char)('0' + (int)min%10);
	time[5]	= ':';
	time[6] = (unsigned char)('0' + (int)sec/10);
	time[7] = (unsigned char)('0' + (int)sec%10);
	time[TIME_FMT_LONG - 1] = (unsigned char)0;
	return;
}

void	getDateString(unsigned char *date){
	int day = getTime(3);
	int month = getTime(4);
	int year = getTime(5);
	date[0] = (char) '0' + day/10;
	date[1] = (char) '0' + day%10;
	date[2] = '/';
	date[3] = (char) '0' + month/10;
	date[4] = (char) '0' + month%10;
	date[5] = '/';
	date[6] = (char) '0' + year/10;
	date[7] = (char) '0' + year%10;
	date[DATE_FMT_LONG - 1] = 0; 
	return;
}

void	getTimeDateString(unsigned char* timeDate){
	getTimeString(timeDate);
	timeDate[TIME_FMT_LONG - 1] = ' ';
	getDateString(timeDate + TIME_FMT_LONG);
	return;
}