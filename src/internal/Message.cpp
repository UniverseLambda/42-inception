#include <internal/Message.hpp>

namespace internal {
	Message::Message(std::string origin, std::string message):
		mOrigin(origin),
		mMessage(message) {}

	Message::Message(const Message &orig):
		mOrigin(orig.mOrigin),
		mMessage(orig.mMessage) {}

	Message::~Message() {}

	Message &Message::operator=(const Message &orig) {
		mOrigin = orig.mOrigin;
		mMessage = orig.mMessage;

		return (*this);
	}

	std::string Message::getOrigin() const {
		return mOrigin;
	}

	std::string Message::getMessage() const {
		return mMessage;
	}

	std::string Message::getChannel() const {
		return mChannel;
	}

	bool Message::hasChannel() const {
		return !mChannel.empty();
	}

	bool Message::trySetChannel(std::string channel) {
		if (hasChannel()) {
			return false;
		}

		mChannel = channel;

		return true;
	}

} // namespace internal
