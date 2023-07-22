#include <iostream>
using namespace std;

const int N = 1005;

struct Process {
	int pid, burst, wait, arr, fin, tt, st, rem;
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

struct queue {
	int queue[N];
	int f = 0, r = 0;
	void push(int n) {
		queue[r++] = n;
		r = r % N;
	}
	int pop() {
		int element = queue[f++];
		f = f % N;
		return element;
	}
	bool isempty() {
		return f == r;
	}
}q;

const int quantum = 4;

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
		p[i].st = -1;
		p[i].rem = p[i].burst;
		mx += p[i].burst;
	}
	int time = 0, prevtime = -1;
	while (time <= mx) {
		while (q.isempty() && time <= mx) {
			for (int j = 0; j < n; j++) {
				// Finding all processes which have arrived
				if (p[j].arr > prevtime && p[j].arr <= time && !p[j].fin)
					q.push(j);
			}
			prevtime = time;
			if (q.isempty()) time++;
		}
		if (time > mx) break;
		int pid = q.pop();
		if (p[pid].st == -1)
			p[pid].st = time;
		if (p[pid].rem <= quantum) {
			prevtime = time;
			time += p[pid].rem;
			p[pid].rem = 0;
			p[pid].fin = time;
			p[pid].tt = p[pid].fin - p[pid].arr;
			p[pid].wait = p[pid].tt - p[pid].burst;
			for (int j = 0; j < n; j++) {
				// Finding all processes which have arrived
				if (p[j].arr > prevtime && p[j].arr <= time && !p[j].fin)
					q.push(j);
			}
		}
		else {
			p[pid].rem -= quantum;
			prevtime = time;
			time += quantum;
			for (int j = 0; j < n; j++) {
				// Finding all processes which have arrived
				if (p[j].arr > prevtime && p[j].arr <= time && !p[j].fin)
					q.push(j);
			}
			q.push(pid);
		}
	}
	findAvgTime(n);
}