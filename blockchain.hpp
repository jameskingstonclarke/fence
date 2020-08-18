#pragma once

#include "block.hpp"
#include <vector>

namespace fence {
	class Blockchain{
	public:
		Blockchain();
		void add_block(Block block);
	private:
		uint32_t m_difficulty;
		// this should support forks
		std::vector<Block> m_chain;
		Block get_latest() const;
	};
}