#include "carbon-calculator.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// lines 9-# Define the constants for the carbon footprint calculations

void Carbon::CalculateVehicleCarbon(double milesPerYear,
                                    double milesPerGallon) {
  double carbonPerGasGallon = 19.6;
  carbonPerGallon =
      milesPerYear * milesPerGallon *
      carbonPerGasGallon; // an approx. amount of CO2 produced per gallon of gas
}

double Carbon::GetVehicleCarbon() { // returns the amount of CO2 produced per
                                    // gallon of gas
  return carbonPerGallon;
}

void Carbon::CalculateElectricityCarbon(double electricityUsage) {
  double carbonPerKWH = .086; // an approx. amount of CO2 produced per kWh
  electricityCarbon = electricityUsage * carbonPerKWH;
}

double
Carbon::GetElectricityCarbon() { // returns the amount of CO2 produced per kWh
  return electricityCarbon;
}

void Carbon::CalculateNaturalGasCarbon(double naturalGasUsage) {
  double carbonPerTherm = 12.08; // an approx. amount of CO2 produced per therm
  naturalGasCarbon =
      naturalGasUsage * carbonPerTherm; // an approx. amount of CO2 produced
                                        // per gallon of natural gas
}

double Carbon::GetNaturalGasCarbon() { // returns the amount of CO2 produced per
                                       // gallon of natural gas

  return naturalGasCarbon;
}

void Carbon::CalculatePropaneCarbon(double propaneGallons) {
  double carbonPerPropaneG =
      12.65; // an approx. amount of CO2 produced per gallon of propane
  propaneCarbon =
      propaneGallons * carbonPerPropaneG; // an approx. amount of CO2 produced
                                          // per gallon of propane
}

double Carbon::GetPropaneCarbon() { return propaneCarbon; }

double Carbon::TotalCarbonFootPrint() {
  return (GetVehicleCarbon() + GetElectricityCarbon() + GetNaturalGasCarbon() +
          GetPropaneCarbon());
}

void Carbon::PrintInfo() {
  cout << "Here are the results!" << endl;
  cout << "Your vehicle carbon footprint is: " << GetVehicleCarbon() << " lbs"
       << endl;
  cout << "Your electricity carbon footprint is: " << GetElectricityCarbon()
       << " lbs" << endl;
  cout << "Your natural gas carbon footprint is: " << GetNaturalGasCarbon()
       << " lbs" << endl;
  cout << "Your propane carbon footprint is: " << GetPropaneCarbon() << " lbs"
       << endl;
  cout << "Your total carbon footprint is: " << TotalCarbonFootPrint() << " lbs"
       << endl;
} // 9-66 Samuel Estrada

void Carbon::CarbonFootPrintEffects() {
  cout << "Here is how your carbon footprint affects the environment!" << endl;
  cout << "- Global warming: Your carbon footprint is worsening climate "
          "change. It is melting polar ice caps, rising sea levels, and "
          "destroying animals' habitats."
       << endl;
  cout
      << "- Air pollution: Your carbon footprint is causing air pollution. The "
         "air we breathe becomes more and more contaminated by the excessive "
         "emissions of carbon, thus exposing us to more respiratory diseases."
      << endl;
  cout << "- Water pollution: Your carbon footprint is causing water "
          "pollution. The water we consume and bathe in is becoming "
          "contaiminated and damaging habitats."
       << endl;
}

void Carbon::lowerCPreport() {
  cout << "Here are some ways to lower your carbon footprint:" << endl;
  cout << "1. Reduce your carbon footprint by driving less. Try to drive less "
          "miles per year by walking, biking, or taking public transportation."
       << endl;
  cout << "2. Reduce Standby Power by unplugging electronics when they're not "
          "in use and utiltize low-power mode on devices when they're "
          "momentarily not in use."
       << endl;
  cout << "3. Keep thermostat at an eco-friendly temperature." << endl;
  cout << "4. Reduce electricity consumption by switching to LED light bulbs "
          "and hanging them to your walls."
       << endl;
  cout
      << "5. Reduce waste by buying reusable products and composting your food."
      << endl;
  cout << "6. Reduce water waste by taking shorter showers and turning off the "
          "water when you're done using it."
       << endl;
  cout << "7. Reduce food waste by buying food that is fresh and organic."
       << endl;
  cout << "8. Clean/replace air filters and vents regularly." << endl;
} // 75 - 85 Tammy Dinh