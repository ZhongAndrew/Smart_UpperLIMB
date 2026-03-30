cmake_minimum_required(VERSION 3.18.1)
project(native_ml_libs)

# --- 第一層模型庫 (genc) ---
file(GLOB L1_SOURCES "model_layer1/*.cpp")
add_library(native_l1 SHARED ${L1_SOURCES} bridge_l1.cpp)
target_include_directories(native_l1 PRIVATE model_layer1 .)

# --- 第二層模型庫 (genc2) ---
file(GLOB L2_SOURCES "model_layer2/*.cpp")
add_library(native_l2 SHARED ${L2_SOURCES} bridge_l2.cpp)
target_include_directories(native_l2 PRIVATE model_layer2 .)

# 3. 編譯特徵擷取函式庫 (Feature Extractor)
file(GLOB FEATURE_SRC "feature_extractor/*.cpp")
add_library(native_features SHARED bridge_features.cpp ${FEATURE_SRC})
target_link_libraries(native_features log)

# 連結 log 庫
target_link_libraries(native_l1 log)
target_link_libraries(native_l2 log)