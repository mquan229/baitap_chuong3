#include <stdio.h>
#include <string.h>

#define MAX 100

void insertWord(char *str, const char *word, int position) {
    char temp[MAX];
    int len = strlen(str);

    // Kiểm tra vị trí hợp lệ
    if (position < 0 || position > len) {
        printf("Vị trí không hợp lệ.\n");
        return;
    }

    // Tạo chuỗi tạm để chứa phần chuỗi sau vị trí chèn
    strcpy(temp, str + position);

    // Chèn từ vào vị trí chỉ định
    str[position] = '\0';
    strcat(str, word);
    strcat(str, temp);
}

int main() {
    char str[MAX], word[MAX];
    int position;

    printf("Nhập chuỗi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại

    printf("Nhập từ cần chèn: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại

    printf("Nhập vị trí cần chèn: ");
    scanf("%d", &position);

    insertWord(str, word, position);
    printf("Chuỗi sau khi chèn: '%s'\n", str);

    return 0;
}
