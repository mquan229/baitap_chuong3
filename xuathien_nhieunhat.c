#include <stdio.h>
#include <string.h>

#define MAX 100

char findMostFrequentChar(const char *str) {
    int freq[256] = {0}; // Mảng đếm tần suất cho các ký tự ASCII
    const char *p = str;
    int maxFreq = 0;
    char mostFrequentChar = '\0';

    // Đếm tần suất xuất hiện của các ký tự
    while (*p) {
        freq[(unsigned char)*p]++;
        p++;
    }

    // Tìm ký tự xuất hiện nhiều nhất
    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostFrequentChar = i;
        }
    }

    return mostFrequentChar;
}

int main() {
    char str[MAX];

    printf("Nhập chuỗi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại

    char mostFrequentChar = findMostFrequentChar(str);
    printf("Ký tự xuất hiện nhiều nhất là: '%c'\n", mostFrequentChar);

    return 0;
}
