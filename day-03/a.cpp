#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    std::string line;
    std::vector<std::vector<char> > mtn;

    while (std::getline(std::cin, line))
        if (line.size() > 1)
            mtn.push_back(std::vector<char>(line.begin(), line.end()));

    size_t row = 0, col = 0, n = 0;

    while (row < mtn.size() && col < mtn[0].size()) {
        char& c = mtn[row][col];
        if (c == '#') {
            c = 'X';
            ++n;
        } else {
            c = 'O';
        }
        row += 1;
        col = (col + 3) % mtn[0].size();
    }

    for (size_t row = 0; row < 20; row++) {
        for (size_t col = 0; col < mtn[row].size(); col++) {
            std::cout << mtn[row][col];
        }
        std::cout << '\n';
    }

    printf("Encountered %lu trees.\n", n);

    return 0;
}
