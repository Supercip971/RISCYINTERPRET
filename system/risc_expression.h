#pragma once
#include <stdint.h>
#include <system/risc_assembly_expression.h>
enum OP51_instructions{ //general 1
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

enum OP19_instructions{ // general Imm
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

enum OP3_instructions{ // load
    OP3_LB = 0x0,
    OP3_LH= 0x1,
    OP3_LW = 0x2,
    OP3_LBU = 0x4,
    OP3_LHU = 0x5,
};

enum OP35_instructions{ // Store
    OP35_SB = 0x0,
    OP35_SH= 0x1,
    OP35_SW = 0x2,
};

enum OP99_instruction{ // branch
    OP99_BEQ = 0x0,
    OP99_BNE = 0x1,
    OP99_BLT = 0x4,
    OP99_BGE = 0x5,
    OP99_BLTU = 0x6,
    OP99_BGEU = 0x7,
};
enum OPMISC_instruction{ // here we only count the OP_code
   OPMISC_JAL = 111,
   OPMISC_JALR  = 103,
    OPMISC_LUI = 55,
    OPMISC_AUIPC = 23,
    OPMISC_ECALL = 115, // with imm = 0x0
    OPMISC_EBREAK = 115, // with imm = 0x1 but we doesn't support break yet
};
enum OPC_instruction{ // here we only count the OP_code
    OP01_LWSP = 2,
    OP01_SWSP = 6,
    OP01_SLLI = 0,
};
class risc_expression;
class risc_expression_code;

risc_expression* get_expression(risc_expression_code execute_code);
