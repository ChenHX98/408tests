#pragma once

void q10_swap1(int a, int b, int* R) {
	int h = a, t = b;
	while (a < b) {
		int s = R[a];
		R[a] = R[b];
		R[b] = s;
		a++, b--;
	}
}
void q10_swap(int* R, int n, int p) {
	q10_swap1(0, p - 1, R);
	q10_swap1(p, n - 1, R);
	q10_swap1(0, n - 1, R);
}
//没加相等判断
//void q11(int* s1, int* s2, int n) {
//	int h1 = 0, h2 = 0, t1 = n, t2 = n;
//	while (t1 != h1 && t2 != h2) {
//		int m1 = (t1 - h1) % 2 == 0 ? (t1 - h1) / 2 - 1 : (t1 - h1) / 2;
//		int m2 = (t2 - h2) % 2 == 0 ? (t2 - h2) / 2 - 1 : (t2 - h2) / 2;
//		if (s1[m1] > s2[m2]) {
//			t1 = m1 + 1; h2 = m2;
//			if ((h1 - t1) != (h2 - t2)) {
//				h2--;
//			}
//		}
//		else {
//			t2 = m2 + 1; h1 = m1;
//			if ((h1 - t1) != (h2 - t2)) {
//				h1--;
//			}
//		}
//	}
//}