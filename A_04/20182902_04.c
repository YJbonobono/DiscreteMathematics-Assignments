#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//[0001] 'symbol for the empty set'
//[0002] a
//[0003] b
//[0004] a, b
//*********************
//Byung-Woo Hong
//Student ID : 12345678
//*********************

int flag[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int number = 1;


void powerset(int n, int depth, char* argv[], FILE* fp) {
	//powerset함수 안에서 printf가 한번 발생할 때마다 넣은 값을 fputs로 넣어줍시당

	fp = fopen(argv[1], "wt");

	int c = 0;
	char c1[2], c3[2], c4[2], c5[2], c6[2], c7[2] = { 0,0 };
	char c2[5] = { 0,0,0,0,0 };

	if (n == depth) {//각 부분함수마다 한번만 실행되겠죵~!
		int cnt = -1;
		for (int j = 0; j < n; j++) {
			if (flag[j] == 1) {
				cnt = j;
			}
		}


		fprintf(fp, "[%.4d]", number);
		printf("[%.4d] ", number++);

		if (cnt == -1) {
			printf("%c", 155);
			*c4 = 155;
			fputs(c4, fp);
		}
		else {
			for (int i = 0; i < n; i++) {
				if (flag[i] == 1) {
					printf("%c", *argv[i + 2]);
					*c5 = *argv[i + 2];
					fputs(c5, fp);
					if (i != cnt) {
						printf(", ");
						*c6 = ', ';
						fputs(c6, fp);
					}
				}
			}
		}
		printf("\n");
		*c7 = '\n';
		fputs(c7, fp);
		return;
	}

	fclose(fp);


	flag[depth] = 0;
	powerset(n, depth + 1, argv, fp);
	flag[depth] = 1;
	powerset(n, depth + 1, argv, fp);

}
 
void signature() {
	printf("\n\n=====SIGNATURE=====\n");
	printf("LEE YUN JUNG\n");
	printf("STUDENT ID: 20182902\n");
	printf("*    *  ****\n");
	printf("*   **    *  \n");
	printf(" *** *    *\n");
	printf("     *    *\n");
	printf("   **   **  \n");
	printf("===================\n");
	return;
}

int main(int argc, char* argv[]) {

	FILE* fp1;

	system("chcp 437");
	if (argc == 1) {
		printf("ERROR_NO INPUT\n");
		exit(1);
	}

	if ((fp1 = fopen(argv[1], "wt")) == NULL) { //fail to open file for write
		printf("ERROR : fail to write file.");
		return 0;
	}

	powerset((argc - 2), 0, argv, fp1);


	signature();
	system("pause");

	return 0;

}
