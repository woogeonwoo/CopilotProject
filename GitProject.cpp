#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

class EngineController {
private:
    bool isRunning;
    int rpm;
    float temperature;

public:
    EngineController() : isRunning(false), rpm(0), temperature(20.0) {
        std::srand(std::time(0)); // Seed for temperature simulation
    }

    void startEngine() {
        if (!isRunning) {
            isRunning = true;
            rpm = 1000; // Default idle RPM
            printf("Engine started. RPM: %d\n", rpm);
        } else {
            printf("Engine is already running.\n");
        }
    }

    void stopEngine() {
        if (isRunning) {
            isRunning = false;
            rpm = 0;
            printf("Engine stopped.\n");
        } else {
            printf("Engine is already stopped.\n");
        }
    }

    void adjustRPM(int newRPM) {
        if (isRunning) {
            rpm = newRPM;
            printf("RPM adjusted to %d\n", rpm);
        } else {
            printf("Cannot adjust RPM. Engine is not running.\n");
        }
    }

    void simulateTemperature() {
        if (isRunning) {
            temperature = 20.0 + (std::rand() % 80); // Simulate temperature between 20 and 100 degrees
            printf("Current engine temperature: %.2f°C\n", temperature);
        } else {
            printf("Engine is not running. Temperature is stable at %.2f°C\n", temperature);
        }
    }
};

int main() {
    EngineController engine;

    engine.startEngine();
    engine.adjustRPM(3000);
    engine.simulateTemperature();
    engine.stopEngine();
    engine.simulateTemperature();

    return 0;
}