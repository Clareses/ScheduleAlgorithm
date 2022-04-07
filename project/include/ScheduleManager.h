/*
 * @Description  : ScheduleManager声明
 * @Author       : FZU Liao
 * @Date         : 2022-03-01 12:41:37
 * @LastEditors  : Liao
 * @LastEditTime : 2022-03-02 13:51:43
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
    Schedule GetRandomIndividual(const Schedule& scheduleTemplate);

    Schedule Mutate(Schedule schedule);

    Schedule GeneCrossover(Schedule schedule_A, Schedule schedule_B);

    int GetConflictCost(const Schedule sechedule);
};