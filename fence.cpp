
#include "fence.hpp"
#include "log.hpp"
#include "blockchain.hpp"

int main() {
	std::cout << TITLE << " " << VERSION << std::endl;

	fence::Blockchain blockchain;

	auto b = fence::Block(1, "");
	b.add_transaction(fence::Transaction("james", "mum", "55"));

	blockchain.add_block(b);

	return 0;
}