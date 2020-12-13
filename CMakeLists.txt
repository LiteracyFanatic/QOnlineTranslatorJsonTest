cmake_minimum_required(VERSION 3.7.0)

project(QOnlineTranslatorJsonTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Multimedia Network REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(src/QOnlineTranslator)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Network
    Qt5::Multimedia
    QOnlineTranslator::QOnlineTranslator
)
