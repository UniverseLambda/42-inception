#pragma once

#include <string>
#include <set>

#include "Forward.hpp"

namespace data {
	class Channel {
		enum ChannelMode {
															// Flags
			CMODE_OPERATOR						= 0x001,	// o
			CMODE_PRIVATE						= 0x002,	// p
			CMODE_SECRET						= 0x004,	// s
			CMODE_INVITE						= 0x08,		// i
			CMODE_TOPIC_OP_ONLY					= 0x010,	// t
			CMODE_NO_OUTSIDE_CLIENT				= 0x020,	// n
			CMODE_MODERATED						= 0x040,	// m
			CMODE_LIMIT							= 0x080,	// l
			CMODE_BAN							= 0x100,	// b
			CMODE_SPEAK_ON_MODERATED_CHANNEL	= 0x200,	// v
			CMODE_PASSWORD						= 0x400,	// k
		};

		enum UserMode {
			UMODE_INVISIBLE			= 0x01,
			UMODE_NOTICE_RECEIPT	= 0x02,
			UMODE_WALLOPS_RECEIVER 	= 0x04,
			UMODE_OPERATOR			= 0x08,
		};

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

		void setUserMode();
	};
} // namespace data
