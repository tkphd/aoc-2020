#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int contains_shiny_gold(std::map<std::string, int>& connects,
                        std::map<std::string, std::map<std::string, unsigned> >& nest,
                        std::string bag)
{
    // Note: if connects[bag] is 2, that means the bag has not yet been tested.
    printf("  Testing %12s (%i)\n", bag.c_str(), connects[bag]);

    // Already tested
    if (connects[bag] != 2)
        return connects[bag];

    // Base case
    if (nest[bag].find(std::string("shiny gold")) != nest[bag].end())
        return 1;

    int parent_connects = 0; // (false)
    for (std::map<std::string, unsigned>::const_iterator it = nest[bag].begin(); !parent_connects && it != nest[bag].end(); it++) {
        int& child_connects = connects[it->first];
        if (child_connects == 2) {
            // untested pathway
            child_connects = contains_shiny_gold(connects, nest, it->first);
        }

        if (child_connects == 1) {
            parent_connects = 1;
        }
    }

    return parent_connects;
}

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
        connects[parent] = 2;
        if (line.find("no other") != std::string::npos) {
            connects[parent] = 0;
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
            connects[child] = 2;
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
    std::cout << '\n';

    for (it = nest.begin(); it != nest.end(); it++) {
        connects[it->first] = contains_shiny_gold(connects, nest, it->first);
    }

    unsigned n = 0;
    for (std::map<std::string, int>::const_iterator it3 = connects.begin(); it3 != connects.end(); it3++) {
        printf("%12s (%i)\n", it3->first.c_str(), it3->second);
        if (it3->second == 1) {
            ++n;
        }
    }

    std::cout << "You have " << n << " bag options" << std::endl;

    return 0;
}
