#ifndef URL_H
#define URL_H

#include <string>

class URL {
    std::string protocol;
    std::string domain;
    std::string path;
    std::string query;
public:
    URL(
        const std::string& prot, 
        const std::string& dom, 
        const std::string& pat, 
        const std::string& query
    );
    void print() const;
};

#endif //URL_H