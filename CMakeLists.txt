cmake_minimum_required(VERSION 3.10)

project(BattleShips VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(AbilityFabricFolder)
add_subdirectory(AbilityFolder)
add_subdirectory(GameStates)
add_subdirectory(FieldCombined)
add_subdirectory(Holders)
add_subdirectory(ShipCombined)

add_executable(BattleShips
    main.cpp
    Game.cpp
    AbilityManager.cpp
    UserInput.cpp
    SaveManager.cpp
    ConsoleRenderer.cpp
)

target_link_libraries(BattleShips PRIVATE AbilityFabric Abilities GameStates FieldCombined Holders ShipCombined)

target_include_directories(BattleShips PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(MSVC)
    target_compile_options(BattleShips PRIVATE /W4)
else()
    target_compile_options(BattleShips PRIVATE -Wall -Wextra -Wpedantic)
endif()
