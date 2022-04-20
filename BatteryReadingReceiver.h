#define NO_OF_READINGS 50

void PrintComputedReadingsOnConsole(char *ComputedData);
float ComputeSMA(float data[]);
float ComputeMax(float data[]);
float ComputeMin(float data[]);

void ComputeTheReadings(float* Temperature, float* SOC, float* ChargeRate, char *ComputedData, float *ComputedDataArray );
void ReadBatteryReadingsfromConsole(float* Temperature, float* SOC, float* ChargeRate);
float * BatteryReceiver(float* Temperature, float* SOC, float* ChargeRate);
