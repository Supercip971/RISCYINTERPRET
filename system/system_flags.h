#pragma once
#include <vector>


/// this is for later use when i will implement arguments
class system_flags
{
    std::vector<int> flags;
public:
    system_flags();

    static system_flags* the(); // YEAH I DO SINGLETON AND WHAT WILL YOU DO ? NOTHING !!!!
};

