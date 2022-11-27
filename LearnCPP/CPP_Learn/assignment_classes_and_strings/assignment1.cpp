#include <iostream>
#include "assignment1.h"

URL::URL(const std::string& prot, const std::string& dom, const std::string& pat, const std::string& query) {
    protocol = prot;
    domain = dom;
    path = pat;
    query = query;
}

void URL::print() const 
{
    std::cout << protocol << "://" << domain << "/" << path << "?" << query << "\n";
}