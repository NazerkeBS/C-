#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


class Creature
{
protected:
    string name;
    int distance;
    int water;
public:
    Creature(const string &name, int water)
    {
        this->name=name;
        this->water = water;
        this->distance = 0;
    }

    bool isAlive()
    {
        return water>0;
    }

    virtual void consume(char dayType)=0;
    virtual void step(char dayType)=0;

    int getDistance()
    {
        return distance;
    }
    string getName()
    {
        return name;
    }
};

class Sandwalker : public Creature
{
public:
    Sandwalker(const string &name, int water) : Creature(name,water)
    {
    }
private:
    void consume(char dayType)
    {
        if(isAlive())
        {
            switch(dayType)
            {
            case 's':
                water-=1;
            case 'c':
                water+=0;
            case 'r':
                water+=3;
            }
        }

        if(water>8)
        {
            water=8;
        }

    }
    void step(char dayType)
    {
        if(isAlive())
        {
            switch(dayType)
            {
            case 's' :
                distance+=3;
            case 'c' :
                distance+=1;
            case 'r' :
                distance+=0;
            }

        }
    }

};

class Sponge : public Creature
{

public:
    Sponge(const string &name, int water) : Creature(name,water) {}
private:
    void consume(char dayType)
    {
        if(isAlive())
        {
            switch(dayType)
            {
            case 's':
                water-=4;
            case 'c':
                water-=1;
            case 'r':
                water+=6;
            }

        }
        if(water > 20 )
        {
            water=20;
        }
    }

    void step(char dayType)
    {
        if(isAlive())
        {
            switch(dayType)
            {
            case 's' :
                distance+=0;
            case 'c' :
                distance+=1;
            case 'r' :
                distance +=3;

            }
        }

    }


};

class Wanderer : public Creature
{
public:
    Wanderer(const string &name, int water) : Creature(name,water) {}
private:
    void consume(char dayType)
    {
        if(isAlive())
        {
            switch(dayType)
            {
            case 's':
                water -=2;
            case 'c':
                water -=1;
            case 'r':
                water +=3;
            }
        }

        if(water > 12)
        {
            water=12;
        }
    }

    void step(char dayType)
    {
        if(isAlive())
        {
            switch(dayType)
            {
            case 's':
                distance +=1;
            case 'c':
                distance +=2;
            case 'r':
                distance +=1;
            }
        }

    }
};


Creature* findWinner(Creature* creatures[], int size)
{
    Creature* winner=0;
    for(int i=0; i<size; i++)
    {

        if((creatures[i]->isAlive()) || (winner==0) && creatures[i]->getDistance() > winner->getDistance())
        {
            winner=creatures[i];
        }
    }
    return winner;
}

int main()
{

    Creature* creatures[4];
    ifstream file("creatures.txt");

    if(!file.is_open())
    {
        cout << "file can't be opened." << endl;
        exit(1);
    }
    int cntLines;
    file >> cntLines;
    for(int i=0; i<cntLines; i++)
    {
        string name,type;
        int water;
        file >> name >> type >> water;
        if(type=="sandwalker")
        {
            creatures[i]= new Sandwalker(name,water);
        }
        else if(type=="wanderer")
        {
            creatures[i]=new Wanderer(name,water);
        }
        else if(type=="sponge")
        {
            creatures[i]=new Sponge(name,water);
        }

    }

    string dayTypes;
    file >> dayTypes;
    file.close();

    for(unsigned int j=0; j<dayTypes.size(); j++)
    {
        for(int i=0; i<cntLines; i++)
        {
            creatures[i]->consume(dayTypes[j]);
            creatures[i]->step(dayTypes[j]);
        }

    }

    Creature* winner = findWinner(creatures, cntLines);
    if(winner==0)
    {
        cout << "everyone died" << endl;
    }
    else
    {
        cout <<"Winner: " <<winner->getName() << endl;
    }

    for(int i=0; i<cntLines; i++)
    {
        delete creatures[i];
    }
    return 0;
}
