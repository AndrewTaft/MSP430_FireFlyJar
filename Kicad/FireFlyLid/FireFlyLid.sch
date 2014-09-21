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
LIBS:FireFlyLid-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "21 sep 2014"
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
P 2400 6250
F 0 "SW1" H 2410 6390 50  0000 C CNN
F 1 "SW_SPDT" H 2400 6050 50  0000 C CNN
F 2 "~" H 2400 6250 60  0000 C CNN
F 3 "~" H 2400 6250 60  0000 C CNN
	1    2400 6250
	0    -1   -1   0   
$EndComp
$Comp
L LED LD1
U 1 1 531CDEAC
P 7700 4250
F 0 "LD1" H 7700 4350 40  0000 C CNN
F 1 "LED" H 7700 4150 40  0000 C CNN
F 2 "~" H 7700 4250 60  0000 C CNN
F 3 "~" H 7700 4250 60  0000 C CNN
	1    7700 4250
	0    1    1    0   
$EndComp
$Comp
L BAT BAT1
U 1 1 531CDEFD
P 2150 5800
F 0 "BAT1" H 2295 5830 50  0000 C CNN
F 1 "BAT" H 2290 5765 50  0000 C CNN
F 2 "~" H 2150 5800 60  0000 C CNN
F 3 "~" H 2150 5800 60  0000 C CNN
	1    2150 5800
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
P 5750 2300
F 0 "J2" H 5750 2450 60  0000 C CNN
F 1 "HEADER_1" H 5750 2150 60  0000 C CNN
F 2 "~" H 5750 2300 60  0000 C CNN
F 3 "~" H 5750 2300 60  0000 C CNN
	1    5750 2300
	1    0    0    -1  
$EndComp
$Comp
L HEADER_1 J3
U 1 1 531CEF1B
P 5750 2700
F 0 "J3" H 5750 2850 60  0000 C CNN
F 1 "HEADER_1" H 5750 2550 60  0000 C CNN
F 2 "~" H 5750 2700 60  0000 C CNN
F 3 "~" H 5750 2700 60  0000 C CNN
	1    5750 2700
	1    0    0    -1  
$EndComp
$Comp
L HEADER_4 J1
U 1 1 531CF10D
P 7200 2450
F 0 "J1" H 7200 2700 60  0000 C CNN
F 1 "HEADER_4" H 7200 2200 60  0000 C CNN
F 2 "~" H 7200 2450 60  0000 C CNN
F 3 "~" H 7200 2450 60  0000 C CNN
	1    7200 2450
	1    0    0    -1  
$EndComp
Text Label 3100 4550 0    60   ~ 0
GND
Text Label 1500 2750 2    60   ~ 0
RST
Text Label 1500 2850 2    60   ~ 0
TEST
Text Label 7100 2500 2    60   ~ 0
TEST
Text Label 7100 2600 2    60   ~ 0
RST
Text Label 7100 2400 2    60   ~ 0
GND
Text Label 7100 2300 2    60   ~ 0
PROG_VCC
Text Label 3100 1250 2    60   ~ 0
VCC
Text Label 2150 5700 1    60   ~ 0
GND
Text Label 4000 5900 0    60   ~ 0
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
Text Notes 7250 2000 2    60   ~ 0
PROG HEAD
Text Label 5650 2300 2    60   ~ 0
P1.1
Text Label 5650 2700 2    60   ~ 0
P2.3
Text Notes 5950 2000 2    60   ~ 0
CAP TOUCH
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
$Comp
L RESISTOR R1
U 1 1 531D017A
P 7700 4550
F 0 "R1" H 7550 4609 50  0000 L BNN
F 1 "RESISTOR" H 7550 4420 50  0000 L BNN
F 2 "" H 7950 5000 50  0001 C CNN
F 3 "" H 7700 4550 60  0000 C CNN
	1    7700 4550
	0    -1   -1   0   
$EndComp
$Comp
L LED LD2
U 1 1 531D02BF
P 8050 4250
F 0 "LD2" H 8050 4350 40  0000 C CNN
F 1 "LED" H 8050 4150 40  0000 C CNN
F 2 "~" H 8050 4250 60  0000 C CNN
F 3 "~" H 8050 4250 60  0000 C CNN
	1    8050 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R2
U 1 1 531D02C5
P 8050 4550
F 0 "R2" H 7900 4609 50  0000 L BNN
F 1 "RESISTOR" H 7900 4420 50  0000 L BNN
F 2 "" H 8300 5000 50  0001 C CNN
F 3 "" H 8050 4550 60  0000 C CNN
	1    8050 4550
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
P 8400 4250
F 0 "LD3" H 8400 4350 40  0000 C CNN
F 1 "LED" H 8400 4150 40  0000 C CNN
F 2 "~" H 8400 4250 60  0000 C CNN
F 3 "~" H 8400 4250 60  0000 C CNN
	1    8400 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R3
U 1 1 531D02D2
P 8400 4550
F 0 "R3" H 8250 4609 50  0000 L BNN
F 1 "RESISTOR" H 8250 4420 50  0000 L BNN
F 2 "" H 8650 5000 50  0001 C CNN
F 3 "" H 8400 4550 60  0000 C CNN
	1    8400 4550
	0    -1   -1   0   
$EndComp
Text Label 7700 4750 3    60   ~ 0
GND
Text Label 8050 4750 3    60   ~ 0
GND
Text Label 8400 4750 3    60   ~ 0
GND
$Comp
L LED LD4
U 1 1 531D0430
P 8750 4250
F 0 "LD4" H 8750 4350 40  0000 C CNN
F 1 "LED" H 8750 4150 40  0000 C CNN
F 2 "~" H 8750 4250 60  0000 C CNN
F 3 "~" H 8750 4250 60  0000 C CNN
	1    8750 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R4
U 1 1 531D0436
P 8750 4550
F 0 "R4" H 8600 4609 50  0000 L BNN
F 1 "RESISTOR" H 8600 4420 50  0000 L BNN
F 2 "" H 9000 5000 50  0001 C CNN
F 3 "" H 8750 4550 60  0000 C CNN
	1    8750 4550
	0    -1   -1   0   
$EndComp
$Comp
L LED LD5
U 1 1 531D043C
P 9100 4250
F 0 "LD5" H 9100 4350 40  0000 C CNN
F 1 "LED" H 9100 4150 40  0000 C CNN
F 2 "~" H 9100 4250 60  0000 C CNN
F 3 "~" H 9100 4250 60  0000 C CNN
	1    9100 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R5
U 1 1 531D0442
P 9100 4550
F 0 "R5" H 8950 4609 50  0000 L BNN
F 1 "RESISTOR" H 8950 4420 50  0000 L BNN
F 2 "" H 9350 5000 50  0001 C CNN
F 3 "" H 9100 4550 60  0000 C CNN
	1    9100 4550
	0    -1   -1   0   
$EndComp
$Comp
L LED LD6
U 1 1 531D0448
P 9450 4250
F 0 "LD6" H 9450 4350 40  0000 C CNN
F 1 "LED" H 9450 4150 40  0000 C CNN
F 2 "~" H 9450 4250 60  0000 C CNN
F 3 "~" H 9450 4250 60  0000 C CNN
	1    9450 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R6
U 1 1 531D044E
P 9450 4550
F 0 "R6" H 9300 4609 50  0000 L BNN
F 1 "RESISTOR" H 9300 4420 50  0000 L BNN
F 2 "" H 9700 5000 50  0001 C CNN
F 3 "" H 9450 4550 60  0000 C CNN
	1    9450 4550
	0    -1   -1   0   
$EndComp
Text Label 8750 4750 3    60   ~ 0
GND
Text Label 9100 4750 3    60   ~ 0
GND
Text Label 9450 4750 3    60   ~ 0
GND
$Comp
L LED LD7
U 1 1 531D0457
P 9800 4250
F 0 "LD7" H 9800 4350 40  0000 C CNN
F 1 "LED" H 9800 4150 40  0000 C CNN
F 2 "~" H 9800 4250 60  0000 C CNN
F 3 "~" H 9800 4250 60  0000 C CNN
	1    9800 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R7
U 1 1 531D045D
P 9800 4550
F 0 "R7" H 9650 4609 50  0000 L BNN
F 1 "RESISTOR" H 9650 4420 50  0000 L BNN
F 2 "" H 10050 5000 50  0001 C CNN
F 3 "" H 9800 4550 60  0000 C CNN
	1    9800 4550
	0    -1   -1   0   
$EndComp
$Comp
L LED LD8
U 1 1 531D0463
P 10150 4250
F 0 "LD8" H 10150 4350 40  0000 C CNN
F 1 "LED" H 10150 4150 40  0000 C CNN
F 2 "~" H 10150 4250 60  0000 C CNN
F 3 "~" H 10150 4250 60  0000 C CNN
	1    10150 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R8
U 1 1 531D0469
P 10150 4550
F 0 "R8" H 10000 4609 50  0000 L BNN
F 1 "RESISTOR" H 10000 4420 50  0000 L BNN
F 2 "" H 10400 5000 50  0001 C CNN
F 3 "" H 10150 4550 60  0000 C CNN
	1    10150 4550
	0    -1   -1   0   
$EndComp
Text Label 9800 4750 3    60   ~ 0
GND
Text Label 10150 4750 3    60   ~ 0
GND
$Comp
L LED LD9
U 1 1 531D0471
P 7700 5650
F 0 "LD9" H 7700 5750 40  0000 C CNN
F 1 "LED" H 7700 5550 40  0000 C CNN
F 2 "~" H 7700 5650 60  0000 C CNN
F 3 "~" H 7700 5650 60  0000 C CNN
	1    7700 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R9
U 1 1 531D0477
P 7700 5950
F 0 "R9" H 7550 6009 50  0000 L BNN
F 1 "RESISTOR" H 7550 5820 50  0000 L BNN
F 2 "" H 7950 6400 50  0001 C CNN
F 3 "" H 7700 5950 60  0000 C CNN
	1    7700 5950
	0    -1   -1   0   
$EndComp
$Comp
L LED LD10
U 1 1 531D047D
P 8050 5650
F 0 "LD10" H 8050 5750 40  0000 C CNN
F 1 "LED" H 8050 5550 40  0000 C CNN
F 2 "~" H 8050 5650 60  0000 C CNN
F 3 "~" H 8050 5650 60  0000 C CNN
	1    8050 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R10
U 1 1 531D0483
P 8050 5950
F 0 "R10" H 7900 6009 50  0000 L BNN
F 1 "RESISTOR" H 7900 5820 50  0000 L BNN
F 2 "" H 8300 6400 50  0001 C CNN
F 3 "" H 8050 5950 60  0000 C CNN
	1    8050 5950
	0    -1   -1   0   
$EndComp
$Comp
L LED LD11
U 1 1 531D0489
P 8400 5650
F 0 "LD11" H 8400 5750 40  0000 C CNN
F 1 "LED" H 8400 5550 40  0000 C CNN
F 2 "~" H 8400 5650 60  0000 C CNN
F 3 "~" H 8400 5650 60  0000 C CNN
	1    8400 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R11
U 1 1 531D048F
P 8400 5950
F 0 "R11" H 8250 6009 50  0000 L BNN
F 1 "RESISTOR" H 8250 5820 50  0000 L BNN
F 2 "" H 8650 6400 50  0001 C CNN
F 3 "" H 8400 5950 60  0000 C CNN
	1    8400 5950
	0    -1   -1   0   
$EndComp
Text Label 7700 6150 3    60   ~ 0
GND
Text Label 8050 6150 3    60   ~ 0
GND
Text Label 8400 6150 3    60   ~ 0
GND
$Comp
L LED LD12
U 1 1 531D0498
P 8750 5650
F 0 "LD12" H 8750 5750 40  0000 C CNN
F 1 "LED" H 8750 5550 40  0000 C CNN
F 2 "~" H 8750 5650 60  0000 C CNN
F 3 "~" H 8750 5650 60  0000 C CNN
	1    8750 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R12
U 1 1 531D049E
P 8750 5950
F 0 "R12" H 8600 6009 50  0000 L BNN
F 1 "RESISTOR" H 8600 5820 50  0000 L BNN
F 2 "" H 9000 6400 50  0001 C CNN
F 3 "" H 8750 5950 60  0000 C CNN
	1    8750 5950
	0    -1   -1   0   
$EndComp
$Comp
L LED LD13
U 1 1 531D04A4
P 9100 5650
F 0 "LD13" H 9100 5750 40  0000 C CNN
F 1 "LED" H 9100 5550 40  0000 C CNN
F 2 "~" H 9100 5650 60  0000 C CNN
F 3 "~" H 9100 5650 60  0000 C CNN
	1    9100 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R13
U 1 1 531D04AA
P 9100 5950
F 0 "R13" H 8950 6009 50  0000 L BNN
F 1 "RESISTOR" H 8950 5820 50  0000 L BNN
F 2 "" H 9350 6400 50  0001 C CNN
F 3 "" H 9100 5950 60  0000 C CNN
	1    9100 5950
	0    -1   -1   0   
$EndComp
$Comp
L LED LD14
U 1 1 531D04B0
P 9450 5650
F 0 "LD14" H 9450 5750 40  0000 C CNN
F 1 "LED" H 9450 5550 40  0000 C CNN
F 2 "~" H 9450 5650 60  0000 C CNN
F 3 "~" H 9450 5650 60  0000 C CNN
	1    9450 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R14
U 1 1 531D04B6
P 9450 5950
F 0 "R14" H 9300 6009 50  0000 L BNN
F 1 "RESISTOR" H 9300 5820 50  0000 L BNN
F 2 "" H 9700 6400 50  0001 C CNN
F 3 "" H 9450 5950 60  0000 C CNN
	1    9450 5950
	0    -1   -1   0   
$EndComp
Text Label 8750 6150 3    60   ~ 0
GND
Text Label 9100 6150 3    60   ~ 0
GND
Text Label 9450 6150 3    60   ~ 0
GND
$Comp
L LED LD15
U 1 1 531D04BF
P 9800 5650
F 0 "LD15" H 9800 5750 40  0000 C CNN
F 1 "LED" H 9800 5550 40  0000 C CNN
F 2 "~" H 9800 5650 60  0000 C CNN
F 3 "~" H 9800 5650 60  0000 C CNN
	1    9800 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R15
U 1 1 531D04C5
P 9800 5950
F 0 "R15" H 9650 6009 50  0000 L BNN
F 1 "RESISTOR" H 9650 5820 50  0000 L BNN
F 2 "" H 10050 6400 50  0001 C CNN
F 3 "" H 9800 5950 60  0000 C CNN
	1    9800 5950
	0    -1   -1   0   
$EndComp
$Comp
L LED LD16
U 1 1 531D04CB
P 10150 5650
F 0 "LD16" H 10150 5750 40  0000 C CNN
F 1 "LED" H 10150 5550 40  0000 C CNN
F 2 "~" H 10150 5650 60  0000 C CNN
F 3 "~" H 10150 5650 60  0000 C CNN
	1    10150 5650
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R16
U 1 1 531D04D1
P 10150 5950
F 0 "R16" H 10000 6009 50  0000 L BNN
F 1 "RESISTOR" H 10000 5820 50  0000 L BNN
F 2 "" H 10400 6400 50  0001 C CNN
F 3 "" H 10150 5950 60  0000 C CNN
	1    10150 5950
	0    -1   -1   0   
$EndComp
Text Label 9800 6150 3    60   ~ 0
GND
Text Label 10150 6150 3    60   ~ 0
GND
Text Label 7700 4200 1    60   ~ 0
P1.0
Text Label 8050 4200 1    60   ~ 0
P1.2
Text Label 8400 4200 1    60   ~ 0
P1.4
Text Label 8750 4200 1    60   ~ 0
P1.5
Text Label 9100 4200 1    60   ~ 0
P2.0
Text Label 9450 4200 1    60   ~ 0
P2.1
Text Label 9800 4200 1    60   ~ 0
P2.2
Text Label 10150 4200 1    60   ~ 0
P2.4
Text Label 7700 5600 1    60   ~ 0
P3.0
Text Label 8050 5600 1    60   ~ 0
P3.1
Text Label 8400 5600 1    60   ~ 0
P3.2
Text Label 8750 5600 1    60   ~ 0
P3.3
Text Label 9100 5600 1    60   ~ 0
P3.4
Text Label 9450 5600 1    60   ~ 0
P3.5
Text Label 9800 5600 1    60   ~ 0
P3.6
Text Label 10150 5600 1    60   ~ 0
P1.3
Text Notes 9100 3700 2    60   ~ 0
LED ARRAY
$Comp
L LED LD17
U 1 1 531D072F
P 5950 4200
F 0 "LD17" H 5950 4300 40  0000 C CNN
F 1 "LED" H 5950 4100 40  0000 C CNN
F 2 "~" H 5950 4200 60  0000 C CNN
F 3 "~" H 5950 4200 60  0000 C CNN
	1    5950 4200
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R17
U 1 1 531D0735
P 5950 4500
F 0 "R17" H 5800 4559 50  0000 L BNN
F 1 "RESISTOR" H 5800 4370 50  0000 L BNN
F 2 "" H 6200 4950 50  0001 C CNN
F 3 "" H 5950 4500 60  0000 C CNN
	1    5950 4500
	0    -1   -1   0   
$EndComp
Text Label 5950 4700 3    60   ~ 0
GND
Text Label 5950 4150 1    60   ~ 0
P2.5
$Comp
L LED LD18
U 1 1 531D073E
P 6300 4200
F 0 "LD18" H 6300 4300 40  0000 C CNN
F 1 "LED" H 6300 4100 40  0000 C CNN
F 2 "~" H 6300 4200 60  0000 C CNN
F 3 "~" H 6300 4200 60  0000 C CNN
	1    6300 4200
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R18
U 1 1 531D0744
P 6300 4500
F 0 "R18" H 6150 4559 50  0000 L BNN
F 1 "RESISTOR" H 6150 4370 50  0000 L BNN
F 2 "" H 6550 4950 50  0001 C CNN
F 3 "" H 6300 4500 60  0000 C CNN
	1    6300 4500
	0    -1   -1   0   
$EndComp
Text Label 6300 4700 3    60   ~ 0
GND
Text Label 6300 4150 1    60   ~ 0
P2.6
$Comp
L LED LD19
U 1 1 531D074F
P 6650 4200
F 0 "LD19" H 6650 4300 40  0000 C CNN
F 1 "LED" H 6650 4100 40  0000 C CNN
F 2 "~" H 6650 4200 60  0000 C CNN
F 3 "~" H 6650 4200 60  0000 C CNN
	1    6650 4200
	0    1    1    0   
$EndComp
$Comp
L RESISTOR R19
U 1 1 531D0755
P 6650 4500
F 0 "R19" H 6500 4559 50  0000 L BNN
F 1 "RESISTOR" H 6500 4370 50  0000 L BNN
F 2 "" H 6900 4950 50  0001 C CNN
F 3 "" H 6650 4500 60  0000 C CNN
	1    6650 4500
	0    -1   -1   0   
$EndComp
Text Label 6650 4700 3    60   ~ 0
GND
Text Label 6650 4150 1    60   ~ 0
P2.7
Text Notes 6600 3700 2    60   ~ 0
OPTIONAL LEDS
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
$Comp
L VREG_5PINS-SOT-23-5 VREG1
U 1 1 541ED831
P 3500 6100
F 0 "VREG1" H 3200 6425 50  0000 L BNN
F 1 "VREG_5PINS-SOT-23-5" H 3200 5700 50  0001 L BNN
F 2 "dp_devices-SOT-23-5" H 3550 6550 50  0001 C CNN
F 3 "" H 3500 6100 60  0000 C CNN
	1    3500 6100
	1    0    0    -1  
$EndComp
Text Label 3000 6100 2    60   ~ 0
GND
$Comp
L CAP C4
U 1 1 541EE183
P 4000 6400
F 0 "C4" H 4050 6500 50  0000 L CNN
F 1 "470pF" H 4050 6300 50  0000 L CNN
F 2 "~" H 4000 6400 60  0000 C CNN
F 3 "~" H 4000 6400 60  0000 C CNN
	1    4000 6400
	1    0    0    -1  
$EndComp
Text Label 4000 6450 3    60   ~ 0
GND
$Comp
L CAP C3
U 1 1 541EE195
P 4000 6000
F 0 "C3" H 4050 6100 50  0000 L CNN
F 1 "1uF" H 4050 5900 50  0000 L CNN
F 2 "~" H 4000 6000 60  0000 C CNN
F 3 "~" H 4000 6000 60  0000 C CNN
	1    4000 6000
	1    0    0    -1  
$EndComp
Text Label 4000 6050 3    60   ~ 0
GND
Wire Notes Line
	6550 2050 7450 2050
Wire Notes Line
	7450 2050 7450 2900
Wire Notes Line
	7450 2900 6550 2900
Wire Notes Line
	6550 2900 6550 2050
Wire Notes Line
	5300 2050 6150 2050
Wire Notes Line
	6150 2050 6150 3000
Wire Notes Line
	6150 3000 5300 3000
Wire Notes Line
	5300 3000 5300 2050
Wire Notes Line
	7750 2050 10600 2050
Wire Notes Line
	10600 2050 10600 2900
Wire Notes Line
	10600 2900 7750 2900
Wire Notes Line
	7750 2900 7750 2050
Wire Wire Line
	1500 3150 1400 3150
Wire Wire Line
	1400 3150 1400 3400
Wire Wire Line
	1500 3050 1300 3050
Wire Wire Line
	1300 3050 1300 3400
Wire Notes Line
	7250 3750 7250 6550
Wire Notes Line
	7250 6550 10600 6550
Wire Notes Line
	10600 6550 10600 3750
Wire Notes Line
	10600 3750 7250 3750
Wire Notes Line
	5550 3750 7050 3750
Wire Notes Line
	7050 3750 7050 5050
Wire Notes Line
	7050 5050 5550 5050
Wire Notes Line
	5550 5050 5550 3750
Wire Wire Line
	8050 2600 8050 2500
Wire Wire Line
	1500 2750 1100 2750
Wire Wire Line
	1300 3400 1150 3400
Wire Wire Line
	1400 3400 1550 3400
Wire Wire Line
	8050 2400 8050 2300
Wire Wire Line
	2000 6400 2750 6400
Wire Wire Line
	2750 6400 2750 5900
Wire Wire Line
	2750 5900 3000 5900
Wire Wire Line
	2800 6650 3000 6650
Wire Wire Line
	3000 6650 3000 6300
$Comp
L VDETECTOR_3PINS-SOT-223 VDET1
U 1 1 541EE0CE
P 2400 6650
F 0 "VDET1" H 2100 6800 50  0000 L BNN
F 1 "VDETECTOR_3PINS-SOT-223" H 1950 6900 50  0001 L BNN
F 2 "dp_devices-SOT-223" H 2450 6300 50  0001 C CNN
F 3 "" H 2400 6650 60  0000 C CNN
	1    2400 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 6400 2000 6650
Connection ~ 2400 6400
Text Label 2400 6950 0    60   ~ 0
GND
Wire Notes Line
	1850 5450 1850 7100
Wire Notes Line
	1850 7100 4450 7100
Wire Notes Line
	4450 7100 4450 5450
Wire Notes Line
	4450 5450 1850 5450
Text Notes 2650 5400 0    60   ~ 0
POWER MANAGEMENT
$Comp
L PWR_FLAG #FLG01
U 1 1 541F4567
P 3000 5900
F 0 "#FLG01" H 3000 5995 30  0001 C CNN
F 1 "PWR_FLAG" H 3000 6080 30  0000 C CNN
F 2 "" H 3000 5900 60  0000 C CNN
F 3 "" H 3000 5900 60  0000 C CNN
	1    3000 5900
	1    0    0    -1  
$EndComp
Text Label 2450 6100 1    60   ~ 0
PROG_VCC
Wire Wire Line
	2150 5900 2150 6000
Wire Wire Line
	2150 6000 2350 6000
Wire Wire Line
	2350 6000 2350 6100
$EndSCHEMATC
