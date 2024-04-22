#include <iostream>
#include <filesystem>
#include <string>

using namespace std;

//function responsible for counting how many camera feeds (for setting loop count)
int file_counter(string& directory)
{
   int count = 0;
   //cout << directory << endl;

   if(directory.length() == 0) //sets default directory if no 
   {
    directory = "C:/Users/admin/Desktop/199/stitching/camsource";
    std::cout << "No directory input. Using default 'C:/Users/admin/Desktop/199/stitching/camsource' as directory..." << endl;
   }

   std::filesystem::path p1 { directory };

   for (auto& p : std::filesystem::directory_iterator(p1))
   {
      ++count;
   }    

   //p1 is string() since without it, display is "C:\\Users\\admin" due to "\" being an escape character
   std::cout << "# of files in " << p1.string() << ": " << count << '\n' << endl;;
   return count;
}

/*int main(){
    string camfeed_directory;
    std::cout << "What is the file directory?" << endl;
    getline(cin, camfeed_directory);
    
    int filecount = file_counter(camfeed_directory);
    return 0;
}*/
