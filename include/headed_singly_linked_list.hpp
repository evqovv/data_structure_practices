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

    headed_singly_linked_list(headed_singly_linked_list const &other) : head(new structure) {
        auto cur_node = other.head;
        for (; cur_node->next != nullptr; cur_node = cur_node->next) {
            insert_back(cur_node->data);
        }
        insert_back(cur_node->data);
    }

    headed_singly_linked_list(headed_singly_linked_list &&other) noexcept : head(other.head) {
        other.head = nullptr;
    }

    headed_singly_linked_list &operator=(headed_singly_linked_list const &other) {
        if (this != &other && !other.empty()) [[likely]] {
            auto cur_node = other.head;
            for (; cur_node->next != nullptr; cur_node = cur_node->next) {
                insert_back(cur_node->data);
            }
            insert_back(cur_node->data);
        }

        return *this;
    }

    headed_singly_linked_list &operator=(headed_singly_linked_list const &&other) noexcept {
        if (this != &other && !other.empty()) [[likely]] {
            head = ::std::exchange(other.head, nullptr);
        }

        return *this;
    }

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

    void insert_back(T const &value) {
        auto cur_node = head;
        for (; cur_node->next != nullptr; cur_node = cur_node->next) {}
        cur_node->next = new structure{ value };
    }

    void delete_at(size_type idx) {
        size_type i = 0;
        auto cur_node = head;
    }

    void display() const noexcept {
        auto cur_node = head->next;
        for (; cur_node->next != nullptr; cur_node = cur_node->next) {
            ::std::print("{} ", cur_node->data);
        }
        ::std::print("{}\n", cur_node->data);
    }

    bool empty() const noexcept {
        return head->next == nullptr;
    }

private:
    structure *head;
};
}