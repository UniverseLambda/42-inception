#include <data/Channel.hpp>
#include <data/User.hpp>

namespace data {
	Channel::Channel(std::string name): mName(name), mMode(CMODE_NONE) {}

	Channel::Channel(const Channel &orig):
		mName(orig.mName),
		mUsers(orig.mUsers),
		mMode(orig.mMode) {}

	Channel::~Channel() {
		for (std::map<UserPtr, UserMode>::iterator it = mUsers.begin(); it != mUsers.end(); ++it) {
			it->first->channelDestroyed(this);
		}
	}

	Channel &Channel::operator=(const Channel &orig) {
		mName = orig.mName;
		mUsers = orig.mUsers;
		return *this;
	}

	std::string Channel::getName() const {
		return mName;
	}

	bool Channel::isOperator(UserPtr user) const {
		try {
			return (mUsers.at(user) & UMODE_OPERATOR) != UMODE_NONE;
		} catch (...) {}

		return false;
	}

	bool Channel::userJoin(UserPtr user) {
		try {
			UserMode mode = (mUsers.empty() ? UMODE_OPERATOR : UMODE_NONE);

			return mUsers.insert(std::make_pair(user, mode)).second;
		} catch (...) {}
		return false;
	}

	void Channel::userDisconnected(UserPtr user) {
		try {
			mUsers.erase(user);
		} catch (...) {}
	}

	bool Channel::setUserMode(UserPtr user, UserMode mode, bool addMode) {
		try {
			UserMode &currentMask = mUsers.at(user);

			if (addMode) {
				currentMask = currentMask | mode;
			} else {
				currentMask = currentMask & (~mode);
			}
		} catch (...) {}

		return false;
	}

	bool Channel::setChannelMode(ChannelMode mode, bool addMode) {
		if (addMode) {
			mMode = mMode | mode;
		} else {
			mMode = mMode & (~mode);
		}
		return false;
	}

	bool Channel::sendMessage(UserPtr sender, internal::Message message) {
		if (mUsers.count(sender) == 0) {
			return false;
		}

		message.trySetChannel(mName);

		for (std::map<UserPtr, UserMode>::iterator it = mUsers.begin(); it != mUsers.end(); ++it) {
			if (it->first != sender) {
				it->first->sendMessage(message);
			}
		}

		return true;
	}

	Channel::UserMode Channel::getUserMode(UserPtr user) const throw(std::out_of_range) {
		return mUsers.at(user);
	}

	Channel::ChannelMode Channel::getChannelMode() const {
		return mMode;
	}

	Channel::ChannelMode operator|(Channel::ChannelMode cm0, Channel::ChannelMode cm1) {
		return static_cast<Channel::ChannelMode>(static_cast<int>(cm0) | static_cast<int>(cm1));
	}

	Channel::ChannelMode operator&(Channel::ChannelMode cm0, Channel::ChannelMode cm1) {
		return static_cast<Channel::ChannelMode>(static_cast<int>(cm0) & static_cast<int>(cm1));
	}

	Channel::ChannelMode operator~(Channel::ChannelMode cm) {
		return static_cast<Channel::ChannelMode>(~(static_cast<int>(cm)));
	}

	Channel::UserMode operator|(Channel::UserMode um0, Channel::UserMode um1) {
		return static_cast<Channel::UserMode>(static_cast<int>(um0) | static_cast<int>(um1));
	}

	Channel::UserMode operator&(Channel::UserMode um0, Channel::UserMode um1) {
		return static_cast<Channel::UserMode>(static_cast<int>(um0) & static_cast<int>(um1));
	}

	Channel::UserMode operator~(Channel::UserMode um) {
		return static_cast<Channel::UserMode>(~(static_cast<int>(um)));
	}
} // namespace data
