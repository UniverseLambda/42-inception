#pragma once

#include <string>
#include <set>

#include "Forward.hpp"

namespace data {
	class Channel {
	private:
		std::string mName;
		std::set<UserPtr> mUsers;
		std::set<UserPtr> mOperators;

	public:
		Channel(std::string name);
		Channel(const Channel &orig);
		~Channel();

		Channel &operator=(const Channel &orig);

		std::string getName() const;

		bool isOperator(UserPtr user) const;

		bool userJoin(UserPtr user);
		void userDisconnected(UserPtr user);
	};
} // namespace data
