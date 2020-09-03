#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>
#define MAX_FILE_SIZE 100000000
#include <elf.h>
#include <future>
#include <mutex>
#include <system/risc_context.h>
class interpreter
{

    Elf64_Ehdr *header;
    uint8_t *interpreter_ram;
    uint8_t *interpreter_raw_data;
    uint64_t ram_size = 0x1000000; // 16m default ram size
    uint64_t data_lenght;
    uint64_t start_addr;
    RISC_context context;
    bool use_little_endian = false;
    void swap_little_endian();
    void load_segment(uint64_t source, uint64_t size, uint64_t dest, uint64_t destsize);

public:
    interpreter();

    void load_elf();
    void init_ram();

    void start();
    void load(std::string file_path, char **argv, int argc);
};

#endif // INTERPRETER_H
