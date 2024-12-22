add_library(GameStates STATIC
    GameEnemyState.cpp
    GamePlayerState.cpp
)

target_include_directories(GameStates PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})