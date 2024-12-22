add_library(Abilities STATIC
    DoubleDamage.cpp
    RandomFire.cpp
    Scanner.cpp
)

target_include_directories(Abilities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
