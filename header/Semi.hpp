#ifndef __SEMI_HPP__
#define __SEMI_HPP__

#include "Base.hpp"
#include "Parser.hpp"
#include "Executor.hpp"

class Semi : public Base {
        private:
                Base* leftNode;
                Base* rightNode;
                int checker = 0;

        public:
                Semi(Base* left, Base* right) : Base() {
                        leftNode = left;
                        rightNode = right;

                }

                virtual int evaluate() {
                        leftNode->evaluate();
                        rightNode->evaluate();
			return checker;
                };
};
#endif //__SEMI_HPP__
