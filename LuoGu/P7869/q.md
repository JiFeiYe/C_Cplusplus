# 「Wdoi-4」使用三个系统程度的能力

## 题目背景

**勘误**：事实上，自从 $2001$ 年发布的 $\text{MacOS X}$ 之后换行符都变成了 $\verb!\n!$。网上发布的很多文章都存在谬误，当时出题人也没实地考察就信了。为了防止谣言继续传播，就在这里放了这段话。数据仍然以目前的题目描述为准，未做更改。

---

赫卡提亚·拉碧斯拉祖利是拥有三副身体，司掌月球、地球、异界三界地狱的神明。由于与纯狐结盟的缘故，赫卡提亚接触到了幻想乡，以及其他的一些现代科技。

赫卡提亚发现，在人类社会中存在三个非常通用流行的操作系统，也就是 $\text{Windows}$、$\text{Linux}$ 和 $\text{Mac}$。这三者就像是赫卡提亚本人的三个身体般，分别占据了很大的市场。

但是赫卡提亚又发现，尽管这三个系统之间的文件可以通过一些方式进行信息流通，可是毕竟存在一些区别：例如换行方面采用的字符的不同。赫卡提亚对此非常感兴趣。

现在赫卡提亚不知道从哪里搞来了一个系统的文本文件，她想知道这个文件是在哪个系统里编辑而成的。你能写个程序帮帮她吗？

## 题目描述

在 $\text{Windows}$、$\text{Linux}$ 和 $\text{Mac}$ 系统下，分别采用了三种不同的换行符方式。表示为显式转义符，分别是 $\verb!\r\n!$、$\verb!\n!$ 和 $\verb!\r!$ 。现在有一份已经写好了的非空文本文件（里面仅由大小写英文字母、下划线、阿拉伯数字、空格，以及换行符组成）。这个文本文件是在单一系统中写成的，因此保证换行符只会出现上述三种情况**之一**。

比如，这是一个合法的文本文件：

```plain
SCP2021 J rp plus plus
chen zhe AK IOI
Welcome to Hell
```

现在将其中的换行变为对应的转义符。那么在上述三个系统中，分别会变为以下三种模样：

- $\text{Windows}$ 系统：  

$$\colorbox{f5f5f5}{\verb!SCP2021 J rp plus plus\r\nchen zhe AK IOI\r\n\r\nWelcome to Hell!}$$

- $\text{Linux}$ 系统：

$$\colorbox{f5f5f5}{\verb!SCP2021 J rp plus plus\nchen zhe AK IOI\n\nWelcome to Hell!\kern{31.5pt}}$$

- $\text{Mac}$ 系统：

$$\colorbox{f5f5f5}{\verb!SCP2021 J rp plus plus\rchen zhe AK IOI\r\rWelcome to Hell!\kern{31.5pt}}$$ 

---

现在你被给定的任务是，根据转换后的文本文件，判断这是哪个系统下编写的文本文件。对于上述三种情况，分别输出 `windows`、`linux` 或 `mac`。

## 输入格式

输入共一行，为转换后的文本文件。保证文本文件非空，且转换前至少有一个换行符。**输入可能包含空格。**

## 输出格式

输出一行一个小写单词，输出此文本文件在哪个系统下编写。

## 样例 #1

### 样例输入 #1

```
SCP2021RPplusplus\nchenzheAKIOI\n1plus1equalto2\n
```

### 样例输出 #1

```C
linux
```

## 样例 #2

### 样例输入 #2

```C
chen_zhe AK IOI\r\nchen_zhe AK NOI\r\n
```

### 样例输出 #2

```C
windows
```

## 样例 #3

### 样例输入 #3

```C
include iostream\rsigned main return 0\r
```

### 样例输出 #3

```C
mac
```

## 提示

样例 $4$ 见下发的附件 $\textbf{\textit{system4.in}/\textit{system4.out}}$。

### 数据范围

- 对于 $40\%$ 的数据，保证不存在空格。
- 对于 $100\%$ 的数据，保证输入字符串的长度 $\le 10^5$。输入中仅包含大写英文字母、小写英文字母、下划线、数字、空格和转义字符（`\r`、`\n`）。

### 注意

本题中的 `\n` 及 `\r` 表示直接写在输入里的一个反斜杠符号跟着一个小写字母 `n` 或 `r`，而不是一个**真正的**转义字符。