#include "fir.h"
#include <stdint.h>

//#define reg_fir (*(volatile uint32_t*)0x38000000)

void __attribute__ ( ( section ( ".mprjram" ) ) ) initfir() {
	//initial your fir
  for (int i = 0; i < N; i++) {
    inputbuffer[i] = inputsignal[i];
    outputsignal[i] = 0;
    //taps[i] = coeffs[i];
  }
}



int* __attribute__ ( ( section ( ".mprjram" ) ) ) fir(){
	initfir();
  
  //reg_fir = 0x00000001;
	//write down your fir
  //int sum = 0;
  for(int i = 0; i<N; i++){
    //  sum = 0;
    //calculate sum
    for(int j=0; j<=i; j++){
      outputsignal[i] += taps[j] * inputbuffer[i-j];
    }
    //put sum into outputsignal
    //outputsignal[i] = sum;
  }
	return outputsignal;
}
		

