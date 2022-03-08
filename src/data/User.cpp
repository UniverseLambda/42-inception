#include <data/User.hpp>
#include <data/Channel.hpp>

namespace data {
	User::User(): mFd(-1), mMode(UMODE_NONE) {

	}

	User::User(int fd): mFd(fd), mMode(UMODE_NONE) {}

	User::User(const User &copy):
		mFd(copy.mFd),
		mNickname(copy.mNickname),
		mUsername(copy.mUsername),
		mRealname(copy.mRealname),
		mAuthenticated(copy.mAuthenticated),
		mMode(copy.mMode) {

	}

	User::~User() {}

	User &User::operator=(const User &rhs) {
		mFd = rhs.mFd;
		mNickname = rhs.mNickname;
		mUsername = rhs.mUsername;
		mRealname = rhs.mRealname;
		mAuthenticated = rhs.mAuthenticated;
		mMode = rhs.mMode;

		return *this;
	}

	void User::setNickname(const std::string &nickname) {
		mNickname = nickname;
	}

	void User::setUsername(const std::string &username) {
		mUsername = username;
	}

	void User::setRealname(const std::string &realname) {
		mRealname = realname;
	}

	void User::setAuthenticated(bool authenticated) {
		mAuthenticated = authenticated;
	}

	void User::setMode(UserMode mode, bool addMode) {
		if (addMode) {
			mMode = mMode | mode;
		} else {
			mMode = mMode & (~mode);
		}
	}

	std::string User::getNickname() const {
		return mNickname;
	}

	std::string User::getUsername() const {
		return mUsername;
	}

	std::string User::getRealname() const {
		return mRealname;
	}

	bool User::getAuthenticated() const {
		return mAuthenticated;
	}

	User::UserMode User::getMode() const {
		return mMode;
	}

	bool User::isOperator() const {
		return !!(mMode & UMODE_OPERATOR);
	}

	bool User::channelDestroyed(ChannelPtr channel) {
		return mChannels.erase(channel) != 0;
	}

	bool User::sendMessage(internal::Message message) {
		message.trySetChannel(mNickname);
		std::cout << "MESSAGE TO SEND: " << message << std::endl;
		return false;
	}

	User::UserMode operator|(User::UserMode cm0, User::UserMode cm1) {
		return static_cast<User::UserMode>(static_cast<int>(cm0) | static_cast<int>(cm1));
	}

	User::UserMode operator&(User::UserMode cm0, User::UserMode cm1) {
		return static_cast<User::UserMode>(static_cast<int>(cm0) & static_cast<int>(cm1));
	}

	User::UserMode operator~(User::UserMode cm) {
		return static_cast<User::UserMode>(~(static_cast<int>(cm)));
	}
} // namespace data
