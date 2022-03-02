#pragma once

#include <data/Forward.hpp>

#include <map>
#include <string>

namespace internal {
	class Server {
	private:
		std::string mPassword;
		std::map<int, data::UserPtr> mUsers;
		std::map<std::string, data::ChannelPtr> mChannels;

	public:
		Server(std::string password);
	private:
		Server(const Server &orig);
	public:
		~Server();

	private:
		Server &operator=(const Server &orig);

	public:
		data::UserPtr addUser(int fd);
		bool removeUser(int fd);

		data::UserPtr getUser(int fd) const;
		data::ChannelPtr getChannel(std::string name) const;

		data::ChannelPtr getOrCreateChannel(std::string name);
	};
} // namespace internal
