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
    std::vector<unsigned>::const_iterator it3;
    unsigned n;

    while (input >> n)
        v.push_back(n);

    input.close();

    std::cout << "Read " << v.size() << " entries." << std::endl;

    it3 = it2 = it1 = v.begin();

    for (it1 = v.begin(); it1 != v.end(); it1++)
        for (it2 = it1; it2 != v.end(); it2++)
            for (it3 = it2; it3 != v.end(); it3++)
                if (*it1 + *it2 + *it3 == 2020) {
                    std::cout <<   "a = " << *it1
                              << ", b = " << *it2
                              << ", c = " << *it3
                              << ", abc = "
                              << (*it1) * (*it2) * (*it3)
                              << std::endl;
                    return EXIT_SUCCESS;
                }

    std::cout << "Failed to find the trio." << std::endl;

    return EXIT_SUCCESS;
}
