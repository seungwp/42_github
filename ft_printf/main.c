#include <stdio.h>  // 실제 printf 사용을 위해 필요

int main(void)
{
    void *ptr = NULL; // 널 포인터 (0)

    printf("========== NULL Pointer Test ==========\n");
    
    // 1. %p 테스트: 0x0이 나오는지 (nil)이 나오는지 확인
    int ret_p = printf("Real printf %%p : [%p]\n", ptr);
    printf("-> Return Length: %d (개행 포함)\n\n", ret_p);

    // 2. %s 테스트: (null)이 나오는지 확인 (덤으로 체크)
    int ret_s = printf("Real printf %%s : [%s]\n", NULL);
    printf("-> Return Length: %d (개행 포함)\n", ret_s);

    return (0);
}