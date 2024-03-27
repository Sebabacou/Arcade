cmake_minimum_required(VERSION 3.0)
project(arcade)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Werror -g")


include_directories(src/core)
include_directories(src/common)
include_directories(src/display)
include_directories(src/game)
include_directories(src/errors)


add_executable(arcade
        src/main.cpp
        src/display/IDisplay.hpp
        src/game/IGame.hpp
        src/common/Event.hpp
        src/common/Color.hpp
        src/common/Object.hpp
        src/core/Core.cpp
        src/core/Core.hpp
        src/errors/ErrorHandler.cpp
        src/errors/ErrorHandler.hpp)

TARGET_LINK_LIBRARIES(arcade dl)

add_subdirectory(src/game/template)

add_custom_command(TARGET arcade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:arcade>
        ${PROJECT_SOURCE_DIR}/$<TARGET_FILE_NAME:arcade>)
