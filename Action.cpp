#include "Action.h"

Action::Action()
{
    this->description = "";
    this->done = false;
    this->idea = "";
    this->priority = 0;
    this->times = 0;
}

Action::Action(bool done, int times,
    string idea, int priority,
    string des, string effCall,
    int targetRadius)
{
    this->done = done;
    this->times = times;
    this->idea = idea;
    this->priority = priority;
    this->description = des;
    this->effList.push_front(effCall);
    this->targetRadius = targetRadius;
}

#pragma region getters/setters

int Action::getTimes()
{
    return times;
}

string Action::getIdea()
{
    return idea;
}

int Action::getPriority()
{
    return priority;
}

bool Action::getFlag()
{
    return done;
}

string Action::getDes()
{
    return description;
}

string Action::getEff()
{
    return effList.front();
}

int Action::getTargetR()
{
    return targetRadius;
}

void Action::popFrontEffList()
{
    this->effList.pop_front();
}

void Action::setFlag(bool d)
{
    done = d;
}

void Action::setTimes(int f) 
{
    times = f;
}

void Action::setIdea(string n)
{
    idea = n;
}

void Action::setPriority(int f)
{
    priority = f;
}

void Action::setDes(string d)
{
    description = d;
}

void Action::setEff(string ef)
{
    effCall = ef;
    effList.push_front(ef);
}

void Action::setTargetR(int r)
{
    targetRadius = r;
}

#pragma endregion

Action::~Action()
{
}