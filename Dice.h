

#pragma once
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
class Dice
{
	vector<int>diceno;
public:
	void reset();
	void rolladice();
	int randomgen();
};

