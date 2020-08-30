#include <system/risc_expression.h>


risc_expression_code::risc_expression_code(){};
risc_expression_code::risc_expression_code(uint64_t val){raw_data = val;};
risc_expression::risc_expression()
{

}




void risc_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not existant code");
}


void R_add_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_sub_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_xor_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_or_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_and_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_sll_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_srl_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_sra_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_slt_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_sltu_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}





void R_add_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_add_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_add_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}

void R_add_expression::execute(RISC_context* context, risc_expression_code code){
    context->error("error trying to execute an not implemented expression");
}
