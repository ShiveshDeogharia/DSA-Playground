#pragma once
#include "interface.h"
#include <stack>
#include <iostream>
namespace dsa{
class StackDS : public IDataStructure {
    std::stack<int> st;
public:
    void menu() override;
};
}