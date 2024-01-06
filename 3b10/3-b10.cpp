/*2151133 孙韩雅 信07*/
#include <iostream>
#include<iomanip>
#include <windows.h> 
using namespace std;
int main()
{
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);
	QueryPerformanceCounter(&begin);
	int a, b, c, d, e, f, g, h, i, fir, sec, thi, num=1;
	for (a = 1; a < 10; a++) {
		for (b = 1; b < 10; b++) {
			if (b != a) {
				for (c = 1; c < 10; c++) {
					if (c != a && c != b) {
						fir = 100 * a + 10 * b + c;
						for (d = 1; d < 10; d++) {
							if (d != a && d != b && d != c) {
								for (e = 1; e < 10; e++) {
									if (e != a && e != b && e != c && e != d) {
										for (f = 1; f < 10; f++) {
											if (f != a && f != b && f != c && f != d && f != e) {
												sec = 100 * d + 10 * e + f;
												for (g = 1; g < 10; g++) {
													if (g != a && g != b && g != c && g != d && g != e && g != f) {
														for (h = 1; h < 10; h++) {
															if (h != a && h != b && h != c && h != d && h != e && h != f && h != g) {
																for (i = 1; i < 10; i++) {
																	if (i != a && i != b && i != c && i != d && i != e && i != f && i != g && i != h) {
																		thi = 100 * g + 10 * h + i;
																		if (fir + sec + thi == 1953) {
																			if (fir < sec && sec < thi) {
																				cout << "NO."<< setw(3)<<num<<" : " << fir << "+" << sec << "+" << thi << "=1953" << endl;
																				num++;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout <<"total=" << num - 1 << endl;
	QueryPerformanceCounter(&end);
	cout << "计数器频率：" << tick.QuadPart << "Hz" << endl;
	cout << "时钟计数 ：" << end.QuadPart - begin.QuadPart << endl; 
	cout << setprecision(6) << (end.QuadPart - begin.QuadPart) / double(tick.QuadPart) << "秒" << endl;
	return 0; 
}
