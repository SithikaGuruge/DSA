#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quickSort(int arr[], int n) {
    int low = 0, high = n-1;
    int pivotIndex;
    
    while (low < high) {
        pivotIndex = partition(arr, low, high);
        
        if (pivotIndex - low < high - pivotIndex) {
            quickSort(arr, pivotIndex - low);
            low = pivotIndex + 1;
        }
        else {
            quickSort(arr + pivotIndex + 1, high - pivotIndex);
            high = pivotIndex - 1;
        }
    }
}

int main() {
    int n = 15000;
    int arr[n];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);
    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
    
    auto start = high_resolution_clock::now();
    quickSort(arr, n);
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "NumOfElements :" << n << endl;
    cout << "Execution time: " << duration.count() << " ns" << endl;
    
    return 0;
}
