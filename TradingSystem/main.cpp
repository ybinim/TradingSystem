#include "gmock/gmock.h"
#include "AutoTradingSystem.cpp"
#include <string>
using namespace std;

class KiwerMock : public StockBrocker {
public:
	MOCK_METHOD(void, login, (string id, string pass), (override));
	MOCK_METHOD(void, buy, (string code, int price, int count), (override));
	MOCK_METHOD(void, sell, (string code, int price, int count), (override));
	MOCK_METHOD(int, getPrice, (string code), (override));
};

class NemoMock : public StockBrocker {
public:
	MOCK_METHOD(void, login, (string id, string pass), (override));
	MOCK_METHOD(void, buy, (string code, int price, int count), (override));
	MOCK_METHOD(void, sell, (string code, int price, int count), (override));
	MOCK_METHOD(int, getPrice, (string code), (override));
};

TEST(TestTradingSystem, TEST_KIWER_LOGIN) {
	AutoTradingSystem autoSystem;
	autoSystem.selectStockBrocker("KIWER");
	EXPECT_NO_THROW(autoSystem.login("USER", "PASSWORD"));
}

TEST(TestTradingSystem, TEST_NEMO_LOGIN) {
	AutoTradingSystem autoSystem;
	autoSystem.selectStockBrocker("NEMO");
	EXPECT_NO_THROW(autoSystem.login("USER", "PASSWORD"));
}

TEST(TestTradingSystem, TEST_KIWER_BUY) {
	AutoTradingSystem autoSystem;
	autoSystem.selectStockBrocker("KIWER");
	KiwerMock testMock;
	EXPECT_CALL(testMock, buy("SAMSUNG", 10000, 3)).Times(1);

	autoSystem.buy("SAMSUNG", 10000, 3);
}

TEST(TestTradingSystem, TEST_NEMO_BUY) {
	AutoTradingSystem autoSystem;
	autoSystem.selectStockBrocker("NEMO");
	NemoMock testMock;
	EXPECT_CALL(testMock, buy("SAMSUNG", 10000, 3)).Times(1);

	autoSystem.buy("SAMSUNG", 10000, 3);
}

TEST(TestTradingSystem, TEST_KIWER_SELL) {
	AutoTradingSystem autoSystem;
	autoSystem.selectStockBrocker("KIWER");
	KiwerMock testMock;
	EXPECT_CALL(testMock, sell("SAMSUNG", 12000, 3)).Times(1);

	autoSystem.sell("SAMSUNG", 12000, 3);
}

TEST(TestTradingSystem, TEST_NEMO_SELL) {
	AutoTradingSystem autoSystem;
	autoSystem.selectStockBrocker("NEMO");
	NemoMock testMock;
	EXPECT_CALL(testMock, sell("SAMSUNG", 12000, 3)).Times(1);

	autoSystem.sell("SAMSUNG", 12000, 3);
}



int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}