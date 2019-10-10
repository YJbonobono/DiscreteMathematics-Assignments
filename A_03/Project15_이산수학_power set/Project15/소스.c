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

void powerset(int n, int depth, char* argv[]) {

	if (n == depth) {//각 부분함수마다 한번만 실행되겠죵~!
		int cnt = -1;
		for (int j = 0; j < n; j++) {
			if (flag[j] == 1) {
				cnt = j;
			}
		}
		printf("[%.4d] ", number++);
		if (cnt == -1) {
			printf("%c", 155);
		}
		else {
			for (int i = 0; i < n; i++) {
				if (flag[i] == 1) {
					printf("%c", *argv[i + 1]);
					if (i != cnt) {
						printf(", ");
					}
				}
			}
		}		
		printf("\n");
		return;
	}
	flag[depth] = 0;
	powerset(n, depth + 1, argv);
	flag[depth] = 1;
	powerset(n, depth + 1, argv);
	
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

	system("chcp 437");
	if (argc == 1) {
		printf("ERROR_NO INPUT\n");
		exit(1);
	}


	powerset((argc - 1), 0, argv);

	signature();
	system("pause");

	return 0;

}
