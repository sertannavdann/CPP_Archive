// C++ implementation below
#include <iostream>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/types.h>
#include <algorithm>
#include <vector>

using namespace std;

class Answer
{
public:
    static bool exists(int ints[], int size, int k)
    {
        // binary search
        // sort the array
        sort(ints, ints + size);

        // search for k
        int low = 0;
        int high = size - 1;
        int mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (ints[mid] == k)
            {
                return true;
            }
            else if (ints[mid] < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;

    }
};