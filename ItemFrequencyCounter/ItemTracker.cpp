#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
// Define a map to store item frequencies
map<string, int> itemFrequency;

// Function to read input from a file and populate itemFrequency map
void readInputFile() {
    ifstream inputFile("Input_File.txt"); // Open input file
    string item;

    // Read items from file and update their frequencies in the map
    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close(); // Close input file
}

// Function to get frequency of each item as a string
string getFrequencyOfEachItem() {
    string result = "";
    for (const auto& pair : itemFrequency) {
        result += pair.first + " : " + to_string(pair.second) + "\n";
    }
    return result;
}

// Function to get frequency of a specific item
int getFrequencyOfSingleItem(string itemName) {
    auto it = itemFrequency.find(itemName);
    if (it != itemFrequency.end()) {
        return it->second; // Return frequency if item is found in the map
    }
    else {
        return 0; // Return 0 if item is not found
    }
}

// Function to display data as a text-based histogram
string showHistogram() {
    string result = "";
    for (const auto& pair : itemFrequency) {
        result += pair.first + " ";
        // Append '*' for each occurrence of the item
        for (int i = 0; i < pair.second; ++i) {
            result += "*";
        }
        result += "\n";
    }
    return result;
}

// Function to save item frequencies to a file
void saveToFile() {
    ofstream outputFile("frequency.dat"); // Open output file
    for (const auto& pair : itemFrequency) {
        outputFile << pair.first << " : " << pair.second << endl; // Write item frequencies to file
    }
    outputFile.close(); // Close output file
    cout << "Data saved to frequency.dat." << endl; // Print a confirmation message
}

int main() {
    readInputFile(); // Read input data from file

    int user_choice = -1;
    // Menu-driven program to interact with item frequencies
    while (user_choice != 4) {
        cout << "========================================================\n";
        cout << "MENU\n";
        cout << "1. Check number of times each individual item appears\n";
        cout << "2. Determine the frequency of a specific item\n";
        cout << "3. Graphically display a data file as a text-based histogram\n";
        cout << "4. Save data to frequency.dat and Exit\n";
        cout << "========================================================\n";
        cout << "Enter your choice: ";
        cin >> user_choice; // Take user input for menu choice

        switch (user_choice) {
        case 1:
            cout << "Frequency of items is : \n";
            cout << getFrequencyOfEachItem() << "\n"; // Display frequencies of all items
            break;
        case 2:
        {
            cout << "Enter an item name, for which you want the frequency : \n";
            string item;
            cin >> item;
            int frequency = getFrequencyOfSingleItem(item);
            if (frequency != 0) {
                cout << "Frequency of " << item << ": " << frequency << "\n"; // Display frequency of a specific item
            }
            else {
                cout << "No such item present\n"; // Display message if item not found
            }
        }
        break;
        case 3:
            cout << "The histogram format of the data is: \n";
            cout << showHistogram() << "\n"; // Display data as a histogram
            break;
        case 4:
            saveToFile(); // Save data to file and exit
            break;
        default:
            cout << "Invalid choice. Please try again.\n"; // Display message for invalid menu choice
        }
    }

    return 0; // Exit the program
}
