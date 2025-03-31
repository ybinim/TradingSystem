#include "gmock/gmock.h"
#include "stockbrocker.cpp"

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

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}