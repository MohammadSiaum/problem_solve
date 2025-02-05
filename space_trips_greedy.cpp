
/// Maximum Space trips using Greedy Algorithm

#include <bits/stdc++.h>
using namespace std;

typedef struct activity
{
    string name;
    int start;
    int duration;
    int finish;

} activity;

bool compare(activity a1, activity a2)
{
    return a1.finish < a2.finish;
}

/*
void duration_convert(activity trips[], int n_trips)
{
    activity trips_update [n_trips];

    for(int i=0; i<n_trips; i++)
    {
        trips_update[i].name     = trips[i].name;
        trips_update[i].start    = trips[i].start;
        trips_update[i].duration = trips[i].duration;
        trips_update[i].finish   = trips[i].start + trips[i].duration;
    }
}
*/

void maximum_profit_by_activity(activity trips[], int trip_amount, int n_trips, int break_time)
{
    activity trips_update[n_trips];

    for (int i = 0; i < n_trips; i++)
    {
        trips_update[i].name = trips[i].name;
        trips_update[i].start = trips[i].start;
        trips_update[i].duration = trips[i].duration;
        trips_update[i].finish = trips[i].start + trips[i].duration;
    }

    sort(trips_update, trips_update + n_trips, compare);

    vector<activity> Selection;

    Selection.push_back(trips_update[0]);
    int last_activity = 0;
    int trip_count = 1;
    int profit = 0;

    for (int current_activity = 1; current_activity < n_trips; current_activity++)
    {
        if (trips_update[current_activity].start >= trips_update[last_activity].finish + break_time)
        {
            Selection.push_back(trips_update[current_activity]);
            last_activity = current_activity;
            trip_count++;
        }
    }
    profit = trip_amount * trip_count;

    cout << endl
         << "Profit : " << trip_count << " x " << trip_amount << " = " << profit << endl;
    cout << "Chosen Tasks :" << endl;

    for (activity ac : Selection)
    {
        cout << ac.name << endl;
    }
}
int main()
{
    int amount, n_trips, break_time;

    cin >> amount >> break_time >> n_trips;
    activity trips[n_trips];

    for (int i = 0; i < n_trips; i++)
    {
        cin >> trips[i].name >> trips[i].start >> trips[i].duration;
        trips[i].finish = 0;
    }

    maximum_profit_by_activity(trips, amount, n_trips, break_time);

    return 0;
}
