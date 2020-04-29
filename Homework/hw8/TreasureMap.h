#include <iostream>

using namespace std;

#pragma once

template <typename T>
class TreasureMap
{
    private:
        T* steps;
        int current_step;
        int total_steps;
        int max_steps;
    public:
        TreasureMap()
        {
            current_step = 0;
            total_steps = 0;
            max_steps = 10;
            steps = new T[max_steps];
        }

        TreasureMap(int max)
        {
            current_step = 0;
            total_steps = 0;
            max_steps = max;
            steps = new T[max_steps];
        }

        int getCurrentStep()
        {
            return current_step;
        }

        int getTotalSteps()
        {
            return total_steps;
        }

        T* getSteps()
        {
            return steps;
        }

        void addStep(T step)
        {
            if(total_steps == max_steps)
            {
                cout << "Cannot add more steps, TreasureMap is full" << endl;
                return;
            }

            steps[total_steps] = step;
            ++total_steps;
        }

        void removeStep(int index)
        {
            if(total_steps == 0)
            {
                cout << "There are no steps to remove" << endl;
                return;
            }

            for(int i = index; i < total_steps; i++)
            {
    
            }
        }

        void nextStep()
        {
            if(current_step > total_steps)
            {
                cout << "Cannot go to next step, treasure has already been found!" << endl;
                return;
            }

            if(current_step == total_steps-2)
            {
                cout << "Congratulations, you have found the treasure!" << endl;
                return;
            }

            cout << "Going from " << steps[current_step] << " to " << steps[current_step+1] << endl;
            current_step++;

            if(current_step == total_steps-1)
            {
                cout << "Congratulations, you have found the treasure!" << endl;
                return;
            }
        }

        void backtrack()
        {
            if(current_step == 0)
            {
                cout << "Cannot backtrack, you're at the very first step!" << endl;
                return;
            }

            cout << "Backtracking from " << steps[current_step] << " to " << steps[current_step-1] << endl;
            current_step--;
        }

        TreasureMap operator+(TreasureMap& rhs)
        {
            TreasureMap<T> newMap;
            if(this->total_steps != rhs.total_steps)
            {
                return newMap;
            }
            else
            {
                for(int i = 0; i < total_steps; i++)
                {
                    newMap.steps[i] = this->steps[i] + rhs.steps[i];
                }
                return newMap;
            }
        }

        bool operator==(TreasureMap& rhs)
        {
            if(total_steps == rhs.total_steps)
            {
                for(int i = 0; i < total_steps; i++)
                {
                    if(steps[i] != rhs.steps[i])
                        return false;
                }
            }
            return true;
        }

};


