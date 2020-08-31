#pragma once
#include <system/risc_register.h>
class RISC_register;
class RISC_context
{

    uint8_t* ram;
    uint64_t memory_lenght;
public:

    uint64_t read_memory(uint64_t address);
    void write_memory(uint64_t address, uint64_t value);
    RISC_register* x_regs[32];
    RISC_register* f_regs[32]; // unused
    uint64_t _current_idx = 0;


    RISC_register* get_register(uint32_t id);
    uint64_t stack = 0;
    int init();
    uint64_t next_idx; // used with expression when they need to change the next index
    RISC_context(uint64_t start, void* memory, uint64_t memory_lenght);
    RISC_context();
    void execute();

    void error(std::string error_code);
};

