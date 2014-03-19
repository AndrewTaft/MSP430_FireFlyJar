//***************************************************************************************
//  Andrew Taft
//  Nov 2013
//  Built with Code Composer Studio v5
//***************************************************************************************


#ifndef SYSTEM_H_
#define SYSTEM_H_

#define FLOATING_ADC_FOR_RAND	INCH_10  	//temp sensor


void System_InitializeHW(void);
int System_Random(void);

#endif /* SYSTEM_H_ */
