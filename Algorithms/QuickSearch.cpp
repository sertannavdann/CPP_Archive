#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
inline int partition(int * arr, int start, int end)
{
  int pivot = arr[start];
  int count = 0;
  for(int a = start + 1; a <= end; a++) {
    if(arr[a] <= pivot) {
      count++;
    } 
    
}
  
  int pivotInd = start + count;
  std::swap(arr[pivotInd], arr[start]);
  int x = start;
  int y = end;
  while((x < pivotInd) && (y > pivotInd)) {
    while(arr[x] <= pivot) {
      x++;
    }
    
    while(arr[y] > pivot) {
      y--;
    }
    
    if((x < pivotInd) && (y > pivotInd)) {
      std::swap(arr[x++], arr[y--]);
    } 
    
  }
  return pivotInd;
}

inline void QuickSort(int * arr, int str, int end)
{
  if(str >= end) {
    return;
  } 

  int p = partition(arr, str, end);
  QuickSort(arr, str, p - 1);
  QuickSort(arr, p + 1, end);
}

int main() {
  int n;
  cin >> n;
  int * arr = new int[n];
  for(int a = 0; a < n; a++) {
    cin >> arr[a];
  } 

  QuickSort(arr, 0, n - 1);
  for(int a = 0; a < n; a++) {
    cout << arr[a] << " ";
  }
  delete[] arr;
  return 0;
}