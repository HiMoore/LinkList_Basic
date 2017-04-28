#include <stdio.h>
#include <stdlib.h>
#include "Func.h"


int main()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,0};
    LinkList List;
    Init_Head(&List);
    Insert_Head_Head(List, A, 10);
    Insert_iX_Head(List, 5, 999);
    Traver_Head(List);
    Find_Head(List, 999);
    Delete_X_Head(List, 999);
    Traver_Head(List);
    Length_Head(List);
    Destroy_Head(&List);
    return 0;
}
