#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    int** jagged = new int*[rows];

    // Taking input for each row size
    for (int i = 0; i < rows; i++) {
        int cols;
        cout << "Enter number of columns for row " << i << ": ";
        cin >> cols;

        jagged[i] = new int[cols];  // allocate different columns for each row

        cout << "Enter " << cols << " elements for row " << i << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> jagged[i][j];
        }
    }

    // Display jagged array
    cout << "\nJagged Array Output:\n";
    for (int i = 0; i < rows; i++) {
        int j = 0;
        while (true) {
            // Break when cin failed due to invalid access (since cols not stored)
            cout << jagged[i][j] << " ";
            j++;
          
        }
     
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] jagged[i];
    }
    delete[] jagged;

    return 0;
}
