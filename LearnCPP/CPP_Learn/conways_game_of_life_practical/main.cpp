#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/

int main()
{
    // vector of mountains
    vector<int> mountains(8);
    // game loop
    while (1) {
        for (int i = 0; i < 8; i++) {
            int mountain_h; // represents the height of one mountain.
            // add mountain_h to the mountains
            cin >> mountain_h; cin.ignore();
            mountains[i] = mountain_h;
        }
        // find the highest mountain
        auto highest = max_element(mountains.begin(), mountains.end());
        // print the index of the highest mountain
        cout << distance(mountains.begin(), highest) << endl;
    }
}