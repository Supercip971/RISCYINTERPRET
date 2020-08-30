#pragma once
#include <system/risc_context.h>
#include <system/risc_register.h>
#include <system/risc_expression.h>



class risc_expression_code{


public:
    uint64_t where = 0;
    uint32_t raw_data = 0;

    risc_expression_code();
    risc_expression_code(uint32_t val);

    inline uint8_t read_opcode(){
        return raw_data & 0x7f;
        // 00000000000000000000000001111111
    }

    inline uint8_t read_rd(){
        return (raw_data & 0xf80) >> 7;
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



class risc_expression
{
public:
    risc_expression();

    virtual void execute(RISC_context* context, risc_expression_code code);
};


#define DEFINE_EXPRESSION(name) \
    class name :public risc_expression { \
    public: \
    void execute(RISC_context* context, risc_expression_code code) override; \
    };
// add expression

DEFINE_EXPRESSION(R_add_expression);
DEFINE_EXPRESSION(R_sub_expression);
DEFINE_EXPRESSION(R_xor_expression);
DEFINE_EXPRESSION(R_or_expression);
DEFINE_EXPRESSION(R_and_expression);
DEFINE_EXPRESSION(R_sll_expression);
DEFINE_EXPRESSION(R_srl_expression);
DEFINE_EXPRESSION(R_sra_expression);
DEFINE_EXPRESSION(R_slt_expression);
DEFINE_EXPRESSION(R_sltu_expression);


DEFINE_EXPRESSION(I_addi_expression);
DEFINE_EXPRESSION(I_subi_expression);
DEFINE_EXPRESSION(I_xori_expression);
DEFINE_EXPRESSION(I_ori_expression);
DEFINE_EXPRESSION(I_andi_expression);
DEFINE_EXPRESSION(I_slli_expression);
DEFINE_EXPRESSION(I_srli_expression);
DEFINE_EXPRESSION(I_srai_expression);
DEFINE_EXPRESSION(I_slti_expression);
DEFINE_EXPRESSION(I_sltiu_expression);


DEFINE_EXPRESSION(I_lb_expression);
DEFINE_EXPRESSION(I_lh_expression);
DEFINE_EXPRESSION(I_lw_expression);
DEFINE_EXPRESSION(I_lbu_expression);
DEFINE_EXPRESSION(I_lhu_expression);

DEFINE_EXPRESSION(S_sb_expression);
DEFINE_EXPRESSION(S_sh_expression);
DEFINE_EXPRESSION(S_sw_expression);


DEFINE_EXPRESSION(B_beq_expression);
DEFINE_EXPRESSION(B_bne_expression);
DEFINE_EXPRESSION(B_blt_expression);
DEFINE_EXPRESSION(B_bge_expression);
DEFINE_EXPRESSION(B_bltu_expression);
DEFINE_EXPRESSION(B_bgeu_expression);

DEFINE_EXPRESSION(J_jal_expression);
DEFINE_EXPRESSION(I_jalr_expression);

DEFINE_EXPRESSION(U_lui_expression);
DEFINE_EXPRESSION(U_auipc_expression);


DEFINE_EXPRESSION(I_ecall_expression);
DEFINE_EXPRESSION(I_ebreak_expression);
