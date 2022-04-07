/*
 * @Description  : 测试
 * @Author       : FZU Liao
 * @Date         : 2022-04-07 22:37:53
 * @LastEditors  : Liao
 * @LastEditTime : 2022-04-07 23:22:53
 * @FilePath     : \project\test.cpp
 * Copyright 2022 FZU Liao, All Rights Reserved.
 */
#include <cstdio>
#include <iostream>
#include <string>
#include "./include/Course.h"
#include "./include/Schedule.h"
#include "./include/ScheduleManager.h"
using namespace std;

vector<Course> courseList;
vector<Classroom> classroomList;
int courseTypeNum;
int classroomNum;

void input() {
    printf("input\nnum of the course types: ");
    scanf("%d", &courseTypeNum);
    printf("num of the classroom: ");
    scanf("%d", &classroomNum);
    printf(
        "please input %d types of course , format: "
        "ClassName beginWeek,endWeek,weekHours,numOfStudents\n",
        courseTypeNum);
    for (int i = 0; i < courseTypeNum; i++) {
        printf("class %d: ", i + 1);
        string className;
        int beginWeek;
        int endWeek;
        int weekHours;
        int numOfStudents;
        cin>>className;
        scanf("%d,%d,%d,%d",&beginWeek,&endWeek,&weekHours,&numOfStudents);
        while (weekHours--)
            courseList.push_back(
                Course(className, beginWeek, endWeek, numOfStudents));
    }
    printf(
        "please input %d the info of classroom , format: "
        "classroomId classroomCapacity\n",
        classroomNum);
    for (int i = 0; i < classroomNum; i++) {
        printf("classroom %d: ", i + 1);
        string classroomId;
        int classroomCapacity;
        cin>>classroomId>>classroomCapacity;
        classroomList.push_back(Classroom(classroomId, classroomCapacity));
    }
}

int main() {
    input();
    Schedule temp(courseList,&classroomList,20);
    ScheduleManager myManager(100, 0.3, 10, 500, temp);
    Schedule result = myManager.GetEvolutionResult();
    return 0;
}
