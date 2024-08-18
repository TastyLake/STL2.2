#include <iostream>
#include <set>
#include <vector>
#include <list>

template <typename T>
void print_container(const T& container) {

    if constexpr (std::is_same_v<T, std::set<typename T::value_type>>) {

        for (const auto& element : container) {
            std::cout << element << " ";
        }
    }
    else {

        for (const auto& element : container) {
            std::cout << element;

            if (&element != &container.back()) {
                std::cout << ", ";
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set); // four one three two

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list); // one, two, three, four

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector); // one, two, three, four

    return 0;
}