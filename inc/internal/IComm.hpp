#pragma once

#include "Interface.hpp"
#include "Message.hpp"

namespace internal {
	struct IComm {
		FT_INTERFACE_PRELUDE(IComm);

		virtual bool sendMessage(int fd, Message message) = 0;
	};
} // namespace internal
