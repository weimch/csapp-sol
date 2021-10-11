### 2.1
- A) 0011 1001 1010 0111 1111 1000
- B) 0xC97B
- C) 1101 0101 0001 0100 1100
- D) 0x26B57E

### 2.2
|n|2^n(十进制)|2^n(16进制)
|---|---|----|
|9|512|0x200|
|19|524288|0x80000|
|14|16384|0x4000|
|16|65536|0x10000|
|17|131072|0x20000|
|5|32|0x20|
|7|128|0x80|

### 2.3
（略）

### 2.4
- A. 0x5044
- B. 0x4FFc
- C. 0x570
- D. 0xAE

### 2.5
- A. 小端法：1，大端法：8
- B. 小端法：12，大端法：87
- C. 小端法：123，大端法：986

### 2.6
- A.
  - 0x00359151=>0000 0000 0011 0101 1001 0001 0101 0001
  - 0x4A564504=>0100 1010 0101 0110 0100 0101 0000 0100
- B.
  - 0x00359151=>00000000001**1010110010001010**10001
  - 0x4A564504=>  010010100**1010110010001010**0000100
  - 有16位匹配
- C. 首部9位和尾部7位比特不匹配

### 2.7
61 62 63 64 65 66

### 2.8
|运算|结果|
|--|--|
|a|[01101001]|
|b|[01010101]|
|~a|[10010110]|
|~b|[10101010]|
|a&b|[01000001]|
|a\|b|[01111101]|
|a^b|[00111100]|

### 2.9
- A. 黑色-白色，蓝色-黄色，绿色-红紫色，蓝绿色-红色
- B. 蓝绿色，绿色，蓝色

### 2.10
|步骤|\*x|\*y|
|--|--|--|
|初始|a|b|
|第1步|a|a^b|
|第2步|a^a^b=b|a^b|
|第3步|b|b^a^b=a|

### 2.11
- A. 数组正中间那个元素
- B. first和last值相等，相等值执行异或操作结果为0
- C. 将`<=`替换成`<`即可解决问题

### 2.12
- A. x=x&0xFF
- B. x=~x^0xFF
- C. x=x|0xFF

## 2.13
- x|y => `result=bis(x,y);`
- x^y => `result=bic(x,y);`

### 2.14
|表达式|值|表达式|值|
|--|--|--|--|
|x & y|0x20|x && y|0x01|
|x \| y|0x7f|x \|\| y|0x01|
|~x \| ~y|-0x21|!x \|\| !y|0x00|
|x & !y|0x00|x && ~y|0x00|

### 2.15

### 2.16
|x|x|x<<3|x<<3|x>>2(逻辑的)|x>>2(逻辑的)|x>>2(算术的)|x(算术的)|
|-|-|-|-|-|-|-|-|
|十六进制|二进制|十六进制|二进制|十六进制|二进制|十六进制|二进制|
|0xC3|1100 0011|0x18|0001 1000|0x30|0011 0000|0xF0|1111 0000|
|0x75|0111 0101|0xA8|1010 1000|0x1D|0001 1101|0x1D|0001 1101|
|0x87|1000 0111|0x38|0011 1000|0x21|0010 0001|0xE1|1110 0001|
|0x66|0110 0110|0x30|0011 0000|0x19|0001 1001|0x19|0001 1001|

### 2.17
|x十六进制|x二进制|B2U(x)|B2T(x)|
|-|-|-|-|
|0xE|[1110]|2^3+2^2+2^1=14|-2^3+2^2+2^1=14|
|0x0|[0000]|0|0|
|0x5|[0101]|2^2+1=5|2^2+1=5|
|0x8|[1000]|2^3=8|-2^3=-8|
|0xD|[1101]|2^3+2^2+1=13|-2^3+2^2+1=-3|
|0xF|[1111]|2^3+2^2+2^1+1=15|-2^3+2^2+2^1+1=-1|

### 2.18
A.736, B.-88, C.40, D.-48, E.120, F.136, G.504, H.192, I.-72

### 2.19
|x|T2U(x)|
|-|-|
|-8|8|
|-3|13|
|-2|14|
|-1|15|
|0|0|
|5|5|

### 2.20
按公式应用的

### 2.21
|表达式|类型|求值|
|-|-|-|
|-2147483647-1 == 2147483647U|无符号|0|
|-2147483647-1 < 2147483647|有符号|1|
|-2147483647-1U < 2147483647|无符号|0|
|-2147483647-1 < -2147483647|有符号|1|
|-2147483647-1U < -2147483647|无符号|1|

### 2.23
|w|func1(w)|func2(w)|
|-|-|-|
|0x00000076|0x00000076|0x00000076|
|0x87654321|0x00000021|0x00000021|
|0x000000C9|0x000000C9|0xFFFFFFC9|
|0xEDCBA987|0x00000087|0xFFFFFF87|

### 2.24
- 无符号：0->0, 2->2, 9->1, 11->3, 15->7
- 补码：0->0, 2->2, -7->1, -5->3, -1->-1

### 2.25
当length为0时，length-1计算出无符号数结果为2^32-1，此时a访问超过其范围的元素，将会遇到内存错误。

### 2.26
A. 当s的长度小于t的长度时，运算结果总是大于0的
B. 当strlen(s)小于strlen(t)，二者相减结果为负数，但运算结果类型为无符号整型，因此会将补码转为无符号数，得到大于0的正值
C. 改为`return strlen(s)>strlen(t);`

### 2.27
```c
int uadd_ok(unsigned x, unsigned y) {
  return x + y > x;
}
```

### 2.28
- x: 0-0, 5-5, 8-8, D-13, F-15
- y: 0-0-0, 5-11-B, 8-8-8, D-3-3, F-1-1

### 2.29
|x|y|x+y|x+y(5)|情况|
|-|-|-|-|-|
|-12[10100]|-15[10001]|-27|5|情况1|
|-8[11000]|-8[11000]|-16|-16|情况2|
|-9[10111]|8[01000]|-1|-1|情况2|
|2[00010]|5[00101]|7|7|情况3|
|12[01100]|4[00100]|16|-16|情况4|

### 2.30
```c
int tadd_ok(int x, int y) {
  int sum = x + y;
  return !(x > 0 && y >0 && sum <=0) && !(x <0 && y<0 && sum >= 0);
}
```
### 2.31
如果已经发生了溢出，那么sum-x将得不到y。

### 2.32
当x为正数，且x大于Tmax，y为负数，且y小于等于Tmin
```c
// 未知
```

### 2.33
|x十六进制|x十进制|逆元十进制|逆元十六进制|
|-|-|-|-|
|0|0|0|0|
|5|5|-5|A|
|8|-8|-8|8|
|D|-3|3|3|
|F|-1|1|1|

### 2.34
|模式|x|y|x\*y|截断的x\*y|
|-|-|-|-|-|
|无符号|[100]|[101]|[10100]|[100]|
|补码|[100]|[101]|[1100]|[100]|
|无符号|[010]|[111]|[1110]|[110]|
|补码|[010]|[111]|[110]|[110]|
|无符号|[110]|[110]|[100100]|[100]|
|补码|[110]|[110]|[0100]|[100]|

### 2.36
```c
int tmult_ok(int x, int y) {
  int64_t p = (int64_t)x * y;
  return p == (int)p;
}
```

### 2.37
- A. 改动是没有帮助的，因为尽管将乘法结果提升到了64位，在执行malloc时，参数还是会被转换为32位。
- B. 通过检查是否产生溢出来消除这个漏洞，如下所示。
  ```c
  uint64_t required_size = ele_cnt * (uint64_t) ele_size;
  size_t request_size = (size_t) required_size;
  if (request_size != request_size)
    return NULL;
  void *result = malloc(request_size);
  if (result == NULL)
    return NULL;
  ```

### 2.38
- b=0时，可以用于a的2^k倍数
- b=a时，可以用于a的2^k+1的倍数

### 2.39
溢出了，导致结果为-(x<<m)

### 2.40
- (x<<3) + (x<<1)
- (x<<5) - x
- (x<<1) - (x<<3)
- (x<<6) - (x<<3) - x

### 2.41
