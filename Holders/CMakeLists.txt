add_library(Holders STATIC
    LogHolder.cpp
)

target_include_directories(Holders PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})