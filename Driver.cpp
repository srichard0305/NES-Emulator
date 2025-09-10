#include <iostream>
#include "cpu.h"

int main() {

	CPU cpu;

	// test
	std::vector<uint8_t> vec = { 0xa9, 0xc0, 0xaa, 0xe8, 0x00 };

	cpu.fetch_decode_cycle(vec);

	return 0;
}

