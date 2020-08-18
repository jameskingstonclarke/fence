#pragma once
#include <string>
#include <sstream>

namespace fence{
	class Transaction {
	public:
		Transaction(std::string from, std::string to, std::string amount);
		std::string to_string() const;
	private:
		std::string m_from;
		std::string m_to;
		std::string m_amount;
	};
}