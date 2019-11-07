#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;

//첫 텍스트파일을 읽어서 배열에 넣고
//배열 순서대로 더한 값을 두번째 배열에 넣고
//두번째 텍스트파일에 배열을 출력
void signature(FILE* fp);
void sumNumbers(int numText, char* str1, char* str2, FILE* fp2);

int main(int argc, char* argv[]) {
	// project18.exe a.txt b.txt
	//   argv[0]    argv[1] argv[2]

	char* name_1 = argv[1];	//텍파1 이름
	char* name_2 = argv[2];	//텍파2 이름

	char str1[100] = { 0, };	//첫 텍스트 파일을 읽어올 배열
	char str2[100] = { 0, };	//두번째 텍스트 파일에 넣기 전에 저장해둘 배열
	int size = sizeof(str1) / sizeof(str1[0]);	//size는 str1과 str2 배열의 크기

	FILE* fp1;
	FILE* fp2;

	fp1 = fopen(name_1, "r");	//읽기전용 fp1 열기
	while (fgets(str1, sizeof(str1), fp1)) {	//텍파fp1을 한 줄씩 읽어서 배열str1에다가 저장
		for (int i = 0; i < size; i++) {
			//str1[i] = fgets(str1, sizeof(str1), fp1);
			fscanf(fp1, "%s", &str1[i]);
		}
	}

	int numText = str1[0];	//str1의 0번째 항은 텍파fp1의 첫줄과 같음 => numText는 합할 숫자의 총 개수
	str2[0] = str1[numText];		//str2의 0번째 항은 텍파fp1에서 가장 마지막 줄의 숫자와 같다

	fp2 = fopen(name_2, "w");	//쓰기전용 텍스트 파일 생성 및 오픈
	fprintf(fp2, "[%03d] %c\n", numText, str2[0]);	//텍파fp2의 첫 줄에 str2의 0번째 항 출력
	sumNumbers(numText, str1, str2, fp2);	//덧셈연산 실시
	

	signature(fp1);	//사인 출력
	fclose(fp1);	//텍파 fp1 닫기
	fclose(fp2);	//텍파 fp1 닫기

	return 0;		//끗

}

void sumNumbers(int numText, char* str1, char* str2, FILE* fp2) {
		
	while (cnt < numText-1) {	//현재 cnt=0, numText=5,  cnt가 0,1,2,3일때 모두 순환		// str2[0] = str1[5]
		str2[cnt + 1] = (int)str2[cnt] + (int)str1[numText-1];									// str2[1] = str2[0] + str1[4]
																						// str2[2] = str2[1] + str1[3]
																						// str2[3] = str2[2] + str1[2]
																						// str2[4] = str2[3] + str1[1]

		fprintf(fp2, "[%03d] %c\n", --numText, str2[cnt+1]);							//텍파 fp2에 str2[1]부터 str[4]까지 출력
		cnt++;
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
