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

