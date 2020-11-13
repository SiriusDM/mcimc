# CompilerLab
mini compiler in mini c by flex & bison & llvm

参考

> flex&bison

## 1 Calculator(+ / - / * / / / int)

+ 版本不识别default->删去即可

+ 同时由于`$$ = $1;`语句是一条C语言的赋值语句，因此也需要加上花括号。

  ```flex
  exp: factor {$$ = $1; }
  ```

  忽略warning，编译成功

  result://支持整数的加减乘除
  
  ![image-20201113104925985](https://gitee.com/KinDog/picgo/raw/master/picture/image-20201113104925985.png)

## 2 A Few More Rules( () / //comments)

添加New Rule

![image-20201113110910861](https://gitee.com/KinDog/picgo/raw/master/picture/image-20201113110910861.png)

Result: //支持圆括号和注释

![image-20201113110813473](https://gitee.com/KinDog/picgo/raw/master/picture/image-20201113110813473.png)