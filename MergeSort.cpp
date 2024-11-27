#include <iostream>
#include <cstdlib>
#include <ctime>

void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *leftArray = new int[n1];
    int *rightArray = new int[n2];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    // Merge the temporary arrays back into array[left..right]
    int i = 0;    // Initial index of the first subarray
    int j = 0;    // Initial index of the second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    // Clean up memory
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}

int main()
{
    int size = 1000;
    do
    {
        // Measure the execution time
        clock_t startTime = clock();
        std::cout << "Please Enter Number to Perform Merge Sort\n";

        int *sample_array = new int[size];
        for (int i = 0; i < size; i++)
        {
            sample_array[i] = rand() % 1000;
        }

        mergeSort(sample_array, 0, size - 1);

        clock_t endTime = clock();

        double duration = double(endTime - startTime) / CLOCKS_PER_SEC;
        std::cout << "For Array Size " << size << " - Total Program Execution Time: "
                  << duration << " seconds\n";

        size += 1000;
        delete[] sample_array;
    } while (size != 5000);

    return 0;
}
