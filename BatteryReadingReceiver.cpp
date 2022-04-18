#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Tests to check whether sensor data is read from console") 
{
  float Temperature[NO_OF_READINGS] = {0};
  float SOC[NO_OF_READINGS] = {0};
  float ChargeRate[NO_OF_READINGS] = {0};
  BatteryReceiver(Temperature,SOC,ChargeRate);
  float expectedoutput[3][3] = {{0.9,1.0,1.8}, {53,64,44},{6,44,7}};
  for(int i=0;i<3;i++)
  {
    REQUIRE(Temperature[i] == expectedoutput[i][0]);
    REQUIRE(SOC[i] == expectedoutput[i][1]);
    REQUIRE(ChargeRate[i] == expectedoutput[i][2]);
  }
  
}

