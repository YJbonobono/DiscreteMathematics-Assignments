#include <stdio.h>
#include <stdlib.h>

// Ctrl+~ 하면 cmd

int main(int argc, char* argv[]){
// + 2 + 3 - 1
// argv[1] = +, argv [2] = 2
// 467

    int result = 0;
    
    if (argc == 1 || argc > 201) {
        fputs("ERROR\n", stderr);
        goto A;
    }
    else {
        for (int i = 1; i < argc; i++){
            if((i%2) == 1){
                switch (*argv[i])
                {
                case '+':
                    result += atoi(argv[i+1]);
                    break;
                case '-':
                    result -= atoi(argv[i+1]);
                    break;
                default:
                    break;
                }
            }            
        }
    }

    printf("\nRESULT = %d\n", result);

    A:
    printf("\n=====SIGNATURE=====\n");
    printf("성명 : 이윤정\n");
    printf("학번 : 20182902\n");
    printf("*    *  ****\n");
    printf("*   **    *  \n");
    printf(" *** *    *\n");
    printf("     *    *\n");
    printf("   **   **  \n");
    printf("===================\n");

    system("pause");
    return 0;

}