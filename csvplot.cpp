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

    //printf("%s, ", _label1);
    //printf("%s, ", _label2);
    //printf("%s, ", _label3);
    //printf("%s\r\n", _label4);
    //output[0] = (uint32_t)_label4;
    //x0 = 1;
}
 
void nBlock_CSVplot::triggerInput(nBlocks_Message message){
    // Any Input triggers an output regardless of value
    // 
    if (message.inputNumber == 0) { 
        const char * lab0;
        lab0 = "%f";
        sprintf(string_buffer0, lab0, message.stringValue);
        x0 = strlen(string_buffer0);
        //printf("string_buffer0 = %s\n", string_buffer0);
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
            // Output contains pointer to string
		    output[0] = (uint32_t)(&string_buffer0);
            available[0] = 1;
            //printf("string_buffer0=%s\n", string_buffer0);
            //printf("output[0]=%s\n", output[0]);
            x0=0;
		}
    }
}
