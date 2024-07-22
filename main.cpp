#include "carbon-calculator.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  Carbon carbon;
  ifstream inFile;
  ofstream ofFile;
  double values;
  vector<double> fileValues;
  double milesPerYear;
  double milesPerGallon;
  double electricityUsage;
  double naturalGasUsage;
  double propaneGallons;
  char choice1;
  char choice2;

  cout << "Welcome to the Carbon Footprint Calculator!" << endl;
  cout << "Please collect the required info to begin such, as miles driven per "
          "year, miles per"
       << " gallon, yearly electricity usage, yearly natural gas usage, and "
          "propane gallons used in a year."
       << endl;

  cout << "Are you ready to begin? (Y/N)"
       << endl; // User inputs whehter they are ready to begin
  cin >> choice1;

  if (choice1 == 'Y' || choice1 == 'y') {
    while (choice1 == 'Y' || choice1 == 'y') {
      cout << "Would you like to input your own values? (Y/N)"
           << endl; // User inputs whether they want to input their own values
      cin >> choice2;
      if (choice2 == 'Y' || choice2 == 'y') { // User inputs their own values
        // Values are based on yearly usage
        cout << "Enter miles driven per year: ";
        cin >> milesPerYear;
        cout << "Enter your vehicle's miles per gallon: ";
        cin >> milesPerGallon;
        cout << "Enter yearly electricity usage in kwh: ";
        cin >> electricityUsage;
        cout << "Enter yearly natural gas usage in therms: ";
        cin >> naturalGasUsage;
        cout << "Enter yearly propane gallons used: ";
        cin >> propaneGallons;
      } else { // Otherwise program gathers data from separate file
        cout << "Gathering data from separate file..." << endl;
        inFile.open("inputsFile.txt");
        if (!inFile.is_open()) { // If the file does not open then the program
                                 // ends
          cout << "Could not open file." << endl;
          return 1;
        }
        while (!inFile.eof()) { // Until the end of file is reached, the program
                                // gathers data from the file and stores it in a
                                // vector
          inFile >> values;
          fileValues.push_back(values);
        }
        milesPerYear = fileValues.at(0);
        milesPerGallon = fileValues.at(1);
        electricityUsage = fileValues.at(2);
        naturalGasUsage = fileValues.at(3);
        propaneGallons = fileValues.at(4);
        cout << "Data gathered from file." << endl;
        inFile.close(); // File closes after data is collected and assigned to
                        // variables
      }
      // Values will now be calculated
      cout << fixed << setprecision(2);
      carbon.CalculateVehicleCarbon(milesPerYear, milesPerGallon);
      carbon.CalculateElectricityCarbon(electricityUsage);
      carbon.CalculateNaturalGasCarbon(naturalGasUsage);
      carbon.CalculatePropaneCarbon(propaneGallons);
      cout << endl;
      carbon.PrintInfo();
      cout << endl;
      // User has the option to learn more about carbon footprints and their
      // impacts
      cout << "Would you like to learn how your carbon footprint is impacting "
              "the environment? (Y/N)"
           << endl;
      cin >> choice2;
      if (choice2 == 'Y' || choice2 == 'y') {
        carbon.CarbonFootPrintEffects();
      }
      cout << endl;
      // User has the option to learn ways to reduce carbon footprints
      cout << "Would you like to learn how to reduce your carbon footprint? "
              "(Y/N)"
           << endl;
      cin >> choice2;
      cout << endl;
      if (choice2 == 'Y' || choice2 == 'y') {
        carbon.lowerCPreport();
      }

      cout << endl; // User has the option to tranfer data to a separate file
      cout << "Would you like to upload your carbon footprint data to a file? "
              "(Y/N)"
           << endl;
      cin >> choice2;
      if (choice2 == 'Y' || choice2 == 'y') {
        ofFile.open("CPresults.txt"); // Opens file
        if (!ofFile.is_open()) { // If the file does not open then the program
                                 // ends
          cout << "CPresults.txt: error in opening file" << endl;
          return 1;
        }
        ofFile << fixed << setprecision(2); // Transfers data to separate file
        ofFile << "Your vehicle carbon footprint: " << carbon.GetVehicleCarbon()
               << endl;
        ofFile << "Your electricity carbon footprint: "
               << carbon.GetElectricityCarbon() << endl;
        ofFile << "Your natural gas carbon footprint: "
               << carbon.GetNaturalGasCarbon() << endl;
        ofFile << "Your propane carbon footprint: " << carbon.GetPropaneCarbon()
               << endl;
        ofFile << "Your total carbon footprint: "
               << carbon.TotalCarbonFootPrint() << endl;

        ofFile.close();

        cout << "Your carbon footprint data has been uploaded to CPresults.txt."
             << endl;
      }

      cout << endl;
      cout << "Thank you for using our Carbon Footprint Calculator!" << endl;

      cout << endl;
      cout << "Would you like to calculate your carbon footprint again? (Y/N)"
           << endl;
      cin >> choice1;
    }
  } else {
    cout << "Thank you for using our Carbon FootPrint Calculator! Have a nice "
            "day/night!"
         << endl;
  }

  return 0;
}