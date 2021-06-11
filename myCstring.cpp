#include "myCstring.h"


void myStrCpy(char text1[],size_t size ,const char text2[]) {
	int i = 0;
	for (; text2[i] != '\0' && i < size - 1; i++) {
		text1[i] = text2[i];
	}
		text1[i] = '\0'; // changed here
}

int myStrlen(const char arr[]) {
	int cnt = 0;
	while (arr[cnt] != '\0') {
		++cnt;
	}
	return cnt;
}

int myStrcmp(const char text1[],const char text2[]) {
	while (*text1 && *text2 && *text1 == *text2) {
		++text1;
		++text2;
	}
	return *text1 - *text2;
}