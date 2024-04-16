#include "Edit.h"

Edit::Edit() : posX(0), posY(0), length(0), text(""), textColor(White), bgColor(Black) {}

Edit::Edit(const Edit& other) : posX(other.posX), posY(other.posY), length(other.length),
text(other.text), textColor(other.textColor), bgColor(other.bgColor) {}

Edit::~Edit() {}

void Edit::setPosition(int x, int y) {
    posX = x;
    posY = y;
}

void Edit::setLength(int len) {
    length = len;
}

void Edit::setText(const std::string& txt) {
    text = txt;
}

std::string Edit::getText() const {
    return text;
}

void Edit::setTextColor(Color color) {
    textColor = color;
}

void Edit::setBackgroundColor(Color color) {
    bgColor = color;
}

void Edit::userText() {
    char ch;
    while (true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == '\r')
                break;
            else if (ch == '\b') {
                if (!text.empty()) {
                    text.pop_back();
                    draw();
                }
            }
            else {
                text.push_back(ch);
                draw();
            }
        }
    }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
}

void Edit::draw() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)posX, (SHORT)posY };
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, (WORD)((bgColor << 4) | textColor));
    std::cout << text;
}
