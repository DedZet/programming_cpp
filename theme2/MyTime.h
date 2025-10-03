#pragma once

class MyTime {

    public:
        int hour;
        int min;
        int sec;
    
        MyTime();
        MyTime(int hour, int min, int sec);
    
        void info();
        MyTime add(int sec);
        MyTime sub(int sec);
    
        MyTime mtAdd(MyTime t);
        MyTime mtSub(MyTime t);
};
