#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

int main(int argc, char* argv[])
{
    std::string line;
    unsigned n = 0;
    unsigned invalid = 0;

    while (std::getline(std::cin, line)) {
        ++n;
        unsigned min, max;
        char key;
        char buff[8192];
        bool valid = true;
        std::map<char, unsigned> cmap;

        sscanf(line.c_str(), "%u-%u %c: %s", &min, &max, &key, buff);
        std::string pass(buff);

        for (unsigned i = 0; i < pass.length(); i++)
            ++cmap[pass[i]];

        if (cmap.find(key) == cmap.end() ||
            cmap[key] < min ||
            cmap[key] > max)
        {
            valid = false;
        }

        if (!valid)
            ++invalid;
        if (n < 10)
            printf("%2u-%2u %c: %20s %c\n", min, max, key, pass.c_str(), valid? ' ' : '*');
    }

    printf("Read %u passwords, of which %u were valid.\n", n, n - invalid);

    return 0;
}
