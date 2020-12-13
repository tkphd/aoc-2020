#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const bool verbose = false;

bool check_pass(const std::set<std::string>& keys,
                const std::map<std::string, std::string>& passport)
{
    if (passport.empty())
        return true;

    for (std::set<std::string>::const_iterator it = keys.begin(); it != keys.end(); it++) {
        if (passport.find(*it) == passport.end()) {
            if (verbose)
                std::cout << "missing " << *it << '\n';
            return false;
        }
    }

    for (std::map<std::string, std::string>::const_iterator it = passport.begin(); it != passport.end(); it++) {
        if (keys.find(it->first) == keys.end()) {
            if (verbose)
                std::cout << "extra " << it->first << '\n';
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[])
{
    std::set<std::string> keys;
    keys.insert(std::string("byr"));
    keys.insert(std::string("iyr"));
    keys.insert(std::string("eyr"));
    keys.insert(std::string("hgt"));
    keys.insert(std::string("hcl"));
    keys.insert(std::string("ecl"));
    keys.insert(std::string("pid"));
    // keys.insert(std::string("cid"));

    std::string line, pair;
    std::map<std::string, std::string> passport;
    size_t n = 1, l = 1;
    size_t err = 0;
    char key[8192];
    char val[8192];

    while(std::getline(std::cin, line, ' ')) {
        std::stringstream ss(line);
        while(std::getline(ss, line)) {
            l++;
            if (line == std::string("")) {
                n++;
                if (!check_pass(keys, passport))
                    err++;
                passport.clear();
                l = 0;
                if (verbose && n < 5)
                    std::cout << '\n';
            } else {
                sscanf(line.c_str(), "%3s:%s", key, val);
                if (std::string(key) == std::string("cid"))
                    continue;
                passport[std::string(key)] = std::string(val);
                if (verbose && n < 5)
                    std::cout << n << ' ' << l << ' ' << key << ' ' << val << '\n';
            }
        }
    }
    if (!passport.empty() && !check_pass(keys, passport))
        err++;

    printf("\n%lu valid of %lu passports.\n", n - err, n);

    return 0;
}
