#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int flag[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int number = 1;

void powerset(int n, int depth, char* arr, FILE* fp);
void signature(FILE* fp);

int main(int argc, char* argv[]) {

	system("chcp 437");

	int length = argc;
	char* name = argv[1];

	char str[100] = { 0, };

	FILE* fp1;

	fp1 = fopen(name, "w");
	for (int i = 2; i < length; i++)
	{
		str[i - 2] = *argv[i];
	}

	powerset(argc - 2, 0, str, fp1);


	signature(fp1);

	fclose(fp1);

	return 0;

}


void powerset(int n, int depth, char* arr, FILE* fp) {
	//powerset함수 안에서 printf가 한번 발생할 때마다 넣은 값을 fputs로 넣어줍시당


	if (n == depth) {//각 부분함수마다 한번만 실행

		int cnt = -1;

		for (int j = 0; j < n; j++) {
			if (flag[j] == 1) {
				cnt = j;
			}
		}

		fprintf(fp, "[%04d]", number++);
		if (cnt == -1) {
			fputs("¢", fp);
		}
		else {
			for (int i = 0; i < n; i++) {
				if (flag[i] == 1) {
					fprintf(fp, "%c", arr[i]);
					if (i != cnt) {
						fputs(", ", fp);
					}
				}
			}
		}

		fputs("\n", fp);
	}

	else {
		flag[depth] = 0;
		powerset(n, depth + 1, arr, fp);
		flag[depth] = 1;
		powerset(n, depth + 1, arr, fp);
	}


}

void signature(FILE* fp) {
	fputs("\n\n=====SIGNATURE=====\n", fp);
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
