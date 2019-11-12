include_directories(include)
set(src FuzzerTracePC.cpp
        Reporter.cpp
        ReporterMain.cpp)

add_library(Reporter ${src})