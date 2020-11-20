# CompilerLab
mini compiler in mini c by flex & bison & llvm

参考

> https://gnuu.org/2009/09/18/writing-your-own-toy-compiler/

> flex&bison

![image-20201113112606060](https://gitee.com/KinDog/picgo/raw/master/picture/image-20201113112606060.png)

Tips：前两部分是flex&bison书中例子

思路：先通过对最简单的语法生成AST，达到阶段性目标，然后再不断扩充语法

## 1 Calculator(+ / - / * / / / int)

+ 版本不识别default->删去即可

+ 同时由于`$$ = $1;`语句是一条C语言的赋值语句，因此也需要加上花括号。

  ```flex
  exp: factor {$$ = $1; }
  ```

  ignore warning

  result://支持整数的加减乘除
  
  ![image-20201113104925985](https://gitee.com/KinDog/picgo/raw/master/picture/image-20201113104925985.png)

## 2 A Few More Rules( () / //comments)

New Rule

![image-20201113110910861](https://gitee.com/KinDog/picgo/raw/master/picture/image-20201113110910861.png)

Result: //支持圆括号和注释

![image-20201113110813473](https://gitee.com/KinDog/picgo/raw/master/picture/image-20201113110813473.png)

## 3 Calculator with AST

fb3-1

## Flex

+ **%option**

> https://www.jianshu.com/p/2a0e9a0cdc61
>
> https://zhuanlan.zhihu.com/p/89473441

```yylineno```:flex 生成的扫描器用全局变量yylineno 维护着输入文件的当前行编号。option lex-compat隐含有这个选项。

```noyywrap```:当扫描器遇到end-of-file 时，不会调用yywrap()，但简单的假定没有更多的文件可以扫描（直到用户把yyin 指向新的文件并再一次调用yylex()）。

```nodefault```:使它不要添加默认的规则这样输入无法被给定的规则完全匹配时，词法分析器可以报告一个错误。

## Bison

三部分：定义、规则、C