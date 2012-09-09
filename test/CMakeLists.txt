
file(
    GLOB_RECURSE
    unit_test_files
    *.cpp
)

add_executable(
    unit-tests
    ${unit_test_files}
)
