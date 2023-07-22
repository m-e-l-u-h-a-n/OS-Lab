#include <iostream>
using namespace std;

const int N = 1005;

struct Process {
	int pid, burst, wait, arr, fin, tt, st, prior;
}p[N];

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

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
	cout << "Enter the arrival time, burst time and priority of each process : " << endl;
	cout << "Arrival Time\tBurst Time\tPriority\n";
	int mx = 0;
	for (int i = 0; i < n; i++) {
		p[i].pid = i;
		cin >> p[i].arr >> p[i].burst >> p[i].prior;
		mx += p[i].burst;
	}
	int time = 0;
	int i = 0;
	while (time <= mx) {
		int pid = -1;
		for (int j = 0; j < n; j++) {
			// Finding max priority of all arrived processes
			// Assuming small values for priority means higher priority of a process
			if (p[j].arr <= time && !p[j].fin && (pid == -1 || p[j].prior < p[pid].prior))
				pid = j;
		}
		if (pid == -1) {
			time++;
		}
		else {
			swap(p[i].pid, p[pid].pid);
			swap(p[i].arr, p[pid].arr);
			swap(p[i].burst, p[pid].burst);
			swap(p[i].prior, p[pid].prior);
			p[i].st = time;
			p[i].fin = p[i].st + p[i].burst;
			p[i].tt = p[i].fin - p[i].arr;
			p[i].wait = p[i].tt - p[i].burst;
			time = p[i].fin;
			i++;
		}
	}
	findAvgTime(n);
}