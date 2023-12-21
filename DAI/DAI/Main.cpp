#include "DAI.h"

String CreateNumber() {
	String num = "AC1234AC";
	num.GetStr()[2] = (rand() % 9 + 1) + '0';
	num.GetStr()[3] = (rand() % 10) + '0';
	num.GetStr()[4] = (rand() % 10) + '0';
	num.GetStr()[5] = (rand() % 10) + '0';
	return num;
}

int main() {
	srand(time(0));
	DAI dai;
	String number1 = CreateNumber();
	dai.insert(number1, "fine1");
	dai.insert(number1, "fine2");
	dai.print();
	String number2 = CreateNumber();
	dai.insert(number2, "fine3");
	dai.insert(number1, "fine4");
	String number3 = CreateNumber();
	dai.insert(number3, "fine5");
	dai.insert(number1, "fine6");
	dai.insert(number2, "fine7");
	dai.insert(number3, "fine8");

	dai.print();
}