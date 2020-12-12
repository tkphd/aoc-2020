#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<unsigned> v;
    std::vector<unsigned>::const_iterator it1, it2, a, b;
    unsigned n;

    while (std::cin >> n)
        v.push_back(n);

    std::sort(v.begin(), v.end());

    // std::cout << "Read " << v.size() << " entries." << std::endl;

    it2 = it1 = v.begin();
    b = a = v.end();
    n = 0;

    for (it1 = v.begin(); it1 != v.end(); it1++) {
        unsigned i = it1 - v.begin();
        for (it2 = it1 + 1; it2 != v.end(); it2++) {
            n++;
            unsigned j = it2 - v.begin();
            unsigned sum = *it1 + *it2;
            unsigned pro = (*it1) * (*it2);
            if (v.size() < 10)
                printf("[%2u,%2u]: %5u %5u %5u %u\n", i, j, *it1, *it2, sum, pro);
            if (*it1 + *it2 == 2020) {
                a = it1;
                b = it2;
                break;
            }
        }
    }

    if (a != v.end() && b != v.end()) {
        std::cout << "Found the pair in " << n << " steps." << std::endl;
        std::cout <<   "a = " << *a
                  << ", b = " << *b
                  << ", ab = "
                  << (*b) * (*b)
                  << std::endl;
    } else {
        std::cout << "Failed to find the pair." << std::endl;
    }

    return 0;
}
