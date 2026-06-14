#pragma once
#include "User.h"
#include "ctime"

class User;

using TimePoint = std::time_t;

struct Comment {
	std::shared_ptr<User> author;
	std::string content;
	TimePoint timeStamp;

	Comment(std::shared_ptr<User> author, std::string content)
		: author(author), content(content), timeStamp(std::time(nullptr)) {}
};

struct HistoryRecord {
	TimePoint timeStamp;
	std::string description;

	explicit HistoryRecord(std::string description) :timeStamp(std::time(nullptr)), description(description){}
};

