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

    size_t i = 0, j = 0, n = 0;

    while (i < mtn.size() && j < mtn[0].size()) {
        if (mtn[i][j] == '#')
            ++n;
        i += 1;
        j = (j + 3) % mtn[0].size();
    }

    /*
    for (size_t i = 0; i < mtn.size(); i++) {
        for (size_t j = 0; j < mtn[i].size(); j++) {
            std::cout << mtn[i][i];
        }
        std::cout << '\n';
    }
    */

    printf("Encountered %lu trees.\n", n);

    return 0;
}
