#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
  
class Activitiy 
{
public: 
    int start, finish; 
}; 
 

void printActivities(vector<Activitiy>& activities)
{
    sort(activities.begin(), activities.end(), [] (Activitiy a, Activitiy b) -> bool { return a.finish < b.finish;});
    int i = 0;
    cout << "Start\tFinish" << endl;
    cout << activities[i].start << "\t" << activities[i].finish << endl;
    for(int curr = 1; curr != activities.size(); curr++)
    {
        if(activities[curr].start >= activities[i].finish)
        {
            cout << activities[curr].start << "\t" << activities[curr].finish << endl;
            i = curr;
        }
    }
}

int main() 
{ 
    vector<Activitiy> activities;
    int start, end;
    while(cin >> start >> end)
        activities.push_back({start, end});
    
    printActivities(activities); 
    return 0; 
} 