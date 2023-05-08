#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip> 

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sort(arr.begin(), arr.begin() + i + 1); 
        double median;
        if ((i+1) % 2 == 0) {
            median = (arr[i/2] + arr[(i/2)+1]) / 2.0; 
        } else {
            median = arr[i/2]; 
        }
        
        cout << fixed << setprecision(1) << median << endl; 
    }
    return 0;
}
