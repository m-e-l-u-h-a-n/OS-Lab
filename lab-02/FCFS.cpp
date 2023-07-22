#include <iostream>
using namespace std;

const int N = 1005;

struct Process {
	int pid, burst, wait, arr, fin, tt, st;
}p[N];

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// Sorting based on arrival time
void sort(int n) {
	for (int i = 0; i < n; i++) {
		int mn = i;
		for (int j = i+1; j < n; j++) {
			if (p[j].arr < p[mn].arr)
				mn = j;
		}
		swap(p[i].pid, p[mn].pid);
		swap(p[i].arr, p[mn].arr);
		swap(p[i].burst, p[mn].burst);
	}
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
	cout << "Enter the arrival time and burst time of each process : " << endl;
	cout << "Arrival Time\tBurst Time\n";
	for (int i = 0; i < n; i++) {
		p[i].pid = i;
		cin >> p[i].arr >> p[i].burst;
	}
	sort(n);
	p[0].wait = 0;
	p[0].st = p[0].arr;
	p[0].fin = p[0].st + p[0].burst;
	p[0].tt = p[0].burst;
	for (int i = 1; i < n; i++) {
		p[i].st = p[i-1].fin;
		if (p[i].st < p[i].arr)
			p[i].st = p[i].arr;
		p[i].fin = p[i].st + p[i].burst;
		p[i].tt = p[i].fin - p[i].arr;
		p[i].wait = p[i].tt - p[i].burst;
	}
	findAvgTime(n);
}