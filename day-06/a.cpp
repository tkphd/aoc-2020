#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const bool verbose = true;

int main(int argc, char* argv[])
{
    std::map<char,int> yes;
    std::string line;
    unsigned count = 0;

    while (std::getline(std::cin, line)) {
        if (verbose)
            std::cout << line << '\n';
        if (line == std::string()) {
            count += yes.size();
            yes.clear();
        } else {
            for (unsigned i = 0; i < line.length(); i++)
                ++yes[line[i]];
        }
    }

    if (! yes.empty()) {
        count += yes.size();
        yes.clear();
    }

    std::cout << count << " categories were declared." << '\n';

    return 0;
}
