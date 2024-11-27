#include <iostream>
#include <cstdlib>
#include <chrono>

int partition(int array[], int low, int high)
{
    // Choosing the rightmost element as pivot
    int pivot = array[high];

    // 1st element
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        // If the current element is smaller than or equal to the pivot
        if (array[j] <= pivot)
        {
            i++;

            // Swap array[i] and array[j]
            std::swap(array[i], array[j]);
        }
    }

    // Swap array[i + 1] and array[high] (or pivot)
    std::swap(array[i + 1], array[high]);

    return i + 1;
}
void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        // Partition
        int part = partition(array, low, high);
        quicksort(array, low, part - 1);
        quicksort(array, part + 1, high);
    }
}

int main()
{
    int size = 1000;
    do
    {
        // Measure the execution time
        // clock_t startTime = clock();
        auto startTime = std::chrono::steady_clock::now();

        int *sample_array = new int[size];
        for (int i = 0; i < size; i++)
        {
            sample_array[i] = rand() % 1000;
        }

        quicksort(sample_array, 0, size - 1);

        // clock_t endTime = clock();
        auto endTime = std::chrono::steady_clock::now();

        auto duration = endTime - startTime;
        std::cout << "Time taken for size " << size << ": " << std::chrono::duration<double, std::milli>(duration).count() << " ms" << std::endl;

        size += 1000;
        delete[] sample_array;
    } while (size != 5000);

    return 0;
}
