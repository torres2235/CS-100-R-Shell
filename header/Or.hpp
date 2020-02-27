#ifndef __OR_HPP__
#define __OR_HPP__

#include "Connector.hpp"

class Or : public Connector {
        private:
                std::string leftLeaf;
                std::string rightLeaf;

        public:
                Or(Connector* left, Connector* right) : Connector() { }

                virtual int isLeftTrue();

                virtual int isRightTrue();
}
#endif //__OR_HPP__
