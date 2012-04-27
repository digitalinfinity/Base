// BaseTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{ 
    testing::InitGoogleTest(&argc, argv); 
    int i = RUN_ALL_TESTS(); 
    std::getchar(); // keep console window open until Return keystroke
    return i;
}