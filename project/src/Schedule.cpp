/*
 * @Description  : 课表类实现
 * @Author       : FZU Liao
 * @Date         : 2022-03-01 12:58:18
 * @LastEditors  : Liao
 * @LastEditTime : 2022-04-08 16:03:32
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
    //遍历课程，对每个课程进行随机初始化
    for (int i = courseList.size() - 1; i >= 0; i--) {
        courseList[i].InitRandomSelf(*this->classroomList, numOfSlot);
    }
}

int Schedule::GetNumOfSlot() {
    return this->numOfSlot;
}

int Schedule::GetConflictNum() {
    int ConflictNum = 0;//冲突数
    int totalTime = 0;//所有课程的学时和
    std::map<std::string, int> classroomUseTime;//记录每个教室的使用时间
    //初始化map
    for (int i = 0; i < classroomList->size(); i++) {
        classroomUseTime.insert(
            std::pair<std::string, int>(classroomList->at(i).GetId(), 0));
    }
    //遍历课程，计算冲突数
    for (int i = 0; i < courseList.size(); i++) {
        //记录每个课程的学时和
        totalTime += courseList[i].GetEndWeek() - courseList[i].GetBeginWeek();
        //更新每间教室的使用时间
        classroomUseTime[courseList[i].GetClassroom().GetId()] +=
            courseList[i].GetEndWeek() - courseList[i].GetBeginWeek();
        //计算冲突数
        for (int j = i + 1; j < courseList.size(); j++) {
            ConflictNum +=
                courseList[i].GetConflictNumWithAnother(courseList[j]);
        }
        //补充计算教室容量与学生人数的冲突
        if (courseList[i].GetNumOfStudent() >
            courseList[i].GetClassroom().GetCapacity())
            ConflictNum++;
    }
    ConflictNum *= 100;
    //计算方差
    float avgTime = (float)totalTime / courseList.size();
    for(auto iter = classroomUseTime.begin(); iter != classroomUseTime.end(); iter++){
        float temp = iter->second - avgTime;
        variance += temp * temp;
    }
    variance /= classroomUseTime.size();
    //返回冲突值
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