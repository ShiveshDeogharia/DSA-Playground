#pragma once
#include "interface.h"
#include <vector>
#include <iostream>

namespace dsa {

class ArrayDS : public IDataStructure {
    std::vector<int> a;
    void print() const;
public:
    void menu() override;
};

}
