#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    std::map<std::string, std::map<std::string, unsigned> > nest;
    std::map<std::string, int> connects;
    std::string line;
    size_t a, b;

    while (std::getline(std::cin, line)) {
        a = 0;
        b = line.find("bag", a);
        const std::string parent = line.substr(a, b - a - 1);
        if (line.find("no other") != std::string::npos) {
            connects[parent] = -1;
            b = a = std::string::npos;
        }
        while (a != std::string::npos && b != std::string::npos) {
            int count = 0;
            a = line.find_first_of("0123456789", a);
            if (a == std::string::npos) {
                continue;
            }
            count = std::atoi(&line[a]);
            b = line.find("bag", a);
            if (b == std::string::npos) {
                continue;
            }
            a = line.find_first_of(" ,.", a+1);
            if (a == std::string::npos) {
                continue;
            }
            std::string child = line.substr(a+1, b - a - 2);
            nest[parent][child] = count;
        }
    }


    std::map<std::string, std::map<std::string, unsigned> >::const_iterator it;
    std::map<std::string, unsigned>::const_iterator it2;
    for (it = nest.begin(); it != nest.end(); it++) {
        std:: cout << it->first << ": ";
        for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
            std::cout << it2->second << " " << it2->first << ". ";
        std::cout << '\n';
    }

    return 0;
}
