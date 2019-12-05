#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void signature(FILE* fp);

int main(int argc, char* argv[]) {

	char str[10] = { 0, };
	char final[100] = { 0, };
	char final_cnt[100] = { 0, };

	char* name1 = argv[1];
	char* name2 = argv[2];

	FILE* fp1;
	fp1 = fopen(name1, "r");
	fgets(str, sizeof(str), fp1);

	int toknum = 0;
	const char delimiters[] = ", !";
	char* token = strtok(str, delimiters);

	while (token != NULL) {
		for (int i = 0; i < sizeof(final); i++)
		{
			for (int j = 0; j < sizeof(final); j++) {
				if (final[i] == final[j]) {
					final_cnt[i]++;
				}
				else {
					final[i] = token;
					token = strtok(NULL, delimiters);
				}
			}
		}
	}


	FILE* fp2;
	fp2 = fopen(name2, "w");
	while (token != NULL)
	{
		fprintf(fp2, "[%.4d] %s (%d)\n", ++toknum, final, atoi(final_cnt));
	}

	fprintf(fp2, "[total] %.4d", sizeof(token));


	signature(fp2);

	fclose(fp1);
	fclose(fp2);
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
