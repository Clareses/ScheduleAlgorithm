/*
 * @Description  : 课表类实现
 * @Author       : FZU Liao
 * @Date         : 2022-03-01 12:58:18
 * @LastEditors  : Liao
 * @LastEditTime : 2022-04-08 15:47:44
 * @FilePath     : \project\src\Schedule.cpp
 * Copyright 2022 FZU Liao, All Rights Reserved.
 */
#include "../include/Schedule.h"
#include <map>
#include <vector>

Schedule::Schedule() {
    variance = 0;
}

Schedule::Schedule(std::vector<Course> courseList,
                   std::vector<Classroom>* classroomList,
                   int numOfSlot) {
    this->courseList = courseList;
    this->classroomList = classroomList;
    this->numOfSlot = numOfSlot;
    variance = 0;
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
    int totalTime = 0;
    std::map<std::string, int> classroomUseTime;
    for (int i = 0; i < classroomList->size(); i++) {
        classroomUseTime.insert(
            std::pair<std::string, int>(classroomList->at(i).GetId(), 0));
    }
    for (int i = 0; i < courseList.size(); i++) {
        totalTime += courseList[i].GetEndWeek() - courseList[i].GetBeginWeek();
        classroomUseTime[courseList[i].GetClassroom().GetId()] +=
            courseList[i].GetEndWeek() - courseList[i].GetBeginWeek();
        for (int j = i + 1; j < courseList.size(); j++) {
            ConflictNum +=
                courseList[i].GetConflictNumWithAnother(courseList[j]);
        }
        if (courseList[i].GetNumOfStudent() >
            courseList[i].GetClassroom().GetCapacity())
            ConflictNum++;
    }
    ConflictNum *= 100;
    float avgTime = (float)totalTime / courseList.size();
    for(auto iter = classroomUseTime.begin(); iter != classroomUseTime.end(); iter++){
        float temp = iter->second - avgTime;
        variance += temp * temp;
    }
    variance /= classroomUseTime.size();
    return ConflictNum+variance;
}

std::vector<Course> Schedule::GetCourseList() {
    return this->courseList;
}

std::vector<Classroom>* Schedule::GetClassroomList() {
    return this->classroomList;
}

float Schedule::GetVariance() {
    return this->variance;
}