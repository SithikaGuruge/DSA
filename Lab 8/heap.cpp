#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int largest = root;
   int left = 2*root +1;
   int right = 2*root +2;
   int temp;
   if(left<n && arr[left]> arr[largest]){
      largest = left;
   }
   if(right<n && arr[right]>arr[largest]){
      largest = right;
   }
   if(largest!=root){
      temp = arr[largest];
      arr[largest] = arr[root];
      arr[root] = temp;
      heapify(arr,n,largest);

   }
}
 
// implementing heap sort
void heapSort(int arr[], int n)
{  
   //build heap
   for(int i = (n-2)/2 ; i>=0;i--){
      heapify(arr,n,i);
   }
   
   // extracting elements from heap one by one
   for(int j = n-1;j>=0;j--)
   {
      int temp = arr[0];
      arr[0] = arr[j];
      arr[j] = temp;
      heapify(arr,j,0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   //int heap_arr[] = {4,17,3,12,9,6};
   //int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   
   vector<int> arr;
   string input;
    
    cout << "Enter elements separated by spaces: ";
    getline(cin, input);
    istringstream stringArr(input);
    int num, i = 0;
    while (stringArr >> num) {
        arr.push_back(num);
    }
    int heap_arr[arr.size()];
    for(int i=0;i<arr.size();i++){
      heap_arr[i] = arr[i];
    }
    int n = arr.size();
    


   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
