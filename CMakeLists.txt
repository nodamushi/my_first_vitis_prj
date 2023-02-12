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

############################
# https://github.com/Xilinx/XilinxBoardStore
# から Cora Z7-07S のボード定義ファイルをダウンロードする。
# 他のボードを使う場合など、必要なければ不要
############################
FetchContent_Declare(
  xilinxboardstore
  GIT_REPOSITORY https://github.com/Xilinx/XilinxBoardStore.git
  GIT_TAG d4e7c68d16042b32a88790162d9b2b5642ca476b
)
FetchContent_MakeAvailable(xilinxboardstore)
############################

############################
# Vivado のプロジェクトを追加
############################
add_vivado_project(
  sample_design                                    # プロジェクト名
  DESIGN     top.tcl                               # デザインファイル
  TOP        top_wrapper                           # トップモジュール名 (デザインファイルから自動生成)
  BOARD      digilentinc.com:cora-z7-07s:part0:1.0 # Cora Z7-07S を使用
  BOARD_REPO ${xilinxboardstore_SOURCE_DIR}        # ↑でダウンロードした XilinXBoardStoreへのパスを追加
)

############################
# Vitis のプロジェクトを追加
############################
add_vitis_hw_project(
  sample_app                       # プロジェクト名
  XSA  sample_design               # Vivado プロジェクトを指定
  PROC 知らんがな。馬鹿にすんな。  # 知らんがな
  SOURCES src                      # ソースコードディレクトリ
)
