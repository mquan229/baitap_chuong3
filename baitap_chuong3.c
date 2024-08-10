#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Hàm đếm số khoảng trắng trong chuỗi
int countSpaces(const char *str) {
    int count = 0;
    while (*str) {
        if (*str == ' ') count++;
        str++;
    }
    return count;
}

// Hàm xóa các khoảng trắng thừa trong chuỗi
void removeExtraSpaces(char *str) {
    char temp[MAX];
    int i = 0, j = 0;

    while (str[i]) {
        // Bỏ qua các khoảng trắng đầu chuỗi
        while (str[i] == ' ' && str[i + 1] == ' ') i++;
        // Sao chép ký tự không phải khoảng trắng
        temp[j++] = str[i++];
    }
    temp[j] = '\0';

    // Xử lý trường hợp chuỗi chỉ có khoảng trắng
    if (temp[0] == ' ') {
        memmove(temp, temp + 1, strlen(temp));
    }

    strcpy(str, temp);
}

// Hàm đổi ký tự đầu tiên của mỗi từ thành chữ in hoa và các ký tự khác thành chữ thường
void capitalizeFirstLetter(char *str) {
    int i = 0;
    while (str[i]) {
        // Đổi ký tự đầu của mỗi từ thành chữ hoa
        if (i == 0 || str[i-1] == ' ') {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
        i++;
    }
}

// Hàm tìm kiếm tên trong chuỗi họ tên
int searchName(const char *fullName, const char *name) {
    char temp[MAX];
    strcpy(temp, fullName);
    removeExtraSpaces(temp);

    char *token = strtok(temp, " ");
    while (token) {
        if (strcmp(token, name) == 0) {
            return 1; // Tìm thấy
        }
        token = strtok(NULL, " ");
    }
    return 0; // Không tìm thấy
}

// Hàm cắt chuỗi họ tên thành chuỗi họ lót và chuỗi tên
void splitName(const char *fullName, char *lastName, char *firstName) {
    char temp[MAX];
    strcpy(temp, fullName);
    removeExtraSpaces(temp);

    char *lastSpace = strrchr(temp, ' ');

    if (lastSpace) {
        *lastSpace = '\0';
        strcpy(lastName, temp);
        strcpy(firstName, lastSpace + 1);
    } else {
        strcpy(lastName, "");
        strcpy(firstName, temp);
    }
}

// Hiển thị menu
void displayMenu() {
    printf("Menu:\n");
    printf("1. Đếm số khoảng trắng trong chuỗi\n");
    printf("2. Xóa khoảng trắng thừa trong chuỗi\n");
    printf("3. Đổi ký tự đầu tiên của mỗi từ thành chữ in hoa và các ký tự khác thành chữ thường\n");
    printf("4. Tìm kiếm tên trong chuỗi họ tên\n");
    printf("5. Cắt chuỗi họ tên thành chuỗi họ lót và chuỗi tên\n");
    printf("0. Thoát\n");
}

int main() {
    char str[MAX];
    char name[MAX];
    char lastName[MAX];
    char firstName[MAX];
    int choice;

    do {
        displayMenu();
        printf("Chọn chức năng: ");
        scanf("%d", &choice);
        getchar(); // Đọc ký tự '\n' còn sót lại trong buffer

        switch (choice) {
            case 1:
                printf("Nhập chuỗi: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại
                printf("Số khoảng trắng trong chuỗi: %d\n", countSpaces(str));
                break;
                
            case 2:
                printf("Nhập chuỗi: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại
                removeExtraSpaces(str);
                printf("Chuỗi sau khi xóa khoảng trắng thừa: '%s'\n", str);
                break;

            case 3:
                printf("Nhập chuỗi: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại
                capitalizeFirstLetter(str);
                printf("Chuỗi sau khi đổi ký tự: '%s'\n", str);
                break;

            case 4:
                printf("Nhập chuỗi họ tên: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại
                printf("Nhập tên cần tìm: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại
                if (searchName(str, name)) {
                    printf("Tên '%s' đã nhập đúng.\n", name);
                } else {
                    printf("Tên '%s' đã nhập sai.\n", name);
                }
                break;

            case 5:
                printf("Nhập chuỗi họ tên: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; // Xóa ký tự '\n' còn sót lại
                splitName(str, lastName, firstName);
                printf("Chuỗi họ lót: '%s'\n", lastName);
                printf("Chuỗi tên: '%s'\n", firstName);
                break;

            case 0:
                printf("Thoát chương trình.\n");
                break;

            default:
                printf("Lựa chọn không hợp lệ.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
