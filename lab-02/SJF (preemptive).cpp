#include <iostream>
using namespace std;

const int N = 1005;

struct Process {
	int pid, burst, wait, arr, fin, tt, st, rem;
}p[N];

void print(int n, double avg_wait, double avg_t) {
	cout << "PID\tStart\tFinish\tWaiting Time\tTurnaround Time" << endl;
	for (int i = 0; i < n; i++) {
		cout << p[i].pid << "\t" << p[i].st << "\t" << p[i].fin << "\t" << p[i].wait << "\t" << p[i].tt << endl;
	}
	cout << "Average Waiting Time : " << avg_wait << endl;
	cout << "Average Turnaround Time : " << avg_t << endl;
}

void findAvgTime(int n) {
	double avg_wait = 0, avg_t = 0;
	for (int i = 0; i < n; i++) {
		avg_wait += p[i].wait;
		avg_t += p[i].tt;
	}
	avg_wait /= n;
	avg_t /= n;
	print(n, avg_wait, avg_t);
}

int main() {
	cout << "Enter total number of processes : ";
	int n;
	cin >> n;
	cout << "Enter the arrival time and burst time of each process : " << endl;
	cout << "Arrival Time\tBurst Time\n";
	int mx = 0;
	for (int i = 0; i < n; i++) {
		p[i].pid = i;
		cin >> p[i].arr >> p[i].burst;
		p[i].rem = p[i].burst;
		p[i].st = -1;
		mx += p[i].burst;
	}
	for (int time = 0; time <= mx; time++) {
		int pid = -1;	
		for (int j = 0; j < n; j++) {
			if (p[j].arr <= time && !p[j].fin && (pid == -1 || p[j].rem < p[pid].rem))
				pid = j;
		}
		if (pid != -1) {
			p[pid].rem--;
			if (p[pid].st == -1)
				p[pid].st = time;
			if (p[pid].rem == 0) {
				p[pid].fin = time + 1;
				p[pid].tt = p[pid].fin - p[pid].arr;
				p[pid].wait = p[pid].tt - p[pid].burst;
			}
		}
	}
	findAvgTime(n);
}