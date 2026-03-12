cmake_minimum_required(VERSION 3.18.1)

project(SmartRehabML)

# 1. 自動搜尋 cpp 資料夾下所有的 .cpp 和 .h 檔案
# 搜尋所有子目錄下的源碼
file(GLOB_RECURSE LIB_SOURCES "model_layer1/*.cpp" "model_layer2/*.cpp" "bridge.cpp")

add_library(native_ml_lib SHARED ${LIB_SOURCES})

# 關鍵：同時加入兩個資料夾作為標頭檔路徑
target_include_directories(native_ml_lib PRIVATE
    model_layer1
    model_layer2
    .
)
# 4. 連結系統庫
find_library(log-lib log)
target_link_libraries(native_ml_lib ${log-lib})