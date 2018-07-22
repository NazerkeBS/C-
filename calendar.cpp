#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <string>
#include <sstream>
/*
Create a program which handles a calendar. One can insert and fetch events on specific dates.
Sample input: in.txt

add 142 C++ exam
add 143 Another C++ exam
add 143 PSEII finish
add 143 Cooking
add 145 Party on the success of C++ exam
get 145
get 150
*/

using namespace std;

struct pr
{
    string eventName;
    int day;
};

class Calendar
{
private:
    vector <pr> calendar;
public:
    void insert(int d, string name)
    {
        pr p;
        p.eventName = name;
        p.day = d;
        if(calendar.size() != 0)
        {
            for(int i=0; i<calendar.size(); i++)
            {
                if(d == calendar[i].day)
                {
                    p.eventName = calendar[i].eventName + ";" + name;
                    calendar.erase(calendar.begin() + i);
                }
            }
        }
        calendar.push_back(p);

    }

    string fetch(int day)
    {
        for(int i=0; i<calendar.size(); i++)
        {
            if(day == calendar[i].day)
            {
                return calendar[i].eventName;
            }
        }
        return " No event";
    }

    void print()
    {
        for(int i=0; i<calendar.size(); i++)
        {
            int number= (calendar[i].day-1) * 24 * 60 * 60;
            time_t t = number;
            string ttt = asctime(localtime(&t));
            cout << ttt.substr(4,7)  << ": " << calendar[i].eventName << endl;
        }
    }
};

int main()
{
    vector <string> notes;
    ifstream file("in.txt");
    string command;
    int day;
    string eventName;
    Calendar calendar;
    string s;
    while(!file.eof())
    {
        file >> command;
        if(command == "add")
        {
            file >> day;
            getline(file, eventName);
            calendar.insert(day, eventName);

        }
        else if(command == "get")
        {
            file >> day;
            notes.push_back(calendar.fetch(day));
        }
    }

    for(int i=0; i<notes.size(); i++)
    {
        cout << notes[i] << endl;
    }

    calendar.print();

    return 0;
}
