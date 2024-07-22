#ifndef CARBONH
#define CARBONH

#include <string>

using namespace std;

class Carbon {
public: 

  void CalculateVehicleCarbon(double milesPerYear, double milesPerGallon);

  double GetVehicleCarbon();

  void CalculateElectricityCarbon(double electricityUsage);

  double GetElectricityCarbon();

  void CalculateNaturalGasCarbon(double naturalGasUsage);

  double GetNaturalGasCarbon();

  void CalculatePropaneCarbon(double propaneGallons);

  double GetPropaneCarbon();

  double TotalCarbonFootPrint();

  void PrintInfo(); 

  void CarbonFootPrintEffects();

  void lowerCPreport();

private:
  double carbonPerGallon;

  double electricityCarbon;

  double naturalGasCarbon;

  double propaneCarbon;

};

#endif 

