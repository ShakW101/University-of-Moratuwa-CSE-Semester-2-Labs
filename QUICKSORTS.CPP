int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1; // Index for elements less than the pivot

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            // Swap arr[i] and arr[j]
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap pivot with the element at index (i + 1)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Return the index of the pivot after partitioning
    return i + 1;
}


void ITERATIVE_QUICK_SORT (vector<int> arr, int low, int high){

    // Initialize variables to simulate the call stack
    int stack[high - low + 1];
    int top = -1;

    // Push initial values of low and high onto the stack
    stack[++top] = low;
    stack[++top] = high;

    // Process intervals until the stack is empty
    while (top >= 0) {
        // Pop high and low from the stack
        high = stack[top--];
        low = stack[top--];

        // Partition the interval and get the index of the pivot
        int pivotIndex = partition(arr, low, high);

        // If there are elements to the left of the pivot, push the interval to the left onto the stack
        if (pivotIndex - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivotIndex - 1;
        }

        // If there are elements to the right of the pivot, push the interval to the right onto the stack
        if (pivotIndex + 1 < high) {
            stack[++top] = pivotIndex + 1;
            stack[++top] = high;
        }
    }

}

void RECURSIVE_QUICK_SORT(vector<int> arr, int low, int high){

    if(low < high){
        int pivotIndex = partition(arr, low, high);

        RECURSIVE_QUICK_SORT(arr, low, pivotIndex - 1);
        RECURSIVE_QUICK_SORT(arr, pivotIndex + 1, high);
    }

}
