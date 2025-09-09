#pragma once
#include <cstdint>
class CPU {
	
public:
	uint8_t register_a;
	uint8_t status_register;
	uint16_t program_counter;

	CPU();
	void fetch_decode_cycle() {};
};