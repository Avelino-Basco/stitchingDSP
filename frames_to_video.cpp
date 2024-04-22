#include <cstdlib> // For system function
#include <iostream>


using namespace std;

int frames_to_video() {
    // Define the desired frames per second (FPS)
    string fps_string;
    int fps = 0;

    cout << "Enter the frame rate (fps) of the output video: ";
    getline(cin, fps_string);

    if(fps_string.length() == 0){
        fps = 1;
        std::cout << "No specified fps. Set to 1 fps by default..." << endl;
    }

    else {
        fps = stoi(fps_string);
    }
    // Specify the input and output filenames
    std::string input_filename = "C:/Users/admin/Desktop/needle/output/stitchedimages/%d.jpg"; // Update the folder path accordingly
    std::string output_filename = "output.mp4";

    // Construct the FFmpeg command
    std::string ffmpeg_command = "ffmpeg -framerate " + std::to_string(fps) +
                                 " -i " + input_filename +
                                 " -vf \"scale=trunc(iw/2)*2:trunc(ih/2)*2\" " +
                                 output_filename;

    // Execute the FFmpeg command
    int status = system(ffmpeg_command.c_str());

    if (status != 0) {
        std::cerr << "FFmpeg command execution failed!" << std::endl;
        return 1; // Error exit status
    }

    std::cout << "Video successfully created!" << std::endl;
    return 0; // Normal exit status
}
