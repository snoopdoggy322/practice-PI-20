#include <stdio.h>
#include <iostream>
#include <locale>
using namespace std;
struct TDate {
	int Day;
	int Month;
	int Year;
};
int CheckDate(TDate D) {
	if (D.Month < 1 || D.Month > 12)
		return 1;
	if (D.Month % 2 == 1) {
		if (D.Month < 8) {
			if (D.Day < 1 || D.Day > 31)
				return 2;
		}
		else {
			if (D.Day < 1 || D.Day > 30)
				return 2;
		}
	}
	else {
		if (D.Month == 2) {
			if (D.Year % 4 == 0) {
				if (D.Day < 1 || D.Day > 29)
					return 2;
			}
			else {
				if (D.Day < 1 || D.Day > 28)
					return 2;
			}
		}
		else {
			if (D.Month >= 8) {
				if (D.Day < 1 || D.Day > 31)
					return 2;
			}
			else {
				if (D.Day < 1 || D.Day > 30)
					return 2;
			}
		}
	}
	return 0;
}
int main(void) {
	TDate a = { 29, 2, 2035 },
		b = { 29, 2, 2036 },
		c = { 25, 12, 2056 },
		d = { 31, 11, 2001 },
		e = { 30, 4, 2004 },
		g = { 2, 13, 2000 };
	cout « CheckDate(a) « endl;
	cout « CheckDate(b) « endl;
	cout « CheckDate(c) « endl;
	cout « CheckDate(d) « endl;
	cout « CheckDate(e) « endl;
	cout « CheckDate(g) « endl;
}