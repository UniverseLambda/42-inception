#pragma once

#include <string>
#include <set>

#include <data/Forward.hpp>

namespace data {
	class User {
	private:
		int mFd;
		std::string mNickname;
		std::string mUsername;
		std::string mRealname;
		bool mAuthenticated;

		std::set<ChannelPtr> mChannels;

	public:
		User();
		User(int fd);
		User(const User &copy);
		~User();

		User &operator=(const User &rhs);

		void setNickname(const std::string &nickname);
		void setUsername(const std::string &username);
		void setRealname(const std::string &realname);
		void setAuthenticated(bool auth);

		std::string getNickname() const;
		std::string getUsername() const;
		std::string getRealname() const;
		bool getAuthenticated() const;

		bool channelDestroyed(ChannelPtr channel);
	};
}
