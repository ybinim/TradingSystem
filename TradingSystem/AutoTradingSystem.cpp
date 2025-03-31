#pragma once

#include "StockBrocker.cpp"
#include "KiwerDriver.cpp"
#include "NemoDriver.cpp"
#include <string>
#include <exception>

using namespace std;

class AutoTradingSystem
{
public:
	void selectStockBrocker(string name)
	{
		if (name == "KIWER")
		{
			myBrocker = &kiwer;
		}
		else if (name == "NEMO")
		{
			myBrocker = &nemo;
		}
		else
		{
			throw exception("No such stock broker exists");
		}
	}

	void login(string id, string pass)
	{
		myBrocker->login(id, pass);
	}

private:
	StockBrocker* myBrocker;
	KiwerDriver kiwer;
	NemoDriver nemo;
};