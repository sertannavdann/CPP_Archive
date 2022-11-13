#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int x[] = {15, 12, 8, 8, 7, 7, 7, 6, 5, 3};
    int y[] = {10, 25, 17, 11, 13, 17, 20, 13, 9, 15};

    int n = sizeof(x)/sizeof(x[0]);

    int sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;

    for(int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }

    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;

    double r = (n * sumXY - sumX * sumY) / sqrt((n * sumX2 - sumX * sumX) * (n * sumY2 - sumY * sumY));

    printf("%.3f", r);

   return 0;
}