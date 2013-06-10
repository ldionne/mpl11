#=============================================================================
# Setup project
#=============================================================================
project(mpl11 CXX)
cmake_minimum_required(VERSION 2.8)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(MPL11_IS_NESTED FALSE)
else()
    set(MPL11_IS_NESTED TRUE)
endif()


#=============================================================================
# Setup CMake options
#=============================================================================
include(CMakeDependentOption)
option(MPL11_ENABLE_PEDANTIC "Compile with pedantic enabled." ON)
option(MPL11_ENABLE_WERROR   "Fail and stop if a warning is triggered." OFF)
option(MPL11_ENABLE_CXX0X    "Use the -std=c++0x switch if the compiler supports it." ON)
option(MPL11_ENABLE_LIBCXX   "Use the -stdlib=libc++ if the compiler supports it." ON)
CMAKE_DEPENDENT_OPTION(
    MPL11_ENABLE_TESTS "Enable the unit tests. To avoid target name conflicts and cluttering the list of targets, unit tests are disabled when the library is nested inside another project."
    OFF "MPL11_IS_NESTED" # OFF when MPL11_IS_NESTED
    ON                    # ON otherwise
)
CMAKE_DEPENDENT_OPTION(
    MPL11_ENABLE_DOC "Enable the documentation target. To avoid target name conflicts and cluttering the list of targets, this is disabled when the library is nested inside another project."
    OFF "MPL11_IS_NESTED" # OFF when MPL11_IS_NESTED
    ON                    # ON otherwise
)


#=============================================================================
# Check available compiler flags
#=============================================================================
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag(-pedantic                    MPL11_HAS_PEDANTIC_FLAG)
check_cxx_compiler_flag(-std=c++0x                   MPL11_HAS_STDCXX0X_FLAG)
check_cxx_compiler_flag(-stdlib=libc++               MPL11_HAS_STDLIB_LIBCXX_FLAG)
check_cxx_compiler_flag(-W                           MPL11_HAS_W_FLAG)
check_cxx_compiler_flag(-Wall                        MPL11_HAS_WALL_FLAG)
check_cxx_compiler_flag(-Werror                      MPL11_HAS_WERROR_FLAG)
check_cxx_compiler_flag(-Wextra                      MPL11_HAS_WEXTRA_FLAG)
check_cxx_compiler_flag(-Wno-long-long               MPL11_HAS_WNO_LONG_LONG_FLAG)
check_cxx_compiler_flag(-Wno-unused-local-typedefs   MPL11_HAS_WNO_UNUSED_LOCAL_TYPEDEFS_FLAG)
check_cxx_compiler_flag(-Wno-unused-parameter        MPL11_HAS_WNO_UNUSED_PARAMETER_FLAG)
check_cxx_compiler_flag(-Wwrite-strings              MPL11_HAS_WWRITE_STRINGS_FLAG)
check_cxx_compiler_flag(-ftemplate-backtrace-limit=0 MPL11_HAS_FTEMPLATE_BACKTRACE_LIMIT_0)


#=============================================================================
# Setup warning flags
#=============================================================================
macro(append_if condition lst var)
    if (${condition})
        list(APPEND ${lst} ${var})
    endif()
endmacro()
append_if(MPL11_HAS_WALL_FLAG                       MPL11_CXX_WARNING_FLAGS -Wall)
append_if(MPL11_HAS_WEXTRA_FLAG                     MPL11_CXX_WARNING_FLAGS -Wextra)
append_if(MPL11_HAS_W_FLAG                          MPL11_CXX_WARNING_FLAGS -W)
append_if(MPL11_HAS_WNO_UNUSED_LOCAL_TYPEDEFS_FLAG  MPL11_CXX_WARNING_FLAGS -Wno-unused-local-typedefs)
append_if(MPL11_HAS_WNO_UNUSED_PARAMETER_FLAG       MPL11_CXX_WARNING_FLAGS -Wno-unused-parameter)
append_if(MPL11_HAS_WWRITE_STRINGS_FLAG             MPL11_CXX_WARNING_FLAGS -Wwrite-strings)
append_if(MPL11_HAS_WNO_LONG_LONG_FLAG              MPL11_CXX_WARNING_FLAGS -Wno-long-long)
append_if(MPL11_HAS_FTEMPLATE_BACKTRACE_LIMIT_0     MPL11_CXX_WARNING_FLAGS -ftemplate-backtrace-limit=0)

if (MPL11_ENABLE_WERROR)
    append_if(MPL11_HAS_WERROR_FLAG  MPL11_CXX_WARNING_FLAGS -Werror)
    append_if(MPL11_HAS_WX_FLAG      MPL11_CXX_WARNING_FLAGS -WX)
endif()

if (MPL11_ENABLE_PEDANTIC)
    append_if(MPL11_HAS_PEDANTIC_FLAG MPL11_CXX_WARNING_FLAGS -pedantic)
endif()


#=============================================================================
# Setup feature flags
#=============================================================================
if (MPL11_ENABLE_CXX0X AND MPL11_HAS_STDCXX0X_FLAG)
    list(APPEND MPL11_CXX_FEATURE_FLAGS -std=c++0x)
endif()

if (MPL11_ENABLE_LIBCXX AND MPL11_HAS_STDLIB_LIBCXX_FLAG)
    list(APPEND MPL11_CXX_FEATURE_FLAGS -stdlib=libc++)
endif()

# This is the only place where add_definitions is called. Other properties
# are set on a per-target basis.
add_definitions(
    ${MPL11_CXX_WARNING_FLAGS}
    ${MPL11_CXX_FEATURE_FLAGS}
)


#=============================================================================
# Setup the library
#=============================================================================
include_directories(include)


#=============================================================================
# Setup the documentation
#=============================================================================
if (MPL11_ENABLE_DOC)
    add_subdirectory(doc)
endif()


#=============================================================================
# Setup tests
#=============================================================================
if (MPL11_ENABLE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
