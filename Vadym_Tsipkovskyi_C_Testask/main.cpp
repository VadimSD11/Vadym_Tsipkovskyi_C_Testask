// main.cpp
#include <iostream>
#include "C:\Users\Vadim_y9xms2s\source\repos\Vadym_Tsipkovskyi_C_Testask\StaticLib1\pch.h"

int main() {
    std::string filename = "your_file_name.txt"; // Change this to the name of the file you want to find
    FileSearch fileSearch(filename);
    fileSearch.StartSearch();
    return 0;
}
