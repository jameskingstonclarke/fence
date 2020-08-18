

#include "blockchain.hpp"

namespace fence{
	Blockchain::Blockchain() {
		m_chain = std::vector<Block>();
		m_difficulty = 4;
		auto genesis = Block(0, std::string("genesis"));
		genesis.mine(m_difficulty);
		m_chain.push_back(genesis);
	}

	void Blockchain::add_block(Block block) {
		block.m_prev_hash = m_chain.back().get_hash();
		block.mine(m_difficulty);
		m_chain.push_back(block);
	}
}