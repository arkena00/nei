cmake_minimum_required(VERSION 3.12)

project(nei_experimental CXX C)

function(exp_make target_file)
    set(targetname exp_${target_file})

    add_executable(${targetname} ${target_file}.cpp)
    target_link_libraries(${targetname} lib_nei)
    set_target_properties(${targetname} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${NEI_BIN_ROOT}/experimental"
            OUTPUT_NAME  ${target_file})

endfunction()

exp_make(analyser)
