#include <iostream>
#include <thread>
#include <chrono>
#include <random>

using namespace std;

class VehicleData {
public:
    int speed;
    int fuelLevel;
    int engineTemp;

    VehicleData() : speed(0), fuelLevel(100), engineTemp(90) {}

    void update() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 100);

        speed = dis(gen);
        fuelLevel = dis(gen);
        engineTemp = dis(gen);

        if (engineTemp > 100) cout << "Warning: High Engine Temperature!" << endl;
        if (fuelLevel < 10) cout << "Warning: Low Fuel Level!" << endl;
    }
};

class Display {
public:
    void show(VehicleData& data) {
        cout << "Speed: " << data.speed << " km/h, "
             << "Fuel: " << data.fuelLevel << "%, "
             << "Temperature: " << data.engineTemp << "°C" << endl;
    }
};

void updateVehicleData(VehicleData& data) {
    while (true) {
        data.update();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void displayData(Display& display, VehicleData& data) {
    while (true) {
        display.show(data);
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    VehicleData vehicleData;
    Display display;

    thread updateThread(updateVehicleData, ref(vehicleData));
    thread displayThread(displayData, ref(display), ref(vehicleData));

    updateThread.join();
    displayThread.join();

    return 0;
}
