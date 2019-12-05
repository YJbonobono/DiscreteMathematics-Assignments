#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int number = 1;
int cnt = 0;
void signature(FILE* fp);

void swap(char* str1, int a, int b) {
	int temp;
	if (a == b) return;
	temp = str1[a];
	str1[a] = str1[b];
	str1[b] = temp;
	return;
}

void scrabble(FILE* fp2, char* str1, int k, int length) {

	int i = 0;

	if (k == length) {
		fprintf(fp2, "[%03d] ", number++);
		for (int i = 0;  i < length; i++) {
			fprintf(fp2, "%c", str1[i]);
		}
		fputs("\n", fp2);
	}
	else {
		for (i = k; i < length; i++) {
			swap(str1, i, k);
			// i=0일 때 a=0, b=2 2와 1을 switch 
			// i=1일 때 a=1, b=2 2와 1을 switch 
			// i=2일 때 a=2, b=2 그냥 return 
			scrabble(fp2, str1, k + 1, length);
			swap(str1, i, k);
		}
	}

}

int main(int argc, char* argv[]) {

	char str[5] = { 0, }; //읽어오는 배열
	char str1[10] = { 0, }; //저장하는 배열 _6까지만 가능해야 함

	char* name1 = argv[1];
	char* name2 = argv[2];


	FILE* fp1;
	fp1 = fopen(name1, "r");

	fgets(str, sizeof(str), fp1);
	str1[cnt] = str[0];
	int length = atoi(str1);

	while (cnt < length) {
		fgets(str, sizeof(str), fp1);
		str1[cnt++] = str[0];
	}
	
	FILE* fp2;
	fp2 = fopen(name2, "w");
	if (length > 6) {
		fputs("ERROR : MAXIMUM NUMBER OF CHARACTERS IS 6", fp2);
		goto A;
	}

	//fprintf(fp2, "LENGTH = %d\n", length);

	//for (int j = 0; j <= length; j++) {
	//	fprintf(fp2, "str1[%d] = %c\n", j, str1[j]);
	//}

	scrabble(fp2, str1, 0, length);
	signature(fp2);

	fclose(fp1);
	fclose(fp2);

A:
	return 0;
}

void signature(FILE* fp) {
	fputs("\n=====SIGNATURE=====\n", fp);
	fputs("LEE YUN JUNG\n", fp);
	fputs("STUDENT ID: 20182902\n", fp);
	fputs("*    *  ****\n", fp);
	fputs("*   **    *  \n", fp);
	fputs(" *** *    *\n", fp);
	fputs("     *    *\n", fp);
	fputs("   **   **  \n", fp);
	fputs("===================\n", fp);
	return;
}
