#include <system/risc_register.h>
#include <stdio.h>
RISC_register::RISC_register()
{

}
void RISC_register::set(uint64_t value){
    base_value = value;
}
uint64_t RISC_register::get(){
    return base_value;
};


std::string RISC_register::get_abi(){
    return std::string("null register"); // oof
}
void  RISC_register::init(){
    base_value = 0; // oof
}



// ------- X0 REGISTER -------

x0_register::x0_register(){
    base_value = 0x0;
}
void x0_register::set(uint64_t value){
    //parent_data->error("trying to change x0 value");
  //  base_value = value;
}

uint64_t x0_register:: get() {
    return 0x0; // everytime x0 is 0
}
std::string x0_register:: get_abi(){

    return std::string("zero");
}

 // ------- X1 REGISTER -------

x1_register::x1_register(){
}
void x1_register::init(){
    base_value = 0;
}
std::string x1_register::get_abi(){
    return std::string("ra");
}

// ------- X2 REGISTER -------

x2_register::x2_register(){
    base_value = 0x0;
}
void x2_register::set(uint64_t value){
    if((value / 16) * 16 != value ){

        parent_data->error("trying to change x2 value with an un aligned address");
    }else if(value == 0){

        parent_data->error("trying to change x2 value with a 0x0 address");
    }else{
        parent_data->stack = value;
    }
  //  base_value = value;
}

uint64_t x2_register:: get() {
    return parent_data->stack; // everytime x0 is 0
}
std::string x2_register:: get_abi(){
    return std::string("sp");
}
void x2_register:: init(){
    base_value = 0;
}
// ------- X3 REGISTER -------

x3_register::x3_register(){
}
void x3_register::init(){
   base_value = 0;
}
std::string x3_register::get_abi(){
   return std::string("gp");
}

// ------- X4 REGISTER -------

x4_register::x4_register(){
}

std::string x4_register::get_abi(){
   return std::string("tp");
}
// ------- X5 REGISTER -------
SIMPLE_REGISTER_CODE(x5_register, "t0");

SIMPLE_REGISTER_CODE(x6_register, "t1");

SIMPLE_REGISTER_CODE(x7_register, "t2");
SIMPLE_REGISTER_CODE(x8_register, "s0/fp");
SIMPLE_REGISTER_CODE(x9_register, "s1");
SIMPLE_REGISTER_CODE(x10_register, "a0");
SIMPLE_REGISTER_CODE(x11_register, "a1");
SIMPLE_REGISTER_CODE(x12_register, "a2");
SIMPLE_REGISTER_CODE(x13_register, "a3");
SIMPLE_REGISTER_CODE(x14_register, "a4");
SIMPLE_REGISTER_CODE(x15_register, "a5");
SIMPLE_REGISTER_CODE(x16_register, "a6");
SIMPLE_REGISTER_CODE(x17_register, "a7");
SIMPLE_REGISTER_CODE(x18_register, "s2");
SIMPLE_REGISTER_CODE(x19_register, "s3");
SIMPLE_REGISTER_CODE(x20_register, "s4");
SIMPLE_REGISTER_CODE(x21_register, "s5");
SIMPLE_REGISTER_CODE(x22_register, "s6");
SIMPLE_REGISTER_CODE(x23_register, "s7");
SIMPLE_REGISTER_CODE(x24_register, "s8");
SIMPLE_REGISTER_CODE(x25_register, "s9");
SIMPLE_REGISTER_CODE(x26_register, "s10");
SIMPLE_REGISTER_CODE(x27_register, "s11");
SIMPLE_REGISTER_CODE(x28_register, "t3");
SIMPLE_REGISTER_CODE(x29_register, "t4");
SIMPLE_REGISTER_CODE(x30_register, "t5");
SIMPLE_REGISTER_CODE(x31_register, "t6");
