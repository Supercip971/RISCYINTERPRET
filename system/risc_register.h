#pragma once

#include <stdint.h>
#include <string>
#include <system/risc_context.h>

#define SIMPLE_REGISTER_HEADER(name) \
    class name : public RISC_register { \
    public: \
    name(); \
    std::string get_abi(); \
 };

#define SIMPLE_REGISTER_CODE(name, sabi) \
    name::name(){}; \
std::string name::get_abi(){ return std::string(sabi);};


class RISC_context;
class RISC_register
{
protected:
    uint64_t base_value = 0;
public:
    RISC_context* parent_data;
    RISC_register();
    void error();

    virtual void set(uint64_t value) ;
    virtual uint64_t get() ;
    virtual std::string get_abi();
    virtual void init();


};

// ------- X0 REGISTER -------

class x0_register : public RISC_register {
public:
    x0_register();
    void set(uint64_t value) override;
    uint64_t get() override;
    std::string get_abi() override;

};


// ------- X1 REGISTER -------

class x1_register : public RISC_register {

public:

    x1_register();
    std::string get_abi() override;
    void init() override;

};

// ------- X2 REGISTER -------

class x2_register : public RISC_register {

public:

    x2_register();
    void set(uint64_t value) override;
    uint64_t get() override;
    std::string get_abi() override;
    void init() override;

};

// ------- X3 REGISTER -------


class x3_register : public RISC_register {

public:

    x3_register();
    std::string get_abi() override;
;
    void init() override;

};

// ------- X4 REGISTER -------

class x4_register : public RISC_register {
public:
    x4_register();
    std::string get_abi() override;

};

SIMPLE_REGISTER_HEADER(x5_register);
SIMPLE_REGISTER_HEADER(x6_register);
SIMPLE_REGISTER_HEADER(x7_register);
SIMPLE_REGISTER_HEADER(x8_register);
SIMPLE_REGISTER_HEADER(x9_register);
SIMPLE_REGISTER_HEADER(x10_register);
SIMPLE_REGISTER_HEADER(x11_register);
SIMPLE_REGISTER_HEADER(x12_register);
SIMPLE_REGISTER_HEADER(x13_register);
SIMPLE_REGISTER_HEADER(x14_register);
SIMPLE_REGISTER_HEADER(x15_register);
SIMPLE_REGISTER_HEADER(x16_register);
SIMPLE_REGISTER_HEADER(x17_register);
SIMPLE_REGISTER_HEADER(x18_register);
SIMPLE_REGISTER_HEADER(x19_register);
SIMPLE_REGISTER_HEADER(x20_register);
SIMPLE_REGISTER_HEADER(x21_register);
SIMPLE_REGISTER_HEADER(x22_register);
SIMPLE_REGISTER_HEADER(x23_register);
SIMPLE_REGISTER_HEADER(x24_register);
SIMPLE_REGISTER_HEADER(x25_register);
SIMPLE_REGISTER_HEADER(x26_register);
SIMPLE_REGISTER_HEADER(x27_register);
SIMPLE_REGISTER_HEADER(x28_register);
SIMPLE_REGISTER_HEADER(x29_register);
SIMPLE_REGISTER_HEADER(x30_register);
SIMPLE_REGISTER_HEADER(x31_register);
