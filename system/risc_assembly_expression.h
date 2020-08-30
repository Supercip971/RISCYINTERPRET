#pragma once
#include <system/risc_context.h>
#include <system/risc_register.h>
#include <system/risc_expression.h>





class risc_expression
{
public:
    risc_expression();

    virtual void execute(RISC_context* context, risc_expression_code code);
};


#define DEFINE_EXPRESSION(name) \
    class name :public risc_expression { \
    public: \
    name();\
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
