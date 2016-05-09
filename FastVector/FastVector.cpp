// FastVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

#include "Arr.h"
#include "ArrUtil.h"
#include "TimeMeasurment.h"
#include "Test.h"

///Written by Piotr Falkowski
std::string AsMemory(unsigned bytes)
{
	std::ostringstream strs;
	if (bytes < 1024)
	{
		strs << (bytes) << " bytes";
	}
	else if (bytes < (1024 * 1024))
	{
		strs << (bytes / 1024) << " Kb";
	}
	else if (bytes < (1024 * 1024 * 1024))
	{
		strs << (bytes / (1024 * 1024)) << " Mb";
	}
	else
	{
		strs << (bytes / (1024 * 1024 * 1024)) << " Gb";
	}
	return strs.str();
}


int main()
{
	auto how_many = 100000000; //381Mb of data, 1 second in release on average new machine
	std::cout << "Test of std::vector<float> adding " << how_many << " elements: " << std::endl;
	Test<float>::STDvectorAdding(how_many);
	std::cout << std::endl << "Press enter to test custom Array: " << std::endl;
	getchar();
	std::cout << "Test of Arr<float> adding " << how_many << " elements: " << std::endl;
	Test<float>::Adding(how_many);
	std::cin.get();
	return 0;
}
