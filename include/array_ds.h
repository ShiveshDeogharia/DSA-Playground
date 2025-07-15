#pragma once
#include "interface.h"
#include <vector>
#include <iostream>

namespace dsa {

class ArrayDS : public IDataStructure {
    std::vector<int> a;

public:
    void push_back(int val);
    void insert_at(int idx, int val);
    void erase_at(int idx);
    int get(int idx) const;
    int size() const;

    void menu() override;
};

}
