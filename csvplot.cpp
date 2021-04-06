#include "csvplot.h"

nBlock_CSVplot::nBlock_CSVplot(const char * label1, const char * label2, const char * label3, const char * label4) { 
    _label1 = label1,
    _label2 = label2;
    _label3 = label3;
    _label4 = label4;
    
    stringBuf[0] = 0; 

    outputType[0] = OUTPUT_TYPE_STRING;
    FLAGS =  31;
}

 
void nBlock_CSVplot::triggerInput(nBlocks_Message message){
    // Any Input triggers an output regardless of value
    // 
    if (message.inputNumber == 0) { 
        in[0] = message.floatValue;
        FLAGS = FLAGS+1;
    }
    if (message.inputNumber == 1) { 
        in[1] = message.floatValue;
        FLAGS = FLAGS+2;
    }
    if (message.inputNumber == 2) {
        in[2] = message.floatValue;
        FLAGS = FLAGS+4;  
    }
    if (message.inputNumber == 3) { 
        in[3] = message.floatValue;
        FLAGS = FLAGS+8;  
    }            
}	

void nBlock_CSVplot::endFrame(void) {
	if (FLAGS == 31){
        sprintf(stringBuf, "%s,%s,%s,%s\n", _label1, _label2, _label3, _label4);     
        output[0] = (uint32_t)(&stringBuf);  // Output contains pointer to string
        available[0] = 1;
        FLAGS=0;
    }
	if (FLAGS > 31){
        sprintf(stringBuf, "%s,%s,%s,%s\n%f,%f,%f,%f\n", _label1, _label2, _label3, _label4, in[0], in[1], in[2], in[3]);     
        output[0] = (uint32_t)(&stringBuf);  // Output contains pointer to string
        available[0] = 1;
        FLAGS=0;
    }    

    if (FLAGS == 15) {  
            sprintf(stringBuf, "%f,%f,%f,%f\n", in[0], in[1], in[2], in[3]);     
		    output[0] = (uint32_t)(&stringBuf);  // Output contains pointer to string
            available[0] = 1;
            FLAGS=0;
    }
}    

