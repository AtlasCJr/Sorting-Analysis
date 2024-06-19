/*
    Sorting Algorithms Expertiment
    Algoritma dan Pemrograman 01
    Proyek Akhir

    Anggota Kelompok:
        1. Jonathan Edward Charles De Fretes
        2. Ilham Ramadhan
        3. Muhammad Farrell Desnanda
        4. Fadhli Ammar Taqiyuddin Hakim

    Algorithms:
        1. Bubble Sort
        2. Selection Sort
        3. Heap Sort
        4. Insertion Sort
        5. Quick Sort

    Features:
        1. Better visualization
        2. Multiple runs for more accurate data
        3. Five algorithms comparison
        4. User chosen parameters
        5. Better time display; up to microseconds 
*/

// C Library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

// Sorting Header
#include "headers/_selectionSort.h"
#include "headers/_bubbleSort.h"
#include "headers/_heapSort.h"
#include "headers/_quickSort.h"
#include "headers/_insertionSort.h"

// Additional Header
#include "headers/Table.h"
#include "headers/initArray.h"
#include "headers/Intro.h"


typedef void (*sortingAlgorithms) (unsigned long long int[], int, int, int);

int main() {
    showIntro();
    if(showTitle() == 0) return -1;



    srand(time(NULL));
    LARGE_INTEGER start, stop, frequency;
    unsigned long long int* myArray;
    unsigned long long int* myArray_COPY;
    int i, j, k, l; 
    int unitType;
    double duration, displayedTime, totalTime = 0;
    int startingLength;
    double lengthRatio;
    int Epochs;
    int* tableData = requestParameter(&startingLength, &lengthRatio, &Epochs);
    int Length = startingLength;
    sortingAlgorithms Algorithms[5] = {bubbleSort, selectionSort, heapSort, insertionSort, quickSort};
    
    

    QueryPerformanceFrequency(&frequency);
    for (i = 0; i < Epochs; i++) {

        double curEpoch[5] = {0};
        for (j = 1; j <= 5; j++) {

            createArray(&myArray, Length);
            for (k = 0; k < 5; k++) {

                myArray_COPY = (unsigned long long int*) malloc(sizeof(unsigned long long int) * Length);
                for (l = 0; l < Length; l++) {
                    myArray_COPY[l] = myArray[l];
                }

                QueryPerformanceCounter(&start);
                Algorithms[k](myArray_COPY, Length, 0, Length-1);
                QueryPerformanceCounter(&stop);

                duration = (double) (stop.QuadPart - start.QuadPart) * 1e6 / frequency.QuadPart;
                totalTime += duration;

                curEpoch[k] += duration; 

                if (curEpoch[k] / j > 1e6) {
                    displayedTime = curEpoch[k] / j / 1e6;
                    unitType = 3;
                } else if (curEpoch[k] / j > 1e3) { 
                    displayedTime = curEpoch[k] / j / 1e3;
                    unitType = 2;
                } else {
                    displayedTime = curEpoch[k] / j / 1e0;
                    unitType = 1;
                }

                updateTable(tableData, k, i, displayedTime, unitType);

                moveTo(3, getConsoleHeight() - 4);
                printf("Time Elapsed: %.6f s", totalTime / 1e6);

                free(myArray_COPY);
            }
        }
        Length *= lengthRatio;
    }


    moveTo(3, getConsoleHeight() - 3);
    printf("Press anything to exit the program...");
    getch();
    cls();
    
    return 0;
}
