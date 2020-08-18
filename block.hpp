#pragma once
#include <cstdint>
#include <string>
#include <time.h>
#include <sstream>

#include "sha256.hpp"
#include "log.hpp"
#include "transaction.hpp"

namespace fence{
	class Block {
	public:
		Block(uint32_t index, const std::string data);
		void add_transaction(Transaction transaction);
		std::string get_hash();
		void mine(uint32_t difficulty);
		std::string m_prev_hash;
	private:
		inline std::string calculate_hash() const;
		uint32_t m_index;
		int64_t m_nonce;
		std::string m_data;
		std::string m_hash;
		time_t m_time;
	};
}