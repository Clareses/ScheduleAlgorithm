/*
 * @Description  : 遗传算法基类定义及实现
 * @Author       : FZU Liao
 * @Date         : 2022-02-26 14:09:40
 * @LastEditors  : Liao
 * @LastEditTime : 2022-04-07 23:10:45
 * @FilePath     : \project\include\GeneticAlgorithm.h
 * \project\include\GeneticAlgorithm.h Copyright
 * 2022 FZU Liao, All Rights Reserved.
 */
#pragma once

#include <queue>
#include <vector>
#include "RandomNum.h"

template <class IndividualType, class ManagerType>
class GeneticAlgorithm {
   public:
    /**
     * @description:构造函数
     * @param popSize int 种群大小
     * @param mutatePos float 变异概率
     * @param numOfElite int 精英数量
     * @param maxTime int 最大迭代次数
     * @param Temp IndividualType 个体模板
     * @return *
     * @example:
     */
    GeneticAlgorithm(int popSize,
                     float mutatePos,
                     int numOfElite,
                     int maxTime,
                     IndividualType Temp) {
        this->populationSize = popSize;
        this->mutatePossibility = mutatePos;
        this->numOfElite = numOfElite;
        this->maxIterationTime = maxTime;
        //向列表中添加初始种群
        for (int i = 0; i < populationSize; i++) {
            populationList.push_back(Chromosome(
                static_cast<ManagerType*>(this)->GetRandomIndividual(Temp)));
        }
    }

    /**
     * @description: 获取迭代后的结果
     * @param *
     * @return IndividualType 迭代后的个体结果
     * @example:
     */
    IndividualType GetEvolutionResult() {
        Evolution();
        return this->populationList.front().individual;
    }

   private:
    //内部类：染色体类定义与实现
    class Chromosome {
       public:
        IndividualType individual;  //个体对象
        int conflictCost;           //冲突代价值

        Chromosome() {}

        Chromosome(IndividualType individual) {
            this->individual = individual;
            this->conflictCost = 0;
        }

        //适应优先队列的操作，重载比较运算符

        bool operator<(const Chromosome& otherChromosome) const {
            return this->conflictCost > otherChromosome.conflictCost;
        }

        bool operator>(const Chromosome& otherChromosome) const {
            return this->conflictCost < otherChromosome.conflictCost;
        }
    };

   protected:
    float mutatePossibility;  //变异概率
    int numOfElite;           //精英数量
    int maxIterationTime;     //最大迭代次数
    int populationSize;       //种群大小

    //种群列表
    std::vector<Chromosome> populationList;

    /**
     * @description: 根据已有种群，进行交叉/变异，创建新种群
     * @param *
     * @return *
     * @example:
     */
    void CreateNewPopulation() {
        //在种群列表被填满之前，不断填充
        while (populationList.size() < populationSize) {
            //随机取出亲代对象
            Chromosome& father =
                populationList[GetRandomNum(0, numOfElite - 1)];
            Chromosome& mother =
                populationList[GetRandomNum(0, numOfElite - 1)];
            //复制构造新生成的子代对象(这样写效率好像会低...)
            IndividualType newIndividual =
                static_cast<ManagerType*>(this)->GeneCrossover(
                    father.individual, mother.individual);
            //判断是否需要变异
            if (GetRandomNum(0, 100) > mutatePossibility * 100) {
                newIndividual =
                    static_cast<ManagerType*>(this)->Mutate(newIndividual);
            }
            //填充
            populationList.push_back(newIndividual);
        }
    }

    /**
     * @description: 对种群进行迭代
     * @param *
     * @return *
     * @example:
     */
    void Evolution() {
        //在达到迭代最大代数之前，不断进行迭代
        for (int i = 0; i < maxIterationTime; i++) {
            //遍历计算所有个体的冲突值
            for (auto iter = populationList.begin();
                 iter != populationList.end(); iter++) {
                iter->conflictCost =
                    static_cast<ManagerType*>(this)->GetConflictCost(
                        iter->individual);
            }
            //选出冲突值小的个体
            std::vector<Chromosome> tempVector;
            std::priority_queue<Chromosome> heap(populationList.begin(),
                                                 populationList.end());
            for (int j = 0; j < numOfElite; j++) {
                tempVector.push_back(heap.top());
                heap.pop();
            }
            this->populationList = tempVector;
            //扩充种群
            CreateNewPopulation();
        }
    }

    /**
     * @description: 根据个体模板，随机生成新的个体
     * @param individualTemplate IndividualType&
     * @return IndividualType 新生成的个体
     * @example:
     */
    IndividualType GetRandomIndividual(
        const IndividualType& individualTemplate);

    /**
     * @description: 令个体发生变异，并返回变异后的个体
     * @param individual IndividualType
     * @return IndividualType 发生变异后的个体对象
     * @example:
     */
    IndividualType Mutate(IndividualType individual);

    /**
     * @description: 由两个已有个体进行交叉互换得到新的个体
     * @param individual_A IndividualType 亲代个体
     * @param individual_B IndividualType 亲代个体
     * @return IndividualType 新生成的个体
     * @example:
     */
    IndividualType GeneCrossover(IndividualType individual_A,
                                 IndividualType individual_B);

    /**
     * @description: 计算个体的冲突代价
     * @param individual IndividualType 供与计算的个体对象
     * @return int 冲突代价的值
     * @example:
     */
    int GetConflictCost(const IndividualType individual);
};