#include <QPushButton>
#include <QCoreApplication>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

// Class for Images and their Locations. Will also work in retrieving images.
class ImageLocations {
    public:
        // List of Images
        std::vector<std::string> images;

        // Active Image
        std::string activeImage;

        // Get Next Image
        void getNextImage();

        // Add an Image to the List
        void addItem(std::string image);

        // Remove an Image from the List
        void removeItem(std::string image);

        // Using filesystem, a current list of files in the directory listed below.
        std::string training_unclassified_im = "Training/train_unclass/image/";
        std::string training_unclassified_seg = "Training/train_unclass/seg/";
        std::string validation_unclassified_im = "Validation/val_unclass/image/";
        std::string validation_unclassified_seg = "Validation/val_unclass/seg/";

        // Create function "listFiles" that returns a vector of strings of the file locations in the directory.
        std::vector<std::string> listFiles(std::string directory);

        // Create a function that will move files from one location to another.
        void moveFiles(std::string oldLocation, std::string newLocation);
};

// Class that stores the ImageLocations class
class ImageLocationsStore {
    public:
        // ImageLocations Object for Reference.
        ImageLocations imageLocations;

        // Active Image Function, which is done by calling the getNextImage function from imageLocations
        std::string current_image = imageLocations.activeImage;
};