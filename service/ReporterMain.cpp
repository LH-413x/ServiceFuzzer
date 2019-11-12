//
// Created by alex on 2019/11/12.
//

#include "FuzzerDefs.h"
#include "Reporter.h"
extern "C" {
// This function should be defined by the user.
int     LLVMFuzzerReporter(int argc, char** argv);
}  // extern "C"

ATTRIBUTE_INTERFACE int main(int argc, char **argv, char* skpath) {
    return fuzzer::Reporter(argc, argv, LLVMFuzzerReporter, skpath);
}
