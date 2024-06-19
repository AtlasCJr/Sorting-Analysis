void heapify(unsigned long long int Array[], int Length, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < Length && Array[left] > Array[largest])
        largest = left;

    if (right < Length && Array[right] > Array[largest])
        largest = right;

    if (largest != i) {
        unsigned long long int temp = Array[i];
        Array[i] = Array[largest];
        Array[largest] = temp;

        heapify(Array, Length, largest);
    }
}

void heapSort(unsigned long long int Array[], int Length, int low, int high) {
    int i;    
    for (i = Length / 2 - 1; i >= 0; i--)
        heapify(Array, Length, i);

    for (i = Length - 1; i > 0; i--) {
        unsigned long long int temp = Array[0];
        Array[0] = Array[i];
        Array[i] = temp;

        heapify(Array, i, 0);
    }
}
