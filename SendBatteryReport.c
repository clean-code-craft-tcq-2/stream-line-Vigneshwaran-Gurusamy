#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<string.h>
#include<stdbool.h>
#include "SendBatteryReport.h"
#include "BatteryData.h"



void printOnConsole(char *Data)
{
  printf("\n%s",Data);
}

float ReadBatteryCR(int location,int BatteryNo)
{
  return BAT_CR_Value[BatteryNo][location];
}

int ReadBatterySOC(int location,int BatteryNo)
{
  return BAT_SOC_Value[BatteryNo][location];
}

int ReadBatteryTemp(int location,int BatteryNo)
{
  return BAT_Temp_Value[BatteryNo][location];
}

void ReadBatteryStatus(int Location,int BatteryPos,char* FormatOPData)
{
  float chargeRate = ReadBatteryCR(Location,BatteryPos);
  int SOC =  ReadBatterySOC(Location,BatteryPos);
  int Temp = ReadBatteryTemp(Location,BatteryPos);
  sprintf(FormatOPData,"%2f,%d,%d",chargeRate,SOC,Temp);  
}

int PrintBatteryStatus(int NoofReadings, int TotalNoOfBattery)
{
  char FormatedData[100];
  int batterycount;
  for(int index=0; NoofReadings > index;index++)
  {
    while(TotalNoOfBattery > batterycount)
    {
      ReadBatteryStatus(index,batterycount,FormatedData);
      printOnConsole(FormatedData);
      batterycount++;
    }
    batterycount=0;
  }
  return 50;
}

