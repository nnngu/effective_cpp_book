/*
条款 30 透彻了解inlining的里里外外
请记住：
	将大多数inlining限制在小型、被频繁调用的函数身上。这可使日后的调试过程和二进制升级(binary upgradability)
更容易，也可使潜在的代码膨胀问题最小化，使程序的速度提升机会最大化。
	不要只因为function templates 出现在头文件，就将它们声明为inline。
*/