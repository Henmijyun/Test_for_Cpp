/*注释可增强可读性
编译生成的.class文件中不包含注释
1.单行注释
2.多行注释，多行注释不可以嵌套使用的。
3.文档注释（Java特有）
  *可以被JDK提供的javadoc所解析，会生成一个文件形式的说明文档 

*/

/**
文档注释
*/
public class HelloJava
{   /*
      main为程序入口
	  main的格式是固定的！
	  多行注释
	 */
	  /**
	  程序的入口
	  */
	public static void main(String[] args)
	{
		//单行注释；如下的语句表示输出到控制台
		System.out.println("Hello,World!");
		System.out.println("Hello,World!");
	}
} 