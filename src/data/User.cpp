#include <data/User.hpp>
#include <data/Channel.hpp>

namespace data {
	User::User(): mFd(-1) {

	}

	User::User(int fd): mFd(fd) {}

	User::User(const User &copy):
		mFd(copy.mFd),
		mNickname(copy.mNickname),
		mUsername(copy.mUsername),
		mRealname(copy.mRealname),
		mAuthenticated(copy.mAuthenticated) {

	}

	User::~User() {}

	User &User::operator=(const User &rhs) {
		mFd = rhs.mFd;
		mNickname = rhs.mNickname;
		mUsername = rhs.mUsername;
		mRealname = rhs.mRealname;
		mAuthenticated = rhs.mAuthenticated;

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

	bool User::channelDestroyed(ChannelPtr channel) {
		return mChannels.erase(channel) != 0;
	}

	bool User::sendMessage(internal::Message message) {
		message.trySetChannel(mNickname);
		return false;
	}
} // namespace data
