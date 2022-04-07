/*
 * @Description  : 课程类实现
 * @Author       : FZU Liao
 * @Date         : 2022-03-01 12:40:41
 * @LastEditors  : Liao
 * @LastEditTime : 2022-03-02 14:35:03
 * @FilePath     : \project\src\Course.cpp
 * Copyright 2022 FZU Liao, All Rights Reserved.
 */
#include "Course.h"
#include "RandomNum.h"
#include "cmath"

Classroom::Classroom() {}

Classroom::Classroom(std::string id, int capacity) {
    this->id = id;
    this->capacity = capacity;
}

int Classroom::GetCapacity() {
    return this->capacity;
}

std::string Classroom::GetId() {
    return this->id;
}

bool Course::IsCross(Course otherCourse) {
    if (this->beginWeek >= otherCourse.endWeek ||
        this->endWeek <= otherCourse.beginWeek)
        return true;
    return false;
}

Course::Course() {}

Course::Course(std::string id, int beginWeek, int endWeek, int numOfStudent) {
    this->id = id;
    this->beginWeek = beginWeek;
    this->endWeek = endWeek;
    this->numOfStudent = numOfStudent;
}

void Course::InitRandomSelf(std::vector<Classroom> classroomList,
                            int slotRange) {
    int temp;
    temp = GetRandomNum(0, classroomList.size() - 1);
    this->classroom = classroomList[temp];
    temp = GetRandomNum(1, slotRange);
    this->slot = temp;
}

std::string Course::GetId() {
    return this->id;
}

int Course::GetBeginWeek() {
    return this->beginWeek;
}

int Course::GetEndWeek() {
    return this->endWeek;
}

int Course::GetSlot() {
    return this->slot;
}

int Course::GetNumOfStudent() {
    return this->numOfStudent;
}

Classroom Course::GetClassroom() {
    return this->classroom;
}

//没有考虑好一种情况（一周课多于2节，有个45节这样，则interval和continue很难保证）
int Course::GetConflictNumWithAnother(Course otherCourse) {
    int ConflictNum = 0;
    bool slotConflict = this->slot == otherCourse.slot;
    bool classroomConflict = this->classroom.GetId() == otherCourse.GetClassroom().GetId();
    bool weekConflict = this->IsCross(otherCourse);
    bool dayConflict = this->slot/4 == otherCourse.slot/4;
    bool idConflict = this->id == otherCourse.id;
    bool intervalConflict = abs(this->slot / 4 - otherCourse.slot / 4) == 1;
    bool continuityConflict = abs(this->slot - otherCourse.slot) != 1;
    if (weekConflict && slotConflict && classroomConflict)
        ConflictNum++;
    if (idConflict && intervalConflict )
        ConflictNum++;
    if (idConflict && continuityConflict&& dayConflict)
        ConflictNum++;
    return ConflictNum;
}

void Course::SetClassroom(Classroom classroom) {
    this->classroom = classroom;
}

void Course::SetSlot(int slot) {
    this->slot = slot;
}