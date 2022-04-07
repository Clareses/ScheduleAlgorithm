/*
 * @Description  : 课程类声明
 * @Author       : FZU Liao
 * @Date         : 2022-03-01 12:40:29
 * @LastEditors  : Liao
 * @LastEditTime : 2022-03-02 13:43:10
 * @FilePath     : \project\include\Course.h
 * Copyright 2022 FZU Liao, All Rights Reserved.
 */
#pragma once

#include <string>
#include <vector>

class Classroom {
   private:
    std::string id;
    int capacity;

   public:
    Classroom();

    Classroom(std::string id, int capacity);

    int GetCapacity();

    std::string GetId();
    
};

class Course {
   private:
    std::string id;
    int beginWeek;
    int endWeek;
    Classroom classroom;
    int numOfStudent;
    int slot;

    bool IsCross(Course otherCourse);

public:
    Course();

    Course(std::string id,int beginWeek,int endWeek,int numOfStudent);

    void InitRandomSelf(std::vector<Classroom> classroomList,int slotRange);

    std::string GetId();

    int GetBeginWeek();

    int GetEndWeek();

    int GetSlot();

    int GetNumOfStudent();

    Classroom GetClassroom();

    int GetConflictNumWithAnother(Course otherCourse);

    void SetClassroom(Classroom classroom);

    void SetSlot(int slot);
    
};