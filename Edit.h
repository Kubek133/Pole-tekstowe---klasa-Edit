#ifndef EDIT_HPP
#define EDIT_HPP

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

class Edit {
public:
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

    Edit();
    Edit(const Edit& other);
    ~Edit();

    void setPosition(int x, int y);
    void setLength(int length);
    void setText(const std::string& text);
    std::string getText() const;
    void setTextColor(Color color);
    void setBackgroundColor(Color color);
    void userText();

private:
    int posX, posY;
    int length;
    std::string text;
    Color textColor;
    Color bgColor;

    void draw();
};

#endif // EDIT_HPP
