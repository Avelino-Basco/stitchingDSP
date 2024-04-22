#include "video_to_frames.cpp" 
#include "directorycounter.cpp"
#include "loopstitch.cpp"
#include "frames_to_video.cpp"

#include <string>
using namespace std;

//naming convention of video files: n.mp4 (e.g. 1.mp4, 2.mp4, 3.mp4)

int main(){
    string folderPath, fps_str;
    int fps;
    
    cout << "Enter the directory path containing .mp4 files: ";
    getline(cin, folderPath);

    //default if no directory
    if(folderPath.length() == 0){
        folderPath = "C:/Users/admin/Desktop/199/output/camsource";
        std::cout << "No directory input. Using default 'C:/Users/admin/Desktop/199/output/camsource' as directory..." << endl;
    }
    
    //requests FPS
    cout << "Enter the frame rate (fps): ";
    getline(cin, fps_str);

    if(fps_str.length() == 0){
        fps = 1;
        std::cout << "No specified fps. Set to 1 fps by default..." << endl;
    }

    else {
        fps = stoi(fps_str);
    }
    
    //MP4 to frames
    //int to keep track of folders
    int no_of_folders = processMp4Files(folderPath, fps);

//looping: stitch frames together
    
    //loop through each x_frames folder and get the minimum number of frames
    int framelimit = 0;
    int framelimit_holder = 0;
    for (int i = 1; i < no_of_folders + 1; ++i) {
        if (i == 1) 
        {
            string folder = to_string(i) + "_frames";
            framelimit = file_counter(folder);
        }

        else 
        {
            string folder = to_string(i) + "_frames";
            framelimit_holder = file_counter(folder);

            if(framelimit_holder < framelimit) 
            {
                framelimit = framelimit_holder;
            }
        }
    }

    cout << "max frames:" << to_string(framelimit) << endl;
    loopstitcher(framelimit, no_of_folders);

    frames_to_video();
        
    return 0;
}