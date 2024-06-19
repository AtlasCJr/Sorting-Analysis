#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <math.h>

#ifndef TABLE_H
#define TABLE_H

void moveTo(int x, int y) {
	COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void cls() {
	system("cls");
    COORD cursorPosition;
    moveTo(0, 0);
}

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.X;
}

int getConsoleHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void formattedInt(char* str, int Number) {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "%d", Number);

    int len = strlen(buffer);
    int dotCount = (len - 1) / 3;
    int newLen = len + dotCount;
    
    str[newLen] = '\0';
    int i, j = newLen - 1;
    int count = 0;

    for (i = len - 1; i >= 0; i--) {
        str[j--] = buffer[i];
        if (++count == 3 && i > 0) {
            str[j--] = '.';
            count = 0;
        }
    }
}

int* initiateTable(int tableIndex, int indexStart, double indexRatio) {
    int Width = getConsoleWidth();
    int Height = getConsoleHeight();
    char formattedNum[50];
    int i, j;

    int widthPerColumn = (Width - 25) / 5;
    int lengthColumn = Width - 10 - widthPerColumn * 5;

    int startingHeight = (Height - 7 - tableIndex) / 2 + 1;

    for(i = 0; i < startingHeight; i++) printf("\n");

    cls();

    // ====================================================================================== //
    //                                          TOP                                           //
    // ====================================================================================== //
    moveTo(0, startingHeight);
    for(i = 0; i < Width - 5; i++) {
        if(i < 5) printf(" ");
        else if(i == 5) printf("%c", 201);
        else if(i == Width - 6) printf("%c", 187);
        else printf("%c", 205);
    }

    moveTo(5, startingHeight + 1);                                                  printf("%c", 186);
    moveTo((Width - strlen("Sorting Algorithm Experiment"))/2, startingHeight + 1); printf("%s", "Sorting Algorithm Experiment");
    moveTo(Width - 6, startingHeight + 1);                                          printf("%c\n", 186);

    for(i = 0; i < Width - 5; i++) {
        if(i < 5) printf(" ");
        else if(i == 5) printf("%c", 204);
        else if(i == Width - 6) printf("%c\n", 185);
        else if(i == 5 + lengthColumn) printf("%c", 203);
        else printf("%c", 205);
    }

    // ====================================================================================== //
    //                                       Header                                           //
    // ====================================================================================== //
    moveTo(5, startingHeight + 3);                                              printf("%c", 186);
    moveTo(Width - 6, startingHeight + 3);                                      printf("%c", 186);
    moveTo(5 + lengthColumn, startingHeight + 3);                               printf("%c", 186);
    moveTo(5 + (lengthColumn + 1 - strlen("Array(s)"))/2, startingHeight + 3);  printf("Array(s)");
    moveTo(5 + (Width - strlen("Sorting Time(s)"))/2, startingHeight + 3);      printf("Sorting Time");

    moveTo(5, startingHeight + 4);                                              printf("%c", 186);
    moveTo(Width - 6, startingHeight + 4);                                      printf("%c", 186);
    moveTo(5 + (lengthColumn + 1 - strlen("Length"))/2, startingHeight + 4);    printf("Length");
    moveTo(5 + lengthColumn, startingHeight + 4);                               printf("%c", 204);
    for(i = 5 + lengthColumn; i < Width - 7; i++)                               printf("%c", 205);
    printf("%c", 185);
    moveTo(5 + lengthColumn + widthPerColumn * 1, startingHeight + 4);          printf("%c", 203);
    moveTo(5 + lengthColumn + widthPerColumn * 2, startingHeight + 4);          printf("%c", 203);
    moveTo(5 + lengthColumn + widthPerColumn * 3, startingHeight + 4);          printf("%c", 203);
    moveTo(5 + lengthColumn + widthPerColumn * 4, startingHeight + 4);          printf("%c", 203);

    moveTo(5, startingHeight + 5);                                                                                  printf("%c", 186);
    moveTo(Width - 6, startingHeight + 5);                                                                          printf("%c", 186);
    moveTo(5 + lengthColumn, startingHeight + 5);                                                                   printf("%c", 186);                      
    moveTo(6 + lengthColumn + widthPerColumn * 0 + (widthPerColumn - strlen("Bubble"))/2, startingHeight + 5);      printf("Bubble");
    
    moveTo(5 + lengthColumn + widthPerColumn * 1, startingHeight + 5);                                              printf("%c", 186); 
    moveTo(6 + lengthColumn + widthPerColumn * 1 + (widthPerColumn - strlen("Selection"))/2, startingHeight + 5);   printf("Selection");
    
    moveTo(5 + lengthColumn + widthPerColumn * 2, startingHeight + 5);                                              printf("%c", 186); 
    moveTo(6 + lengthColumn + widthPerColumn * 2 + (widthPerColumn - strlen("Heap"))/2, startingHeight + 5);        printf("Heap");
    
    moveTo(5 + lengthColumn + widthPerColumn * 3, startingHeight + 5);                                              printf("%c", 186); 
    moveTo(5 + lengthColumn + widthPerColumn * 3 + (widthPerColumn - strlen("Insertion"))/2+1, startingHeight + 5); printf("Insertion");
    
    moveTo(5 + lengthColumn + widthPerColumn * 4, startingHeight + 5);                                              printf("%c", 186); 
    moveTo(5 + lengthColumn + widthPerColumn * 4 + (widthPerColumn - strlen("Quick"))/2+1, startingHeight + 5);     printf("Quick");
    
    printf("\n");
    for(i = 0; i < Width - 5; i++) {
        if(i < 5) printf(" ");
        else if(i == 5) printf("%c", 204);
        else if(i == Width - 6) printf("%c\n", 185);
        else if(
            i-5 == lengthColumn || i-5 == lengthColumn + widthPerColumn || i-5 == lengthColumn + widthPerColumn * 2 || 
            i-5 == lengthColumn + widthPerColumn * 3 || i-5 == lengthColumn + widthPerColumn * 3 || 
            i-5 == lengthColumn + widthPerColumn * 4) printf("%c", 206);
        else printf("%c", 205);
    }

    // ====================================================================================== //
    //                                      Content                                           //
    // ====================================================================================== //
    // moveTo(Width-1, startingHeight + 6);
    for(j = 0; j < tableIndex; j++) {
        for(i = 0; i < Width - 5; i++) {
            if(i < 5) printf(" ");
            else if(
                i-5 == 0 || i == Width - 6 || 
                i-5 == lengthColumn || i-5 == lengthColumn + widthPerColumn || i-5 == lengthColumn + widthPerColumn * 2 || 
                i-5 == lengthColumn + widthPerColumn * 3 || i-5 == lengthColumn + widthPerColumn * 3 || 
                i-5 == lengthColumn + widthPerColumn * 4) printf("%c", 186);
            else printf(" ");
        }

        formattedInt(formattedNum, (int) (indexStart * pow(indexRatio, j)));
        moveTo(7, startingHeight + 7 + j); printf("%-2d%*s", j+1, lengthColumn - 5, formattedNum);
        moveTo(Width-1, Width + 6 + j); printf("\n");
    }

    // ====================================================================================== //
    //                                        Bottom                                          //
    // ====================================================================================== //
    for(i = 0; i < Width - 5; i++) {
            if(i < 5) printf(" ");
            else if(i == 5) printf("%c", 200);
            else if(i == Width - 6) printf("%c", 188);
            else if(
                i-5 == lengthColumn || i-5 == lengthColumn + widthPerColumn || i-5 == lengthColumn + widthPerColumn * 2 || 
                i-5 == lengthColumn + widthPerColumn * 3 || i-5 == lengthColumn + widthPerColumn * 3 || 
                i-5 == lengthColumn + widthPerColumn * 4) printf("%c", 202);
        else printf("%c", 205);
    }


    // ====================================================================================== //
    //                                      Parameters                                        //
    // ====================================================================================== //
    moveTo(3, 2);
    printf("Parameters");
        
    moveTo(3, 3);
    printf("%-30s: %d", "Initial Array Length", indexStart);

    moveTo(3, 4);
    printf("%-30s: %.2f", "Array Length Ratio", indexRatio);
    
    moveTo(3, 5);
    printf("%-30s: %d", "Epochs", tableIndex);




    

    static int Data[3];
    Data[0] = widthPerColumn;
    Data[1] = startingHeight + 7;
    Data[2] = 5 + lengthColumn;
    return Data;
}

void updateTable(int* tableData, int x, int y, double Time, int unitType) {
    int widthPerColumn = tableData[0];
    int Height = tableData[1];
    int Width = tableData[2];

    const char* RED = "\033[1;31m";
    const char* GREEN = "\033[1;32m";
    const char* YELLOW = "\033[1;33m";
    const char* RESET = "\033[0m";
    const char* curColor = RESET;
    const char* Unit = "";

    switch(unitType) {
        case 1:
            Unit = "\xE6s"; // � Symbol
            curColor = GREEN;
            break;
        case 2:
            Unit = "ms";
            curColor = YELLOW;
            break;
        case 3:
            Unit = "s";
            curColor = RED;
            break;
        default:
            break;
    }

    moveTo(Width + x * widthPerColumn + widthPerColumn/2 - 5, Height + y);
    printf("%s%7.3f%s", curColor, Time, RESET);

    moveTo(Width + x * widthPerColumn + widthPerColumn/2 + 3, Height + y); 
    printf("%s%s%s", curColor, Unit, RESET);
}



#endif
