#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "SendBatteryReport.h"

TEST_CASE("Check Battery status sending count")
{ 
PrintBatteryStatus(50,2);
}

