#include <string.h>
#include <stdio.h>

#include "Table.h"


void showIntro() {
    int Height = getConsoleHeight();
    moveTo(0, Height/2 - 2);
    printf("\t>> Loading program...\n");
    printf("\t>> Please maximize the window\n");
    sleep(3);

    printf("\t>> Press anything to continue");
    getch();
    cls();
}

int showTitle() {
    int Height = getConsoleHeight();
    int Width = getConsoleWidth();

    char* Title[] = {
        "Sorting Algorithm Experiment"
        "",
        "",
        "Jonathan Edward Charles De Fretes........2206055750",
        "Ilham Ramadhan...........................2206811221",
        "Fadhli Ammar Taqiyuddin Hakim............2206817396",
        "Muhammad Farrell Desnanda................2206027261"
    };

    int i;
    int Length = sizeof(Title)/sizeof(Title[0]);
    for(i = 0; i < Length; i++) {
        char* curStr = Title[i];
        
        moveTo((Width - strlen(curStr))/2, (Height - Length)/2 + i);

        printf("%s\n", curStr);
    }

    moveTo(3, getConsoleHeight() - 4);
    printf("[ESCAPE] to leave the program");
    moveTo(3, getConsoleHeight() - 3);
    printf("Press anything else to continue the program");
    char userInput = getch();
    cls();

    if(userInput == 27) return 0;
    else return 1;
}

int* requestParameter(int* startingLength, double* lengthRatio, int* Epochs) {
    int* tableData;
    int i, Height, Width;
    while(1) {
        cls();

        moveTo(3, 2);
        printf("Parameters");
        
        moveTo(3, 3);
        printf("%-30s: ", "Initial Array Length");
        scanf("%d", startingLength);

        moveTo(3, 4);
        printf("%-30s: ", "Array Length Ratio");
        scanf("%lf", lengthRatio);
        
        moveTo(3, 5);
        printf("%-30s: ", "Epochs");
        scanf("%d", Epochs);

        Width = getConsoleWidth();
        Height = getConsoleHeight();

        if(*Epochs > Height - 3 - 3 - 9 - 9) {
            printf("\n\n>> Cannot contain that many epoch in one window.");
            printf("\n>> Please lower the Epoch or increase/maximize the window size.");
            printf("\n>> Current maximum Epochs: %d", Height - 3 - 3 - 9 - 9);
            getch();
            continue;
        }

        tableData = initiateTable(*Epochs, *startingLength, *lengthRatio);
        int** timeData = (int**) malloc(sizeof(int*) * 5);
        for (i = 0; i < 5; i++) timeData[i] = (int*) malloc(sizeof(int) * *Epochs);
        moveTo(3, getConsoleHeight() - 5); printf("Press [R] to change the parameters");
        moveTo(3, getConsoleHeight() - 4); printf("Press [ESCAPE] to close the program");
        moveTo(3, getConsoleHeight() - 3); printf("Press anything else to start the simulations");  
        
        char userInput = getch(); 
        if(userInput == 27) { exit(0); }
        else if(userInput == 114 || userInput == 122) continue;
        else {            
            moveTo(3, getConsoleHeight() - 5); printf("                                  ");
            moveTo(3, getConsoleHeight() - 4); printf("                                   ");
            moveTo(3, getConsoleHeight() - 3); printf("                                            ");
            break;
        }
    }

    return tableData;
}
