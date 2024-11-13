#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

int hasThreeConsecutiveExclamations(const char* line) {
    for (int i = 0; line[i + 2] != '\0'; i++) {
        if (line[i] == '!' && line[i + 1] == '!' && line[i + 2] == '!') {
            return 1;  
        }
    }
    return 0;  
}

int checkFileForExclamations(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Не вдалося відкрити файл: %s\n", filename);
        return 0;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (hasThreeConsecutiveExclamations(line)) {
            fclose(file);
            return 1;  
        }
    }

    fclose(file);
    return 0;  
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* filename = "t.txt";

    if (checkFileForExclamations(filename)) {
        printf("У файлі знайдено групу з трьох знаків оклику '!!!'.\n");
    }
    else {
        printf("У файлі НЕ знайдено групу з трьох знаків оклику '!!!'.\n");
    }

    return 0;
}
