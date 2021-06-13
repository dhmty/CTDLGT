#include <iostream>
#include"NHANVIEN.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	SetConsoleTitle("Material Management-CDT");
	RemoveScroll();
	int x = 10, y = 5;
	resizeconsole(1300, 600);
	MenuChinh();
	EscVT();
	return 0;
}
