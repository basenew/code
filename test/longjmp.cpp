#include <stdio.h>
#include <setjmp.h>
jmp_buf j;
void test_longjmp()
{
    longjmp(j, 1);    
    printf("1");
}
int main()
{
    int ret = setjmp(j);
    printf("ret=%d\n", ret);
    {
        test_longjmp();  
    }
           
    printf("3");     
    return 0;
}
