cmake_minimum_required(VERSION 3.15)
project(server-side_coursework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_EXTENSIONS OFF)

# Виводити всю відладкову інформацію
set(CMAKE_BUILD_TYPE Debug)

# Шляхи до хедерів
include_directories(
    ${PROJECT_SOURCE_DIR}/src/common
    ${PROJECT_SOURCE_DIR}/src/winsock
    ${PROJECT_SOURCE_DIR}/src/sockets
    ${PROJECT_SOURCE_DIR}/src/connection
    ${PROJECT_SOURCE_DIR}/src/session
)

# Основна програма
add_executable(client 
    src/main.cpp
    src/winsock/winsock_utils.cpp
    src/sockets/socket_utils.cpp
    src/connection/connection_utils.cpp
    src/session/client_session.cpp
)