cmake_minimum_required(VERSION 3.20)

project(miniefi LANGUAGES C CXX)

find_package(UefiNewLib REQUIRED)

add_executable(simplefi
    main.cc

    simplefi/guid.cc
    simplefi/newlib-shim.cc
)

set_target_properties(simplefi PROPERTIES
    OUTPUT_NAME "SIMPLEFI"
    SUFFIX ".EFI"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/esp"
)

target_link_libraries(simplefi PRIVATE UefiNewLib::c_uefi)

target_compile_features(simplefi PRIVATE cxx_std_26)

target_compile_options(simplefi PRIVATE
    -ffreestanding
    -fno-stack-protector
    -fno-builtin
    -mno-red-zone
    -Wall
    -Wextra
)

target_include_directories(simplefi PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(simplefi PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
)

target_link_options(simplefi PRIVATE
    -nostdlib
    -fuse-ld=lld
)

add_custom_command(TARGET simplefi POST_BUILD
    COMMAND llvm-readobj --file-headers $<TARGET_FILE:simplefi>
    COMMENT "Inspecting generated UEFI PE/COFF image"
)
