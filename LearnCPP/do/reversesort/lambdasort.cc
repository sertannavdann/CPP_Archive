#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int>& vec) {
	for (auto v : vec) {
		cout << v << ", ";
	}
	cout << endl;
}

int main() {
	vector<int> vec {3, 1, 4, 1, 5, 9, 13, 8};
	
	cout << "Before sorting: ";
	print(vec);
	
	// To sort in reverse order, we invert the < operator
	sort(begin(vec), end(vec),
		[](int a, int b) { return b < a; }
		);
		
	cout << "After sorting: ";
	print(vec);
}