# Flex/Bison
# On Windows, just assume these paths
if (WIN32)
	set(BISON_EXECUTABLE "C:/cygwin64/bin/bison.exe")
	set(FLEX_EXECUTABLE "C:/cygwin64/bin/flex.exe")
endif()

# Find packages
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# Setup bison/flex targets
if(APPLE)
	BISON_TARGET(MyParser calc.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp COMPILE_FLAGS "-d -b calc -p calc")
else()
	BISON_TARGET(MyParser calc.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp COMPILE_FLAGS "-d -b calc -p calc -Wno-deprecated")
endif()
FLEX_TARGET(MyScanner calc.l  ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp COMPILE_FLAGS "-Pcalc -Cem")
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

# If you create new headers/cpp files, add them to these list!
set(SOURCE_FILES
	calc.cpp
)

# Don't change this
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(calc ${SOURCE_FILES}
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
)
