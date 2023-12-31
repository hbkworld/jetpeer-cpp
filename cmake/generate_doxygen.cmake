FIND_PACKAGE(Doxygen QUIET)
IF(DOXYGEN_FOUND)
    IF (DOXYGEN_CREATE_GRAPHS EQUAL 1)
        SET (JET_HAVE_DOT YES)
        SET (JET_SET_CALL_GRAPH YES)
        SET (JET_SET_CALLER_GRAPH YES)
    ELSE()
        SET (JET_HAVE_DOT NO)
        SET (JET_SET_CALL_GRAPHi NO)
        SET (JET_SET_CALLER_GRAPH NO)
    ENDIF()
    SET(JET_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
    CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/generated/Doxyfile)
    ADD_CUSTOM_TARGET(doc ALL ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/generated/Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} COMMENT "Generating API documentation with Doxygen" VERBATIM)
ENDIF(DOXYGEN_FOUND)
