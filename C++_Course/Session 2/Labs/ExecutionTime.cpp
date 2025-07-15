#include <iostream>

using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;
};

/*
Time getTimeNow()
{
    Time t = new Time();
    //return current time;
    return t;
}
class ExecutionTime
{
    private:
        Time startTime;
        Time endTime;  
    public:
        ExecutionTime()
        {
            startTime = getTimeNow();
        }
        ~ExecutionTime()
        {
            endTime = getTimeNow();
            int diff = startTime - endTime;
            cout << "Execution time: " << diff << "ms" << endl;
        }
};

void func(void)
{
    ExecutionTime et;
}
*/
int main()
{
    func();
}