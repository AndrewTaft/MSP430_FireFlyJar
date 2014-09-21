EESchema Schematic File Version 2
LIBS:analog
LIBS:connectors
LIBS:device
LIBS:dp_devices
LIBS:embedded-microcontrollers
LIBS:logic
LIBS:memory
LIBS:microcontrollers
LIBS:MSP430G2553IPW28
LIBS:opto
LIBS:power
LIBS:relay
LIBS:rtx
LIBS:transistor
LIBS:vacuum
LIBS:FireFlyLid v0.2-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "17 mar 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MSP430G2553IPW28 U1
U 1 1 531CDE34
P 1800 1550
F 0 "U1" H 4250 1650 60  0000 C CNN
F 1 "MSP430G2553IPW28" H 3100 250 60  0000 C CNN
F 2 "~" H 1800 1550 60  0000 C CNN
F 3 "~" H 1800 1550 60  0000 C CNN
	1    1800 1550
	1    0    0    -1  
$EndComp
$Comp
L SW_SPDT SW1
U 1 1 531CDE92
P 5850 2700
F 0 "SW1" H 5860 2840 50  0000 C CNN
F 1 "SW_SPDT" H 5850 2605 50  0000 C CNN
F 2 "~" H 5850 2700 60  0000 C CNN
F 3 "~" H 5850 2700 60  0000 C CNN
	1    5850 2700
	1    0    0    -1  
$EndComp
$Comp
L LED LD1
U 1 1 531CDEAC
P 7150 4250
F 0 "LD1" H 7150 4350 40  0000 C CNN
F 1 "LED" H 7150 4150 40  0000 C CNN
F 2 "~" H 7150 4250 60  0000 C CNN
F 3 "~" H 7150 4250 60  0000 C CNN
	1    7150 4250
	0    1    1    0   
$EndComp
$Comp
L BAT BAT1
U 1 1 531CDEFD
P 5700 2400
F 0 "BAT1" H 5845 2430 50  0000 C CNN
F 1 "BAT" H 5840 2365 50  0000 C CNN
F 2 "~" H 5700 2400 60  0000 C CNN
F 3 "~" H 5700 2400 60  0000 C CNN
	1    5700 2400
	-1   0    0    1   
$EndComp
$Comp
L CAP C1
U 1 1 531CED1C
P 2050 1250
F 0 "C1" H 2100 1350 50  0000 L CNN
F 1 "100nF" H 2100 1150 50  0000 L CNN
F 2 "~" H 2050 1250 60  0000 C CNN
F 3 "~" H 2050 1250 60  0000 C CNN
	1    2050 1250
	1    0    0    -1  
$EndComp
$Comp
L MAXIM_MAX44009 U2
U 1 1 531CEE0F
P 8600 2500
F 0 "U2" H 8600 2800 60  0000 C CNN
F 1 "MAXIM_MAX44009" H 8600 2200 60  0000 C CNN
F 2 "~" H 8700 2400 60  0000 C CNN
F 3 "~" H 8700 2400 60  0000 C CNN
	1    8600 2500
	1    0    0    -1  
$EndComp
$Comp
L HEADER_1 J2
U 1 1 531CEF0C
P 5800 4000
F 0 "J2" H 5800 4150 60  0000 C CNN
F 1 "HEADER_1" H 5800 3850 60  0000 C CNN
F 2 "~" H 5800 4000 60  0000 C CNN
F 3 "~" H 5800 4000 60  0000 C CNN
	1    5800 4000
	1    0    0    -1  
$EndComp
$Comp
L HEADER_1 J3
U 1 1 531CEF1B
P 5800 4400
F 0 "J3" H 5800 4550 60  0000 C CNN
F 1 "HEADER_1" H 5800 4250 60  0000 C CNN
F 2 "~" H 5800 4400 60  0000 C CNN
F 3 "~" H 5800 4400 60  0000 C CNN
	1    5800 4400
	1    0    0    -1  
$EndComp
$Comp
L HEADER_4 J1
U 1 1 531CF10D
P 7000 2450
F 0 "J1" H 7000 2700 60  0000 C CNN
F 1 "HEADER_4" H 7000 2200 60  0000 C CNN
F 2 "~" H 7000 2450 60  0000 C CNN
F 3 "~" H 7000 2450 60  0000 C CNN
	1    7000 2450
	1    0    0    -1  
$EndComp
Text Label 3100 4550 0    60   ~ 0
GND
$Comp
L PWR_FLAG #FLG01
U 1 1 531CF540
P 3100 1250
F 0 "#FLG01" H 3100 1345 30  0001 C CNN
F 1 "PWR_FLAG" H 3100 1430 30  0000 C CNN
F 2 "" H 3100 1250 60  0000 C CNN
F 3 "" H 3100 1250 60  0000 C CNN
	1    3100 1250
	1    0    0    -1  
$EndComp
Text Label 1500 2750 2    60   ~ 0
RST
Text Label 1500 2850 2    60   ~ 0
TEST
Text Label 6900 2500 2    60   ~ 0
TEST
Text Label 6900 2600 2    60   ~ 0
RST
Text Label 6900 2400 2    60   ~ 0
GND
Text Label 6900 2300 2    60   ~ 0
VCC
Text Label 3100 1250 2    60   ~ 0
VCC
Text Label 5700 2300 1    60   ~ 0
GND
Text Label 5700 2700 2    60   ~ 0
VCC
Text Label 9150 2400 0    60   ~ 0
SDA
Text Label 9150 2500 0    60   ~ 0
SCL
Text Label 8050 2500 2    60   ~ 0
GND
Text Label 8050 2400 2    60   ~ 0
VCC
Text Label 2050 1150 2    60   ~ 0
VCC
Text Label 2050 1300 2    60   ~ 0
GND
Wire Notes Line
	5400 2050 6250 2050
Wire Notes Line
	6250 2050 6250 2900
Wire Notes Line
	6250 2900 5400 2900
Wire Notes Line
	5400 2900 5400 2050
Text Notes 6150 2000 2    60   ~ 0
BATTERY POWER
Wire Notes Line
	6550 2050 7450 2050
Wire Notes Line
	7450 2050 7450 2900
Wire Notes Line
	7450 2900 6550 2900
Wire Notes Line
	6550 2900 6550 2050
Text Notes 7250 2000 2    60   ~ 0
PROG HEAD
Text Label 5700 4000 2    60   ~ 0
P1.1
Text Label 5700 4400 2    60   ~ 0
P2.3
Wire Notes Line
	5350 3750 6200 3750
Wire Notes Line
	6200 3750 6200 4700
Wire Notes Line
	6200 4700 5350 4700
Wire Notes Line
	5350 4700 5350 3750
Text Notes 6000 3700 2    60   ~ 0
CAP TOUCH
Wire Notes Line
	7750 2050 10600 2050
Wire Notes Line
	10600 2050 10600 2900
Wire Notes Line
	10600 2900 7750 2900
Wire Notes Line
	7750 2900 7750 2050
Text Notes 8900 2000 2    60   ~ 0
LIGHT SENSOR
$Comp
L RESISTOR R30
U 1 1 531CFFC1
P 9900 2450
F 0 "R30" H 9750 2509 50  0000 L BNN
F 1 "10K" H 9750 2320 50  0000 L BNN
F 2 "" H 10150 2900 50  0001 C CNN
F 3 "" H 9900 2450 60  0000 C CNN
	1    9900 2450
	0    -1   -1   0   
$EndComp
$Comp
L RESISTOR R31
U 1 1 531CFFD0
P 9550 2450
F 0 "R31" H 9400 2509 50  0000 L BNN
F 1 "10K" H 9400 2320 50  0000 L BNN
F 2 "" H 9800 2900 50  0001 C CNN
F 3 "" H 9550 2450 60  0000 C CNN
	1    9550 2450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 3150 1400 3150
Wire Wire Line
	1400 3150 1400 3400
Wire Wire Line
	1500 3050 1300 3050
Wire Wire Line
	1300 3050 1300 3400
$Comp
L RESISTOR R1
U 1 1 531D017A
P 7150 4550
F 0 "R1" H 7000 4609 50  0000 L BNN
F 1 "RESISTOR" H 7000 4420 50  0000 L BNN
F 2 "" H 7400 5000 50  0001 C CNN
F 3 "" H 7150 4550 60  0000 C CNN
	1    7150 4550
	0    -1   -1   0   
$EndComp
$Comp
L LED LD2
U 1 1 531D02BF
P 7500 4250
F 0 "LD2" H 7500 4350 40  0000 C CNN
F 1 "LED" H 7500 4150 40  0000 C CNN
F 2 "~" H 7500 4250 60  0000 C CNN
F 3 "~" H 7500 4250 60  0000 C CNN
	1    7500 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R2
U 1 1 531D02C5
P 7500 4550
F 0 "R2" H 7350 4609 50  0000 L BNN
F 1 "RESISTOR" H 7350 4420 50  0000 L BNN
F 2 "" H 7750 5000 50  0001 C CNN
F 3 "" H 7500 4550 60  0000 C CNN
	1    7500 4550
	0    -1   -1   0   
$EndComp
Text Label 1500 1850 2    60   ~ 0
P1.0
Text Label 1500 1950 2    60   ~ 0
P1.1
Text Label 1500 2050 2    60   ~ 0
P1.2
Text Label 1500 2150 2    60   ~ 0
P1.3
Text Label 1500 2250 2    60   ~ 0
P1.4
Text Label 1500 2350 2    60   ~ 0
P1.5
Text Label 4600 2700 0    60   ~ 0
P2.0
Text Label 4600 2800 0    60   ~ 0
P2.1
Text Label 4600 2900 0    60   ~ 0
P2.2
Text Label 4600 3000 0    60   ~ 0
P2.3
Text Label 4600 3100 0    60   ~ 0
P2.4
Text Label 4600 3200 0    60   ~ 0
P2.5
Text Label 4600 3400 0    60   ~ 0
P3.0
Text Label 4600 3500 0    60   ~ 0
P3.1
Text Label 4600 3600 0    60   ~ 0
P3.2
Text Label 4600 3700 0    60   ~ 0
P3.3
Text Label 4600 3800 0    60   ~ 0
P3.4
Text Label 4600 3900 0    60   ~ 0
P3.5
Text Label 4600 4000 0    60   ~ 0
P3.6
Text Label 4600 4100 0    60   ~ 0
P3.7
Text Label 9150 2600 0    60   ~ 0
P3.7
$Comp
L LED LD3
U 1 1 531D02CC
P 7850 4250
F 0 "LD3" H 7850 4350 40  0000 C CNN
F 1 "LED" H 7850 4150 40  0000 C CNN
F 2 "~" H 7850 4250 60  0000 C CNN
F 3 "~" H 7850 4250 60  0000 C CNN
	1    7850 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R3
U 1 1 531D02D2
P 7850 4550
F 0 "R3" H 7700 4609 50  0000 L BNN
F 1 "RESISTOR" H 7700 4420 50  0000 L BNN
F 2 "" H 8100 5000 50  0001 C CNN
F 3 "" H 7850 4550 60  0000 C CNN
	1    7850 4550
	0    -1   -1   0   
$EndComp
Text Label 7150 4750 3    60   ~ 0
GND
Text Label 7500 4750 3    60   ~ 0
GND
Text Label 7850 4750 3    60   ~ 0
GND
$Comp
L LED LD4
U 1 1 531D0430
P 8200 4250
F 0 "LD4" H 8200 4350 40  0000 C CNN
F 1 "LED" H 8200 4150 40  0000 C CNN
F 2 "~" H 8200 4250 60  0000 C CNN
F 3 "~" H 8200 4250 60  0000 C CNN
	1    8200 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R4
U 1 1 531D0436
P 8200 4550
F 0 "R4" H 8050 4609 50  0000 L BNN
F 1 "RESISTOR" H 8050 4420 50  0000 L BNN
F 2 "" H 8450 5000 50  0001 C CNN
F 3 "" H 8200 4550 60  0000 C CNN
	1    8200 4550
	0    -1   -1   0   
$EndComp
$Comp
L LED LD5
U 1 1 531D043C
P 8550 4250
F 0 "LD5" H 8550 4350 40  0000 C CNN
F 1 "LED" H 8550 4150 40  0000 C CNN
F 2 "~" H 8550 4250 60  0000 C CNN
F 3 "~" H 8550 4250 60  0000 C CNN
	1    8550 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R5
U 1 1 531D0442
P 8550 4550
F 0 "R5" H 8400 4609 50  0000 L BNN
F 1 "RESISTOR" H 8400 4420 50  0000 L BNN
F 2 "" H 8800 5000 50  0001 C CNN
F 3 "" H 8550 4550 60  0000 C CNN
	1    8550 4550
	0    -1   -1   0   
$EndComp
$Comp
L LED LD6
U 1 1 531D0448
P 8900 4250
F 0 "LD6" H 8900 4350 40  0000 C CNN
F 1 "LED" H 8900 4150 40  0000 C CNN
F 2 "~" H 8900 4250 60  0000 C CNN
F 3 "~" H 8900 4250 60  0000 C CNN
	1    8900 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R6
U 1 1 531D044E
P 8900 4550
F 0 "R6" H 8750 4609 50  0000 L BNN
F 1 "RESISTOR" H 8750 4420 50  0000 L BNN
F 2 "" H 9150 5000 50  0001 C CNN
F 3 "" H 8900 4550 60  0000 C CNN
	1    8900 4550
	0    -1   -1   0   
$EndComp
Text Label 8200 4750 3    60   ~ 0
GND
Text Label 8550 4750 3    60   ~ 0
GND
Text Label 8900 4750 3    60   ~ 0
GND
$Comp
L LED LD7
U 1 1 531D0457
P 9250 4250
F 0 "LD7" H 9250 4350 40  0000 C CNN
F 1 "LED" H 9250 4150 40  0000 C CNN
F 2 "~" H 9250 4250 60  0000 C CNN
F 3 "~" H 9250 4250 60  0000 C CNN
	1    9250 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R7
U 1 1 531D045D
P 9250 4550
F 0 "R7" H 9100 4609 50  0000 L BNN
F 1 "RESISTOR" H 9100 4420 50  0000 L BNN
F 2 "" H 9500 5000 50  0001 C CNN
F 3 "" H 9250 4550 60  0000 C CNN
	1    9250 4550
	0    -1   -1   0   
$EndComp
$Comp
L LED LD8
U 1 1 531D0463
P 9600 4250
F 0 "LD8" H 9600 4350 40  0000 C CNN
F 1 "LED" H 9600 4150 40  0000 C CNN
F 2 "~" H 9600 4250 60  0000 C CNN
F 3 "~" H 9600 4250 60  0000 C CNN
	1    9600 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R8
U 1 1 531D0469
P 9600 4550
F 0 "R8" H 9450 4609 50  0000 L BNN
F 1 "RESISTOR" H 9450 4420 50  0000 L BNN
F 2 "" H 9850 5000 50  0001 C CNN
F 3 "" H 9600 4550 60  0000 C CNN
	1    9600 4550
	0    -1   -1   0   
$EndComp
Text Label 9250 4750 3    60   ~ 0
GND
Text Label 9600 4750 3    60   ~ 0
GND
$Comp
L LED LD9
U 1 1 531D0471
P 7150 5650
F 0 "LD9" H 7150 5750 40  0000 C CNN
F 1 "LED" H 7150 5550 40  0000 C CNN
F 2 "~" H 7150 5650 60  0000 C CNN
F 3 "~" H 7150 5650 60  0000 C CNN
	1    7150 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R9
U 1 1 531D0477
P 7150 5950
F 0 "R9" H 7000 6009 50  0000 L BNN
F 1 "RESISTOR" H 7000 5820 50  0000 L BNN
F 2 "" H 7400 6400 50  0001 C CNN
F 3 "" H 7150 5950 60  0000 C CNN
	1    7150 5950
	0    -1   -1   0   
$EndComp
$Comp
L LED LD10
U 1 1 531D047D
P 7500 5650
F 0 "LD10" H 7500 5750 40  0000 C CNN
F 1 "LED" H 7500 5550 40  0000 C CNN
F 2 "~" H 7500 5650 60  0000 C CNN
F 3 "~" H 7500 5650 60  0000 C CNN
	1    7500 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R10
U 1 1 531D0483
P 7500 5950
F 0 "R10" H 7350 6009 50  0000 L BNN
F 1 "RESISTOR" H 7350 5820 50  0000 L BNN
F 2 "" H 7750 6400 50  0001 C CNN
F 3 "" H 7500 5950 60  0000 C CNN
	1    7500 5950
	0    -1   -1   0   
$EndComp
$Comp
L LED LD11
U 1 1 531D0489
P 7850 5650
F 0 "LD11" H 7850 5750 40  0000 C CNN
F 1 "LED" H 7850 5550 40  0000 C CNN
F 2 "~" H 7850 5650 60  0000 C CNN
F 3 "~" H 7850 5650 60  0000 C CNN
	1    7850 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R11
U 1 1 531D048F
P 7850 5950
F 0 "R11" H 7700 6009 50  0000 L BNN
F 1 "RESISTOR" H 7700 5820 50  0000 L BNN
F 2 "" H 8100 6400 50  0001 C CNN
F 3 "" H 7850 5950 60  0000 C CNN
	1    7850 5950
	0    -1   -1   0   
$EndComp
Text Label 7150 6150 3    60   ~ 0
GND
Text Label 7500 6150 3    60   ~ 0
GND
Text Label 7850 6150 3    60   ~ 0
GND
$Comp
L LED LD12
U 1 1 531D0498
P 8200 5650
F 0 "LD12" H 8200 5750 40  0000 C CNN
F 1 "LED" H 8200 5550 40  0000 C CNN
F 2 "~" H 8200 5650 60  0000 C CNN
F 3 "~" H 8200 5650 60  0000 C CNN
	1    8200 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R12
U 1 1 531D049E
P 8200 5950
F 0 "R12" H 8050 6009 50  0000 L BNN
F 1 "RESISTOR" H 8050 5820 50  0000 L BNN
F 2 "" H 8450 6400 50  0001 C CNN
F 3 "" H 8200 5950 60  0000 C CNN
	1    8200 5950
	0    -1   -1   0   
$EndComp
$Comp
L LED LD13
U 1 1 531D04A4
P 8550 5650
F 0 "LD13" H 8550 5750 40  0000 C CNN
F 1 "LED" H 8550 5550 40  0000 C CNN
F 2 "~" H 8550 5650 60  0000 C CNN
F 3 "~" H 8550 5650 60  0000 C CNN
	1    8550 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R13
U 1 1 531D04AA
P 8550 5950
F 0 "R13" H 8400 6009 50  0000 L BNN
F 1 "RESISTOR" H 8400 5820 50  0000 L BNN
F 2 "" H 8800 6400 50  0001 C CNN
F 3 "" H 8550 5950 60  0000 C CNN
	1    8550 5950
	0    -1   -1   0   
$EndComp
$Comp
L LED LD14
U 1 1 531D04B0
P 8900 5650
F 0 "LD14" H 8900 5750 40  0000 C CNN
F 1 "LED" H 8900 5550 40  0000 C CNN
F 2 "~" H 8900 5650 60  0000 C CNN
F 3 "~" H 8900 5650 60  0000 C CNN
	1    8900 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R14
U 1 1 531D04B6
P 8900 5950
F 0 "R14" H 8750 6009 50  0000 L BNN
F 1 "RESISTOR" H 8750 5820 50  0000 L BNN
F 2 "" H 9150 6400 50  0001 C CNN
F 3 "" H 8900 5950 60  0000 C CNN
	1    8900 5950
	0    -1   -1   0   
$EndComp
Text Label 8200 6150 3    60   ~ 0
GND
Text Label 8550 6150 3    60   ~ 0
GND
Text Label 8900 6150 3    60   ~ 0
GND
$Comp
L LED LD15
U 1 1 531D04BF
P 9250 5650
F 0 "LD15" H 9250 5750 40  0000 C CNN
F 1 "LED" H 9250 5550 40  0000 C CNN
F 2 "~" H 9250 5650 60  0000 C CNN
F 3 "~" H 9250 5650 60  0000 C CNN
	1    9250 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R15
U 1 1 531D04C5
P 9250 5950
F 0 "R15" H 9100 6009 50  0000 L BNN
F 1 "RESISTOR" H 9100 5820 50  0000 L BNN
F 2 "" H 9500 6400 50  0001 C CNN
F 3 "" H 9250 5950 60  0000 C CNN
	1    9250 5950
	0    -1   -1   0   
$EndComp
$Comp
L LED LD16
U 1 1 531D04CB
P 9600 5650
F 0 "LD16" H 9600 5750 40  0000 C CNN
F 1 "LED" H 9600 5550 40  0000 C CNN
F 2 "~" H 9600 5650 60  0000 C CNN
F 3 "~" H 9600 5650 60  0000 C CNN
	1    9600 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R16
U 1 1 531D04D1
P 9600 5950
F 0 "R16" H 9450 6009 50  0000 L BNN
F 1 "RESISTOR" H 9450 5820 50  0000 L BNN
F 2 "" H 9850 6400 50  0001 C CNN
F 3 "" H 9600 5950 60  0000 C CNN
	1    9600 5950
	0    -1   -1   0   
$EndComp
Text Label 9250 6150 3    60   ~ 0
GND
Text Label 9600 6150 3    60   ~ 0
GND
Text Label 7150 4200 1    60   ~ 0
P1.0
Text Label 7500 4200 1    60   ~ 0
P1.2
Text Label 7850 4200 1    60   ~ 0
P1.4
Text Label 8200 4200 1    60   ~ 0
P1.5
Text Label 8550 4200 1    60   ~ 0
P2.0
Text Label 8900 4200 1    60   ~ 0
P2.1
Text Label 9250 4200 1    60   ~ 0
P2.2
Text Label 9600 4200 1    60   ~ 0
P2.4
Text Label 7150 5600 1    60   ~ 0
P3.0
Text Label 7500 5600 1    60   ~ 0
P3.1
Text Label 7850 5600 1    60   ~ 0
P3.2
Text Label 8200 5600 1    60   ~ 0
P3.3
Text Label 8550 5600 1    60   ~ 0
P3.4
Text Label 8900 5600 1    60   ~ 0
P3.5
Text Label 9250 5600 1    60   ~ 0
P3.6
Text Label 9600 5600 1    60   ~ 0
P1.3
Wire Notes Line
	6700 3750 6700 6550
Wire Notes Line
	6700 6550 10050 6550
Wire Notes Line
	10050 6550 10050 3750
Wire Notes Line
	10050 3750 6700 3750
Text Notes 8550 3700 2    60   ~ 0
LED ARRAY
$Comp
L LED LD17
U 1 1 531D072F
P 4400 5750
F 0 "LD17" H 4400 5850 40  0000 C CNN
F 1 "LED" H 4400 5650 40  0000 C CNN
F 2 "~" H 4400 5750 60  0000 C CNN
F 3 "~" H 4400 5750 60  0000 C CNN
	1    4400 5750
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R17
U 1 1 531D0735
P 4400 6050
F 0 "R17" H 4250 6109 50  0000 L BNN
F 1 "RESISTOR" H 4250 5920 50  0000 L BNN
F 2 "" H 4650 6500 50  0001 C CNN
F 3 "" H 4400 6050 60  0000 C CNN
	1    4400 6050
	0    -1   -1   0   
$EndComp
Text Label 4400 6250 3    60   ~ 0
GND
Text Label 4400 5700 1    60   ~ 0
P2.5
$Comp
L LED LD18
U 1 1 531D073E
P 4750 5750
F 0 "LD18" H 4750 5850 40  0000 C CNN
F 1 "LED" H 4750 5650 40  0000 C CNN
F 2 "~" H 4750 5750 60  0000 C CNN
F 3 "~" H 4750 5750 60  0000 C CNN
	1    4750 5750
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R18
U 1 1 531D0744
P 4750 6050
F 0 "R18" H 4600 6109 50  0000 L BNN
F 1 "RESISTOR" H 4600 5920 50  0000 L BNN
F 2 "" H 5000 6500 50  0001 C CNN
F 3 "" H 4750 6050 60  0000 C CNN
	1    4750 6050
	0    -1   -1   0   
$EndComp
Text Label 4750 6250 3    60   ~ 0
GND
Text Label 4750 5700 1    60   ~ 0
P2.6
$Comp
L LED LD19
U 1 1 531D074F
P 5100 5750
F 0 "LD19" H 5100 5850 40  0000 C CNN
F 1 "LED" H 5100 5650 40  0000 C CNN
F 2 "~" H 5100 5750 60  0000 C CNN
F 3 "~" H 5100 5750 60  0000 C CNN
	1    5100 5750
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R19
U 1 1 531D0755
P 5100 6050
F 0 "R19" H 4950 6109 50  0000 L BNN
F 1 "RESISTOR" H 4950 5920 50  0000 L BNN
F 2 "" H 5350 6500 50  0001 C CNN
F 3 "" H 5100 6050 60  0000 C CNN
	1    5100 6050
	0    -1   -1   0   
$EndComp
Text Label 5100 6250 3    60   ~ 0
GND
Text Label 5100 5700 1    60   ~ 0
P2.7
Wire Notes Line
	4000 5300 5500 5300
Wire Notes Line
	5500 5300 5500 6600
Wire Notes Line
	5500 6600 4000 6600
Wire Notes Line
	4000 6600 4000 5300
Text Notes 5050 5250 2    60   ~ 0
OPTIONAL LEDS
NoConn ~ 6000 2750
Wire Wire Line
	8050 2600 8050 2500
$Comp
L GND #PWR02
U 1 1 531D0B78
P 3100 4550
F 0 "#PWR02" H 3100 4550 30  0001 C CNN
F 1 "GND" H 3100 4480 30  0001 C CNN
F 2 "" H 3100 4550 60  0000 C CNN
F 3 "" H 3100 4550 60  0000 C CNN
	1    3100 4550
	1    0    0    -1  
$EndComp
Text Label 1500 2450 2    60   ~ 0
SCL
Text Label 1500 2550 2    60   ~ 0
SDA
Text Label 9900 2650 3    60   ~ 0
VCC
Text Label 9550 2650 3    60   ~ 0
VCC
Text Label 9550 2250 1    60   ~ 0
SDA
Text Label 9900 2250 1    60   ~ 0
SCL
$Comp
L RESISTOR R20
U 1 1 5320491B
P 1100 2550
F 0 "R20" H 950 2609 50  0000 L BNN
F 1 "47K" H 950 2420 50  0000 L BNN
F 2 "" H 1350 3000 50  0001 C CNN
F 3 "" H 1100 2550 60  0000 C CNN
	1    1100 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 2750 1100 2750
Text Label 1100 2350 1    60   ~ 0
VCC
Text Label 1150 3400 3    60   ~ 0
P2.6
Text Label 1550 3400 3    60   ~ 0
P2.7
$Comp
L CRYSTAL-PLUS_GND X1
U 1 1 5320D7A8
P 1350 3400
F 0 "X1" H 1450 3300 60  0000 C CNN
F 1 "32K" H 1250 3300 60  0000 C CNN
F 2 "~" H 1350 3400 60  0000 C CNN
F 3 "~" H 1350 3400 60  0000 C CNN
	1    1350 3400
	-1   0    0    1   
$EndComp
Text Label 1350 3450 3    60   ~ 0
GND
Wire Wire Line
	5700 2500 6000 2500
Wire Wire Line
	6000 2500 6000 2650
Wire Wire Line
	1300 3400 1150 3400
Wire Wire Line
	1400 3400 1550 3400
$Comp
L RESISTOR R32
U 1 1 53274B95
P 10300 2450
F 0 "R32" H 10150 2509 50  0000 L BNN
F 1 "10K" H 10150 2320 50  0000 L BNN
F 2 "" H 10550 2900 50  0001 C CNN
F 3 "" H 10300 2450 60  0000 C CNN
	1    10300 2450
	0    -1   -1   0   
$EndComp
Text Label 10300 2650 3    60   ~ 0
VCC
Text Label 10300 2250 1    60   ~ 0
P3.7
$Comp
L CAP C2
U 1 1 53274DA8
P 8050 2250
F 0 "C2" H 8100 2350 50  0000 L CNN
F 1 "1uF" H 8150 2250 50  0000 L CNN
F 2 "~" H 8050 2250 60  0000 C CNN
F 3 "~" H 8050 2250 60  0000 C CNN
	1    8050 2250
	1    0    0    -1  
$EndComp
Text Label 8050 2150 2    60   ~ 0
GND
Wire Wire Line
	8050 2400 8050 2300
$EndSCHEMATC