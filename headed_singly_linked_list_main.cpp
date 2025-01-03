#include "headed_singly_linked_list.hpp"
#include <memory>
void func(evqovv::headed_singly_linked_list<int> l) {
    l.delete_at(1);
    l.delete_at(1);
    l.delete_element(5);
    l.display();
}

int main() {
    using namespace evqovv;
    headed_singly_linked_list<int> list;
    
    int arr[]{ 1,2,3,4,5 };
    for (auto &&ele : arr) {
        list.insert(0, ele);
    }
    list.insert_order(0);
    list.display();

    func(list);
}