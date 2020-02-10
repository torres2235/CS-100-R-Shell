#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__

class Connector() {
	/*
        private:
                Connector* leftLeaf;
                Connector* rightLeaf;
	*/
        public:
                Connector() { };
        	virtual bool isLeftTrue() = 0;
		virtual bool isRightTrue() = 0;
		
#endif //__CONNECTOR_HPP__    
