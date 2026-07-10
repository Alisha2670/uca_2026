#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "audit.log"
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int fd;
    char buf[BUF_SIZE];
    ssize_t numRead;
    int line = 1;
    int startOfLine = 1;

    if (argc < 2) {
        printf("Usage:\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
        return -1;
    }

    if (strcmp(argv[1], "--add") == 0) {

        if (argc != 3) {
            printf("Usage: ./auditlog --add \"message\"\n");
            return -1;
        }

        fd = open(LOG_FILE, O_CREAT | O_WRONLY | O_APPEND, 0644);

        if (fd == -1) {
            printf("Error opening log file\n");
            exit(-1);
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }

    else if (strcmp(argv[1], "--view") == 0) {

        fd = open(LOG_FILE, O_RDONLY);

        if (fd == -1) {
            printf("Error opening log file\n");
            exit(-1);
        }

        while ((numRead = read(fd, buf, BUF_SIZE)) > 0) {

            for (int i = 0; i < numRead; i++) {

                if (startOfLine) {

                    char lineNum[20];
                    int len = sprintf(lineNum, "%d: ", line);

                    write(STDOUT_FILENO, lineNum, len);

                    line++;
                    startOfLine = 0;
                }

                write(STDOUT_FILENO, &buf[i], 1);

                if (buf[i] == '\n')
                    startOfLine = 1;
            }
        }

        close(fd);
    }

    else {

        printf("Invalid option\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
        return -1;
    }

    return 0;
}