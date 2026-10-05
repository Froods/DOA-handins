#include <iostream>

void bookletPrint(int startPage, int endPage) {
	if (startPage >= endPage) return;

	std::cout << "Sheets: " << startPage << ", " << startPage+1 << ", " << endPage-1 << ", " << endPage << "\n";
	bookletPrint(startPage+2, endPage-2); //Ved recursive kald lægges 1 til startPage og 1 trækkes fra endPage for at følge mønsteret 
}

int main() {
	bookletPrint(1,16); //Teste med en bog på 16 sider

	return 0;
}