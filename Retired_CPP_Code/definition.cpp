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

// Return the first image in the list of images.
void ImageLocations::getNextImage() {
    // If the list of images is not empty, set the active image to the first image in the list.
    if (!images.empty()) {
        activeImage = images[0];
    } else {
        // If the list of images is empty, set the active image to an empty string.
        activeImage = "";
    }
}

// Add an image to the end of the list of images.
void ImageLocations::addItem(std::string image) {
    images.push_back(image);
}

// Remove the first image in the list of images.
void ImageLocations::removeItem(std::string image) {
    // If the list of images is not empty, remove the first image in the list.
    if (!images.empty()) {
        images.erase(images.begin());
    }
}

// Default Constructor for the ImageLocationStore
PrimaryStorage::PrimaryStorage() : 
    imageLocations_tr_un_im("../Training/train_unclass/image/"),
    imageLocations_tr_un_seg("../Training/train_unclass/seg/"),
    imageLocations_val_un_im("../Training/val_unclass/image/"),
    imageLocations_val_un_seg("../Training/val_unclass/seg/") {
}

// Read in the JSON File that contains emotions.
void PrimaryStorage::readJSONFile(std::string filename) {
    // Load the JSON File that is located at filename
    nlohmann::json data = nlohmann::json::parse(std::ifstream (filename));

    // Print out the JSON File line by line in format "key: value"
    for (auto& element : data.items()) {
        std::cout << element.key() << ": " << element.value() << std::endl;
    }
}

// Add a name to the JSON File
void PrimaryStorage::addNameToJSONFile(std::string filename, std::string name) {
    // Load the JSON File that is located at filename
    nlohmann::json data = nlohmann::json::parse(std::ifstream (filename));

    // Get the last entry's key in the JSON File
    std::string lastKey = data.rbegin().key();

    // lastKey is a number, convert to int, add one, convert back to string.
    int newKey = std::stoi(lastKey) + 1; // This is the new key.

    // Add the key and the name to the JSON File
    data[std::to_string(newKey)] = name;

    // Print data
    std::cout << "Printing Data" << std::endl;
    std::cout << data.dump(4) << std::endl;

    // Open the JSON File for writing
    std::ofstream file(filename);

    // Write the JSON File to the file
    file << data.dump(4);

    // Save the File to the disk location specified by filename
    file.close();

    // Print message to console
    // std::cout << "Added " << newKey << ". " << name << " to " << filename << std::endl;
}