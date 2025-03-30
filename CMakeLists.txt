# CMakeList.txt : CMake project for Hangie, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

# Enable Hot Reload for MSVC compilers if supported.
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
project ("Hangie" VERSION 0.1)
message("PATH  TO MODULE IS " ${CMAKE_SOURCE_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/vcpkg_installed/vcpkg/pkgs/nlohmann-json_x64-windows/share/nlohmann_json)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/vcpkg_installed/vcpkg/pkgs/sqlite3_x64-windows/share/unofficial-sqlite3)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

# Add source to this project's executable.
add_executable (Hangie "src/Hangie.cpp" "src/Duel.cpp" "src/GetTodaysWord.cpp" "resource.rc")
configure_file("src/headerTemplate/Hangie.h.in" ${CMAKE_SOURCE_DIR}/src/headers/Hangie.h)


set(SQLITE_DLL_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/vcpkg/pkgs/sqlite3_x64-windows/debug/bin/sqlite3.dll")

add_custom_command(TARGET Hangie POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${SQLITE_DLL_PATH} $<TARGET_FILE_DIR:Hangie>)

    set(DATA_FOLDER "${CMAKE_BINARY_DIR}/bin/data")
    file(MAKE_DIRECTORY ${DATA_FOLDER})


    set(SQL_DB_FILE "${CMAKE_SOURCE_DIR}/data/sqlite/hangie.db")
    add_custom_command(TARGET Hangie POST_BUILD 
                        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                        ${SQL_DB_FILE} ${DATA_FOLDER})

    set(JSON_DATA_FILE "${CMAKE_SOURCE_DIR}/data/hangie.json")
    add_custom_command(TARGET Hangie POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                        ${JSON_DATA_FILE} ${DATA_FOLDER})



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Hangie PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
# include("$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(Hangie PRIVATE nlohmann_json::nlohmann_json)
find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(Hangie PRIVATE unofficial::sqlite3::sqlite3)
