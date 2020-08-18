#include "block.hpp"

namespace fence {
	Block::Block(uint32_t index, const std::string data) {
		this->m_index = index;
		this->m_data = data;
		this->m_nonce = -1;
		this->m_time = time(nullptr);
	}


	void Block::add_transaction(Transaction transaction) {
		m_data.append(transaction.to_string());
	}

	std::string Block::get_hash() {
		return m_hash;
	}

	inline std::string Block::calculate_hash() const{
		std::stringstream ss;
		ss << m_index << m_time << m_data << m_nonce << m_prev_hash;

		const std::string src_str = ss.str();

		std::vector<unsigned char> hash(picosha2::k_digest_size);
		picosha2::hash256(src_str.begin(), src_str.end(), hash.begin(), hash.end());
		std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
		return hex_str;
	}

	void Block::mine(uint32_t difficulty){
		std::cout << "mining block " << std::endl;
		std::cout << m_data << std::endl;
		// make a string out of the difficulty
		char* diff = (char*)malloc(sizeof(char) * (difficulty + 1));
		for (int i = 0; i < difficulty; i++)
			diff[i] = '0';
		diff[difficulty] = '\0';
		std::string difficulty_string(diff);

		// hash until we get a valid hash and nonce
		do {
			m_nonce++;
			m_hash = calculate_hash();
		} while (m_hash.substr(0, difficulty) != difficulty_string);

		std::cout << "block mined " << m_hash << std::endl;
		free(diff);
	}
}