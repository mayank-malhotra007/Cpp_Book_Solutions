
#include<iostream>
#include<algorithm>

int main()
{
    int src1[] = {2,3,4,6,8};
    int src2[] = {1,3,5};
    int dest[8];

    std::merge(src1, src1+5, src2, src2+3, dest);

    for(int x=0; x<8; x++)
    {
        std::cout << dest[x] << " ";
    }

    return 0;
}
