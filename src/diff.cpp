// feito por: maquinzz
#include "diff.hpp"
#include <cstdio>
#include <fstream>
namespace bytdiff {
std::vector<Diff> compare(const std::string &a, const std::string &b, std::string &err) {
    std::ifstream fa(a, std::ios::binary | std::ios::ate);
    std::ifstream fb(b, std::ios::binary | std::ios::ate);
    if (!fa || !fb) { err = "open_failed"; return {}; }
    auto sa = fa.tellg(); auto sb = fb.tellg();
    if (sa < 0 || sb < 0) { err = "bad"; return {}; }
    if (sa > static_cast<std::streamoff>(kMaxFile) || sb > static_cast<std::streamoff>(kMaxFile)) { err = "too_big"; return {}; }
    std::size_t na = static_cast<std::size_t>(sa), nb = static_cast<std::size_t>(sb);
    fa.seekg(0, std::ios::beg); fb.seekg(0, std::ios::beg);
    std::vector<std::uint8_t> ba(na), bb(nb);
    if (na && !fa.read(reinterpret_cast<char*>(ba.data()), static_cast<std::streamsize>(na))) { err = "read_a"; return {}; }
    if (nb && !fb.read(reinterpret_cast<char*>(bb.data()), static_cast<std::streamsize>(nb))) { err = "read_b"; return {}; }
    std::size_t i = 0;
    for (; i < na && i < nb; ++i) {
        if (ba[i] != bb[i]) {
            Diff d; d.offset = i; d.a = ba[i]; d.b = bb[i];
            return { d };
        }
    }
    if (na != nb) {
        Diff d; d.offset = i; d.a = i < na ? ba[i] : 0; d.b = i < nb ? bb[i] : 0;
        return { d };
    }
    return {};
}
}
