/*
 * @Description  : ScheduleManager实现
 * @Author       : FZU Liao
 * @Date         : 2022-03-01 12:41:47
 * @LastEditors  : Liao
 * @LastEditTime : 2022-04-07 23:24:37
 * @FilePath     : \project\src\ScheduleManager.cpp
 * Copyright 2022 FZU Liao, All Rights Reserved.
 */
#include "../include/ScheduleManager.h"

ScheduleManager::ScheduleManager(int popSize,
                                 float mutatePos,
                                 int numOfElite,
                                 int maxTime,
                                 Schedule Temp)
    : GeneticAlgorithm(popSize, mutatePos, numOfElite, maxTime, Temp) {}

Schedule ScheduleManager::GetRandomIndividual(
    const Schedule& scheduleTemplate) {
    Schedule schedule = scheduleTemplate;
    schedule.InitRandomSelf();
    return schedule;
}

Schedule ScheduleManager::Mutate(Schedule schedule) {
    std::vector<Course> courseList = schedule.GetCourseList();
    for (int i = 0; i < courseList.size(); i++) {
        if (GetRandomNum(0, 1)) {
            courseList[i].InitRandomSelf(*schedule.GetClassroomList(),
                                         schedule.GetNumOfSlot());
        }
    }
    Schedule newSchedule(courseList, schedule.GetClassroomList(),
                         schedule.GetNumOfSlot());
    return newSchedule;
}

Schedule ScheduleManager::GeneCrossover(Schedule schedule_A,
                                        Schedule schedule_B) {
    int CrossPos;
    std::vector<Course> courseList = schedule_A.GetCourseList();
    for (int i = 0; i < courseList.size(); i++) {
        CrossPos = GetRandomNum(0, 1);
        if (CrossPos == 0)
            courseList[i].SetClassroom(
                schedule_B.GetCourseList()[i].GetClassroom());
        else
            courseList[i].SetSlot(schedule_B.GetCourseList()[i].GetSlot());
        return Schedule(courseList, schedule_B.GetClassroomList(),
                        schedule_B.GetNumOfSlot());
    }
}

int ScheduleManager::GetConflictCost(Schedule schedule) {
    return schedule.GetConflictNum();
}
