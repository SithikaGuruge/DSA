#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return i+1;
}


void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}


int main() {
    int n = 20000;
    int arr[n];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);
    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
    
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = high_resolution_clock::now();
    
    
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "NumOfElements :" << n << endl;
    cout << "Execution time: " << duration.count() << " ns" << endl;
    
    return 0;
}
