#ifndef __OR_HPP__
#define __OR_HPP__

#include "Connector.hpp"

class Or : public Connector {
        private:
                Connector* leftLeaf;
                Connector* rightLeaf;

        public:
                Or(Connector* left, Connector* right) : Connector() {
                        leftLeaf = left;
                        rightLeaf = right;
                }

                virtual bool isLeftTrue() { 

                }

                virtual bool isRightTrue() {

                }
#endif //__OR_HPP__
