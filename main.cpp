#include <system/interpreter.h>


int main(int argc, char** argv){
    printf("loading \n");

    printf("loading from %s \n",argv[0]);
    if(argc == 1){
        printf("please enter a binary file");
        return 1;
    }else{
        interpreter interpret;
        interpret.load(std::string(argv[1]));
    }



    return 0;
}
