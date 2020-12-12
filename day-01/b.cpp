#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<unsigned> v;
    std::vector<unsigned>::const_iterator it1, it2, it3, a, b, c;
    unsigned n;

    while (std::cin >> n)
        v.push_back(n);

    // std::sort(v.begin(), v.end());

    // std::cout << "Read " << v.size() << " entries." << std::endl;

    it3 = it2 = it1 = v.begin();
    c = b = a = v.end();
    n = 0;

    for (it1 = v.begin(); it1 != v.end(); it1++) {
        unsigned i = it1 - v.begin();
        if (*it1 >= 2020)
            continue;
        for (it2 = it1 + 1; it2 != v.end(); it2++) {
            unsigned j = it2 - v.begin();
            if (*it1 + *it2 >= 2020)
                continue;
            for (it3 = it2 + 1; it3 != v.end(); it3++) {
                ++n;
                unsigned k = it3 - v.begin();
                unsigned sum = *it1 + *it2 + *it3;
                unsigned pro = (*it1) * (*it2) * (*it3);
                if (v.size() < 10)
                    printf("[%2u,%2u,%2u]: %5u %5u %5u %5u %u\n",
                           i, j, k, *it1, *it2, *it3, sum, pro);
                if (*it1 + *it2 + *it3 == 2020) {
                    a = it1;
                    b = it2;
                    c = it3;
                    break;
                }
            }
        }
    }

    if (a != v.end() && b != v.end() && c != v.end()) {
        std::cout << "Found the trio in " << n << " steps." << std::endl;
        std::cout <<   "a = " << *a
                  << ", b = " << *b
                  << ", c = " << *c
                  << ", abc = "
                  << (*a) * (*b) * (*c)
                  << std::endl;
    } else {
        std::cout << "Failed to find the trio." << std::endl;
    }

    return 0;
}
