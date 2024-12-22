add_library(AbilityFabric STATIC
    DoubleDamageFactory.cpp
    RandomFireFactory.cpp
    ScannerFactory.cpp
)

target_include_directories(AbilityFabric PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
