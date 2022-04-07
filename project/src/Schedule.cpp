/*
 * @Description  : 课表类实现
 * @Author       : FZU Liao
 * @Date         : 2022-03-01 12:58:18
 * @LastEditors  : Liao
 * @LastEditTime : 2022-03-02 13:39:41
 * @FilePath     : \project\src\Schedule.cpp
 * Copyright 2022 FZU Liao, All Rights Reserved.
 */
#include "../include/Schedule.h"
#include <vector>

Schedule::Schedule() {}

Schedule::Schedule(std::vector<Course> courseList,
                   std::vector<Classroom>* classroomList,
                   int numOfSlot) {
    this->courseList = courseList;
    this->classroomList = classroomList;
    this->numOfSlot = numOfSlot;
}

void Schedule::InitRandomSelf() {
    for (int i = courseList.size() - 1; i >= 0; i--) {
        courseList[i].InitRandomSelf(*this->classroomList, numOfSlot);
    }
}

int Schedule::GetNumOfSlot() {
    return this->numOfSlot;
}

int Schedule::GetConflictNum() {
    int ConflictNum = 0;
    for (int i = 0; i < courseList.size(); i++) {
        for (int j = i + 1; j < courseList.size(); j++) {
            ConflictNum +=
                courseList[i].GetConflictNumWithAnother(courseList[j]);
        }
        if (courseList[i].GetNumOfStudent() >
            courseList[i].GetClassroom().GetCapacity())
            ConflictNum++;
    }
    ConflictNum *= 100;
    // todo 计算方差

    return ConflictNum;
}

std::vector<Course> Schedule::GetCourseList() {
    return this->courseList;
}

std::vector<Classroom>* Schedule::GetClassroomList() {
    return this->classroomList;
}
