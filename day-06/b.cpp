#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const bool verbose = false;

int main(int argc, char* argv[])
{
    std::map<char,unsigned> yes;
    std::string line;
    unsigned count = 0;
    unsigned people = 0;

    while (std::getline(std::cin, line)) {
        if (line == std::string()) {
            for (std::map<char,unsigned>::const_iterator it = yes.begin(); it != yes.end(); it++) {
                if (verbose)
                    std::cout << it->first << ":" << it->second << " " << '\n';
                if (it->second == people)
                    ++count;
            }
            if (verbose)
                std::cout << '\n';
            yes.clear();
            people = 0;
        } else {
            ++people;
            for (unsigned i = 0; i < line.length(); i++)
                ++yes[line[i]];
        }
    }

    if (! yes.empty()) {
        for (std::map<char,unsigned>::const_iterator it = yes.begin(); it != yes.end(); it++)
            if (it->second == people)
                ++count;
        yes.clear();
    }

    std::cout << count << " categories were declared." << '\n';

    return 0;
}
