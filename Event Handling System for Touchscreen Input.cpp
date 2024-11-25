#include <iostream>
#include <queue>
#include <random>
#include <string>

using namespace std;

class Event {
public:
    enum EventType { TAP, SWIPE };
    EventType type;
    int x, y;

    Event(EventType type, int x, int y) : type(type), x(x), y(y) {}
};

class EventQueue {
private:
    queue<Event> events;

public:
    void pushEvent(Event event) {
        events.push(event);
    }

    Event popEvent() {
        Event e = events.front();
        events.pop();
        return e;
    }

    bool isEmpty() const {
        return events.empty();
    }
};

void processEvent(const Event& event) {
    if (event.type == Event::TAP) {
        cout << "Tapped at (" << event.x << ", " << event.y << ")" << endl;
    } else if (event.type == Event::SWIPE) {
        cout << "Swipe detected: ";
        if (event.x > 0) cout << "Right";
        else cout << "Left";
        cout << endl;
    }
}

int main() {
    EventQueue queue;

    queue.pushEvent(Event(Event::TAP, 10, 20));
    queue.pushEvent(Event(Event::SWIPE, -5, 0));
    queue.pushEvent(Event(Event::TAP, 15, 30));

    while (!queue.isEmpty()) {
        Event event = queue.popEvent();
        processEvent(event);
    }

    return 0;
}
