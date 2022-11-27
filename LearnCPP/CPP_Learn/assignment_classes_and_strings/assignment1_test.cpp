#include <iostream>
#include "assignment1.h"

int main() {
    URL url("http", "example.com", "index.html", "query");
    url.print();
}