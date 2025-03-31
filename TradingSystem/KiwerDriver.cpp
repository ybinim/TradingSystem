#pragma once
#include "StockBrocker.cpp"

class KiwerDriver : public StockBrocker
{
public:
	void login(string id, string pass) override
	{

	}

	void buy(string code, int price, int count) override
	{

	}

	void sell(string code, int price, int count) override
	{

	}

	int getPrice(string code) override
	{
		return 0;
	}
};