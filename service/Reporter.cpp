//
// Created by alex on 2019/11/12.
//
#include "Reporter.h"
#include <thread>

enum{
    INIT,
    REPORT
};

namespace fuzzer{

    TracePC trace;

    void getCoverage(uint8_t* & buf, size_t & size){
        trace.GetTotalPCCoverage();
    }

    int startUnixSocketServer(char* skpath){
        struct sockaddr_un addr;
        uint8_t id;
        int fd,cl,rc;

        if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
            perror("socket error");
            exit(-1);
        }

        memset(&addr, 0, sizeof(addr));
        addr.sun_family = AF_UNIX;

        strncpy(addr.sun_path, skpath, sizeof(addr.sun_path)-1);
        unlink(skpath);

        if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
            perror("bind error");
            exit(-1);
        }

        if (listen(fd, 5) == -1) {
            perror("listen error");
            exit(-1);
        }

        while (1) {
            if ( (cl = accept(fd, NULL, NULL)) == -1) {
                perror("accept error");
                continue;
            }
            rc=read(cl,&id,sizeof(id));
            if (rc != 1) {
                perror("read");
                exit(-1);
            }
            switch (id) {
                case INIT:
                    trace.ResetMaps();
                case REPORT:
                    uint8_t* buffer=nullptr;
                    size_t size=0;
                    getCoverage(buffer,size);
                    write(fd,buffer,size);
                    delete buffer;
            }
        }
    }

    int Reporter(int argc, char** argv, std::function<int(int argc , char** argv)> CB, char* skpath){
        std::thread sock_thread(startUnixSocketServer, skpath);
        int ret = CB(argc, argv);
        sock_thread.join();
        return ret;
    }
}