#include <QApplication>
#include <QGridLayout>
#include "compartments.h"

int main(int argc, char *argv[]) {
    // Create a Image Locations Store Object
    PrimaryStorage imageLocationsStore;

    bool keepPlaying = true;
    while(keepPlaying == true){
        // Ask the user to add a name.
        std::string name;
        std::cout << "Enter a name: ";
        std::cin >> name;

        // Add the name to the JSON File
        imageLocationsStore.addNameToJSONFile("../emotions.json", name);

        // Ask the user if they want to add another name.
        // std::string answer;
        // std::cout << "Do you want to add another name? (y/n): ";
        // std::cin >> answer;

        // // If the user does not want to add another name, set keepPlaying to false.
        // if (answer == "n") {
        //     keepPlaying = false;
        // }
    }
}