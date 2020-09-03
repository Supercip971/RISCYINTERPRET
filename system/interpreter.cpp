
#include <fstream>
#include "interpreter.h"
#include <filesystem>
#include <cstdlib>
#include <cstring>
#include <system/risc_context.h>
#include <byteswap.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <cstring>

interpreter::interpreter()
{
}
void interpreter::swap_little_endian(){

}
void interpreter::load_segment(uint64_t source, uint64_t size, uint64_t dest, uint64_t destsize){
    printf("loading segment from %lu(%i lenght) to %i(%i lenght)", source,size,dest, destsize);
    for(int i = 0; i <  size; i++){
        interpreter_ram[dest + i] = interpreter_raw_data[source + i];
    }
    if(size < destsize){
        for(int i = size; i <  destsize; i++){
            interpreter_ram[dest + i] = 0; // zeroing if too much
        }
    }
}
void interpreter::init_ram(){ // to do : set custom ram
    printf("loading ram size %i \n",(int)ram_size );
    interpreter_ram =(uint8_t*)calloc(1, ram_size );

}
void interpreter::load_elf(){

    printf("loading elf \n");
    Elf64_Phdr* p_entry = (Elf64_Phdr*)((uint64_t)interpreter_raw_data + header->e_phoff);
    if(header->e_ident[0x5] == 1){
        printf("file in little endian \n");
        use_little_endian = true;
    }else if(header->e_ident[0x5] == 2){
        printf("file in big endian \n");
        printf("we doesn't support BIG endian for the moment");
        exit(2);
        use_little_endian = false;

    }else{
        printf("invalid endian file");
        exit(2);
    }
    printf("loading elf 1 \n");
        printf("loading elf 2 \n");
    printf("table entry count : %i \n",(int) header->e_phnum);
    printf("loading elf 3 \n");
    for(int table_entry = 0; table_entry < header->e_phnum; table_entry++, p_entry ++ ){

        if (p_entry->p_type == PT_LOAD) {
            printf("loading valid elf entry \n");

            load_segment(p_entry->p_offset, p_entry->p_filesz, p_entry->p_vaddr, p_entry->p_memsz);

            printf("loading valid elf entry OK \n");
        }
    }
}
void interpreter::start(){

   // main_mutex.lock();
    context = RISC_context(start_addr, (void*)interpreter_ram, ram_size);
    printf("loading context \n");
    context.init();
    printf("executing context \n");
  //  main_mutex.unlock();
    context.execute();
}


void interpreter::load(std::string file_path, char** argv, int argc){

    for(int i = 0; i < argc; i++){

    }

    printf("loading %s \n", file_path.c_str());

    std::filesystem::path data{file_path};

    if(std::filesystem::is_regular_file(data)){
        uint64_t file_size = std::filesystem::file_size(data);


        // handle too big file
        if(file_size > MAX_FILE_SIZE){

            printf(" %s is too big :( (max size : %i) \n", file_path.c_str(), MAX_FILE_SIZE);
            return;
        }

        std::ifstream myfile (file_path,  std::ios::in| std::ios::binary| std::ios::ate);
        char* temp_buffer = new char[sizeof (Elf64_Ehdr)];
        myfile.seekg (0, std::ios::beg);
        myfile.read(temp_buffer, sizeof (Elf64_Ehdr));

        header = ((Elf64_Ehdr*)temp_buffer);
        if(header->e_ident[0] == 0x7f &&
              header->e_ident[1] == 'E' &&
              header->e_ident[2] == 'L' &&
              header->e_ident[3] == 'F'){
            if(header->e_machine != EM_RISCV){
               myfile.close();
               printf(" %s is not a RISCV file, it is %i \n", file_path.c_str(), header->e_machine);
               return;
            }else{
                printf("reading file... \n");
                interpreter_raw_data = new uint8_t[file_size];
                myfile.seekg (0, std::ios::beg);
                myfile.read((char*)interpreter_raw_data,file_size);
                ram_size += file_size;
                printf("reading file : OK \n");
                init_ram();
                printf("init ram : OK \n");
                load_elf();
                start_addr = header->e_entry;
                printf("starting at address : %i \n", header->e_entry);

                start();

            }
        }else{
            myfile.close();
            printf(" %s is not a ELF file \n", file_path.c_str());
            return;

        }


    }else{

        printf(" %s is not a regular file \n", file_path.c_str());

        return ;
    }


}
