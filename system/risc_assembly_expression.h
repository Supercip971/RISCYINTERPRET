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
    static inline int32_t sign_extend32(uint32_t value, int signed_bit)
    {
        int32_t ret = value;
        int bit_position = 0;
        int32_t sign = (value >> signed_bit) & 1;
        for (bit_position = signed_bit; bit_position <= 31; bit_position++) {
            ret |= (sign << bit_position);
        }
        return ret;
    }
    inline uint64_t x(int lo, int len) { return (raw_data >> lo) & ((uint64_t(1) << len)-1); }
    uint64_t xs(int lo, int len) { return int64_t(raw_data) << (64-lo-len) >> (64-len); }
    inline uint64_t read_data(uint64_t from, uint64_t lenght){
        uint64_t result = raw_data;
        raw_data >>= lenght;
        return result;
    }
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

    inline uint32_t I_read_imm(){
        return (raw_data & 0b1111111111100000000000000000000) >> 20;
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
    inline uint8_t U_read_imm(){
        return (raw_data>> 12) & 0xfffff ;
       // 11111110000000000000000000000000
       // 11111111111111111111000000000000
    }


    // here i put every odd thing, when i see them i want to die


    inline uint32_t UJ_read_imm(){
        uint32_t result = 0;
       result  = ( raw_data >> 21) & 0x3ff; // 10 bits
       result |= ((raw_data >> 20) & 0x1) << 10; // 1 bit
       result |= ((raw_data >> 12) & 0xff) << 11; // 8 bit
       result |= ((raw_data >> 31) & 0x1) << 19; // 1 bit
        return result;
    }
    inline uint32_t B_read_imm(){
        uint32_t result = 0;

         result  = ((raw_data >> (31 - 12)) & (1 << 12));
         result |= ((raw_data >> (25 - 5))  & 0x7e0);
         result |= ((raw_data >> (8 - 1))   & 0x1e);
         result |= ((raw_data << (11 - 7))  & (1 << 11));
         result |= ( raw_data << 19) >> 19;

         return result;
    }


    // ---- compressed ----


    inline uint16_t C_read_op(){
        return (raw_data & 0x3);
        // 0000000000000011
    }
    inline uint16_t CSLW_read_rds2(){
        return (raw_data & 0x1c) >> 2;
        // 0000000000011100
    }
    inline uint16_t CSL_read_limm(){ // funct3 with inter register operation
        return (raw_data & 0x60) >> 5;
        // 0000000001100000
    }inline uint16_t CSLB_read_rs1(){
        return (raw_data & 0x380) >> 7;
        // 0000001110000000
    }inline uint16_t CSL_read_himm(){  // funct3 with inter register operation
        return (raw_data & 0x1c00) >> 10;
        // 0001110000000000
    }inline uint16_t CISWLSBJ_read_funct3(){ // yeah everything but no CR why ?
        return (raw_data & 0xe000) >> 13;
        // 1110000000000000
    }inline uint16_t CR_read_funct4(){ // yeah everything but no CR why ?
        return (raw_data & 0b1111000000000000) >> 12;
        // 1111000000000000
    }
    inline uint16_t CS_read_funct6(){
        return (raw_data & 0xfc00) >> 10;
        // 1111110000000000
    }

    inline uint16_t CRISB_read_limm(){ // or rs2
        return (raw_data & 0b0000000001111100) >> 2; // to do : change everything into binary code as it is more readable

    }

    inline uint16_t CI_read_himm(){
        return (raw_data & 0b0001000000000000) >> 12; // to do : change everything into binary code as it is more readable

    }
    inline uint16_t CRI_read_rd(){ // or rs1
        return (raw_data & 0b0000111110000000) >> 7; // to do : change everything into binary code as it is more readable

    }
    inline uint16_t CANDI_read_func2(){ // or rs1
        return (raw_data & 0b0000110000000000) >> 10; // to do : change everything into binary code as it is more readable

    }
    inline uint64_t worst_imm_ever(){
        // when i see that i just want to die >:(
        return (x(3, 2) << 1) + (x(10, 2) << 3) + (x(2, 1) << 5) + (x(5, 2) << 6) + (xs(12, 1) << 8);
    }

    inline uint64_t c_lw_imm() { return (x(6, 1) << 2) + (x(10, 3) << 3) + (x(5, 1) << 6); }
    inline uint64_t c_ld_imm() { return (x(10, 3) << 3) + (x(5, 2) << 6); }
};



class risc_expression
{
public:
    risc_expression();
    inline virtual std::string get_name(){
        return std::string("null risc expression");
    };
    virtual void execute(RISC_context* context, risc_expression_code code);
};


#define DEFINE_EXPRESSION(name) \
    class name :public risc_expression { \
    public: \
    inline std::string get_name() override{ \
         return std::string(#name);   \
    } \
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


DEFINE_EXPRESSION(C_lwsp_expression);
DEFINE_EXPRESSION(C_swsp_expression);
DEFINE_EXPRESSION(C_lw_expression);
DEFINE_EXPRESSION(C_sw_expression);
DEFINE_EXPRESSION(C_j_expression);
DEFINE_EXPRESSION(C_jal_expression);
DEFINE_EXPRESSION(C_jr_expression);
DEFINE_EXPRESSION(C_jalr_expression);
DEFINE_EXPRESSION(C_beqz_expression);
DEFINE_EXPRESSION(C_bnez_expression);
DEFINE_EXPRESSION(C_li_expression);
DEFINE_EXPRESSION(C_lui_expression);
DEFINE_EXPRESSION(C_addi_expression);
DEFINE_EXPRESSION(C_addi16_expression);
DEFINE_EXPRESSION(C_addi4_expression);
DEFINE_EXPRESSION(C_slli_expression);
DEFINE_EXPRESSION(C_srli_expression);
DEFINE_EXPRESSION(C_srai_expression);
DEFINE_EXPRESSION(C_andi_expression);
DEFINE_EXPRESSION(C_mv_expression);
DEFINE_EXPRESSION(C_add_expression);
DEFINE_EXPRESSION(C_and_expression);
DEFINE_EXPRESSION(C_or_expression);
DEFINE_EXPRESSION(C_xor_expression);
DEFINE_EXPRESSION(C_sub_expression);
DEFINE_EXPRESSION(C_nop_expression);
DEFINE_EXPRESSION(C_ebreak_expression);
