#include <system/risc_assembly_expression.h>
risc_expression* get_expression_51(risc_expression_code execute_code){
    switch (execute_code.read_f3()) { // maybe doing an array would be faster ?
        case O51_ADD: // or sub
            if(execute_code.read_f7() == 0x00){
                return(risc_expression*) (new R_add_expression());
            }else{
                 return(risc_expression*) (new R_sub_expression());
            }
            break;

        case O51_XOR:
            return(risc_expression*) (new R_xor_expression());
            break;

        case O51_OR:
            return(risc_expression*) (new R_or_expression());
            break;

        case O51_AND:
            return(risc_expression*) (new R_and_expression());
            break;

        case O51_SLL:
            return(risc_expression*) (new R_sll_expression());
            break;
        case O51_SRL:
            if(execute_code.read_f7() == 0x00){
                return(risc_expression*) (new R_srl_expression());
            }else{
                 return(risc_expression*) (new R_sra_expression());
            }
            break;
        case O51_SLT:
            return(risc_expression*) (new R_slt_expression());
            break;
        case O51_SLTU:
            return(risc_expression*) (new R_sltu_expression());
            break;
        default:
            printf("un handled expression OPCODE %i/%i \n", execute_code.read_opcode(), execute_code.read_f3());
    }
    return nullptr;
}

risc_expression* get_expression_19(risc_expression_code execute_code){
    switch (execute_code.read_f3()) { // maybe doing an array would be faster ?
        case O19_ADDI:
            return(risc_expression*) (new I_addi_expression());
            break;

        case O19_XORI:
            return(risc_expression*) (new I_xori_expression());
            break;

        case O19_ORI:
            return(risc_expression*) (new I_ori_expression());
            break;

        case O19_ANDI:
            return(risc_expression*) (new I_andi_expression());
            break;

        case O19_SLLI:
            return(risc_expression*) (new I_slli_expression());
            break;
        case O19_SRLI:
            if(execute_code.I_read_imm() == 0x20){
                return(risc_expression*) (new I_srli_expression());
            }else{
                 return(risc_expression*) (new I_srai_expression());
            }
            break;
        case O19_SLTI:
            return(risc_expression*) (new I_slti_expression());
            break;
        case O19_SLTIU:
            return(risc_expression*) (new I_sltiu_expression());
            break;
        default:
                printf("un handled expression OPCODE %i/%i \n", execute_code.read_opcode(), execute_code.read_f3());
    }
    return nullptr;
}

risc_expression* get_expression_3(risc_expression_code execute_code){
    switch (execute_code.read_f3()) { // maybe doing an array would be faster ?
        case OP3_LB:
            return(risc_expression*) (new I_lb_expression());
            break;

        case OP3_LH:
            return(risc_expression*) (new I_lh_expression());
            break;

        case OP3_LW:
            return(risc_expression*) (new I_lw_expression());
            break;

        case OP3_LBU:
            return(risc_expression*) (new I_lbu_expression());
            break;

        case OP3_LHU:
            return(risc_expression*) (new I_lhu_expression());
            break;

        default:
                printf("un handled expression OPCODE %i/%i \n", execute_code.read_opcode(), execute_code.read_f3());
    }
    return nullptr;
}
risc_expression* get_expression_35(risc_expression_code execute_code){
    switch (execute_code.read_f3()) { // maybe doing an array would be faster ?
        case OP35_SB:
            return(risc_expression*) (new S_sb_expression());
            break;

        case OP35_SH:
            return(risc_expression*) (new S_sh_expression());
            break;

        case OP35_SW:
            return(risc_expression*) (new S_sw_expression());
            break;


        default:
                printf("un handled expression OPCODE %i/%i \n", execute_code.read_opcode(), execute_code.read_f3());
    }
    return nullptr;
}
risc_expression* get_expression_99(risc_expression_code execute_code){
    switch (execute_code.read_f3()) { // maybe doing an array would be faster ?
        case OP99_BEQ:
            return(risc_expression*) (new B_beq_expression());
            break;
        case OP99_BNE:
            return(risc_expression*) (new B_bne_expression());
            break;
        case OP99_BLT:
            return(risc_expression*) (new B_blt_expression());
            break;
        case OP99_BGE:
            return(risc_expression*) (new B_bge_expression());
            break;
        case OP99_BLTU:
            return(risc_expression*) (new B_bltu_expression());
            break;
        case OP99_BGEU:
            return(risc_expression*) (new B_bgeu_expression());
            break;
        default:
                printf("un handled expression OPCODE %i/%i \n", execute_code.read_opcode(), execute_code.read_f3());
    }
    return nullptr;
}
risc_expression* get_expression_MISC(risc_expression_code execute_code){
    switch (execute_code.read_opcode()) { // maybe doing an array would be faster ?
        case OPMISC_JAL:
            return(risc_expression*) (new J_jal_expression());
            break;
        case OPMISC_JALR:
            return(risc_expression*) (new I_jalr_expression());
            break;
        case OPMISC_LUI:
            return(risc_expression*) (new U_lui_expression());
            break;
        case OPMISC_AUIPC:
            return(risc_expression*) (new U_auipc_expression());
            break;
        case OPMISC_ECALL:
            return(risc_expression*) (new I_ecall_expression());
            break;
        default:
                printf("un handled expression OPCODE %i \n", execute_code.read_opcode());
    }
    return nullptr;
}
risc_expression* get_expression(risc_expression_code execute_code){
    if(execute_code.read_opcode() == 0b110011){
        return get_expression_51(execute_code);
    }else if(execute_code.read_opcode() == 0b010011){
        return get_expression_19(execute_code);
    }else if(execute_code.read_opcode() == 0b000011){
        return get_expression_3(execute_code);
    }else {
        return get_expression_MISC(execute_code);
    }
    return 0x0;
}
