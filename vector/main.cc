#include <stdlib.h>
#include "qh_vector.h"


int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。

    qh::vector<int> num_vect;
    num_vect.push_back(1);

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

