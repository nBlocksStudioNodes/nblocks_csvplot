#ifndef __NB_CSVPLOT
#define __NB_CSVPLOT

#include "nworkbench.h"

class nBlock_CSVplot: public nBlockSimpleNode<1> {

public:
    nBlock_CSVplot(const char * label1, const char * label2, const char * label3, const char * label4);
    void triggerInput(nBlocks_Message message);
	void endFrame(void);
    uint32_t newValueFLAG;
    uint32_t x0;
    uint32_t x1;
    uint32_t x2;
    uint32_t x3;

        char string_buffer0[32];
    char string_buffer1[32];
    char string_buffer2[32];
    char string_buffer3[32]; 
    char string_buffer0out[32];     
    

private:	
    float _ratio1;
    float _ratio2;
    float _ratio3;
    float _ratio4; 
    float _outvalue;
      

    const char * _label1;
    const char * _label2;
    const char * _label3;
    const char * _label4;

    

};
 
#endif