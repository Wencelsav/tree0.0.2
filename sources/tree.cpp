
#include "tree_class.cpp"
int main()
{   
	
	std::cout << '\n';
	tree_t<int> tree;
	tree_t<int> tree1{8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
	tree_t<int>  tree2{ 8,4,12,2,6,10,14,1,3,5,7,9,11,13,15 };
	

	std::cout << (tree1==tree2) <<'\n';
	tree1.remove(12);
	tree1.remove(8);
	tree1.print(std::cout);
	std::cout << '\n';
	

	char com;
	while (std::cin >> com && com != 'q') {

		int r = 0;
		bool y = 0;
		switch (com) {
		case '=':
			tree.print(std::cout);
			break;
		case '+':

			if (std::cin >> r) {
				tree.insert(r);
				tree.print(std::cout);
			}
			else {
				std::cout << "Error";
				exit(0);
			}
			break;
		case '?':

			if (std::cin >> r) {
				y = tree.find(r);
				if (y) {
					std::cout << "true" << '\n';
				}
				else {
					std::cout << "false" << '\n';
				}
			}
			else {
				std::cout << "Error";
				exit(0);
			}
			break;
		}

	}

	return 0;
}
