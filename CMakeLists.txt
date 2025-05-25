cmake_minimum_required(VERSION 3.20)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1 CACHE INTERNAL "Patch version")
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

project(helloworld VERSION ${PROJECT_VERSION})

add_subdirectory(version_lib)
enable_testing()
add_subdirectory(tests)

add_executable(helloworld main.cpp)

target_include_directories(helloworld PUBLIC
    ${CMAKE_SOURCE_DIR}/version_lib
)

target_link_libraries(helloworld PRIVATE
    version_lib
)

set_target_properties(helloworld PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)

set(CPACK_GENERATOR DEB)
include(CPack)
