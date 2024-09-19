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

        // Create function "listFiles" that returns a vector of strings of the file locations in the directory.
        std::vector<std::string> listFiles(std::string directory);

        // Active Image
        std::string activeImage;

        // Get Next Image
        void getNextImage();

        // Constructor, with a string leading to a particular location.
        ImageLocations(std::string location) {
            // List of Images
            images = listFiles(location);

            // Active Image
            getNextImage();
        }

        // Add an Image to the List
        void addItem(std::string image);

        // Remove an Image from the List
        void removeItem(std::string image);

        // Create a function that will move files from one location to another.
        void moveFiles(std::string oldLocation, std::string newLocation);
};

// Class that stores the ImageLocations class
class ImageLocationsStore {
    public:
        // Constructor
        ImageLocationsStore() {
            // ImageLocations Object for Reference.
            ImageLocations imageLocations_tr_un_im = ImageLocations("Training/train_unclass/image/");
            ImageLocations imageLocations_tr_un_seg = ImageLocations("Training/train_unclass/seg/");
            ImageLocations imageLocations_val_un_im = ImageLocations("Validation/val_unclass/image/");
            ImageLocations imageLocations_val_un_seg = ImageLocations("Validation/val_unclass/seg/");
        }

        // Active Image Function, which is done by calling the getNextImage function from imageLocations
        
};