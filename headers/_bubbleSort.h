void bubbleSort(unsigned long long int Array[], int Length, int low, int high) {
    unsigned long long int temp;
    int i, j;
    for (i = 0; i < Length - 1; i++) {
        for (j = 0; j < Length - i - 1; j++) {
            if (Array[j] > Array[j + 1]) {
                temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
}
