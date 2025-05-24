include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_executable(test_version test_version.cpp)

target_include_directories(test_version PUBLIC
    ${CMAKE_SOURCE_DIR}/version_lib
    ${CMAKE_BINARY_DIR}/version_lib
)

target_link_libraries(test_version 
    PRIVATE
    gtest_main 
    version_lib
)

set_target_properties(test_version PROPERTIES
CXX_STANDARD 14
CXX_STANDARD_REQUIRED ON
)

add_custom_command(
  TARGET test_version 
  POST_BUILD
  COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Running version tests..."
)

enable_testing()
add_test(NAME version_test COMMAND test_version)