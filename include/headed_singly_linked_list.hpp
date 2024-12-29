#pragma once

#include <cstddef>
#include <print>

namespace evqovv {
template <typename T>
class headed_singly_linked_list {
private:
    struct structure {
        T data;
        structure *next{};
    };

public:
    using value_type = T;
    using size_type = ::std::size_t;

    headed_singly_linked_list() : head(new structure) {}

    ~headed_singly_linked_list() noexcept {
        auto cur_node = head;

        while (cur_node->next != nullptr) {
            auto temp = cur_node;
            cur_node = cur_node->next;
            delete temp;
        }

        delete cur_node;
    }

    void insert(size_type idx, T const &value) {
        size_type i = 0;
        auto cur_node = head;

        while (i < idx && cur_node->next != nullptr) {
            cur_node = cur_node->next;
            ++i;
        }

        if (cur_node) {
            auto new_node = new structure;
            new_node->data = value;
            new_node->next = cur_node->next;

            cur_node->next = new_node;
        } else {
            ::std::abort();
        }
    }

    void display() const noexcept {
        auto cur_node = head->next;
        for (; cur_node->next != nullptr; cur_node = cur_node->next) {
            ::std::print("{} ", cur_node->data);
        }
        ::std::print("{}\n", cur_node->data);
    }

private:
    structure *head;
};
}