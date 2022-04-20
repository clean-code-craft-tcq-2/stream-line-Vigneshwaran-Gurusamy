#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "BatteryReadingReceiver.h"

TEST_CASE("Tests to check whether sensor data is read from console") 
{
  float Temperature[NO_OF_READINGS] = {0};
  float SOC[NO_OF_READINGS] = {0};
  float ChargeRate[NO_OF_READINGS] = {0};
  float *ComputeDData;
  ComputeDData = BatteryReceiver(Temperature,SOC,ChargeRate);
  float expectedoutput[9] = {0.000000,45.000000,21.000000,80.000000,0.000000,1.200000,21.000000,73.000000,74.000000};
  for(int i=0;i<9;i++)
  {
    REQUIRE(ComputeDData[i] == expectedoutput[i]);
  }
  
}

