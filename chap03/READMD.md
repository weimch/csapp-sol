### 3.6
- 6+x
- x+y
- x+4y
- 9x+7
- 4y+10
- x+2y+9

### 3.7
5x+2y+8z

### 3.8
- 0x100, 0x100
- 0x108, 0xA8
- 0x118, 0x110
- 0x100, 0x00
- %rcx, 0x00
- %rax, 0xFD

### 3.9
- salq 4, %rax
- sarq %esi, %rax

### 3.10
- y | x
- t1 >> 3
- ~t2
- z - t3

### 3.11
- A. 赋值0
- B. movq 0, %rdx
- C. xorq版本只需3个字节，movq版本需要7个字节。可以使用更新低位4字节自动把高位4字节设为0的特性来进一步减少所需字节数。

### 3.12
```assembel
remdiv:
  movq %rdx, %r8
  movq $rdi, %rax
  xorq %rdx, %rdx
  divq %rsi
  movq %rax, (%r8)
  movq %rdx, (%rcx)
```

### 3.13
- A. int
- B. short
- C. char
- D. long, unsigned long, 某种无符号的指针

### 3.14
- A. long
- B. short, unsigned short
- C. unsigned char
- D. int, unsigned int

### 3.15
- A. 0x4003fe
- B. 0x400425
- C. pop是400545, ja是400543
- D. 0x400560

### 3.16
- A.
  ```c
  void cond(long a, long *p) {
    if(p == 0)
      goto done
    if (*p >= a)
      goto done
    *p = a;
  done:
    return;
  }
  ```
- B. 第一个条件分支语句检查p是否为空，为空则跳过比较检查。

### 3.17
A.
```c
long gotodiff_se(long x, long y) {
  long result;
  if (x < y)
    goto true;
  ge_cnt++;
  result = x - y;
true:
  lt_cnt++;
  result = y - x;
done:
  return result;
}
```
B. 大多数情况下，可以在这两种方式中任意选择，但原来的方法对于没有else语句的情况要好些，如下：
```c
t = test-expr;
if (!t)
  goto done
then-statement
done:
```

### 3.18
- x + y + z
- x < -3
- y < z
- val = x * y
- val = y * z
- x > 2
- val = x * z

### 3.19
A. `0.5*16 + (1-0.5)*(16+x)=31 -> x = 30`
B. `30+16=46`

### 3.20
A. `/`
B. 这个程序创建一个临时值等于x+7，预期x为负，需要加偏移量时使用。cmovns指令在当x>=0条件成立时把临时值修改为x，然后再移动3位，得到x/8
```assembly
long arith(long x)
x in %rdi

arith
  leaq    7(%rdi), %rax   temp = x+7
  testq   %rdi, %rdi      Test x
  cmovns  %rdi, %rax      If x >= 0, temp = x
  sarq    $3, %rax        result = temp >> 3 (= x / 8)
```

### 3.21
- `8*y`
- `y > 0`
- `x >= y`
- `x&y`
- `y-x`
- `y <= -2`
- `x+y`

### 3.22
A. 13
B. 20

### 3.23
- A. x->%rax, y->%rcx, n->%rdx
- B. 使用`leaq 1(%rcx, %rax), %rax`完成

### 3.24
- `1`
- `a < b`
- `(a+b)*result`
- `a+1`

### 3.25
- `b`
- `b > 0`
- `result * a`
- `b - a`

### 3.26
A. guarded-do
B. 
  ```c
  long func_a(unsigned long x) {
    long val = 0;
    while (x != 0) {
      val = val ^ x;
      x = x >> 1;
    }
    return val & 1;
  }
  ```
C. 计算x的奇偶性

### 3.27
```c
long fact_for_gd_goto(long n) {
  long i = 2;
  long result = 1;
  if (n <= 1)
    goto done;
loop:
  result *= i;
  i++;
  if (i <= n)
    goto loop;
done:
  return result;
}
```

### 3.28
A.
  ```c
  long func_b(unsigned long x) {
    long val = 0;
    long i;
    for (i = 64; i != 0; --i) {
      val = (val << 1) | (x & 0x1);
      x >>= 1;
    }
  }
  ```
B. 这段代码是用guarded-do变换生成的，但是编译器发现因为i初始化成了64，所以一定会满足i不等于0，因此初始化的测试是没有必要的。
C. 将x中的位反转过来

### 3.29
A. i得不到更新，代码将会无限循环。
  ```c
  long sum = 0;
  long i = 0;
  while (i < 10) {
    if (i & 1)
      continue
    sum += i;
    i++;
   }
  ```
B. 使用goto语句替代continue语句，跳过循环余下部分
  ```c
  long sum = 0;
  long i = 0;
  while (i < 10) {
    if (i & 1)
      goto update;
    sum += 1;
  update:
    i++;
  }
  ```

3.30
- A. -1, 0, 1, 2, 4, 5, 7
- B. 目标为.L5情况标号为0和7
- C. 目标为.L7情况标号为2和4


