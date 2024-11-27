#include <iostream>
#include <cstdlib>
using namespace std;
void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);
void printArray(int array[], int size);
void binarySearch(int array[], int key, int low, int high);

int main() {
    int list[5000];
    int high = sizeof(list) / sizeof(list[0]) - 1;
    int low = 0;

    // Initialize random seed
    srand(time(0));

    // Fill the array with random numbers
    for (int i = 0; i < 5000; i++) {
        list[i] = rand() % 1000;
    }

    // Print the array before sorting (optional)
    cout << "Array before sorting:" << endl;
    printArray(list, 5000);

    // Sort the array using QuickSort
    quicksort(list, 0, high);

    // Print the array after sorting (optional)
    // std::cout << "\nArray after sorting:" << std::endl;
    // printArray(list, 5000);

    int key;
    cout << "Enter Key to Search: ";
    cin >> key;
    binarySearch(list, key, low, high);

    return 0;
}

void quicksort(int array[], int low, int high) {
    if (low < high) {
        // Partition
        int part = partition(array, low, high);
        quicksort(array, low, part - 1);
        quicksort(array, part + 1, high);
    }
}

int partition(int array[], int low, int high) {
    // Choosing the rightmost element as pivot
    int pivot = array[high];

    // Index of the smaller element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (array[j] <= pivot) {
            i++;

            // Swap array[i] and array[j]
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Swap array[i + 1] and array[high] (or pivot)
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void binarySearch(int array[], int key, int low, int high) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (array[mid] == key) {
            cout << "Element Found" << endl;
        } else if (array[mid] < key) {
            binarySearch(array, key, mid + 1, high);
        } else {
            binarySearch(array, key, low, mid - 1);
        }
    } else {
        cout << "Element Not Found" << endl;
    }
}
