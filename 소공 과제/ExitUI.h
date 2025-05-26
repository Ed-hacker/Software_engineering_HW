#pragma once
#include <iostream>

class ExitUI {
public:
    ExitUI() = default;
    void exitProgram(std::ostream& out);
};