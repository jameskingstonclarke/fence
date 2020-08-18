#include "transaction.hpp"

namespace fence {
	Transaction::Transaction(std::string from, std::string to, std::string amount) : m_from(from), m_to(to), m_amount(amount){}


	std::string Transaction::to_string() const {
		std::stringstream ss;
		ss << m_to << m_from << m_amount;
		return ss.str();
	}
}