// feito por: maquinzz
#pragma once
#include <cstdint>
#include <string>
#include <vector>
namespace bytdiff {
struct Diff {
    std::uint64_t offset;
    std::uint8_t a;
    std::uint8_t b;
};
constexpr std::uint64_t kMaxFile = 512 * 1024 * 1024;
std::vector<Diff> compare(const std::string &a, const std::string &b, std::string &err);
}
