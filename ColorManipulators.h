#ifndef COLORMANIPULATORS_HPP
#define COLORMANIPULATORS_HPP

#include <iostream>
#include <windows.h>

enum Color {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    LBlue = 9,
    LGreen = 10,
    LCyan = 11,
    LRed = 12,
    LMagenta = 13,
    LYellow = 14,
    LWhite = 15
};

struct ColorManip {
    ColorManip(WORD attribute) : mAttribute(attribute) {}
    WORD mAttribute;
};

inline std::ostream& operator<<(std::ostream& os, const ColorManip& manip) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, manip.mAttribute);
    return os;
}

inline ColorManip setColor(Color textColor, Color bgColor) {
    return ColorManip((WORD)((bgColor << 4) | textColor));
}

inline ColorManip resetColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD attribute = csbi.wAttributes;
    return ColorManip(attribute);
}

#endif // COLORMANIPULATORS_HPP
