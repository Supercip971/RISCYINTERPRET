#include <system/risc_context.h>

RISC_context::RISC_context(uint64_t start, void* memory, uint64_t memory_lenght)
{
    _current_idx = start;
    ram = (uint8_t*) memory;
    this->memory_lenght = memory_lenght;
}

RISC_context::RISC_context()
{

}

void RISC_context::execute(){

}
int RISC_context::init(){
    printf("RISC context loading \n");

    printf("RISC context loading [x] registers  \n");
    x_regs[0] = (RISC_register*)new x0_register();
    x_regs[1] = (RISC_register*)new x1_register();
    x_regs[2] = (RISC_register*)new x2_register();
    x_regs[3] = (RISC_register*)new x3_register();
    x_regs[4] = (RISC_register*)new x4_register();
    x_regs[5] = (RISC_register*)new x5_register();
    x_regs[6] = (RISC_register*)new x6_register();
    x_regs[7] = (RISC_register*)new x7_register();
    x_regs[8] = (RISC_register*)new x8_register();
    x_regs[9] = (RISC_register*)new x9_register();
    x_regs[10] = (RISC_register*)new x10_register();
    x_regs[11] = (RISC_register*)new x11_register();
    x_regs[12] = (RISC_register*)new x12_register();
    x_regs[13] = (RISC_register*)new x13_register();
    x_regs[14] = (RISC_register*)new x14_register();
    x_regs[15] = (RISC_register*)new x15_register();
    x_regs[16] = (RISC_register*)new x16_register();
    x_regs[17] = (RISC_register*)new x17_register();
    x_regs[18] = (RISC_register*)new x18_register();
    x_regs[19] = (RISC_register*)new x19_register();
    x_regs[20] = (RISC_register*)new x20_register();
    x_regs[21] = (RISC_register*)new x21_register();
    x_regs[22] = (RISC_register*)new x22_register();
    x_regs[23] = (RISC_register*)new x23_register();
    x_regs[24] = (RISC_register*)new x24_register();
    x_regs[25] = (RISC_register*)new x25_register();
    x_regs[26] = (RISC_register*)new x26_register();
    x_regs[27] = (RISC_register*)new x27_register();
    x_regs[28] = (RISC_register*)new x28_register();
    x_regs[29] = (RISC_register*)new x29_register();
    x_regs[30] = (RISC_register*)new x30_register();
    x_regs[31] = (RISC_register*)new x31_register();

    for(int i = 0; i < 31; i++){
        x_regs[i]->parent_data = this;
        x_regs[i]->init();
    }
    printf("RISC context loaded [x] registers \n ");

    for(uint32_t i = _current_idx; i <_current_idx+ 100; i+= 4){
        printf("hey : %x\n ", *((uint32_t*)&ram[i]) );
    }

    return 0;
}
void RISC_context::error(std::string error_code){

    printf("[ RISC ] error : %s ", error_code.c_str());

    exit(1);
}