#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    std::string line;
    unsigned n = 0;
    unsigned invalid = 0;

    while (std::getline(std::cin, line)) {
        ++n;
        unsigned min, max;
        char key;
        char pass[8192];
        bool valid = false;

        sscanf(line.c_str(), "%u-%u %c: %s", &min, &max, &key, pass);

        bool inFirst = (pass[min - 1] == key);
        bool inLast  = (pass[max - 1] == key);

        if ( (inFirst || inLast) &&
            !(inFirst && inLast))
        {
            valid = true;
        }

        if (!valid)
            ++invalid;
        if (n < 10)
            printf("%2u-%2u %c: %20s %c\n", min, max, key, pass, valid? ' ' : '*');
    }

    printf("Read %u passwords, of which %u were valid.\n", n, n - invalid);

    return 0;
}
