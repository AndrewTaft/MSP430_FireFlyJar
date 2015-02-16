################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
PlaySong.obj: ../PlaySong.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"c:/ti/ccsv6/tools/compiler/msp430_4.3.3/bin/cl430" -vmsp --abi=coffabi -g --include_path="c:/ti/ccsv6/ccs_base/msp430/include" --include_path="c:/ti/ccsv6/tools/compiler/msp430_4.3.3/include" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar/CapTouch" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar/BinaryCodeModulation" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar/I2C" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar" --gcc --define=__MSP430G2553__ --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="PlaySong.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

System.obj: ../System.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"c:/ti/ccsv6/tools/compiler/msp430_4.3.3/bin/cl430" -vmsp --abi=coffabi -g --include_path="c:/ti/ccsv6/ccs_base/msp430/include" --include_path="c:/ti/ccsv6/tools/compiler/msp430_4.3.3/include" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar/CapTouch" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar/BinaryCodeModulation" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar/I2C" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar" --gcc --define=__MSP430G2553__ --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="System.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"c:/ti/ccsv6/tools/compiler/msp430_4.3.3/bin/cl430" -vmsp --abi=coffabi -g --include_path="c:/ti/ccsv6/ccs_base/msp430/include" --include_path="c:/ti/ccsv6/tools/compiler/msp430_4.3.3/include" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar/CapTouch" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar/BinaryCodeModulation" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar/I2C" --include_path="C:/Users/ataft/git/MSP430_FireFlyJar/FireFlyJar" --gcc --define=__MSP430G2553__ --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


