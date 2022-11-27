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
        // std::binary_search
        bool result = 
            std::binary_search(ints, ints + size, k);
        return result;
    }
};