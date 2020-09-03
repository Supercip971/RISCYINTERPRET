#include <system/risc_assembly_expression.h>

#include <algorithm>
#include <bitset>
#include <cinttypes>
#include <cstddef>
#include <cstdint>
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

risc_expression_code::risc_expression_code(){};
risc_expression_code::risc_expression_code(uint32_t val) { raw_data = val; };
risc_expression::risc_expression()
{
}

#define NOT_IMPLEMENTED_EXPRESSION(expression)                                                                                       \
    void expression::execute(RISC_context *context, risc_expression_code code)                                                       \
    {                                                                                                                                \
        (void)(code);                                                                                                                \
        (void)(context);                                                                                                             \
        printf("error trying to execute an not implemented expression %s line %lx \n", typeid(*this).name(), context->_current_idx); \
    };

void risc_expression::execute(RISC_context *context, risc_expression_code code)
{
    context->error("error trying to execute an not existant code");
}

NOT_IMPLEMENTED_EXPRESSION(R_add_expression);
NOT_IMPLEMENTED_EXPRESSION(R_sub_expression);
NOT_IMPLEMENTED_EXPRESSION(R_xor_expression);
NOT_IMPLEMENTED_EXPRESSION(R_or_expression);
NOT_IMPLEMENTED_EXPRESSION(R_and_expression);
NOT_IMPLEMENTED_EXPRESSION(R_sll_expression);
NOT_IMPLEMENTED_EXPRESSION(R_srl_expression);
NOT_IMPLEMENTED_EXPRESSION(R_sra_expression);
NOT_IMPLEMENTED_EXPRESSION(R_slt_expression);
NOT_IMPLEMENTED_EXPRESSION(R_sltu_expression);
// I expression
void I_addi_expression::execute(RISC_context *context, risc_expression_code code)
{
    RISC_register *rd = context->get_register(code.read_rd());
    RISC_register *rs1 = context->get_register(code.read_rs1());
    uint64_t imm = code.I_read_imm();
    if (rd == nullptr)
    {
        return; // trying to write to regs 0
    }
    rd->set(rs1->get() + (int)imm);
}

NOT_IMPLEMENTED_EXPRESSION(I_subi_expression);
NOT_IMPLEMENTED_EXPRESSION(I_xori_expression);
NOT_IMPLEMENTED_EXPRESSION(I_ori_expression);
void I_andi_expression::execute(RISC_context *context, risc_expression_code code)
{
    RISC_register *rd = context->get_register(code.read_rd());
    RISC_register *rs1 = context->get_register(code.read_rs1());
    uint64_t imm = code.I_read_imm();
    if (rd == nullptr)
    {
        return; // trying to write to regs 0
    }
    rd->set(rs1->get() & (int)imm);
}
void I_slli_expression::execute(RISC_context *context, risc_expression_code code)
{
    RISC_register *rd = context->get_register(code.read_rd());
    RISC_register *rs1 = context->get_register(code.read_rs1());
    uint64_t imm = code.I_read_imm();
    if (rd == nullptr)
    {
        return; // trying to write to regs 0
    }
    rd->set(rs1->get() << imm);
}
NOT_IMPLEMENTED_EXPRESSION(I_srli_expression);
NOT_IMPLEMENTED_EXPRESSION(I_srai_expression);
NOT_IMPLEMENTED_EXPRESSION(I_slti_expression);
NOT_IMPLEMENTED_EXPRESSION(I_sltiu_expression);

// LOAD expression
void I_lb_expression::execute(RISC_context *context, risc_expression_code code)
{

    auto rs1 = context->get_register(code.read_rs1());
    auto rd = context->get_register(code.read_rd());

    rd->set(context->read_memoryT<uint8_t>(rs1->get() + code.I_read_imm()));
}
void I_lh_expression::execute(RISC_context *context, risc_expression_code code)
{

    auto rs1 = context->get_register(code.read_rs1());
    auto rd = context->get_register(code.read_rd());

    rd->set(context->read_memoryT<uint16_t>(rs1->get() + code.I_read_imm()));
}
void I_lw_expression::execute(RISC_context *context, risc_expression_code code)
{

    auto rs1 = context->get_register(code.read_rs1());
    auto rd = context->get_register(code.read_rd());

    rd->set(context->read_memoryT<uint32_t>(rs1->get() + code.I_read_imm()));
}
NOT_IMPLEMENTED_EXPRESSION(I_lbu_expression);
NOT_IMPLEMENTED_EXPRESSION(I_lhu_expression);

// STORE EXPRESSION

NOT_IMPLEMENTED_EXPRESSION(S_sb_expression);
NOT_IMPLEMENTED_EXPRESSION(S_sh_expression);
NOT_IMPLEMENTED_EXPRESSION(S_sw_expression);

// BRANCH EXPRESSION

NOT_IMPLEMENTED_EXPRESSION(B_beq_expression);
void B_bne_expression::execute(RISC_context *context, risc_expression_code code)
{

    RISC_register *rs1 = context->get_register(code.read_rs1());
    RISC_register *rs2 = context->get_register(code.read_rs2());

    if (rs1->get() != rs2->get())
    {

        context->next_idx = context->_current_idx + (int64_t)risc_expression_code::sign_extend32((code.B_read_imm()) << 1, 8);
    }
    else
    {
    }

    //  printf("jumping (jal) (before %x) %x \n", context->_current_idx, context->next_idx);
}
NOT_IMPLEMENTED_EXPRESSION(B_blt_expression);
NOT_IMPLEMENTED_EXPRESSION(B_bge_expression);
NOT_IMPLEMENTED_EXPRESSION(B_bltu_expression);
void B_bgeu_expression::execute(RISC_context *context, risc_expression_code code)
{

    RISC_register *rs1 = context->get_register(code.read_rs1());
    RISC_register *rs2 = context->get_register(code.read_rs2());

    if (rs1->get() >= rs2->get())
    {

        context->next_idx = context->_current_idx + (int64_t)risc_expression_code::sign_extend32((code.B_read_imm()) << 1, 8);
    }
    else
    {
    }

    //  printf("jumping (jal) (before %x) %x \n", context->_current_idx, context->next_idx);
}
// JUMP EXPRESSION
void J_jal_expression::execute(RISC_context *context, risc_expression_code code)
{

    RISC_register *rd = context->get_register(code.read_rd());
    int64_t dest = code.UJ_read_imm();

    rd->set(context->next_idx);

    context->next_idx = context->_current_idx + risc_expression_code::sign_extend32((dest) << 1, 20);
    //    printf("jumping (jal) (before %x) %x \n", context->_current_idx, context->next_idx);
}

void I_jalr_expression::execute(RISC_context *context, risc_expression_code code)
{

    RISC_register *rd = context->get_register(code.read_rd());
    RISC_register *rs1 = context->get_register(code.read_rs1());
    int64_t dest = code.I_read_imm();
    rd->set(context->next_idx);

    context->next_idx = rs1->get() + dest;
    //    printf("jumping (jalr) (before %x) %x \n", context->_current_idx, context->next_idx);
}

// OTHER

void U_lui_expression::execute(RISC_context *context, risc_expression_code code)
{
    RISC_register *rd = context->get_register(code.read_rd());
    uint64_t imm = code.U_read_imm();

    rd->set(imm);
}

void U_auipc_expression::execute(RISC_context *context, risc_expression_code code)
{
    RISC_register *rd = context->get_register(code.read_rd());
    uint64_t imm = code.U_read_imm();

    rd->set(context->_current_idx + imm);
}

// MISC
void I_ecall_expression::execute(RISC_context *context, risc_expression_code code)
{

    if (syscall(context->x_regs[17]->get() /* a0 */, context->x_regs[10]->get(), context->x_regs[12]->get()) == -1)
    {
        printf("an error has occured with a syscall \n");
    }
}

// COMPRESSED
uint16_t cto_uncompressed_reg(uint16_t register_id)
{
    return register_id + 8;
}
NOT_IMPLEMENTED_EXPRESSION(C_lwsp_expression);
NOT_IMPLEMENTED_EXPRESSION(C_swsp_expression);
void C_lw_expression::execute(RISC_context *context, risc_expression_code code)
{
    if (context->get_register(cto_uncompressed_reg(code.CSLB_read_rs1()))->get() == 0)
    {
        context->next_idx = context->_current_idx + code.worst_imm_ever();
    }
    printf("lw is not fully implemented");
}
NOT_IMPLEMENTED_EXPRESSION(C_sw_expression);
NOT_IMPLEMENTED_EXPRESSION(C_j_expression);
NOT_IMPLEMENTED_EXPRESSION(C_jal_expression);
NOT_IMPLEMENTED_EXPRESSION(C_jr_expression);
NOT_IMPLEMENTED_EXPRESSION(C_jalr_expression);
NOT_IMPLEMENTED_EXPRESSION(C_beqz_expression);

void C_bnez_expression::execute(RISC_context *context, risc_expression_code code)
{
    if (context->get_register(cto_uncompressed_reg(code.CSLB_read_rs1()))->get() == 0)
    {
        context->next_idx = context->_current_idx + code.worst_imm_ever();
    }
}
void C_li_expression::execute(RISC_context *context, risc_expression_code code)
{
    RISC_register *rd = context->get_register(code.CRI_read_rd());
    uint64_t finnal_imm = code.CRISB_read_limm();
    if (code.CI_read_himm() == 1)
    {
        finnal_imm += 32;
    }
    rd->set(finnal_imm);
}
NOT_IMPLEMENTED_EXPRESSION(C_lui_expression);

void C_addi_expression::execute(RISC_context *context, risc_expression_code code)
{
    RISC_register *rd = context->get_register((code.CRI_read_rd()));
    uint64_t finnal_imm = code.CRISB_read_limm();
    if (code.CI_read_himm() == 1)
    {
        finnal_imm += 32;
    }
    rd->set(rd->get() + finnal_imm);
}
NOT_IMPLEMENTED_EXPRESSION(C_addi16_expression);
NOT_IMPLEMENTED_EXPRESSION(C_addi4_expression);
NOT_IMPLEMENTED_EXPRESSION(C_slli_expression);
NOT_IMPLEMENTED_EXPRESSION(C_srli_expression);
NOT_IMPLEMENTED_EXPRESSION(C_srai_expression);
void C_andi_expression::execute(RISC_context *context, risc_expression_code code)
{
    RISC_register *rd = context->get_register(cto_uncompressed_reg(code.CSLB_read_rs1()));
    uint64_t finnal_imm = code.CRISB_read_limm();
    if (code.CI_read_himm() == 1)
    {
        finnal_imm += 32;
    }
    rd->set(rd->get() & finnal_imm);
}
NOT_IMPLEMENTED_EXPRESSION(C_mv_expression);
void C_add_expression::execute(RISC_context *context, risc_expression_code code)
{
    RISC_register *rd = context->get_register((code.CRI_read_rd()));
    RISC_register *rs2 = context->get_register((code.CRISB_read_limm()));
    rd->set(rd->get() + rs2->get());
}
NOT_IMPLEMENTED_EXPRESSION(C_and_expression);
NOT_IMPLEMENTED_EXPRESSION(C_or_expression);
NOT_IMPLEMENTED_EXPRESSION(C_xor_expression);
void C_sub_expression::execute(RISC_context *context, risc_expression_code code)
{
    RISC_register *rd = context->get_register(cto_uncompressed_reg(code.CSLW_read_rds2()));
    RISC_register *rs2 = context->get_register(cto_uncompressed_reg(code.CSLB_read_rs1()));
    rd->set(rd->get() - rs2->get());
}
void C_nop_expression::execute(RISC_context *context, risc_expression_code code)
{
    // just do nothing
}
NOT_IMPLEMENTED_EXPRESSION(C_ebreak_expression);
