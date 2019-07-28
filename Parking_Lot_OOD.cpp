#include <bits/stdc++.h>

using namespace std;

class Vehicle{
private:
    char SIZE;
    int level;
    int spot;
public:
    void setSize(char c)    { SIZE = c;  }
    char getSize()          { return SIZE; }
    void parkInSpot(int l,int spt)  {  level = l;   spot = spt;    }
    int getLevel()          {   return level;  }
    int getSpot()           {   return spot;  }
};

class Car : public Vehicle{
public:
    Car()   {   setSize('m');   }
};

class Bike : public Vehicle{
public:
    Bike()  { setSize('s');  }
};

class Bus : public Vehicle{
public:
    Bus()  { setSize('l');  }
};

class Level{
private:
    queue<int> small,med,lg;

public :
    Level(int s,int m, int l)
    {
        for(int i=1;i<=s;++i)   small.push(i);
        for(int i=1;i<=m;++i)   med.push(i);
        for(int i=1;i<=l;++i)   lg.push(i);
    }
    int find_small(){
    if(small.size()!=0) {    int val = small.front();    small.pop();    return val;    }
    return -1;
    }

    int find_med(){
    if(med.size()!=0) {    int val = med.front();    med.pop();    return val;    }
    return -1;
    }

    int find_large(){
    if(lg.size()!=0) {    int val = lg.front();    lg.pop();    return val;    }
    return -1;
    }

    void clear_small(int spot)  {   small.push(spot);  }
    void clear_med(int spot)  {   med.push(spot);  }
    void clear_large(int spot)  {   lg.push(spot);  }

};


class ParkingStruct{
private:
    vector<Level> lvl;

public:
    ParkingStruct()
    {
       Level ll(10,10,10);
       lvl.push_back(ll);
    }

    void show_level(){    cout<<"Total Levels are "<<lvl.size()<<endl;      }


    void add_level(int s,int m,int lg)
    {
        Level l(s,m,lg);
        lvl.push_back(l);
    }

    void park(Vehicle* v)
    {
    int spot,i;
    char sz = v->getSize();
    for(i=0;i<lvl.size();++i)
    {
        if(sz=='s')
        {
            spot = lvl[i].find_small();
            if(spot!=-1)
                break;
        }
        else if(sz=='m')
        {
            spot = lvl[i].find_med();
            if(spot!=-1)
                break;
        }
        else if(sz=='m')
        {
            spot = lvl[i].find_large();
            if(spot!=-1)
                break;
        }
    }

    if(i==lvl.size())   {   cout<<"NO SPACE LEFT\n";    return; }
    cout<<"SPOT FOUND AT LEVEL-"<<i<<" and SLOT - "<<spot<<endl;

    v->parkInSpot(i,spot);

    }

    void unpark(Vehicle* v)
    {
        char sz = v->getSize();
        int l = v->getLevel();
        int spot = v->getSpot();

        if(sz=='s')              lvl[l].clear_small(spot);
        else if(sz=='m')         lvl[l].clear_med(spot);
        else if(sz=='l')         lvl[l].clear_large(spot);
    }
};


int main()
{
    ParkingStruct ps;
    Car c,c1;
    Bike b;
    Bus bb;
    ps.park(&c);
    ps.park(&c1);
    ps.unpark(&c);
}
