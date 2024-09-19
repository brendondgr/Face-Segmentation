#include <QPushButton>
#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

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
class PrimaryStorage {
    public:
        // Initialize the ImageLocations
        ImageLocations imageLocations_tr_un_im;
        ImageLocations imageLocations_tr_un_seg;
        ImageLocations imageLocations_val_un_im;
        ImageLocations imageLocations_val_un_seg;

        // Constructor
        PrimaryStorage();

        // Move-To Locations...
        std::string imageLocation_tr_cl_im = "Training/train/image/";
        std::string imageLocation_tr_cl_seg = "Training/train/seg/";
        std::string imageLocation_val_cl_im = "Training/val/image/";
        std::string imageLocation_val_cl_seg = "Training/val/seg/";

        // Read in the JSON File that contains emotions.
        void readJSONFile(std::string filename);

        // Add Name to JSONFile
        void addNameToJSONFile(std::string filename, std::string name);
};