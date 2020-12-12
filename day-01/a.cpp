#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[])
{
    std::ifstream input("input1.txt");
    if (!input) {
        std::cerr << "Error: unable to open input file!" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::vector<unsigned> v;
    std::vector<unsigned>::const_iterator it1;
    std::vector<unsigned>::const_iterator it2;
    unsigned n;

    while (input >> n)
        v.push_back(n);

    input.close();

    std::cout << "Read " << v.size() << " entries." << std::endl;

    it1 = v.begin();
    it2 = it1++;

    for (it1 = v.begin(); it1 != v.end(); it1++)
        for (it2 = it1; it2 != v.end(); it2++)
            if (*it1 + *it2 == 2020) {
                std::cout <<   "a = " << *it1
                          << ", b = " << *it2
                          << ", ab = "
                          << (*it1) * (*it2)
                          << std::endl;
                return 0;
            }

    std::cout << "Failed to find the pair." << std::endl;

    return 0;
}
