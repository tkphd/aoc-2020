#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const bool verbose = false;

bool check_pass(const std::set<std::string>& keys,
                const std::set<std::string>& colors,
                const std::map<std::string, std::string>& passport)
{
    if (passport.empty())
        return true;

    std::set<std::string>::const_iterator st;
    std::map<std::string, std::string>::const_iterator it;

    for (st = keys.begin(); st != keys.end(); st++) {
        if (passport.find(*st) == passport.end()) {
            if (verbose)
                std::cout << "missing " << *st << '\n';
            return false;
        }
    }

    for (it = passport.begin(); it != passport.end(); it++) {
        if (keys.find(it->first) == keys.end()) {
            if (verbose)
                std::cout << "extra " << it->first << '\n';
            return false;
        }
    }

    // Check "byr" (Birth Year) - four digits; at least 1920 and at most 2002
    it = passport.find(std::string("byr"));
    if (it->second.length() != 4 ||
        std::atoi(it->second.c_str()) < 1920 ||
        std::atoi(it->second.c_str()) > 2002)
    {
        if (verbose)
            std::cout << "Bad byr" << '\n';
        return false;
    }

    // Check "iyr" (Issue Year) - four digits; at least 2010 and at most 2020
    it = passport.find(std::string("iyr"));
    if (it->second.length() != 4 ||
        std::atoi(it->second.c_str()) < 2010 ||
        std::atoi(it->second.c_str()) > 2020)
    {
        if (verbose)
            std::cout << "Bad iyr" << '\n';
        return false;
    }

    // Check "eyr" (Expiration Year) - four digits; at least 2020 and at most 2030
    it = passport.find(std::string("eyr"));
    if (it->second.length() != 4 ||
        std::atoi(it->second.c_str()) < 2020 ||
        std::atoi(it->second.c_str()) > 2030)
    {
        if (verbose)
            std::cout << "Bad eyr" << '\n';
        return false;
    }

    // Check "hgt" (Height) - a number followed by either cm or in
    it = passport.find(std::string("hgt"));
    if (it->second.find_first_of("cm") == std::string::npos &&
        it->second.find_first_of("in") == std::string::npos)
    {
        if (verbose)
            std::cout << "Bad hgt unit" << '\n';
        return false;
    }

    if (it->second.find_first_of("cm") != std::string::npos) {
        std::string hgt_cm(it->second);
        while (hgt_cm.find_first_of("cm") != std::string::npos)
            hgt_cm[hgt_cm.find_first_of("cm")] = '\0';
        int hgt = std::atoi(hgt_cm.c_str());
        if (hgt < 150 || hgt > 193)
        {
            if (verbose)
                std::cout << "Bad hgt " << hgt << " cm" << '\n';
            return false;
        }
    }
    if (it->second.find_first_of("in") != std::string::npos) {
        std::string hgt_in(it->second);
        while (hgt_in.find_first_of("in") != std::string::npos)
            hgt_in[hgt_in.find_first_of("in")] = '\0';
        int hgt = std::atoi(hgt_in.c_str());
        if (hgt < 59 || hgt > 76)
        {
            if (verbose)
                std::cout << "Bad hgt " << hgt << " in" << '\n';
            return false;
        }
    }

    // Check "hcl" (Hair Color) - a # followed by exactly six characters 0-9 or a-f
    it = passport.find(std::string("hcl"));
    if (it->second[0] != '#' ||
        it->second.find_first_not_of("#0123456789abcdef") != std::string::npos ||
        it->second.length() != 7)
    {
        if (verbose)
            std::cout << "Bad hcl" << '\n';
        return false;
    }

    // Check "ecl" (Eye Color) - exactly one of: amb blu brn gry grn hzl oth
    it = passport.find(std::string("ecl"));
    if (it->second.length() != 3 ||
        colors.find(it->second) == colors.end())
    {
        if (verbose)
            std::cout << "Bad ecl" << '\n';
        return false;
    }

    // Check "pid" (Passport ID) - a nine-digit number, including leading zeroes
    it = passport.find(std::string("pid"));
    if (it->second.length() != 9 ||
        it->second.find_first_not_of("0123456789") != std::string::npos)
    {
        if (verbose)
            std::cout << "Bad pid" << '\n';
        return false;
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

    std::set<std::string> colors;
    colors.insert(std::string("amb"));
    colors.insert(std::string("blu"));
    colors.insert(std::string("brn"));
    colors.insert(std::string("gry"));
    colors.insert(std::string("grn"));
    colors.insert(std::string("hzl"));
    colors.insert(std::string("oth"));

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
                if (!check_pass(keys, colors, passport))
                    err++;
                passport.clear();
                l = 0;
                if (verbose && n < 10)
                    std::cout << '\n';
            } else {
                sscanf(line.c_str(), "%3s:%s", key, val);
                if (std::string(key) == std::string("cid"))
                    continue;
                passport[std::string(key)] = std::string(val);
                std::map<std::string, std::string>::const_iterator it = passport.find(std::string(key));
                if (verbose && n < 10)
                    std::cout << n << ' ' << l << ' ' << it->first << ' ' << it->second << '\n';
            }
        }
    }
    if (!passport.empty() && !check_pass(keys, colors, passport))
        err++;

    printf("\n%lu valid of %lu passports.\n", n - err, n);

    return 0;
}
