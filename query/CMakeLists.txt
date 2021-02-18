cmake_minimum_required(VERSION 3.8)
project(vnx-query)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -pthread -Wno-deprecated-declarations")

file(GLOB GENERATED_SOURCE_FILES generated/src/*.cpp)

add_library(vnx_query SHARED
	${GENERATED_SOURCE_FILES}
	src/Query.cpp
)

target_include_directories(vnx_query
	PUBLIC
		include
		generated/include
)

target_link_libraries(vnx_query
	vnx_base
)

install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY generated/include/ DESTINATION include)
install(DIRECTORY interface/ DESTINATION interface/vnx/keyvalue)

install(TARGETS vnx_query DESTINATION lib)
