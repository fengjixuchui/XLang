# XLang
![XLang](https://raw.githubusercontent.com/lwingteam/XLang/master/.logo.png)     
`Design By TNiK (TencentQQ:1771284750)`.     
XLang是一个编译器，负责把.x文件编译为可执行文件。     
代码格式：
```
ObjectMode(App);
Import(XCore);
class MyClass{
	public void foo1(){
		Console.out.Write("Hello,World!");
	}
}
class App : Application{
	public void Main(string[] args){
		MyClass c = new MyClass();
		c.foo1();
	}
}
/*
	编译：xlang.exe test.x -o=hello -p+BaseParser
	解释：
	    -o=       --- 输出的文件名（windows上自动加.exe）
		-p+       --- 使用的语法解析器（BaseParser为基础解析器） 
*/
```

# F&Q
F: 为什么你的[个人主页](http://www.github.com/qingyiwebt/ "轻翼的个人主页")已经有了XLang项目，还要在这里再发一份呢？     
Q: 我[个人主页](http://www.github.com/qingyiwebt/ "轻翼的个人主页")的XLang项目是已经弃坑版本，因为我发现[之前的XLang](http://www.github.com/qingyiwebt/XLang "XLang")的分析器有部分缺陷，所以我打算重写。     