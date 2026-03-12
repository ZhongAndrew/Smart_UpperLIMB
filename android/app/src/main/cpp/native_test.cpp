#include <stdint.h>

extern "C" {
// 加上 __attribute__ 確保函式不會被優化掉且外部可見
__attribute__((visibility("default"))) __attribute__((used))
int32_t test_connection(int32_t input_value) {
    // 簡單的回傳測試：輸入什麼，加 100 後回傳
    return input_value + 100;
}
}