/// part time job using greedy method

#include <bits/stdc++.h>
using namespace std;

typedef struct activity
{
    int num;
    int start;
    int duration;
    int finish;
    int level;
} activity;

bool compare(activity a1, activity a2)
{
    return a1.finish < a2.finish;
}

void select_jobs_maximized(activity jobs[], int n_jobs, int dollars, int r_start, int r_end)
{
    activity jobs_up[n_jobs];
    for (int i = 0; i < n_jobs; i++)
    {
        jobs_up[i].num = jobs[i].num;
        jobs_up[i].start = jobs[i].start;
        jobs_up[i].duration = jobs[i].duration;
        jobs_up[i].finish = jobs[i].start + jobs[i].duration;
        jobs_up[i].level = jobs[i].level;
    }
    sort(jobs_up, jobs_up + n_jobs, compare);
    vector<activity> Solution;

    /*
    for(int i=0; i<n_jobs; i++)
    {
        cout << jobs_up[i].num <<" "<< jobs_up[i].start << " " << jobs_up[i].finish << " " << jobs_up[i].level << endl;
    }
    */

    Solution.push_back(jobs_up[0]);
    int last_activity = 0;
    int jobs_count = 1;
    int profit = 0;

    for (int current_activity = 1; current_activity < n_jobs; current_activity++)
    {
        if (r_start <= jobs_up[current_activity].start && r_end >= jobs_up[current_activity].finish)
        {
            if (jobs_up[current_activity].start >= jobs_up[last_activity].finish)
            {
                Solution.push_back(jobs_up[current_activity]);
                last_activity = current_activity;
                jobs_count++;
            }
        }
    }
    profit = dollars * jobs_count;
    cout << "Recommended jobs:" << endl;

    for (activity job : Solution)
    {
        cout << "Job" << job.num << " starts at " << job.start << ",ends at " << job.finish << ", difficulty " << job.level << endl;
    }
    cout << "expected earning " << profit << " dollars" << endl;
}

int main()
{
    int dollars, n_jobs, range_start, range_end;
    cin >> n_jobs;

    activity jobs[n_jobs];
    for (int i = 0; i < n_jobs; i++)
    {
        cin >> jobs[i].start >> jobs[i].duration >> jobs[i].level;
        jobs[i].finish = 0;
        jobs[i].num = i + 1;
    }
    cin >> dollars;
    cin >> range_start >> range_end;

    select_jobs_maximized(jobs, n_jobs, dollars, range_start, range_end);

    return 0;
}
