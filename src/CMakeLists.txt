# Build the generator as a separate executable (not included in final binary)
add_executable(generator generator.cpp generator.h)

set(GENERATED_FILES
        ${CMAKE_CURRENT_BINARY_DIR}/wctype_properties.h
        ${CMAKE_CURRENT_BINARY_DIR}/wctype_level1.inc
        ${CMAKE_CURRENT_BINARY_DIR}/wctype_level2.inc
        ${CMAKE_CURRENT_BINARY_DIR}/wctype_table.h
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../unicodedata
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Custom command for running the generator at build time
add_custom_command(
        OUTPUT ${GENERATED_FILES}
        COMMAND generator
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/wctype_properties.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../generated/wctype_properties.h
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/wctype_level1.inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../generated/wctype_level1.inc
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/wctype_level2.inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../generated/wctype_level2.inc
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/wctype_table.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../generated/wctype_table.h
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS generator ${CMAKE_CURRENT_SOURCE_DIR}/../unicodedata/UnicodeData.txt
        COMMENT "Generating wctype lookup tables..."
)

add_custom_target(generate_tables DEPENDS ${GENERATED_FILES})

add_library(mywctype INTERFACE)
target_include_directories(mywctype INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
)
add_dependencies(mywctype generate_tables)

add_executable(size_check_temp EXCLUDE_FROM_ALL test_size.cpp)
target_link_libraries(size_check_temp mywctype)

add_custom_target(check_size
        COMMAND ${CMAKE_COMMAND} -E echo "=== Binary Size Report ==="
        COMMAND size $<TARGET_FILE:size_check_temp> 2>/dev/null || echo "size command not available, using ls:"
        COMMAND ls -lh $<TARGET_FILE:size_check_temp>
        COMMAND ${CMAKE_COMMAND} -E echo ""
        COMMAND ${CMAKE_COMMAND} -E echo "Data section contains lookup tables - level1 and level2"
        DEPENDS size_check_temp
        COMMENT "Checking binary size impact of lookup tables..."
        VERBATIM
)