// BaseTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{ 
    testing::InitGoogleTest(&argc, argv); 
    RUN_ALL_TESTS(); 
    std::getchar(); // keep console window open until Return keystroke
}