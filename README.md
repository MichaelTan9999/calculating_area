# 一个简单的图形面积口算

## 编译命令

```shell
g++ -std=c++17 -fsanitize=address -g -Wall main.cpp list.cpp shapes.cpp -o target
```



## 需求

一位小学教师Ken希望完成这样的任务：针对于小学生正在学习四边形(quadrangle)的特性，编写一个小软件，能够随机在屏幕上显示矩形(rectangle)、正方形(square)、平行四边形(parallelogram)、梯形(trapezoid)和菱形(diamond)五种形体之一，同时显示该形体的轮廓形状和关键数据（随机产生），学生根据给出的关键数据计算形体的面积并输入，软件判断其结果的正确性。在学习过程中，软件记录产生的每一个形体，在学生选择不再继续后，将其学习的过程重放一遍（及显示所有学过的形体数据、形状及结果），用以重温，加深印象。

## 编码要求

1. 理清形体概念之间的关系，然后用（多）继承来实现这些关系。
2. 使用抽象类来表示顶层概念。
3. 矩形、平行四边形用长和高表示；正方形用边长表示；梯形用两条平行边长和高表示；菱形两条对象线长表示。
4. 使用链表模板来存储数据。
5. 为链表模板设计迭代器。
6. 要体现多态。

## 输入输出样本

Practicing. Input negative value to halt.
diamond: diagnal1=4, diagnal2=6, area=?24  
Your answer is incorrect

square: width=3, area=?9  
Your answer is correct

rectangle: width=3, height=4, area=?12  
Your answer is correct

square: width=4, area=?16  
Your answer is correct

parallelogram: width=5, height=8, area=?40  
Your answer is correct

square: width=5, area=?25  
Your answer is correct

trapezoid: width1=8, width2=5, height=3, area=?19.5  
Your answer is correct

trapezoid: width1=5, width2=3, height=8, area=?32  
Your answer is correct

diamond: diagnal1=3, diagnal2=8, area=?12  
Your answer is correct

trapezoid: width1=6, width2=7, height=6, area=?-1







Reviewing...

diamond: diagnal1=4, diagnal2=6, area=12, answer=24 X

square: width=3, area=9, answer=9 V

rectangle: width=3, height=4, area=12, answer=12 V

square: width=4, area=16, answer=16 V

parallelogram: width=5, height=8, area=40, answer=40 V

square: width=5, area=25, answer=25 V

trapezoid: width1=8, width2=5, height=3, area=19.5, answer=19.5 V

trapezoid: width1=5, width2=3, height=8, area=32, answer=32 V

diamond: diagnal1=3, diagnal2=8, area=12, answer=12 V

Total: 9, Correct: 8