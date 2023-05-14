#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c/-w] <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Cannot open file: %s\n", argv[2]);
        return 1;
    }

    int count_characters = 0;
    int count_words = 0;
    if (strcmp(argv[1], "-c") == 0) {
        count_characters = 1;
    } else if (strcmp(argv[1], "-w") == 0) {
        count_words = 1;
    } else {
        printf("Invalid parameter: %s\n", argv[1]);
        return 1;
    }

    int num_chars = 0;
    int num_words = 0;
    char ch;
    int in_word = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (count_characters) {
            num_chars++;
        }
        if (count_words) {
            if (ch == ' ' || ch == '\t' || ch == '\n' || ch == ',' || ch == '.') {
                if (in_word) {
                    num_words++;
                    in_word = 0;
                }
            } else {
                in_word = 1;
            }
        }
    }
    if (count_words && in_word) {
        num_words++;
    }

    if (count_characters) {
        printf("×Ö·ûÊý£º%d\n", num_chars);
    }
    if (count_words) {
        printf("µ¥´ÊÊý£º%d\n", num_words);
    }

    fclose(file);

    return 0;
}

