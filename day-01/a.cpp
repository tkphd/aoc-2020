#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<unsigned> entries;
    unsigned n;

    while (std::cin >> n)
        entries.push_back(n);

    std::set<unsigned> seen(entries.begin(), entries.end());

    n = 0;

    for (std::vector<unsigned>::const_iterator it = entries.begin(); it != entries.end(); it++) {
        n++;
        const unsigned &x = *it;
        if (*it >= 2020)
            continue;
        const unsigned y = 2020 - x;
        if (seen.find(y) != seen.end()) {
            std::cout << "Found the pair in " << n << " steps." << std::endl;
            std::cout <<   "a = " << x
                      << ", b = " << y
                      << ", ab = "
                      << x * y
                      << std::endl;
            return 0;
        }
    }

    return 0;
}
