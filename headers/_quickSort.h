void quickSort(unsigned long long int Array[], int Length, int low, int high) {
    if (low < high) {
        int pi = partition(Array, low, high);
        quickSort(Array, Length, low, pi - 1);
        quickSort(Array, Length, pi + 1, high);
    }
}

void swap(unsigned long long int* a, unsigned long long int* b) {
    unsigned long long int t = *a;
    *a = *b;
    *b = t;
}

int partition(unsigned long long int Array[], int low, int high) {
    unsigned long long int pivot = Array[high];
    int i = low;
    int j;

    for (j = low; j < high; j++) {
        if (Array[j] < pivot) {
            swap(&Array[i], &Array[j]);
            i++;
        }
    }
    swap(&Array[i], &Array[high]);
    return (i);
}
