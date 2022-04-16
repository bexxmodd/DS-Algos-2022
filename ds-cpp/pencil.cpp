#include <iostream>
#include <vector>


class Pencil {
public:
    Pencil() {};

    bool write(std::string& paper, std::string& text) {
        if (length < text.size())
            return false;
        paper.append(text);
        return true;
    }

    bool sharpen() {
        return false;
    }

    bool erase(std::string& paper) {
        return false;
    }

private:
    size_t length = 10000;
    size_t eraser = 500;
};
