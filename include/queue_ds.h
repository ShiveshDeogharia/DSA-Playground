#pragma once
#include "interface.h"
#include <queue>
#include <iostream>
namespace dsa{
class QueueDS : public IDataStructure {
    std::queue<int> q;
public:
    void menu() override;
};
}