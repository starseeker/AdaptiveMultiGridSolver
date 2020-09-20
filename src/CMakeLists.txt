add_subdirectory(amgs)

if(WITH_IO)
add_subdirectory(amgs_io)
endif()

if(BUILD_APPS)
add_subdirectory(apps)
add_subdirectory(apps_utils)
endif()