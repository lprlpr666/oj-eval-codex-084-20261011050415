# Problem 084 - 林克德·哈什玛普

**ACMOJ Problem ID**: 2027

## Table of Contents

- [Problem 084 - 林克德·哈什玛普](#problem-084-林克德哈什玛普)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [Submission Format](#submission-format)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **2027. 林克德·哈什玛普** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/084/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

禁止使用其他 STL。

下发文件链接：[attachment]2027-supplements.zip[/attachment] / <https://jbox.sjtu.edu.cn/l/G16Zg7> / <https://wwqd.lanzoul.com/iIM2G1ikp7na>

**重要提醒：除以上网址外，严禁访问 ACMOJ 主页、比赛界面、题面以外的任何网页！违者将按考试作弊处理。**

<img src="https://acm.sjtu.edu.cn/OnlineJudge/oj-images/bf50e86d-c03d-4ac5-b66f-1744a3892ee3" style="width: 100%">

关于评测方式：你提交的代码将作为 `src.hpp` 被 `main.cpp`（已下发）引用。

在本题中，你需要实现一个 `LinkedHashMap` 类，下面是对这个类的具体介绍：

下图是 Linked Hashmap 结构的简要说明图，数组 `array` 的每个元素对应一个单链表。我们将 `array[i]` 指向的的结点称为单链表的头结点），单链表最后一个结点称为尾结点。如在 `6` 下方对应的单链表中 `'E'` 为头结点，`'A'` 为尾结点。


除此以外，我们还需要实现一个双向链表（如图中蓝色虚线箭头所示）来维护结点插入单链表的先后顺序。例如，上图的插入顺序依照字典序 `A,B,C,...`。在下面将要给出的代码框架中，我们定义 `beg` 指向双向链表的头结点，`cur` 指向双向链表的尾结点；但你也可以根据自己实现双向链表的习惯，自行修改或删除这两个结点。

我们规定两种方式遍历 Linked Hashmap 中的所有结点：

1. 按照插入的时间从早到晚输出；
2. 按照 `array` 数组的下标从小到大输出。

对于一次测试，遍历 Linked Hashmap 的方式是唯一的，它将会在 `LinkedHashMap` 类被构造后，在初始化函数中指定。每种遍历方式分别对应一个全局函数，而你需要在这两个函数中实现相应的遍历方式。

具体地说：在实现第一种方式时，函数按照结点插入单链表的时间顺序，从早到晚遍历每个结点，并且记录结点中的值；在实现第二种方式时，函数从小到大遍历 `array` 数组的每一个元素，如果它对应的链表不为空，则从头到尾遍历该链表中所有结点，记录结点中的值。

``LinkedHashMap`` 类必须实现下列方法：

- 初始化函数 `void init(int len_, bool forEachByTime)`：主函数会在构造 `LinkedHashMap` 后马上调用它。有两个参数，分别为 `array` 数组的长度和这个类采用的遍历函数。初始化函数会根据传入的长度构造 `array` 数组，其元素类型为 `Node` 类的指针（`Node` 类已在代码框架中给出），并将双链表设置为空，最后根据第二个参数的值确定遍历方式，并且保存相应的函数指针。
- 释放空间的函数 `void clearMemory()`：释放内存空间。主函数将会在退出之前调用它。这个函数需要遍历每个结点，你可以任选上述两种方式中的一种实现这个函数。
- 插入指令 `void insert(int key, std::string value)`：将新的结点插入在上图中 `array[key]` 对应的单链表的 **头部** 以及双链表的 **尾部**。结点中的值为 `std::string` 类型的 `value`。
- 删除操作 `void remove(int key, std::string value)`：删除 `array[key]` 对应的单链表中所有值为 `value` 的结点。若不存在满足要求的结点，请勿对链表做任何改动。不要忘记在双链表中做删除操作！
- 查找操作 `std::vector<std::string> ask(int key) const`：返回的 `vector` 应当包含 `array[key]` 对应的单链表中所有结点的值，顺序为链表的头结点到链表的尾结点。
- 输出链表的全部内容 `std::vector<Data> forEach() const` ：根据所选择的遍历函数遍历所有结点。其中 `Data` 结构体可以理解为 `(key, value)` pair。

建议使用下发的代码框架。

注意：**你不能使用 `auto` 和 `decltype` 关键字，违者本题计零分**。

### Input Format



### Output Format



### Samples

No sample data provided for this problem.

### Data Constraints

仅有一个对复杂度的要求：删除双向链表中的元素复杂度必须为 $O(1)$。

| Subtask No. | Testcases No. | 考察的内容                                        | 分数 |
| ----------- | ------------- | ------------------------------------------------- | ---- |
| $1$         | $1,2$         | 考察插入和查找                                    | $9$  |
| $2$         | $3,4$         | 考察插入、删除和查找                              | $9$  |
| $3$         | $5,6$         | 考察插入、查找，和按照 `array` 数组下标遍历       | $9$  |
| $4$         | $7,8$         | 考察插入、查找，和按照插入时间顺序遍历            | $9$  |
| $5$         | $9,10,11$     | 考察插入、删除、查找，和按照 `array` 数组下标遍历 | $12$ |
| $6$         | $12,13,14$    | 考察插入，删除、查找，和按照插入时间顺序遍历      | $12$ |
| $7$         | $15, 16$      | 对 Subtask 1 检查内存泄漏                         | $6$  |
| $8$         | $17, 18$      | 对 Subtask 2 检查内存泄漏                         | $6$  |
| $9$         | $19, 20$      | 对 Subtask 3 检查内存泄漏                         | $6$  |
| $10$        | $21, 22$      | 对 Subtask 4 检查内存泄漏                         | $6$  |
| $11$        | $23, 24, 25$  | 对 Subtask 5 检查内存泄漏                         | $8$  |
| $12$        | $26, 27, 28$  | 对 Subtask 6 检查内存泄漏                         | $8$  |

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 3000 ms
- **Memory Limit (per test case)**: 244 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/084/data_test/`.

Attachments and starter files for this problem are located at `/workspace/data/084/`.

## Submission Requirements

### Submission Format

Submit a single C++ source file to the Online Judge. The OJ provides its own `main.cpp` which `#include "src.hpp"`. Your submission will be written to `src.hpp` and compiled together with the OJ's driver code.

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
