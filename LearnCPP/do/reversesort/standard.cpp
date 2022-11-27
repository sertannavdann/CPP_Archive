#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> getVector()
{
    std::vector<int> v;
    std::cout << "Enter 5 integers: ";
    std::copy_n(std::istream_iterator<int>(std::cin), 5, std::back_inserter(v));
    return v;
}

int main()
{
    std::vector<int> v1 = getVector();

    std::sort(begin(v1), end(v1), [](int a, int b) { return b < a; });

    std::cout << std::endl;
}