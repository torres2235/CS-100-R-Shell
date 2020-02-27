#ifndef __SEMI_HPP__
#define __SEMI_HPP__

#include "Connector.hpp"

class Semi : public Connector {
        private:
                std::string leftLeaf;

        public:
                Semi(std::string left) : Connector() { }

                virtual int isLeftTrue();

		virtual int isRightTrue();
}
#endif //__SEMI_HPP__
