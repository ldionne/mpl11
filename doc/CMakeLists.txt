#=============================================================================
# Setup the documentation
#=============================================================================
find_package(Boost QUIET)
find_package(Doxygen)
if (DOXYGEN_FOUND)
    if (NOT Boost_FOUND)
        message(STATUS "Boost headers were not found. The documentation will still be generated, but several macros will not expand correctly.")
    endif()
    configure_file(Doxyfile.in Doxyfile @ONLY)
    add_custom_target(
        doc
        ${DOXYGEN_EXECUTABLE} Doxyfile
        COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
else()
    message(STATUS "Doxygen not found, the 'doc' target will be unavailable.")
endif()
