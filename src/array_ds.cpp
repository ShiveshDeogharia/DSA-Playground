#include "array_ds.h"
namespace dsa {

void ArrayDS::push_back(int val) {
    a.push_back(val);
}

void ArrayDS::insert_at(int idx, int val) {
    if (idx >= 0 && idx <= a.size()) a.insert(a.begin() + idx, val);
}

void ArrayDS::erase_at(int idx) {
    if (idx >= 0 && idx < a.size()) a.erase(a.begin() + idx);
}

int ArrayDS::get(int idx) const {
    return a[idx];
}

int ArrayDS::size() const {
    return static_cast<int>(a.size());
}

void ArrayDS::menu() {
    while (true) {
        std::cout << "\n— Array Operations —\n"
                     "1. Push Back\n2. Insert at Index\n3. Erase at Index\n4. Display\n0. Return\n> ";
        int c; std::cin >> c;
        if (c == 0) break;
        switch (c) {
            case 1: {
                int val; std::cout << "Value: "; std::cin >> val;
                push_back(val);
                break;
            }
            case 2: {
                int idx, val; std::cout << "Index Value: "; std::cin >> idx >> val;
                insert_at(idx, val);
                break;
            }
            case 3: {
                int idx; std::cout << "Index: "; std::cin >> idx;
                erase_at(idx);
                break;
            }
            case 4: {
                std::cout << "[ ";
                for (int x : a) std::cout << x << ' ';
                std::cout << "]\n";
                break;
            }
            default: std::cout << "Invalid option\n";
        }
    }
}

}
