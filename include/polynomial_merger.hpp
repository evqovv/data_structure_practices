#pragma once

#include <cstddef>
#include <utility>
#include <string>
#include <string_view>
#include <stdexcept>

namespace evqovv {
struct monomial {
    int coefficient{};
    int exponent{};
};

class polynomial {
    friend polynomial operator+(polynomial const &lhs, polynomial const &rhs);

public:
    polynomial() : head(new linked_list) {}

    ~polynomial() noexcept {
        auto cur = head->next;

        while (cur != nullptr) {
            auto temp = cur;
            cur = cur->next;
            delete temp;
        }

        delete head;
    }

    polynomial(polynomial const &other) : head(new linked_list) {
        for (auto cur = other.head->next; cur != nullptr; cur = cur->next) {
            add(cur->data);
        }
    }

    polynomial(polynomial &&other) noexcept : head(other.head) {
        other.head = nullptr;
    }

    polynomial &operator=(polynomial const &other) {
        if (this != &other) [[likely]] {
            for (auto cur = other.head->next; cur != nullptr; cur = cur->next) {
                add(cur->data);
            }
        }

        return *this;
    }

    polynomial &operator=(polynomial &&other) {
        if (this != &other) [[likely]] {
            head = ::std::exchange(other.head, nullptr);
        }

        return *this;
    }

    polynomial &add(monomial const &value) {
        auto cur = head;

        while (cur->next != nullptr && value.exponent > cur->next->data.exponent) {
            cur = cur->next;
        }

        if (cur->next == nullptr) {
            cur->next = new linked_list{ value, nullptr };
        } else {
            if (value.exponent != cur->next->data.exponent) {
                auto temp = cur->next;
                cur->next = new linked_list{ value, temp };
            } else {
                cur->next->data.coefficient += value.coefficient;
                if (cur->next->data.coefficient == 0) {
                    auto temp = cur->next;
                    cur->next = temp->next;
                    delete temp;
                }
            }
        }

        return *this;
    }

    ::std::size_t size() const noexcept {
        ::std::size_t ret{};

        for (auto cur = head->next; cur != nullptr; cur = cur->next) {
            ++ret;
        }

        return ret;
    }

private:
    struct linked_list {
        monomial data;
        linked_list *next{};
    };

    linked_list *head{};
};

polynomial operator+(polynomial const &lhs, polynomial const &rhs) {
    polynomial ret;

    for (auto cur1 = lhs.head->next; cur1 != nullptr; cur1 = cur1->next) {
        ret.add(cur1->data);
    }

    for (auto cur2 = rhs.head->next; cur2 != nullptr; cur2 = cur2->next) {
        ret.add(cur2->data);
    }

    return ret;
}
}
