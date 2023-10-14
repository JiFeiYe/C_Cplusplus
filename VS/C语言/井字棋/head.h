#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

//菜单打印1					（多多使用system("cls")刷新界面）
//选择模式1
//整体框架？				（二维数组）
//棋盘打印1
//玩家下棋					（谁先下棋？）
//输赢平判断
//电脑下棋					（随机函数）
//输赢平判断

//菜单打印	
void ShowMenu();

//选择模式
void ChooseMode();

//人机对战
void WithComputer();

//好友对战
void WithFriend();

//机器挑子
void ComputerAct();

//输赢平判断
char WinorLose();

//先手权选择（随机数）
void WhoFirst();

//棋盘打印
void ShowBorad();