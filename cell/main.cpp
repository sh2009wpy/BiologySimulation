#include <iostream>
#include "Cell.h"

int main() {
    std::cout << "Cell simulation started." << std::endl;
    Cell cell(1.0, 6.0, 0.0); // 初始糖1.0, 氧6.0, ATP 0.0
    for (int t =0; t < 3; ++t){
        std::cout << "time step " << t << std::endl;
        cell.metabolize();
    }
    return 0;
}