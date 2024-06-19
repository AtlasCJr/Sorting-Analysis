void selectionSort(unsigned long long int Array[], int Length, int low, int high) {
    int i, j, minIndex;
    unsigned long long int temp;

    for (i = 0; i < Length - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < Length; j++) {
            if (Array[j] < Array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = Array[i];
            Array[i] = Array[minIndex];
            Array[minIndex] = temp;
        }
    }
}
