//#include "../header/And.hpp"
#include "../header/Executor.hpp"
#include "../header/Connector.hpp"

using namespace std;

And::And(string left, string right) : Connector(){ 
	leftLeaf = left;
	rightLeaf = right;
};

int And::isLeftTrue() {
	//leftLeaf = left;

	Executor toCheck = Executor();
	return toCheck.execute(leftLeaf);

//	return toCheck;
};

int And::isRightTrue() {
        //rightLeaf = right;

        Executor toCheck = Executor();
        return toCheck.execute(rightLeaf);

//        return toCheck;
};
