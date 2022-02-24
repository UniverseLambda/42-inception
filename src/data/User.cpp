#include <data/User.hpp>

namespace data {
	User::User(): mFd(-1) {

	}

	User::User(int fd): mFd(fd) {

	}

	User::User(const User &copy):
		mFd(copy.mFd),
		mUsername(copy.mUsername),
		mNickname(copy.mNickname),
		mPrivilege(copy.mPrivilege) {

	}

	User::~User() {}

	User &User::operator=(const User &rhs) {
		mFd = rhs.mFd;
		mUsername = rhs.mUsername;
		mNickname = rhs.mNickname;
		mPrivilege = rhs.mPrivilege;

		return *this;
	}

	void User::setNickname(const std::string &nickname) {
		mNickname = nickname;
	}

	void User::setUsername(const std::string &username) {
		mUsername = username;
	}

	void User::setPrivilege(UserPrivilege privilege) {
		mPrivilege = privilege;
	}

	std::string User::getNickname() const {
		return mNickname;
	}

	std::string User::getUsername() const {
		return mUsername;
	}

	UserPrivilege User::setPrivilege() const {
		return mPrivilege;
	}
} // namespace data
