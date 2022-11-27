#include <thread>
#include <iostream>
#include <vector>


// multi thread
void main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back([]() {
            std::cout << "Hello from thread " << std::this_thread::get_id() << '\n';
        });
    }
    for (auto& thread : threads) {
        thread.join();
    }
    return 0;
}