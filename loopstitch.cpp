#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int loopstitcher( int totalFrames, int cameras) {
    // Set the path to your C++ program
    string programPath = "C:\\Users\\admin\\Desktop\\needle\\build\\Debug\\needle.exe";
    if (!fs::exists("stitchedimages"))
        fs::create_directory("stitchedimages");

    // Define the total number of frames

    // Define the number of cameras

    // Loop through each frame
    for (int i = 1; i < totalFrames; i++) {
        // Construct the arguments
        stringstream arguments;
        string cont_str;
        int cont;

        arguments << "--frameno " << i << " " << cameras << " --output C:\\Users\\admin\\Desktop\\gittest\\stitchingDSP\\output\\stitchedimages\\" << i << ".jpg --features akaze --conf_thresh 0.1 --match_conf 0.1 --warp mercator";

        // Convert the stringstream to a string
        string argumentString = arguments.str();

        // Execute the program with the arguments
        string command = programPath + " " + argumentString;
        cout << "Executing command: " << command << endl;
        system(command.c_str());

        if(i == 1){
            cout << "1st frame produced. Continue? (1/0)" << endl;
            getline(cin, cont_str);
                if(cont_str.length() == 0){
                    cont = 0;
                    std::cout << "No input provided. Proceeding with stitching..." << endl;
                }

                else {
                    cont = stoi(cont_str);
                    if (cont)
                        std::cout << "Proceeding with stitching videos.." << endl;
                    else{
                        std::cout << "Stopping stiching..." << endl;
                    }
                }
        }
    }

    return 0;
}