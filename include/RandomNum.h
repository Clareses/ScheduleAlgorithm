/*
 * @Description  : 随机数生成函数
 * @Author       : FZU Liao
 * @Date         : 2022-02-26 15:00:17
 * @LastEditors  : Liao
 * @LastEditTime : 2022-02-26 15:26:05
 * @FilePath     : \project\include\RandomNum.h
 * Copyright 2022 FZU Liao, All Rights Reserved.
 */
#pragma once

#include <cstdlib>
#include <ctime>

static void InitRandomNum() {
    srand(int(time(0)));
}


/**
 * @description: 生成范围在top与bottom之间的随机数
 * @param top int 随机数最大值
 * @param bottom int 随机数最小值
 * @return *
 * @example:
 */
static int GetRandomNum(int bottom, int top) { 
    return rand() % (top - bottom + 1) + bottom;
}
