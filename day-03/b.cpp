#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    std::string line;
    std::vector<std::vector<char> > mtn;
    size_t dx[5] = {1, 3, 5, 7, 1};
    size_t dy[5] = {1, 1, 1, 1, 2};
    size_t n[5] = {0};

    while (std::getline(std::cin, line))
        if (line.size() > 1)
            mtn.push_back(std::vector<char>(line.begin(), line.end()));

    for (unsigned k = 0; k < 5; k++) {
        size_t i = 0, j = 0;
        while (i < mtn.size() && j < mtn[0].size()) {
            if (mtn[i][j] == '#')
                ++n[k];
            i += dy[k];
            j = (j + dx[k]) % mtn[0].size();
        }
    }

    size_t pro = 1;
    for (unsigned k = 0; k < 5; k++) {
        pro *= n[k];
        printf("%lu %lu: encountered %lu trees.\n", dx[k], dy[k], n[k]);
    }

    printf("Product of encountered trees is %lu.\n", pro);

    return 0;
}
