// StaticLib1.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include <iostream>
#include <mutex>
#include <windows.h>

FileSearch::FileSearch(const std::string& filename) : filename(filename) {}

void FileSearch::StartSearch() {
    SearchDirectory("C:\\"); // Start from C:\ for Windows
}

void FileSearch::SearchDirectory(const std::string& directory) {
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind = FindFirstFileA((directory + "\\*").c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                if (threads.size() < MAX_THREADS) {
                    threads.emplace_back([this, &findFileData, &directory]() {
                        SearchDirectory(directory + "\\" + findFileData.cFileName);
                        });
                }
            }
            else {
                std::string filePath = directory + "\\" + findFileData.cFileName;
                if (findFileData.cFileName == filename) {
                    std::cout << "File found: " << filePath << std::endl;
                    // Notify other threads to stop searching
                    for (auto& thread : threads) {
                        if (thread.get_id() != std::this_thread::get_id()) {
                            thread.detach();
                        }
                    }
                }
            }
        } while (FindNextFileA(hFind, &findFileData) != 0);
        FindClose(hFind);
    }
}
