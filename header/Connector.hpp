#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__

using namespace std;
#include <string>
#include "Executor.hpp"
#include "Parser.hpp"

class Connector {
	
        private:
                //int leftBool;
		//int rightBool;
	
        public:
                Connector() { };

        	//virtual setLeftLeaf() = 0;
		//virtual setRightLeaf() = 0;

		virtual int isLeftTrue() = 0;
		virtual int isRightTrue() = 0;

};
#endif //__CONNECTOR_HPP__    
