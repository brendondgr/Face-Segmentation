#include <QApplication>
#include <QGridLayout>
#include "compartments.h"

int main(int argc, char *argv[]) {
    // Create a Image Locations Store Object
    ImageLocationsStore imageLocationsStore;

    // Print the current image
    std::cout << "Current Image: " << imageLocationsStore.current_image << std::endl;
}