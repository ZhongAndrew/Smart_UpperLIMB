cmake_minimum_required(VERSION 3.18.1)

project(SmartRehabML)

# 1. 自動搜尋 cpp 資料夾下所有的 .cpp 和 .h 檔案
file(GLOB_RECURSE LIB_SOURCES "*.cpp" "*.h" "*.c")

# 2. 定義你的機器學習庫
add_library(native_ml_lib SHARED ${LIB_SOURCES})

# 3. 指定標頭檔搜尋路徑（目前都在 cpp 資料夾下）
target_include_directories(native_ml_lib PRIVATE .)

# 4. 連結系統庫
find_library(log-lib log)
target_link_libraries(native_ml_lib ${log-lib})