void insertionSort(unsigned long long int Array[], int Length, int low, int high) {
    int i;
    for (i = 1; i < Length; i++) {
        unsigned long long int key = Array[i];
        int j = i - 1;

        while (j >= 0 && Array[j] > key) {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = key;
    }
}
