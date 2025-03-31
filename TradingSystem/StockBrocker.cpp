#pragma once
#include <string>

using std::string;

class StockBrocker
{
public:
	virtual void login(string id, string pass) = 0;
	virtual void buy(string code, int price, int count) = 0;
	virtual void sell(string code, int price, int count) = 0;
	virtual int getPrice(string code) = 0;
};