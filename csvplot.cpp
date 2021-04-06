#include "csvplot.h"

nBlock_CSVplot::nBlock_CSVplot(const char * label1, const char * label2, const char * label3, const char * label4) { 
    _label1 = label1,
    _label2 = label2;
    _label3 = label3;
    _label4 = label4;
    
    string_buffer0[0] = 0; 
    string_buffer1[0] = 0;
    string_buffer2[0] = 0;
    string_buffer3[0] = 0;
    outputType[0] = OUTPUT_TYPE_STRING;
}
 
void nBlock_CSVplot::triggerInput(nBlocks_Message message){
    // Any Input triggers an output regardless of value
    // 
    if (message.inputNumber == 0) { 
        sprintf(string_buffer0, _label1, message.stringValue);
        x0 = strlen(string_buffer0);       
    }
    if (message.inputNumber == 1) { 
        sprintf(string_buffer1, _label2, message.stringValue);          
        x1 = strlen(string_buffer1);  
    }
    if (message.inputNumber == 2) {
        sprintf(string_buffer2, _label3, message.stringValue);            
        x2 = strlen(string_buffer2);  
    }
    if (message.inputNumber == 3) { 
        sprintf(string_buffer3, _label4, message.stringValue);           
        x3 = strlen(string_buffer3);  
    }            
}	

void nBlock_CSVplot::endFrame(void) {
	if (x0 > 0) {
		for (uint32_t i=0; i < x0; i++){
			string_buffer0[i] = string_buffer0[i];
		}
	if (x1 > 0) {
		for (uint32_t i=x1; i < (x0+x1); i++){
			string_buffer1[i] = string_buffer0[i];
		}        
		// Output contains pointer to string
		output[0] = (uint32_t)(&string_buffer0);
	}
    x0=0; x1=0; x2=0; x3=0;
    return;	
    }
}
