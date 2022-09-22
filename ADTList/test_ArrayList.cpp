#include "ArrayList.h"

int main(int argc, char* argv[])
{
	// ArrayList A;
	// A.insert(34, 0);
	// A.insert(12, 1);
	// A.insert(52, 2);
	// A.insert(16, 3);
	// A.insert(12, 4);
	ArrayList A{34, 12, 52, 16, 12};
	A.printList();

	A.insert(3.14, 2);
	A.printList();

	A.remove(52);
	A.printList();

	std::cout << A.findKth(10) << std::endl;
	return 0;
};
