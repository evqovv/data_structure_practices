#include "headed_singly_linked_list.hpp"

int main() {
    using namespace evqovv;
    headed_singly_linked_list<int> list;

    int arr[]{ 1 };
    for (auto &&ele : arr) {
        list.insert(0, ele);
    }
    list.display();
}