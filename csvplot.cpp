#include "csvplot.h"

nBlock_CSVplot::nBlock_CSVplot(const char * label1, const char * label2, const char * label3, const char * label4) {
    _label1 = label1;
    _label2 = label2;
    _label3 = label3;
    _label4 = label4;

    _format = "%f,";
    string_buffer_in[0] = 0; 
	string_buffer_out[0] = 0; 
    outputType[0] = OUTPUT_TYPE_STRING;
}
 
void nBlock_CSVplot::triggerInput(nBlocks_Message message){
    // Any Input triggers an output regardless of value
    // 
    if (message.inputNumber == 0) { 
        sprintf(string_buffer0, _format, message.stringValue);
        x[0] = strlen(string_buffer0);       
    }
    if (message.inputNumber == 1) { 
        sprintf(string_buffer1, _format, message.stringValue);          
        x[1] = strlen(string_buffer1);  
    }
    if (message.inputNumber == 2) {
        sprintf(string_buffer2, _format, message.stringValue);            
        x[2] = strlen(string_buffer2);  
    }
    if (message.inputNumber == 3) { 
        sprintf(string_buffer3, _format, message.stringValue);           
        x[3] = strlen(string_buffer3);  
    }            
}	

void nBlock_CSVplot::endFrame(void) {
	if (x[0] > 0) {
		for (uint32_t i=0; i < x[0]; i++){
			string_buffer_out[i] = string_buffer0[i];
		}
	if (x[1] > 0) {
		for (uint32_t i=x[0]; i < (x[0]+x[1]); i++){
			string_buffer_out[i] = string_buffer0[i];
		}        
		// Output contains pointer to string
		output[0] = (uint32_t)(&string_buffer_out);
	}
    x[0]=0; x[1]=0; x[2]=0; x[3]=0;
    return;	
}
