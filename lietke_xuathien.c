#include <stdio.h>
#include <string.h>

#define MAX 100

void countCharacterFrequency(const char *str) {
    int freq[256] = {0}; // Mảng đếm tần suất cho các ký tự ASCII
    const char *p = str;

    // Đếm tần suất xuất hiện của các ký tự
    while (*p) {
        freq[(unsigned char)*p]++;
        p++;
    }

    printf("Tần suất xuất hiện của mỗi ký tự:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c': %d lần\n", i, freq[i]);
        }
    }
}

int main() {
    char str[MAX];

    printf("Nhập chuỗi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại

    countCharacterFrequency(str);

    return 0;
}
