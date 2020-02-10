#ifndef __SEMI_HPP__
#define __SEMI_HPP__

#include "Connector.hpp"

class Semi : public Connector {
        private:
                Connector* leftLeaf;

        public:
                Semi(Connector* left) : Connector() {
                        leftLeaf = left;
                }

                virtual bool isLeftTrue() { 

                }

#endif //__SEMI_HPP__
