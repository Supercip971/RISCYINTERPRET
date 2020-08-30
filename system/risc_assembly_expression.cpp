#include <system/risc_assembly_expression.h>


risc_expression_code::risc_expression_code(){};
risc_expression_code::risc_expression_code(uint64_t val){raw_data = val;};
risc_expression::risc_expression()
{

}




void risc_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not existant code");
}


void R_add_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}

void R_sub_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}

void R_xor_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}

void R_or_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}

void R_and_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}

void R_sll_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}

void R_srl_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}

void R_sra_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}

void R_slt_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}

void R_sltu_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}




void I_addi_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_subi_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_xori_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_ori_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}void I_andi_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_slli_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_srli_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_srai_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_slti_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_sltiu_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
//
void I_lb_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_lh_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_lw_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_lbu_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}void I_lhu_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
//

void S_sb_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void S_sh_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void S_sw_expression::execute(RISC_context* context, risc_expression_code code){
printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());}


//
void B_beq_expression::execute(RISC_context* context, risc_expression_code code){
 printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());}
void B_bne_expression::execute(RISC_context* context, risc_expression_code code){
 printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());}
void B_blt_expression::execute(RISC_context* context, risc_expression_code code){
 printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());}
void B_bge_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void B_bltu_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void B_bgeu_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
//
void J_jal_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_jalr_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
//
void U_lui_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void U_auipc_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
void I_ecall_expression::execute(RISC_context* context, risc_expression_code code){
    printf("error trying to execute an not implemented expression %s \n", typeid(*this).name());
}
