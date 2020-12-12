#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<unsigned> entries;
    std::vector<unsigned>::const_iterator it, a, b;
    unsigned n;

    while (std::cin >> n)
        entries.push_back(n);

    std::set<unsigned> seen(entries.begin(), entries.end());

    // std::sort(entries.begin(), entries.end());

    // std::cout << "Read " << entries.size() << " entries." << std::endl;

    it = entries.begin();
    b = a = entries.end();
    n = 0;

    for (it = entries.begin(); it != entries.end(); it++) {
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
            break;
        }
    }

    return 0;
}
