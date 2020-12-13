#include <algorithm>
#include <cmath>
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
    std::string line;
    unsigned row,  col; // zero-indexed
    unsigned erow = 7, ecol = 3;
    // unsigned nrow = std::pow(2, erow);
    // unsigned ncol = std::pow(2, ecol);
    std::set<unsigned> filled_seats;

    while (std::getline(std::cin, line)) {
        erow = line.length() - ecol;
        row = col = 0;
        unsigned char crow = 0;
        unsigned char ccol = 0;

        std::string row_str = line.substr(0, erow);
        std::reverse(row_str.begin(), row_str.end());

        for (unsigned i = 0; i < row_str.length(); i++) {
            char c = row_str[i];
            if (c == 'B') {
                crow |= 1 << i;
            }
        }

        row = unsigned(crow);
        if (verbose)
            std::cout << row_str << " = " << row << '\n';

        std::string col_str = line.substr(erow, ecol);
        std::reverse(col_str.begin(), col_str.end());

        for (unsigned i = 0; i < col_str.length(); i++) {
            char c = col_str[i];
            if (c == 'R') {
                ccol |= 1 << i;
            }
        }

        col = unsigned(ccol);
        if (verbose)
            std::cout << col_str << " = " << col << '\n';

        const unsigned idx = row * std::pow(2, ecol) + col;
        if (verbose)
            std::cout << line << " (" << row << ',' << col << ") -> " << idx << std::endl;

        filled_seats.insert(idx);
    }

    std::set<unsigned>::const_reverse_iterator it = filled_seats.rbegin();
    std::cout << "The highest filled seat number was " << *it << '\n';

    return 0;
}
