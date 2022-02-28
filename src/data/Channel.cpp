#include <data/Channel.hpp>
#include <data/User.hpp>

namespace data {
	Channel::Channel(std::string name): mName(name) {}

	Channel::Channel(const Channel &orig):
		mName(orig.mName),
		mUsers(orig.mUsers),
		mOperators(orig.mOperators) {

	}

	Channel::~Channel() {
		for (std::set<UserPtr>::iterator it = mUsers.begin(); it != mUsers.end(); ++it) {
			(*it)->channelDestroyed(this);
		}
	}

	Channel &Channel::operator=(const Channel &orig) {
		mName = orig.mName;
		mUsers = orig.mUsers;
		mOperators = orig.mOperators;
		return *this;
	}

	std::string Channel::getName() const {
		return mName;
	}

	bool Channel::isOperator(UserPtr user) const {
		return !!mOperators.count(user);
	}

	bool Channel::userJoin(UserPtr user) {
		try {
			return mUsers.insert(user).second;
		} catch (...) {}
		return false;
	}

	void Channel::userDisconnected(UserPtr user) {
		try {
			mUsers.erase(user);
			mOperators.erase(user);
		} catch (...) {}
	}
} // namespace data
