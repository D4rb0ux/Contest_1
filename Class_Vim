#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Vim {
    string mode;
    string curr_text;
    size_t pos;

public:
    Vim() {
        this->mode = "view";
        this->curr_text.push_back(' ');
        this->pos = 0;
    }

    void change_mode(const char& c) {
        if (mode == "view" && c == 'i')
            mode = "edit";
        else if (mode == "edit" && c == 'i')
            insert('i');
        else if (mode == "edit" && c == '<')
            mode = "view";
    }

    void insert(const char& c) {
        if (mode == "edit") {
            curr_text.insert(pos, 1, c);
            pos++;
        }
    }

    void left() {
        if (mode == "view") {
            if (pos != 0) {
                pos--;
            }
        } else {
            insert('h');
        }
    }

    void right() {
        if (mode == "view") {
            if (pos != curr_text.size() - 1) {
                pos++;
            }
        } else {
            insert('l');
        }
    }

    string getStr() {
        return curr_text;
    }
};

int main() {
    string str;
    getline(cin, str);
    Vim v;
    for (char& c : str) {
        if (c == 'h')
            v.left();
        else if (c == 'l')
            v.right();
        else if (c == '<' || c == 'i')
            v.change_mode(c);
        else
            v.insert(c);
    }
    string ans = v.getStr();
    ans.pop_back();
    for (auto& elem : ans)
        cout << elem;
}
