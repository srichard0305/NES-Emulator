#include "cpu.h"
#include <iostream>

//default constuctor 
CPU::CPU() : register_a(0)
, register_x(0)
, status_register(0)
, program_counter(0) {}

void CPU::lda(uint8_t val) {
	this->register_a = val;
	update_zero_and_neg_flag(register_a);
}

void CPU::tax() {
	this->register_x = this->register_a;
	update_zero_and_neg_flag(register_x);
}

void CPU::update_zero_and_neg_flag(uint8_t val) {
	if (val == 0) 
		this->status_register |= 0b00000010;
	else 
		this->status_register &= 0b11111101;
	

	if ((this->register_a & 0b10000000) != 0) 
		this->status_register |= 0b10000010;
	else 
		this->status_register &= 0b01111111;
	
}

void CPU::fetch_decode_cycle(const std::vector<uint8_t>& program) {

	// infinite loop for executing instructions 
	while (true){

		//fetch opscode
		uint8_t opscode = program.at(this->program_counter);
		this->program_counter += 1;

		switch (opscode) {

		case 0x00:
			return;

		case 0xA9:
		{ 
			uint8_t param = program.at(this->program_counter); 
			this->program_counter += 1;
			lda(param);
			break;
		}

		case 0xAA:
			tax();
			break;
		}

		/////////////////////////////////end of switch //////////////////////////////////////////////

	}

}