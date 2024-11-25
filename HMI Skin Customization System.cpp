#include <iostream>
#include <map>
#include <string>

using namespace std;

class Theme {
public:
    string backgroundColor;
    string fontColor;
    string fontSize;
    string iconStyle;

    Theme(string bg, string font, string size, string icon)
        : backgroundColor(bg), fontColor(font), fontSize(size), iconStyle(icon) {}

    void apply() {
        cout << "Applied theme: Background=" << backgroundColor
             << ", Font=" << fontColor << ", Font Size=" << fontSize
             << ", Icon Style=" << iconStyle << endl;
    }

    void preview() {
        cout << "Preview: Background=" << backgroundColor
             << ", Font=" << fontColor << ", Font Size=" << fontSize
             << ", Icon Style=" << iconStyle << endl;
    }
};

class ThemeManager {
private:
    map<string, Theme> themes;

public:
    void addTheme(string name, Theme theme) {
        themes[name] = theme;
    }

    void applyTheme(string name) {
        if (themes.find(name) != themes.end()) {
            themes[name].apply();
        } else {
            cout << "Theme not found!" << endl;
        }
    }

    void previewTheme(string name) {
        if (themes.find(name) != themes.end()) {
            themes[name].preview();
        } else {
            cout << "Theme not found!" << endl;
        }
    }
};

int main() {
    ThemeManager manager;
    manager.addTheme("Classic", Theme("White", "Black", "Medium", "Standard"));
    manager.addTheme("Sport", Theme("Red", "White", "Large", "Sport"));
    manager.addTheme("Eco", Theme("Green", "Black", "Small", "Eco"));

    string choice;
    cout << "Select a theme: Classic, Sport, Eco or type 'exit' to quit: ";
    while (cin >> choice) {
        if (choice == "exit") {
            break;
        }
        manager.previewTheme(choice);
        manager.applyTheme(choice);
        cout << "Select a theme: Classic, Sport, Eco or type 'exit' to quit: ";
    }

    cout << "Exiting the program." << endl;
    return 0;
}
