#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int loopstitcher( int totalFrames, int cameras) {
    // Set the path to your C++ program
    string programPath = "C:\\Users\\admin\\Desktop\\needle\\build\\Debug\\needle.exe";

    // Define the total number of frames

    // Define the number of cameras

    // Loop through each frame
    for (int i = 1; i < totalFrames; i++) {
        // Construct the arguments
        stringstream arguments;
        arguments << "--frameno " << i << " " << cameras << " --output " << i << ".jpg --features akaze --conf_thresh 0.1 --match_conf 0.1 --warp mercator";

        // Convert the stringstream to a string
        string argumentString = arguments.str();

        // Execute the program with the arguments
        string command = programPath + " " + argumentString;
        cout << "Executing command: " << command << endl;
        system(command.c_str());
    }

    return 0;
}