#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count_chars(FILE *fp) {
    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        count++;
    }
    return count;
}//字符统计函数

int count_words(FILE *fp) {
    int count = 0;
    int in_word = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c) || c == ',' || c == '.') {
            if (in_word) {
                count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) {
        count++;
    }
    return count;
}//单词统计函数

int main(int argc, char *argv[]) {
    char *filename;
    char *parameter;
    FILE *fp;
    int count;
    if (argc == 3) {
        parameter = argv[1];
        filename = argv[2];
    } else if (argc == 2) {
        parameter = "-c";
        filename = argv[1];
    } else {
        fprintf(stderr, "Usage: %s -c/-w [input_file_name]\n", argv[0]);
        exit(1);
    }
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        exit(1);
    }
    if (strcmp(parameter, "-c") == 0) {
        count = count_chars(fp);
        printf("×Ö·ûÊý£º%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        count = count_words(fp);
        printf("µ¥´ÊÊý£º%d\n", count);
    } else {
        fprintf(stderr, "Unknown parameter: %s\n", parameter);
        exit(1);
    }
    fclose(fp);
    return 0;
}
