#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    //Find the array located at index , which corresponds to . We must print the value at index  of this array which, as you can see, is .
    int i,j;
    cin>>i>>j;
    int *a[i];
    for(int k=0;k<i;k++)
    {
        int n;
        cin>>n;
        a[k]=new int[n];
        for(int l=0;l<n;l++)
        {
            cin>>a[k][l];
        }
    }

    for(int k=0;k<j;k++)
    {
        int x,y;
        cin>>x>>y;
        cout<<a[x][y]<<endl;
    }
    return 0;
}
