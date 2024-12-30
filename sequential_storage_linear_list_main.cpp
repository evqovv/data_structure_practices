#include "sequential_storage_linear_list.hpp"

int main() {
    using namespace evqovv;

    sequential_storage_linear_list l1{1,2,3,4,5};
    sequential_storage_linear_list l2{6,7,8,9,10,10,10,10,10,10};

    l1.combine_unique(l2);

    l1.display();

    l1.delete_at(2);

    l1.display();
}   