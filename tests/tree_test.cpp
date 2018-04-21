#include <catch.hpp>
#include <sstream>

#include "tree_class.cpp"

TEST_CASE("insert,print and remove")
{   std::string input{"------------18\n----------------17\n--------16\n------------13\n----10\n--------4\n----------------3\n------------2\n"};
std::string input1{"------------18\n----------------17\n--------16\n----13\n--------4\n----------------3\n------------2\n"};
     std::ostringstream ostream;
    tree_t<int> tree{10,4,16,2,13,18,3,17};
    tree.print(ostream);
    std::cout<<"removing 10:"<<(tree.remove(10)? "removed":"not removed")<<'\n';
    tree.print(ostream);
    REQUIRE(input+input1==ostream.str());
   
}
TEST_CASE("compare"){



    std::ostringstream ostream;
    tree_t<int> tree{10,4,16,2,13,18,3,17};
    tree_t<int> tree1{10,4,16,2,13,18,3,17};
    ostream<<(tree==tree1?"equal\n":"not equal\n");
    tree1.insert(8);
    tree1.insert(9);
    tree1.insert(15);
    ostream<<(tree==tree1?"equal\n":"not equal\n");
    REQUIRE("equal\nnot equal\n"==ostream.str());

}





