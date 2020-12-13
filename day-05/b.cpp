#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

const bool verbose = false;

int main(int argc, char* argv[])
{
    const unsigned erow = 7, ecol = 3;
    const unsigned nrow = std::pow(2, erow);
    const unsigned ncol = std::pow(2, ecol);

    std::string line;
    std::vector<unsigned> filled_idx(nrow * ncol, 0);

    while (std::getline(std::cin, line)) {
        unsigned row = 0, col = 0; // zero-indexed

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

        ++filled_idx[idx];
        if (filled_idx[idx] > 1)
            std::cout << "Oh, fun! Seat " << idx
                      << " has " << filled_idx[idx]
                      << " occupants." << std::endl;
    }

    unsigned seat;
    std::vector<unsigned> zero(1, 0);
    std::vector<unsigned> one(1, 1);

    std::vector<unsigned>::iterator it = filled_idx.begin() + ncol;
    std::vector<unsigned>::iterator sit(filled_idx.begin());
    it = std::find_first_of(it,
                            filled_idx.end() - ncol,
                            one.begin(), one.end());
    it = std::find_first_of(it,
                            filled_idx.end() - ncol,
                            zero.begin(), zero.end());

    while (   (it != filled_idx.end() - ncol)
           && (sit == filled_idx.begin()))
    {
        it = std::find_first_of(it, filled_idx.end() - ncol,
                                zero.begin(), zero.end());
        seat = unsigned(it - filled_idx.begin());
        if (verbose)
            std::cout << "Empty seat: " << seat << '\n';
        if (*(it - 1) && *(it + 1))
        {
            sit = it;
        }

        ++it;
    }

    seat = unsigned(sit - filled_idx.begin());
    std:: cout << "Your seat is " << seat << " of " << ncol * nrow << ".\n";

    return 0;
}
