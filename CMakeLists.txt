cmake_minimum_required(VERSION 3.14)
project(my_first_vitis_prj)

##################
# Vivado Version #
##################
set(VIVADO_REQUIRED_VERSION 2021.1)


#### おまじない ##########
include(FetchContent)
# https://github.com/nodamushi/vivado_cmake_module
FetchContent_Declare(
  vivado_cmake_module
  GIT_REPOSITORY  https://github.com/nodamushi/vivado_cmake_module.git
  GIT_TAG v0.0.6 # バージョンは最新のを使う
)
FetchContent_MakeAvailable(vivado_cmake_module)
list(APPEND CMAKE_MODULE_PATH ${vivado_cmake_module_SOURCE_DIR})
find_package(HLS)
find_package(Vivado)
find_package(Vitis)
############################

