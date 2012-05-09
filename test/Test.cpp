// BaseTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <base.h>

using namespace Util;

int main(int argc, char* argv[])
{ 
    testing::InitGoogleTest(&argc, argv); 
    int i = RUN_ALL_TESTS(); 

	Output.Log(L"Sample log output: %d, %d\n", 5, 5);

    std::getchar(); // keep console window open until Return keystroke
    return i;
}