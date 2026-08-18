cmake_minimum_required(VERSION 3.28)
project(atan2-playground LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependemcies
include(Dependencies.cmake)

# Asset files
set(ASSET_FILES
    Assets/player.png
    Assets/crosshair.png
    Assets/projectile.png
)

# Sources
set(SOURCES
    Source/Main.cpp
    Source/Application.h
    Source/Application.cpp
    Source/Crosshair.h
    Source/Crosshair.cpp
    Source/Player.h
    Source/Player.cpp
    Source/Projectile.h
    Source/Projectile.cpp
    Source/ResourceIdentifiers.h
    Source/ResourceManager.h

    ${ASSET_FILES}
)
add_executable(atan2-playground)
target_sources(atan2-playground PRIVATE ${SOURCES})

# Libraries
target_link_libraries(atan2-playground PRIVATE
    SFML::System
    SFML::Window
    SFML::Graphics
)

# StartUp Project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT atan2-playground)

source_group("Assets" FILES ${ASSET_FILES})

# Copy Assets/ folder to build/ dir
add_custom_command(
    TARGET atan2-playground POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Assets
    $<TARGET_FILE_DIR:atan2-playground>/Assets
)

# Working dir
set_target_properties(atan2-playground PROPERTIES 
    VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:atan2-playground>
)
