#include <iostream>
#include "RightAngled.hpp"

using namespace std;

int main() {
    RightAngled rightangled1;
    Read(rightangled1);
    RightAngled rightangled2(rightangled1);
    Display(rightangled2);
    return 0;
}
