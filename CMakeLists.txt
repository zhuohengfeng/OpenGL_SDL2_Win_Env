cmake_minimum_required(VERSION 3.15)
project(SDL_Env_Test)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_USE_RELATIVE_PATHS ON)

set(PROJECT_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${PROJECT_OUTPUT_PATH}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_OUTPUT_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  "${PROJECT_OUTPUT_PATH}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#================== SDL =====================
set(SDL2_DIR ${PROJECT_SOURCE_DIR}/SDL2-2.24.0)

# 设置要包含的头文件的路径
include_directories(${SDL2_DIR}/include)

# 设置要关联的库的路径
link_directories(${SDL2_DIR}/bin)

#================== OPENGL ==================

set(GLAD_DIR ${PROJECT_SOURCE_DIR}/openGL/glad)
set(GLFW_DIR ${PROJECT_SOURCE_DIR}/OpenGL/glfw-3.3.3)

link_directories("${GLFW_DIR}/lib-static-ucrt")
include_directories(
        "${GLFW_DIR}/include"
        "${GLAD_DIR}/include")


add_executable(learn_opengl OpenglTest.cpp ${GLAD_DIR}/src/glad.c)
target_link_libraries(learn_opengl glfw3)

#add_custom_command(TARGET learn_opengl PRE_BUILD
#        COMMAND  ${CMAKE_COMMAND} -E remove -f ${PROJECT_OUTPUT_PATH}/glfw3.dll)

add_custom_command(TARGET learn_opengl POST_BUILD
        COMMAND  ${CMAKE_COMMAND} -E copy ${GLFW_DIR}/lib-static-ucrt/glfw3.dll ${PROJECT_OUTPUT_PATH})


#============================================
add_executable(SDL_Env_Test main.cpp)
target_link_libraries(SDL_Env_Test mingw32 SDL2 SDL2main)
