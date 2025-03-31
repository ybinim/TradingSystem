#include "gmock/gmock.h"

TEST(TestTradingSystem, TEST_KIWER_LOGIN) {
	StockBrocker brocker;
	brocker.selectStockBrocker("KIWER");
	AutoTradingSystem tradingSystem{ &brocker };
	
	EXPECT_NO_THROW(tradingSystem.login("USER", "PASSWORD"));
}

TEST(TestTradingSystem, TEST_NEMO_LOGIN) {
	StockBrocker brocker;
	brocker.selectStockBrocker("NEMO");
	AutoTradingSystem tradingSystem{ &brocker };

	EXPECT_NO_THROW(tradingSystem.certification("USER", "PASSWORD"));
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}