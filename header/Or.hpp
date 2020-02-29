#ifndef __OR_HPP__
#define __OR_HPP__

#include "Base.hpp"
#include "Parser.hpp"
#include "Executor.hpp"

class Or : public Base {
        private:
                Base* leftNode;
                Base* rightNode;
                int checker;

        public:
                Or(Base* left, Base* right) : Base() {
                        leftNode = left;
                        rightNode = right;

                }

                virtual int evaluate() {
                        checker = leftNode->evaluate();
                        if (checker == 256) {
                                return rightNode->evaluate();
                        }
			else {
				return checker;
			}
                };
};
#endif //__OR_HPP__
