#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MenuItem {
public:
    string name;
    vector<MenuItem> subMenuItems;

    MenuItem(string name) : name(name) {}

    void addSubMenuItem(MenuItem item) {
        subMenuItems.push_back(item);
    }
};

class Menu {
private:
    vector<MenuItem> items;
    int currentIndex = 0;

public:
    void addItem(MenuItem item) {
        items.push_back(item);
    }

    void display() {
        cout << "Current Menu:" << endl;
        for (int i = 0; i < items.size(); i++) {
            cout << (i == currentIndex ? "> " : "  ") << items[i].name << endl;
        }
    }

    void navigateDown() {
        if (currentIndex < items.size() - 1) currentIndex++;
    }

    void navigateUp() {
        if (currentIndex > 0) currentIndex--;
    }

    void enter() {
        if (!items[currentIndex].subMenuItems.empty()) {
            Menu subMenu;
            for (auto& subItem : items[currentIndex].subMenuItems) {
                subMenu.addItem(subItem);
            }
            subMenu.display();
        }
    }
};

int main() {
    Menu mainMenu;

    MenuItem settings("Settings");
    settings.addSubMenuItem(MenuItem("Display Settings"));
    settings.addSubMenuItem(MenuItem("Audio Settings"));

    MenuItem media("Media");
    media.addSubMenuItem(MenuItem("Radio"));
    media.addSubMenuItem(MenuItem("Bluetooth Audio"));

    mainMenu.addItem(settings);
    mainMenu.addItem(media);

    mainMenu.display();

    int choice;
    while (true) {
        cout << "\nChoose an action (1: down, 2: up, 3: enter, 4: exit): ";
        cin >> choice;
        switch (choice) {
            case 1: mainMenu.navigateDown(); break;
            case 2: mainMenu.navigateUp(); break;
            case 3: mainMenu.enter(); break;
            case 4: return 0;
        }
        mainMenu.display();
    }
}
