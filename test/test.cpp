#include <internal/Server.hpp>
#include <internal/Message.hpp>
#include <data/User.hpp>
#include <data/Channel.hpp>

#include <iostream>
#include <utility>

#define EXEC_TEST(X) { std::cout << "[*] EXECUTING " #X "..." << std::endl; if (!X()) return 1; }

#define test_assert_equal(V, X) if (!(V == X)) {std::cerr << __FILE__ << ":" << __LINE__ << ": " << __FUNCTION__ << " failed (failed assertion)" << std::endl; std::abort(); }

bool test_user() {
	try {
		data::User user;

		// Testing default values
		test_assert_equal(user.getNickname().empty(), true);
		test_assert_equal(user.getUsername().empty(), true);
		test_assert_equal(user.getRealname().empty(), true);
		test_assert_equal(user.getAuthenticated(), false);

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

		test_assert_equal(user.channelDestroyed(NULL), false);
		test_assert_equal(user.channelDestroyed(reinterpret_cast<data::ChannelPtr>(0xDEADBEAF)), false);
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

	return 0;
}
