
该项目是一道简单的面试题。

该面试题是我们从实际项目中抽出来的，完成一个项目中的局部的一个小功能。

该功能是从原始url中根据提供的参数key将value部分提取出来。

例如：
http://localhost/query.php?name=360&address=beijing

如果给定的参数是那么“name”,那么提取出来的value是“360”
如果给定的参数是那么“address”,那么提取出来的value是“beijing”

具体到实际应用中，有一个url是
“http://www.microsofttranslator.com/bv.aspx?from=&to=zh-chs&xxx&query=http://hnujug.com/”
我们给定的参数key是“query”，因此提取出来的value为“http://hnujug.com/”


项目当前是可以编译通过的，也有一个基本的实现，部分单元测试是对的，但部分单元测试错的。
请实现这个函数：
	void ProxyURLExtractor::Extract( const KeyItems& keys, const std::string& raw_url, std::string& sub_url )
	使得所有的单元测试都通过。

考察点：
	-	核心功能完备
	-	异常分支流程处理正确
	-	构建更多单元测试
	-	尽量优化性能
	-	最好能性能分析报告(gprofile or google profile)

实现完成之后，将工程代码打包(注意包文件名上带上自己的姓名)发给我们，并回答下面的几个问题：
1. 算法的时间复杂度
2. 算法的空间复杂度
3. 是否有资源泄露：内存泄露、文件句柄打开而没有关闭等等

