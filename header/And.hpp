#ifndef __AND_HPP__
#define __AND_HPP__

#include "Base.hpp"
//#include "Parser.hpp"
#include "Executor.hpp"

class And : public Base {
	private:
		Base* leftNode;
		Base* rightNode;
		int checker;

	public:
		And(Base* left, Base* right) : Base() {
			leftNode = left;
			rightNode = right;

		}

		virtual int evaluate() {
			checker = leftNode->evaluate();
			if (checker != 256) {
				return rightNode->evaluate();
			}
			else {
				return checker;
			}
		};
};
#endif //__AND_HPP__
