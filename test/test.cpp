#include <internal/Server.hpp>
#include <internal/Message.hpp>
#include <data/User.hpp>
#include <data/Channel.hpp>

#include <iostream>
#include <utility>

#define EXEC_TEST(X) { std::cout << "[*] EXECUTING " #X "..." << std::endl; if (!X()) return 1; }

#define test_assert_equal(V, X) if (!((V) == (X))) fail_test(__FILE__, __LINE__, __FUNCTION__, "failed assertion")
#define test_expect_exception(V, X) try { V; fail_test(__FILE__, __LINE__, __FUNCTION__, "exception expected"); } \
									catch (X &e) {(void)e;} \
									catch (...) { fail_test(__FILE__, __LINE__, __FUNCTION__, "wrong exception caught"); }

void fail_test(std::string file, int line, std::string function, std::string reason) {
	std::cerr << file << ":" << line << ": " << function << " failed (" << reason << ")" << std::endl;
	std::abort();
}

bool test_user() {
	try {
		data::User user;

		// Testing default values
		test_assert_equal(user.getNickname().empty(), true);
		test_assert_equal(user.getUsername().empty(), true);
		test_assert_equal(user.getRealname().empty(), true);
		test_assert_equal(user.getAuthenticated(), false);
		test_assert_equal(user.isOperator(), false);
		test_assert_equal(user.getMode(), data::User::UMODE_NONE);

		// Testing setters
		user.setNickname("MDR0");
		test_assert_equal(user.getNickname().empty(), false);
		test_assert_equal(user.getNickname(), "MDR0");

		user.setUsername("MDR1");
		test_assert_equal(user.getUsername().empty(), false);
		test_assert_equal(user.getUsername(), "MDR1");

		user.setRealname("MDR2");
		test_assert_equal(user.getRealname().empty(), false);
		test_assert_equal(user.getRealname(), "MDR2");

		user.setNickname("LoL0");
		test_assert_equal(user.getNickname().empty(), false);
		test_assert_equal(user.getNickname(), "LoL0");

		user.setUsername("LoL1");
		test_assert_equal(user.getUsername().empty(), false);
		test_assert_equal(user.getUsername(), "LoL1");

		user.setRealname("LoL2");
		test_assert_equal(user.getRealname().empty(), false);
		test_assert_equal(user.getRealname(), "LoL2");

		user.setAuthenticated(true);
		test_assert_equal(user.getAuthenticated(), true);
		user.setAuthenticated(true);
		test_assert_equal(user.getAuthenticated(), true);
		user.setAuthenticated(false);
		test_assert_equal(user.getAuthenticated(), false);

		user.setMode(data::User::UMODE_INVISIBLE | data::User::UMODE_OPERATOR, true);
		test_assert_equal(user.getMode(), data::User::UMODE_INVISIBLE | data::User::UMODE_OPERATOR);
		user.setMode(data::User::UMODE_INVISIBLE, false);
		test_assert_equal(user.getMode(), data::User::UMODE_OPERATOR);

		test_assert_equal(user.channelDestroyed(NULL), false);
		test_assert_equal(user.channelDestroyed(reinterpret_cast<data::ChannelPtr>(0xDEADBEAF)), false);
	} catch (...) {
	}

	return true;
}

bool test_channel() {
	try {
		const std::string name = "#nicechannel";
		data::Channel channel(name);

		// Testing default values
		test_assert_equal(channel.getName(), name);
		test_expect_exception(channel.isOperator(NULL), std::out_of_range);
		test_assert_equal(channel.getMode(), data::Channel::CMODE_NONE);

		// Testing setters


	} catch (...) {
		std::cerr << "Caught an exception" << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;

	EXEC_TEST(test_user)
	EXEC_TEST(test_channel)

	return 0;
}
