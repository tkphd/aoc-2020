#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    std::string line;
    unsigned row,  col; // zero-indexed
    unsigned nrow = 0, ncol = 3;
    std::set<unsigned> filled_seats;

    while (std::getline(std::cin, line)) {
        nrow = line.length() - ncol;
        row = col = 0;

        unsigned seats = std::pow(2, nrow); // zero-indexed

        // std::cout << "There are " << seats << " rows.\n";

        for (unsigned i = 0; i < nrow; i++) {
            const char& key = line[i];
            std::cout << key << ' ';
            if (key == 'B') {
                // seat is toward the back
                row += seats / 2;
            }
            std::cout << row << '\n';
            seats /= 2;
        }

        seats = std::pow(2, ncol);
        // std::cout << "There are " << seats << " cols.\n";

        for (unsigned i = nrow; i < nrow + ncol; i++) {
            const char& key = line[i];
            std::cout << key << ' ';
            if (key == 'R') {
                // seat is toward the back
                col += seats / 2;
            }
            std::cout << col << '\n';
            seats /= 2;
        }

        const unsigned idx = row * std::pow(2, ncol) + col;
        std::cout << line << " (" << row << ',' << col << ") -> " << idx << std::endl;

        filled_seats.insert(idx);
    }

    std::set<unsigned>::const_reverse_iterator it = filled_seats.rbegin();
    std::cout << "The highest filled seat number was " << *it << '\n';

    return 0;
}
