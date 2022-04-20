#ifndef SendBatteryReport_h
#define SendBatteryReport_h

void printOnConsole(char *Data);
float ReadBatteryCR(int location,int BatteryNo);
int ReadBatterySOC(int location,int BatteryNo);
int ReadBatteryTemp(int location,int BatteryNo);
void ReadBatteryStatus(int Location,int BatteryPos,char* FormatOPData);
int PrintBatteryStatus(int NoofReadings, int TotalNoOfBattery);

#endif
