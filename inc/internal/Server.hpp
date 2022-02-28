#pragma once

#include <data/Forward.hpp>

#include <map>

namespace internal {
	class Server {
	private:
		std::map<int, data::UserPtr> mUsers;

	public:
		Server();
		Server(const Server &orig);
		~Server();

		Server &operator=(const Server &orig);

		data::UserPtr addUser(int fd) const;
		bool removeUser(int fd) const;

		data::UserPtr getUser(int fd) const;

	};
} // namespace internal
