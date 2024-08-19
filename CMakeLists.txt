cmake_minimum_required(VERSION 3.10)

# Set the project name
project(FlowCLI)

# Add the executable
add_executable(flow src/main.cpp src/timer.cpp src/task_manager.cpp)

# Include the header files
target_include_directories(flow PUBLIC ${PROJECT_SOURCE_DIR}/include)
