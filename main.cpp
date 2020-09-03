#include <system/interpreter.h>
#include <future>
#include <cstring>
struct data_argument{
    int argc; char** argv;
};

void classic_start(interpreter* inter, int argc, char** argv){

    inter->load(std::string(argv[1]),argv,argc);
}
int main(int argc, char** argv){


    bool debugging = false;
    for(int i = 0; i < argc; i ++){
        if(strncmp(argv[i], "-con", 4) == 0){
            printf("activated the CONSOLE \n");
            debugging = true;
        }
    }

    data_argument* arg = new data_argument();
    arg->argc = argc;
    arg->argv = argv;
    interpreter main_interpreter = interpreter();
    printf("loading \n");

    printf("loading from %s \n",argv[0]);
    if(argc == 1){
        printf("please enter a binary file");
        return 1;
    }else{
        std::future<void> main_thread = std::async(std::launch::async, classic_start, &main_interpreter, argc, argv);

        //      std::thread main_thread = std::thread(classic_start,main_interpreter, argc, argv);

       //     main_interpreter.main_mutex.unlock();
            main_thread.wait();

    }



    return 0;
}
