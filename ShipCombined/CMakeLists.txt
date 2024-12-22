add_library(ShipCombined STATIC
    Ship.cpp
    ShipManager.cpp
)

target_include_directories(ShipCombined PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})