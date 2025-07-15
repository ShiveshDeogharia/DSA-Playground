#pragma once

namespace dsa {

class IDataStructure {
public:
    virtual void menu() = 0;
    virtual ~IDataStructure() = default;
};

} 
