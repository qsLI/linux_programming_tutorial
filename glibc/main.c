#include<gnu/libc-version.h>
#include<errno.h>
#include<stdio.h>
#include<fcntl.h>

void gnu_libc_version() {
    const char* v = gnu_get_libc_version();
    // version=2.17
    printf("version=%s\n", v);
}

void test_errno() {
    const char* fd = open('/tmp', O_RDWR+O_CREAT);
    if(fd == -1) {
        // open file failed 14
        int err = errno;
        fprintf(stderr, "open file failed errno=%d, errmsg=%s\n", err, strerror(err));
        // open: Bad address
        perror("open");
    }
}

/* 主函数 */
int main(int argc, char *argv[]) {
    gnu_libc_version();
    test_errno();
    return 0;
}