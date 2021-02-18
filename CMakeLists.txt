cmake_minimum_required(VERSION 3.8)
project(vnx-database)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -pthread -Wno-deprecated-declarations")

add_subdirectory(query)

file(GLOB GENERATED_SOURCE_FILES generated/src/*.cpp)

add_library(vnx_database SHARED
	${GENERATED_SOURCE_FILES}
	src/Server.cpp
)

target_include_directories(vnx_database
	PUBLIC
		include
		generated/include
)

target_link_libraries(vnx_database
	vnx_query vnx_base
)

add_executable(vnx_database_server src/vnx_database_server.cpp)
target_link_libraries(vnx_database_server vnx_database)

install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY generated/include/ DESTINATION include)
install(DIRECTORY interface/ DESTINATION interface/vnx/keyvalue)

install(TARGETS vnx_database DESTINATION lib)
install(TARGETS vnx_database_server DESTINATION bin)
