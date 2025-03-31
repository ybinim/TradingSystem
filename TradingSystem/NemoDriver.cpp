#pragma once
#include "StockBrocker.cpp"

class NemoDriver : public StockBrocker
{
public:
	void login(string id, string pass) override
	{

	}

	void but(string code, int price, int count) override
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