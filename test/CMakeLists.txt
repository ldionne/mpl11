#=============================================================================
# Setup unit tests
#=============================================================================
file(GLOB_RECURSE MPL11_TEST_SOURCES *.cpp)
add_executable(unit ${MPL11_TEST_SOURCES})
