请面试者用C++实现这个INI解析器

这个INI解析器可以直接解析内存数据和磁盘文件。
举个简单例子：
	
const char* ini_text= "a=1\nb=2\n"; 
qh::INIParser parser;
if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
    //TODO error process
}

const std::string& a = parser.Get("a", NULL);
assert(a == "1");

std::string b = parser.Get("a", NULL);
assert(b == "2");

const std::string& c = parser.Get("c", NULL);
assert(c == "");

	这个ini_text就是内存数据。调用代码如上。
	硬盘数据可以通过读文件的api读入内存而变为内存数据。

考察点：
-          INI核心解析功能的完备性
-          测试用例覆盖率尽量高
-          代码编程风格比较友好(参考google的C++编程规范)
-          代码可阅读性、可维护性比较好
-          Linux下开发和测试
请将源码、测试用例代码、Makefile等一并打包(注意包文件名上带上自己的姓名)发给我们。
