#include <iostream>

void drawOneTick(int tickLength, int tickLabel = -1) {
    for (int i = 0; i < tickLength; i++) {
        std::cout << "-";
    }
    if (tickLabel >= 0)
        std::cout << " " << tickLabel;
    std::cout << std::endl;
}

void drawTicks(int tickLength) {
    if (tickLength > 0) {
        drawTicks(tickLength - 1);
        drawOneTick(tickLength);
        drawTicks(tickLength - 1);
    }
}

void drawRuler(int nInches, int majorLength) {
    drawOneTick(majorLength, 0);
    for (auto i = 1; i <= nInches; i++) {
        drawTicks(majorLength - 1);
        drawOneTick(majorLength, i);
    }
}

int main() {
    drawRuler(10, 3);
    return 0;
}
