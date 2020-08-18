#pragma once
/*
 * File:   Log.h
 * Author: Alberto Lepe <dev@alepe.com>
 *
 * Created on December 1, 2015, 6:00 PM
 */

#include <iostream>

using namespace std;

enum Level {
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class LOG {
public:
    LOG() {}
    LOG(Level level) : level(level){

    }
    ~LOG() {
    }
    template<class T>
    LOG& operator<<(const T& msg) {
        cout << msg;
        return *this;
    }
private:
    Level level;
    inline string getLabel(Level level) {
        string label;
        switch (level) {
        case DEBUG: label = "DEBUG"; break;
        case INFO:  label = "INFO "; break;
        case WARN:  label = "WARN "; break;
        case ERROR: label = "ERROR"; break;
        }
        return label;
    }
};