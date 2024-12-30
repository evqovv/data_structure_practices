#pragma once

#include <cstddef>
#include <print>
#include <initializer_list>

namespace evqovv {
template <typename T, ::std::size_t list_max_size = 1024>
class sequential_storage_linear_list {
public:
    using value_type = T;
    using size_type = ::std::size_t;

    static constexpr size_type npos = -1;

    sequential_storage_linear_list(::std::initializer_list<T> l) {
        for (auto &&ele : l) {
            insert(cur_size, ele);
        }
    }

    void insert(size_type idx, T value) {
        if (cur_size == list_max_size) {
            ::std::abort();
        }

        if (idx >= list_max_size) {
            ::std::abort();
        }

        if (idx > cur_size) {
            ::std::abort();
        }

        for (auto i = cur_size; i != idx; --i) {
            elements[i] = elements[i - 1];
        }

        elements[idx] = value;

        ++cur_size;
    }

    void delete_at(size_type idx) {
        if (idx >= cur_size) {
            ::std::abort();
        }

        if (idx != cur_size - 1) {
            for (auto i = idx; i != cur_size - 1; ++i) {
                elements[i] = elements[i + 1];
            }
        }

        --cur_size;
    }

    void display() const {
        for (size_type i = 0; i != cur_size; ++i) {
            ::std::print("{} ", elements[i]);
        }

        ::std::print("\n");
    }

    bool empty() const noexcept {
        return cur_size != 0;
    }

    size_type size() const noexcept {
        return cur_size;
    }

    constexpr size_type max_size() const noexcept {
        return list_max_size;
    }

    bool clear() noexcept {
        cur_size = 0;
    }

    size_type find(T const &value) const {
        for (size_type i = 0; i != cur_size; ++i) {
            if (elements[i] == value) {
                return i;
            }
        }

        return npos;
    }

    T &operator[](size_type pos) {
        return elements[pos];
    }

    T const &operator[](size_type pos) const {
        return elements[pos];
    }

    void combine(sequential_storage_linear_list const &other) {
        for (size_type i = 0; i != other.size(); ++i) {
            insert(cur_size, other[i]);
        }
    }

    void combine_unique(sequential_storage_linear_list const &other) {
        for (size_type i = 0; i != other.size(); ++i) {
            if (find(other[i]) == npos) {
                insert(cur_size, other[i]);
            }
        }
    }

private:
    T elements[list_max_size];
    size_type cur_size = 0;
};
}