#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "BatteryReadingReceiver.h"


void PrintComputedReadingsOnConsole(char *ComputedData)
{
  printf("%s\n",ComputedData);
}

float ComputeSMA(float data[])
{
    int sum;
    float average;
    for(int i=0; i<NO_OF_READINGS; i++)
        {
            sum += data[i];
        }
        average = sum/NO_OF_READINGS;
        return average;
}
float ComputeMax(float data[])
{
    float Maximum = data[0];
    for(int i=1; i<NO_OF_READINGS; i++)
    {
        if(Maximum < data[i])
        {
            Maximum = data[i];
        }
    }
    return Maximum;
}
float ComputeMin(float data[])
{
    float Minimum = data[0];
    for(int i=1; i<NO_OF_READINGS; i++)
    {
        if(Minimum > data[i])
        {
            Minimum = data[i];
        }
    }
    return Minimum;
}

float * ComputeTheReadings(float* Temperature, float* SOC, float* ChargeRate, char *ComputedData)
{
    float MinTemperature = ComputeMin(Temperature);
    float MaxTemperature = ComputeMax(Temperature);
    float MinSOC = ComputeMin(SOC);
    float MaxSOC = ComputeMax(SOC);
    float MinChargeRate =  ComputeMin(ChargeRate);
    float MaxChargeRate =  ComputeMax(ChargeRate);
    float SMATemperature =  ComputeSMA(Temperature);
    float SMASOC = ComputeSMA(SOC);
    float SMAChargeRate =  ComputeSMA(ChargeRate);
    float ComputedDataArray[9] = {MinTemperature,MaxTemperature,MinSOC,MaxSOC,MinChargeRate,MaxChargeRate, SMATemperature, SMASOC, SMAChargeRate};
    sprintf(ComputedData,"MinTemperature:%f,MaxTemperature:%f,MinSOC:%f,MaxSOC:%f,MinChargeRate:%f,MaxChargeRate:%f,SMATemperature:%f,SMASOC:%f,SMAChargeRate:%f",MinTemperature,MaxTemperature,MinSOC,MaxSOC,MinChargeRate,MaxChargeRate, SMATemperature, SMASOC, SMAChargeRate);  
    return ComputedDataArray;
}

void ReadBatteryReadingsfromConsole(float* Temperature, float* SOC, float* ChargeRate)
{
    for(int i=0; i<NO_OF_READINGS; i++)
    {
        scanf("%f ,%f ,%f",&ChargeRate[i],&SOC[i],&Temperature[i]);
    }
}

float * BatteryReceiver(float* Temperature, float* SOC, float* ChargeRate)
{
  char ComputedData[50];
  float *ComputedDataArray;
  ReadBatteryReadingsfromConsole(Temperature,SOC,ChargeRate);
  ComputedDataArray = ComputeTheReadings(Temperature,SOC,ChargeRate, ComputedData);
  PrintComputedReadingsOnConsole(ComputedData);
      for(int i=0; i<9; i++)
    {
        printf("%f",ComputedDataArray[i]);
    }
  
  return ComputedDataArray;
 }
