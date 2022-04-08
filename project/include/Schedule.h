/*
 * @Description  : 课表类声明
 * @Author       : FZU Liao
 * @Date         : 2022-03-02 09:39:18
 * @LastEditors  : Liao
 * @LastEditTime : 2022-04-08 15:15:20
 * @FilePath     : \project\include\Schedule.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */
#pragma once

#include "Course.h"

class Schedule{
private:
    std::vector<Course> courseList;
    std::vector<Classroom>* classroomList;
    int numOfSlot;
    float variance;
public:
    Schedule();
    Schedule(std::vector<Course> courseList,std::vector<Classroom>* classroomList,int numOfSlot);
    void InitRandomSelf();
    int GetConflictNum();
    int GetNumOfSlot();
    float GetVariance();
    std::vector<Course> GetCourseList();
    std::vector<Classroom>* GetClassroomList();
};