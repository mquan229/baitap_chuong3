#include <stdio.h>
#include <string.h>

#define MAX 100

void removeWord(char *str, const char *word) {
    char temp[MAX];
    char *pos;
    
    // Tìm từ cần xóa
    pos = strstr(str, word);
    if (pos == NULL) {
        printf("Từ không được tìm thấy trong chuỗi.\n");
        return;
    }
    
    // Sao chép phần trước từ cần xóa
    strncpy(temp, str, pos - str);
    temp[pos - str] = '\0';
    
    // Sao chép phần sau từ cần xóa
    strcat(temp, pos + strlen(word));
    
    // Cập nhật chuỗi
    strcpy(str, temp);
}

int main() {
    char str[MAX], word[MAX];

    printf("Nhập chuỗi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại

    printf("Nhập từ cần xóa: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại

    removeWord(str, word);
    printf("Chuỗi sau khi xóa: '%s'\n", str);

    return 0;
}
