#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<unsigned> entries;
    std::vector<unsigned>::const_iterator it1, it2;
    unsigned n;

    while (std::cin >> n)
        entries.push_back(n);

    std::set<unsigned> seen(entries.begin(), entries.end());

    it2 = it1 = entries.begin();
    n = 0;

    for (it1 = entries.begin(); it1 != entries.end(); it1++) {
        const unsigned& x = *it1;
        if (x >= 2020)
            continue;
        for (it2 = it1 + 1; it2 != entries.end(); it2++) {
            const unsigned& y = *it2;
            if (x + y >= 2020)
                continue;
            ++n;
            const unsigned z = 2020 - x - y;
            if (seen.find(z) != seen.end()) {
                std::cout << "Found the trio in " << n << " steps." << std::endl;
                std::cout <<   "a = " << x
                          << ", b = " << y
                          << ", c = " << z
                          << ", abc = "
                          << x * y * z
                          << std::endl;
                break;
            }
        }
    }

    return 0;
}
