/*
 * @Description  : ScheduleManager声明
 * @Author       : FZU Liao
 * @Date         : 2022-03-01 12:41:37
 * @LastEditors  : Liao
 * @LastEditTime : 2022-04-08 16:06:02
 * @FilePath     : \project\include\ScheduleManager.h
 * Copyright 2022 FZU Liao, All Rights Reserved.
 */
#pragma once

#include "GeneticAlgorithm.h"
#include "Schedule.h"

class ScheduleManager : public GeneticAlgorithm<Schedule, ScheduleManager> {
    friend class GeneticAlgorithm;

   public:
    ScheduleManager(int popSize,
                    float mutatePos,
                    int numOfElite,
                    int maxTime,
                    Schedule Temp);

   protected:
    /**
     * @description: 根据模板初始化个体
     * @param scheduleTemplate Schedule&
     * @return Schedule 根据模板个体随机生成的新个体
     * @example: 
     */    
    Schedule GetRandomIndividual(const Schedule& scheduleTemplate);

    /**
     * @description: 基因变异
     * @param schedule Schedule
     * @return Schedudle 变异后的新Schedule
     * @example: 
     */    
    Schedule Mutate(Schedule schedule);

    /**
     * @description: 基因交叉
     * @param schedule_A Schedule
     * @param schedule_B Schedule
     * @return Schedule 基因交叉后得到的新的Schedule
     * @example: 
     */    
    Schedule GeneCrossover(Schedule schedule_A, Schedule schedule_B);
    
    /**
     * @description: 获取冲突数
     * @param sechedule Schedule&
     * @return int 冲突值
     * @example: 
     */    
    int GetConflictCost(Schedule& sechedule);
};