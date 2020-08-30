#pragma once
#include <stdint.h>
#include <system/risc_assembly_expression.h>
enum OP51_instructions{
    O51_ADD = 0x0,
    O51_SUB = 0x0,
    O51_XOR = 0x4,
    O51_OR = 0x6,
    O51_AND = 0x7,
    O51_SLL = 0x1,
    O51_SRL = 0x5,
    O51_SRA = 0x5,
    O51_SLT = 0x2,
    O51_SLTU = 0x3
};

enum OP19_instructions{
    O19_ADDI = 0x0,
    O19_XORI= 0x4,
    O19_ORI = 0x6,
    O19_ANDI = 0x7,
    O19_SLLI = 0x1,
    O19_SRLI = 0x5,
    O19_SRAI = 0x5,
    O19_SLTI = 0x2,
    O19_SLTIU= 0x3,
};






class risc_expression_code{


public:
    uint64_t where = 0;
    uint32_t raw_data = 0;

    risc_expression_code();
    risc_expression_code(uint64_t val);

    inline uint8_t read_opcode(){
        return raw_data & 0x7f;
        // 00000000000000000000000001111111
    }

    inline uint8_t read_rd(){
        return (raw_data & 0xf8) >> 7;
        // 00000000000000000000111110000000
    }

    inline uint8_t read_f3(){
        return (raw_data & 0x7000) >> 12;
        // 00000000000000000111000000000000
    }

    inline uint8_t read_rs1(){
        return (raw_data & 0xf8000) >> 15;
        // 00000000000011111000000000000000
    }

    inline uint8_t read_rs2(){
        return (raw_data & 0x1f00000) >> 20;
        // 00000001111100000000000000000000
    }

    inline uint8_t read_f7(){
        return (raw_data & 0xfe000000) >> 25;
       // 11111110000000000000000000000000
    }

    inline uint8_t I_read_imm(){
        return (raw_data & 0xfff00000) >> 20;
       // 11111111111100000000000000000000
    }

    inline uint8_t SB_read_imm_start(){
        return (raw_data & 0xf8) >> 7;
        // 00000000000000000000111110000000
    }

    inline uint8_t SB_read_imm_end(){
        return (raw_data & 0xfe000000) >> 25;
       // 11111110000000000000000000000000
    }

    inline uint8_t UJ_read_imm(){
        return (raw_data & 0xfffff000) >> 12;
        // 11111111111111111111000000000000
    }
};



risc_expression* get_expression(risc_expression_code execute_code);
