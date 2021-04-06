#ifndef __NB_CSVPLOT
#define __NB_CSVPLOT

#include "nworkbench.h"

class nBlock_CSVplot: public nBlockSimpleNode<1> {

public:
    nBlock_CSVplot(const char * label1, const char * label2, const char * label3, const char * label4);
    void triggerInput(nBlocks_Message message);
	void endFrame(void);
    uint32_t newValueFLAG;
    uint32_t FLAGS;

    char stringBuf[64];
    float in[4];
    
    

private:	   
    const char * _label1;
    const char * _label2;
    const char * _label3;
    const char * _label4;

    

};
 
#endif