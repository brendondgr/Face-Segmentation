#include <QApplication>
#include <QGridLayout>
#include "compartments.h"

int main(int argc, char *argv[]) {
    // Create a Image Locations Store Object
    ImageLocationsStore imageLocationsStore;

    // Print out the first items in all of the Image Locations.
    std::cout << "Training Unclassified Image: " << imageLocationsStore.imageLocations_tr_un_im.activeImage << std::endl;
    std::cout << "Training Unclassified Segmentation: " << imageLocationsStore.imageLocations_tr_un_seg.activeImage << std::endl;
    std::cout << "Validation Unclassified Image: " << imageLocationsStore.imageLocations_val_un_im.activeImage << std::endl;
    std::cout << "Validation Unclassified Segmentation: " << imageLocationsStore.imageLocations_val_un_seg.activeImage << std::endl;
}