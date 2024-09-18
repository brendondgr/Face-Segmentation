#include "compartments.h"

// Function that returns a vector of strings of the file locations in the directory.
std::vector<std::string> ImageLocations::listFiles(std::string directory) {
    std::vector<std::string> files;
    for (const auto & entry : std::filesystem::directory_iterator(directory)) {
        // Convert entry.path() to a string and push it to the vector.
        files.push_back(entry.path().string());
    }
    return files;
}

// Function that will move files from one location to another, based on the two specified string paths.
void ImageLocations::moveFiles(std::string oldLocation, std::string newLocation) {
    // Move the file from the old location to the new location.
    std::filesystem::rename(oldLocation, newLocation);
}