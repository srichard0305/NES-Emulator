#pragma once
#include <cstdint>
#include <vector>

class CPU {
	
public:
	uint8_t register_a;
	uint8_t register_x;
	uint8_t status_register;
	uint16_t program_counter;

	CPU();
	void fetch_decode_cycle(const std::vector<uint8_t>& program);
	void lda(uint8_t val);
	void tax();
	void update_zero_and_neg_flag(uint8_t val);
};