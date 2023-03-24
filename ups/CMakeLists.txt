# create package configuration and version files
if(DEFINED CETMODULES_CURRENT_PROJECT_NAME)
    process_ups_files()
    cet_cmake_config()
endif()
