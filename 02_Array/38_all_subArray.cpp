#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Loop to pick starting index
    for(int i = 0; i < n; i++) {
        // Loop to pick ending index
        for(int j = i; j < n; j++) {
            // Print elements from i to j
            for(int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
