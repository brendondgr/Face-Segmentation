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
ImageLocationsStore::ImageLocationsStore() : 
    imageLocations_tr_un_im("../Training/train_unclass/image/"),
    imageLocations_tr_un_seg("../Training/train_unclass/seg/"),
    imageLocations_val_un_im("../Training/val_unclass/image/"),
    imageLocations_val_un_seg("../Training/val_unclass/seg/") {
}