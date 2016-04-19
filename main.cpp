#include <iostream>
#include <cstdlib>
#include <cstring>

#include "file.h"

/**=========== Example of Use =============**/
int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        std::cout << "Use: '-read' or '-write'" << std::endl;
        return -1;
    }

    string file_path = "example.txt";



    ///Write
    if (strcmp(argv[1],"-write") == 0)
    {
        if (write_comment(file_path, 1, "//Example File Config") == -1)//if file does not exist return -1
        {
            cout << "File Does Not Exist!" << std::endl;
            return -1;
        }
        write_comment(file_path, 2, "");
        write_comment(file_path, 3, "//Video Config");

        write_variable(file_path, "width", "1024");
        write_variable(file_path, "height", "720");
        write_variable(file_path, "mode", "fullscreen");

        return 0;
    }



    ///Read
    if (strcmp(argv[1],"-read") == 0)
    {
        int width;
        int height;
        string mode;

        width = atoi(read_variable(file_path, "width").c_str());
        height = atoi(read_variable(file_path, "height").c_str());
        mode = read_variable(file_path, "mode");//if file does not exist return "null"

        std::cout << "Width = " << width << std::endl;
        std::cout << "Height = " << height << std::endl;
        std::cout << "Mode = " << mode << std::endl;

        return 0;
    }

    //invalid
    else
    {
        std::cout << "Use: '-read' or '-write'" << std::endl;
        return -1;
    }
}
