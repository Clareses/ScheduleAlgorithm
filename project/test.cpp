/*
 * @Description  : 测试
 * @Author       : FZU Liao
 * @Date         : 2022-04-07 22:37:53
 * @LastEditors  : Liao
 * @LastEditTime : 2022-04-08 15:15:37
 * @FilePath     : \project\test.cpp
 * Copyright 2022 FZU Liao, All Rights Reserved.
 */
#include <algorithm>
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

void input();
void output(Schedule schedule);

int main() {
    input();
    Schedule temp(courseList, &classroomList, 20);
    ScheduleManager myManager(100, 0.3, 10, 500, temp);
    printf("Loading...\n");
    Schedule result = myManager.GetEvolutionResult();
    output(result);
    return 0;
}

void input() {
    printf("please input\nnum of the course types: ");
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
        cin >> className;
        scanf("%d,%d,%d,%d", &beginWeek, &endWeek, &weekHours, &numOfStudents);
        weekHours/=2;
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
        cin >> classroomId >> classroomCapacity;
        classroomList.push_back(Classroom(classroomId, classroomCapacity));
    }
}

void output(Schedule result) {
    printf("\n");
    printf("%-10s %-10s %-10s %-10s\n", "Course", "Classroom", "Weekday", "Time");
    vector<Course> courseList = result.GetCourseList();
    sort(courseList.begin(), courseList.end(),
         [](Course a, Course b) { return a.GetSlot() < b.GetSlot(); });
    for (int i = 0; i < courseList.size(); i++) {
        Course temp = courseList[i];
        int time = temp.GetSlot()%4;
        printf("%-10s %-10s %-10d %-10s\n",temp.GetId().c_str(),temp.GetClassroom().GetId().c_str(),
        temp.GetSlot()/4+1,(to_string(time*2+1)+","+to_string(time*2+2)).c_str());
    }
    printf("\n%s:%f","Classroom utilization variance = ",result.GetVariance());
}