#ifndef __NB_CSVPLOT
#define __NB_CSVPLOT

#include "nworkbench.h"

class Block_CSVplot: public nBlockSimpleNode<1> {

public:
    nBlock_CSVplot(const char * label1, const char * label2, const char * label3, const char * label4);
    void triggerInput(nBlocks_Message message);
	void endFrame(void);
    uint32_t newValueFLAG;

private:	
    float _ratio1;
    float _ratio2;
    float _ratio3;
    float _ratio4; 
    float _outvalue;
    char string_buffer_in[256];
    char string_buffer_out[256];
    const char * _format;

};
 
#endif