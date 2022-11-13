#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    //3D tensor
    int ***arr = new int**[x];
    for (int i = 0; i < x; i++) {
        arr[i] = new int*[y];
        for (int j = 0; j < y; j++) {
            arr[i][j] = new int[z];
        }
    }
    // Fill 
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                arr[i][j][k] = i + j + k;
            }
        }
    }
    // Print
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    // Delete
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}