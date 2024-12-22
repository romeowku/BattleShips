add_library(FieldCombined STATIC
    Cell.cpp
    GameField.cpp
)

target_include_directories(FieldCombined PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})