#include <syscall.h>

void write(char * string, uint64_t length, char color){
	return _int_80(WRITE,string,length,color);
}

void read(int in_id, char * buffer, int qty_to_read) {
	return _int_80(READ, in_id, buffer, qty_to_read);
}

void printPixel(uint32_t x, uint32_t y, char color){
	return _int_80(WRITE_PIXEL,x,y,color);
}

uint64_t getResolutionX(){
	return _int_80(GET_RESOLUTION_X,0,0,0);
}

uint64_t getResolutionY(){
	return _int_80(GET_RESOLUTION_Y,0,0,0);
}

uint64_t getTime(int time){
	return _int_80(TIME,time,0,0);
}

void cleanScreen(){
	return _int_80(CLEAR,0,0,0);
}
