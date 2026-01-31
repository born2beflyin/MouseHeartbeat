
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <thread>

#pragma comment(lib, "User32.lib")

// Main entry point
int main(int argc, char* argv[]) {
	
	// Set some flags
	bool MOVEMOUSE = false;
	bool DEBUG = false;
	
	// Output some basic usage info
	std::cout << "MouseHeartbeat started" << std::endl;
	std::cout << "-- to output debug info, use argument \"debug\"" << std::endl;
	std::cout << "-- to move the mouse in a circle, use argument \"move\"" << std::endl;
	std::cout << std::endl;
	
    // Convert argv to a more convenient container
    std::vector<std::string> args;
    for (int i = 0; i < argc; ++i) {
        args.push_back(argv[i]);
    }

    // Handle arguments
    for (auto arg : args) {
        if (arg == "debug") {
            std::cout << "DEBUG ON" << std::endl;
			DEBUG = true;
        }
		if (arg == "move") {
            std::cout << "MOVE ON" << std::endl;
			MOVEMOUSE = true;
		}
    }
	
	// Run the loop
	while (true) {
		if (!MOVEMOUSE) {
			// Just send a mouse move of 0,0 to keep the system awake
			const int DELTA = 2;
			if (DEBUG) {
				std::cout << "Sending mouse heartbeat" << std::endl;
			}
			INPUT input = {0};
			input.type = INPUT_MOUSE;
			input.mi.dx = DELTA;
			input.mi.dy = DELTA;
			input.mi.dwFlags = MOUSEEVENTF_MOVE;
			SendInput(1, &input, sizeof(INPUT));
			std::this_thread::sleep_for(std::chrono::milliseconds(2)); // Wait 2 milliseconds
			input.mi.dx = -DELTA;
			input.mi.dy = -DELTA;
			SendInput(1, &input, sizeof(INPUT));
			std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait 2 seconds
		} else {
			// Move the mouse in a small circle
			static double angle = 0.0;
			const double radius = 5.0; // pixels
			int dx = static_cast<int>(radius * cos(angle));
			int dy = static_cast<int>(radius * sin(angle));
			if (DEBUG) {
				std::cout << "Moving mouse by (" << dx << "," << dy << ")" << std::endl;
			}
			INPUT input = {0};
			input.type = INPUT_MOUSE;
			input.mi.dx = dx;
			input.mi.dy = dy;
			input.mi.dwFlags = MOUSEEVENTF_MOVE;
			SendInput(1, &input, sizeof(INPUT));
			angle += 0.5; // Increment angle for next move
			if (angle >= 2 * 3.14159265) {
				angle -= 2 * 3.14159265; // Keep angle within 0 to 2π
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Wait 100 milliseconds
		}
	}

    return 0; // Return 0 on success
}