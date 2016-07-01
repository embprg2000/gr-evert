INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_EVERT evert)

FIND_PATH(
    EVERT_INCLUDE_DIRS
    NAMES evert/api.h
    HINTS $ENV{EVERT_DIR}/include
        ${PC_EVERT_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    EVERT_LIBRARIES
    NAMES gnuradio-evert
    HINTS $ENV{EVERT_DIR}/lib
        ${PC_EVERT_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(EVERT DEFAULT_MSG EVERT_LIBRARIES EVERT_INCLUDE_DIRS)
MARK_AS_ADVANCED(EVERT_LIBRARIES EVERT_INCLUDE_DIRS)

