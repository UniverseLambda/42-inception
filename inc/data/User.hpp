#pragma once

#include <string>

namespace data {
	enum UserPrivilege {
		PRIV_USER,
		PRIV_OPERATOR,
	};

	class User {
	private:
		int mFd;
		std::string mUsername;
		std::string mNickname;
		UserPrivilege mPrivilege;

	public:
		User();
		User(int fd);
		User(const User &copy);
		~User();

		User &operator=(const User &rhs);

		void setNickname(const std::string &nickname);
		void setUsername(const std::string &username);
		void setPrivilege(UserPrivilege privilege);

		std::string getNickname() const;
		std::string getUsername() const;
		UserPrivilege setPrivilege() const;
	};
}
