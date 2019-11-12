//
// Created by alex on 2019/11/12.
//

#ifndef AOSP_SERVICE_FUZZER_REPORTER_H
#define AOSP_SERVICE_FUZZER_REPORTER_H

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>


#include "FuzzerTracePC.h"
#include <iostream>
#include <functional>
#include "Reporter.h"
#endif //AOSP_SERVICE_FUZZER_REPORTER_H

namespace fuzzer{
    int Reporter(int argc, char** argv, std::function<int(int argc, char** argv)>,char* skpath);
}

#endif