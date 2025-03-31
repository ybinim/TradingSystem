#include "gmock/gmock.h"
#include "AutoTradingSystem.cpp"
#include <string>

using namespace testing;
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

class TradingSystemFixture : public testing::Test {
public:
	AutoTradingSystem autoSystem;
	NemoMock testMock;

	void selectStockBrocker(string type) {
		if (type == "KIWER") {
			autoSystem.selectStockBrocker("KIWER");
		}
		else if (type == "NEMO") {
			autoSystem.selectStockBrocker("NEMO");
		}
	}
};

TEST_F(TradingSystemFixture, TEST_KIWER_LOGIN) {
	selectStockBrocker("KIWER");
	EXPECT_NO_THROW(autoSystem.login("USER", "PASSWORD"));
}

TEST_F(TradingSystemFixture, TEST_NEMO_LOGIN) {
	selectStockBrocker("NEMO");
	EXPECT_NO_THROW(autoSystem.login("USER", "PASSWORD"));
}

TEST_F(TradingSystemFixture, TEST_KIWER_BUY) {
	KiwerMock testMock;
	EXPECT_CALL(testMock, buy("SAMSUNG", 10000, 3)).Times(1);

	AutoTradingSystem autoSystem{ &testMock };

	autoSystem.buy("SAMSUNG", 10000, 3);
}

TEST_F(TradingSystemFixture, TEST_NEMO_BUY) {
	NemoMock testMock;

	EXPECT_CALL(testMock, buy("SAMSUNG", 10000, 3)).Times(1);

	AutoTradingSystem autoSystem{ &testMock };
	autoSystem.buy("SAMSUNG", 10000, 3);
}

TEST_F(TradingSystemFixture, TEST_KIWER_SELL) {
	selectStockBrocker("KIWER");
	EXPECT_CALL(testMock, sell("SAMSUNG", 12000, 3)).Times(1);

	autoSystem.sell("SAMSUNG", 12000, 3);
}

TEST_F(TradingSystemFixture, TEST_NEMO_SELL) {
	selectStockBrocker("NEMO");
	EXPECT_CALL(testMock, sell("SAMSUNG", 12000, 3)).Times(1);

	autoSystem.sell("SAMSUNG", 12000, 3);
}

TEST_F(TradingSystemFixture, TEST_KIWER_GET_PRICE) {
	selectStockBrocker("KIWER");
	EXPECT_CALL(testMock, getPrice("SAMSUNG")).Times(1).WillOnce(Return(3000));

	EXPECT_EQ(3000, autoSystem.getPrice("SAMSUNG"));
}

TEST_F(TradingSystemFixture, TEST_NEMO_GET_PRICE) {
	selectStockBrocker("NEMO");
	EXPECT_CALL(testMock, getPrice("SAMSUNG")).Times(1).WillOnce(Return(3000));

	EXPECT_EQ(3000, autoSystem.getPrice("SAMSUNG"));
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}