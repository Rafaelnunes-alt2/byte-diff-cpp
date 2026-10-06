// feito por: maquinzz
#include "diff.hpp"
#include <cstdio>
#include <iostream>
int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "usage: byte-diff <fileA> <fileB>\n";
        return 1;
    }
    std::string err;
    auto diffs = bytdiff::compare(argv[1], argv[2], err);
    if (!err.empty()) { std::cerr << "error: " << err << "\n"; return 2; }
    if (diffs.empty()) { std::cout << "identical\n"; return 0; }
    for (auto &d : diffs) {
        char buf[64] = {};
        std::snprintf(buf, sizeof(buf), "offset=%llu a=0x%02x b=0x%02x\n",
                      static_cast<unsigned long long>(d.offset), d.a, d.b);
        std::cout << buf;
    }
    return 0;
}
