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

TEST_CASE("Tests to check minimum value from the battery parameters") 
{
  float Temperature[NO_OF_READINGS] = {0};
  float SOC[NO_OF_READINGS] = {0};
  float ChargeRate[NO_OF_READINGS] = {0};
  float TemperatureMin;
  float SOCMin;
  float ChargeRateMin;
  BatteryReceiver(Temperature,SOC,ChargeRate);
  float expectedMinoutput[3] = {0,21,0};
  for(int i=0;i<3;i++)
  {
    REQUIRE(TemperatureMin == expectedMinoutput[0]);
    REQUIRE(SOCMin == expectedMinoutput[1]);
    REQUIRE(ChargeRateMin== expectedMinoutput[2]);
  }
  
}

TEST_CASE("Tests to check maximum value from the battery parameters") 
{
  float Temperature[NO_OF_READINGS] = {0};
  float SOC[NO_OF_READINGS] = {0};
  float ChargeRate[NO_OF_READINGS] = {0};
  float TemperatureMax;
  float SOCMax;
  float ChargeRateMax;
  BatteryReceiver(Temperature,SOC,ChargeRate);
  float expectedMaxoutput[3] = {1.2,80,45};
  for(int i=0;i<3;i++)
  {
    REQUIRE(TemperatureMax == expectedMaxoutput[0]);
    REQUIRE(SOCMax == expectedMaxoutput[1]);
    REQUIRE(ChargeRateMax== expectedMaxoutput[2]);
  }
  
}


TEST_CASE("Tests to check SMA from the battery parameters") 
{
  float Temperature[NO_OF_READINGS] = {0};
  float SOC[NO_OF_READINGS] = {0};
  float ChargeRate[NO_OF_READINGS] = {0};
  float TemperatureAverage
  float SOCAverage;
  float ChargeRateAverage;
  BatteryReceiver(Temperature,SOC,ChargeRate);
  float expectedAverageoutput[3] = {1.2,80,45};
  for(int i=0;i<3;i++)
  {
    REQUIRE(TemperatureAverage == expectedAverageoutput[0]);
    REQUIRE(SOCAverage == expectedAverageoutput[1]);
    REQUIRE(ChargeRateAverage== expectedAverageoutput[2]);
  }
}
