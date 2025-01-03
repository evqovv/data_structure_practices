#include "polynomial_merger.hpp"

int main() {
    ::evqovv::polynomial p1;
    p1.add({1, 2}); // x^2
    p1.add({2, 4}); // 2x^4

    ::evqovv::polynomial p2;
    p2.add({-2, 4}); // 2x^4
    p2.add({10, 2}); // 10x^2

    auto p3 = p1 + p2;

    int i{};
}