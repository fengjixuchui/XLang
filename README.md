# XLang
![XLang](https://raw.githubusercontent.com/lwingteam/XLang/master/.logo.png)     
`Design By TNiK (TencentQQ:1771284750)`.     
XLang��һ���������������.x�ļ�����Ϊ��ִ���ļ���     
�����ʽ��
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
	���룺xlang.exe test.x -o=hello -p+BaseParser
	���ͣ�
	    -o=       --- ������ļ�����windows���Զ���.exe��
		-p+       --- ʹ�õ��﷨��������BaseParserΪ������������ 
*/
```

# F&Q
F: Ϊʲô���[������ҳ](http://www.github.com/qingyiwebt/ "����ĸ�����ҳ")�Ѿ�����XLang��Ŀ����Ҫ�������ٷ�һ���أ�     
Q: ��[������ҳ](http://www.github.com/qingyiwebt/ "����ĸ�����ҳ")��XLang��Ŀ���Ѿ����Ӱ汾����Ϊ�ҷ���[֮ǰ��XLang](http://www.github.com/qingyiwebt/XLang "XLang")�ķ������в���ȱ�ݣ������Ҵ�����д��     