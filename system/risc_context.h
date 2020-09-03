#pragma once
#include <mutex>
#include <stdint.h>
#include <system/risc_register.h>
class RISC_register;
class RISC_context
{

    uint8_t *ram;
    uint64_t memory_lenght;

public:
    std::mutex *parent_mutex;
    uint64_t read_memory(uint64_t address);
    void write_memory(uint64_t address, uint64_t value);
    bool ended = false;
    // these are used for load and store instructions
    // template T need to be in a header for the compiler
    // or in a different HEADER file
    template <typename T>
    T read_memoryT(uint64_t address)
    {
        if (address >= memory_lenght)
        {
            error("trying to read higher than the memory limit \n");
            return 0;
        }
        T *content = (T *)&ram[address];
        return *content;
    }
    template <typename T>
    void write_memoryT(uint64_t address, T value)
    {
        if (address > memory_lenght)
        {
            error("trying to write higher than the memory limit \n");
            return;
        }
        T *content = (uint64_t *)&ram[address];
        *content = value;
    }
    RISC_register *x_regs[32];
    RISC_register *f_regs[32]; // unused
    uint64_t _current_idx = 0;
    void execute_once();

    RISC_register *get_register(uint32_t id);
    uint64_t stack = 0;
    int init();
    uint64_t next_idx; // used with expression when they need to change the next index
    RISC_context(uint64_t start, void *memory, uint64_t memory_lenght);
    RISC_context();
    void execute();

    void error(std::string error_code);
};
