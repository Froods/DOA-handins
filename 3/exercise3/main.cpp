#include <iostream>

void bookletPrint(int startPage, int endPage) {
	if (startPage >= endPage) return;

	std::cout << "Sheets: " << startPage << ", " << startPage+1 << ", " << endPage-1 << ", " << endPage << "\n";
	bookletPrint(startPage+2, endPage-2);
}

int main() {
	bookletPrint(1,16);

	return 0;
}