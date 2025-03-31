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
	AutoTradingSystem()
	{
	}

	AutoTradingSystem(StockBrocker* broker) : myBrocker(broker)
	{
	}

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

	void buy(string code, int price, int count)
	{
		myBrocker->buy(code, price, count);
	}
  
	void sell(string code, int price, int count)
	{
		myBrocker->sell(code, price, count);
  }
  
private:
	StockBrocker* myBrocker;
	KiwerDriver kiwer;
	NemoDriver nemo;
};