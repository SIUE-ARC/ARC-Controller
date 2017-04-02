EESchema Schematic File Version 2
LIBS:74xx
LIBS:adc-dac
LIBS:analog_switches
LIBS:atmel
LIBS:audio
LIBS:cmos4000
LIBS:conn
LIBS:contrib
LIBS:cypress
LIBS:device
LIBS:digital-audio
LIBS:display
LIBS:dsp
LIBS:intel
LIBS:interface
LIBS:linear
LIBS:memory
LIBS:microchip
LIBS:microcontrollers
LIBS:motorola
LIBS:opto
LIBS:philips
LIBS:power
LIBS:regul
LIBS:siliconi
LIBS:texas
LIBS:transistors
LIBS:valves
LIBS:xilinx
LIBS:Connectors
LIBS:c-var
LIBS:cy8c29466-pxi
LIBS:lipo-chips
LIBS:misc
LIBS:opamps
LIBS:psoc4
LIBS:regulators
LIBS:roadrunner
LIBS:tinkerforge
LIBS:FET
LIBS:buck-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L D_Schottky_Small D2
U 1 1 58962EBE
P 5900 4700
F 0 "D2" H 5850 4780 50  0000 L CNN
F 1 "D_Schottky_Small" H 5620 4620 50  0001 L CNN
F 2 "Diodes_SMD:D_SMA_Handsoldering" V 5900 4700 50  0001 C CNN
F 3 "" V 5900 4700 50  0000 C CNN
	1    5900 4700
	-1   0    0    1   
$EndComp
$Comp
L R_Small R1
U 1 1 58962F52
P 6900 4050
F 0 "R1" H 6930 4070 50  0000 L CNN
F 1 "33m" H 6930 4010 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 6900 4050 50  0001 C CNN
F 3 "" H 6900 4050 50  0000 C CNN
	1    6900 4050
	1    0    0    1   
$EndComp
$Comp
L INDUCTOR_SMALL L1
U 1 1 5896391B
P 4950 2600
F 0 "L1" H 4950 2700 50  0000 C CNN
F 1 "22uH" H 4950 2550 50  0000 C CNN
F 2 "Buck:14mm-Inductor" H 4950 2600 50  0001 C CNN
F 3 "" H 4950 2600 50  0000 C CNN
	1    4950 2600
	1    0    0    -1  
$EndComp
$Comp
L R_Small R4
U 1 1 589647B4
P 5250 3300
F 0 "R4" H 5280 3320 50  0000 L CNN
F 1 "3.09M" H 5280 3260 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5250 3300 50  0001 C CNN
F 3 "" H 5250 3300 50  0000 C CNN
	1    5250 3300
	0    1    1    0   
$EndComp
$Comp
L R_Small R3
U 1 1 589647EB
P 4700 3900
F 0 "R3" H 4730 3920 50  0000 L CNN
F 1 "10K" H 4730 3860 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 4700 3900 50  0001 C CNN
F 3 "" H 4700 3900 50  0000 C CNN
	1    4700 3900
	1    0    0    -1  
$EndComp
$Comp
L R_Small R2
U 1 1 58964811
P 4700 3300
F 0 "R2" H 4730 3320 50  0000 L CNN
F 1 "1M" H 4730 3260 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 4700 3300 50  0001 C CNN
F 3 "" H 4700 3300 50  0000 C CNN
	1    4700 3300
	0    1    1    0   
$EndComp
$Comp
L C_Small C5
U 1 1 58964849
P 7250 3800
F 0 "C5" H 7260 3870 50  0000 L CNN
F 1 "1nF" H 7260 3720 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7250 3800 50  0001 C CNN
F 3 "" H 7250 3800 50  0000 C CNN
	1    7250 3800
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C2
U 1 1 58964916
P 4700 4100
F 0 "C2" H 4710 4170 50  0000 L CNN
F 1 "330pF" H 4710 4020 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4700 4100 50  0001 C CNN
F 3 "" H 4700 4100 50  0000 C CNN
	1    4700 4100
	1    0    0    -1  
$EndComp
$Comp
L C_Small C1
U 1 1 5896494D
P 4450 4100
F 0 "C1" H 4460 4170 50  0000 L CNN
F 1 "10nF" H 4460 4020 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4450 4100 50  0001 C CNN
F 3 "" H 4450 4100 50  0000 C CNN
	1    4450 4100
	1    0    0    -1  
$EndComp
$Comp
L CP1_Small C6
U 1 1 5896497F
P 7500 4150
F 0 "C6" H 7510 4220 50  0000 L CNN
F 1 "56uF" H 7510 4070 50  0000 L CNN
F 2 "Capacitors_SMD:CP_Elec_5x5.7" H 7500 4150 50  0001 C CNN
F 3 "" H 7500 4150 50  0000 C CNN
	1    7500 4150
	1    0    0    -1  
$EndComp
$Comp
L CP1_Small C4
U 1 1 58964A61
P 5600 2700
F 0 "C4" H 5610 2770 50  0000 L CNN
F 1 "150uF" H 5610 2620 50  0000 L CNN
F 2 "Capacitors_SMD:CP_Elec_6.3x7.7" H 5600 2700 50  0001 C CNN
F 3 "" H 5600 2700 50  0000 C CNN
	1    5600 2700
	1    0    0    -1  
$EndComp
$Comp
L LTC1771 U1
U 1 1 58964B32
P 5750 3850
F 0 "U1" H 6050 3550 60  0000 C CNN
F 1 "LTC1771" H 5600 4150 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 5750 3400 60  0001 C CNN
F 3 "" H 5750 3400 60  0001 C CNN
	1    5750 3850
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P1
U 1 1 58964CDF
P 3750 3750
F 0 "P1" H 3750 3900 50  0000 C CNN
F 1 "VIN" V 3850 3750 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_PT-3.5mm_2pol" H 3750 3750 50  0001 C CNN
F 3 "" H 3750 3750 50  0000 C CNN
	1    3750 3750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3800 3950 3800 4050
Wire Wire Line
	3800 4050 3900 4050
Wire Wire Line
	3700 3950 3700 4050
Wire Wire Line
	3700 4050 3600 4050
$Comp
L GND #PWR3
U 1 1 58964DDE
P 3900 4050
F 0 "#PWR3" H 3900 3800 50  0001 C CNN
F 1 "GND" H 3900 3900 50  0000 C CNN
F 2 "" H 3900 4050 50  0000 C CNN
F 3 "" H 3900 4050 50  0000 C CNN
	1    3900 4050
	0    -1   -1   0   
$EndComp
$Comp
L +BATT #PWR1
U 1 1 58964E10
P 3600 4050
F 0 "#PWR1" H 3600 3900 50  0001 C CNN
F 1 "+BATT" H 3600 4190 50  0000 C CNN
F 2 "" H 3600 4050 50  0000 C CNN
F 3 "" H 3600 4050 50  0000 C CNN
	1    3600 4050
	0    -1   -1   0   
$EndComp
$Comp
L +BATT #PWR13
U 1 1 5896507A
P 7950 3900
F 0 "#PWR13" H 7950 3750 50  0001 C CNN
F 1 "+BATT" H 7950 4040 50  0000 C CNN
F 2 "" H 7950 3900 50  0000 C CNN
F 3 "" H 7950 3900 50  0000 C CNN
	1    7950 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 3900 7950 3900
$Comp
L GND #PWR6
U 1 1 589650C7
P 4950 4700
F 0 "#PWR6" H 4950 4450 50  0001 C CNN
F 1 "GND" H 4950 4550 50  0000 C CNN
F 2 "" H 4950 4700 50  0000 C CNN
F 3 "" H 4950 4700 50  0000 C CNN
	1    4950 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 4000 5200 4700
Connection ~ 7500 3900
Wire Wire Line
	7500 3800 7500 4050
Wire Wire Line
	6300 3800 7150 3800
Wire Wire Line
	6000 4700 7150 4700
$Comp
L GND #PWR11
U 1 1 589662F9
P 7500 4250
F 0 "#PWR11" H 7500 4000 50  0001 C CNN
F 1 "GND" H 7500 4100 50  0000 C CNN
F 2 "" H 7500 4250 50  0000 C CNN
F 3 "" H 7500 4250 50  0000 C CNN
	1    7500 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3700 6900 3700
Wire Wire Line
	4700 3800 5200 3800
Wire Wire Line
	5200 4700 4700 4700
Wire Wire Line
	4700 4700 4700 4200
Connection ~ 4700 4400
Connection ~ 4950 4700
Wire Wire Line
	4450 4200 4450 4400
Wire Wire Line
	4450 4400 4700 4400
Wire Wire Line
	4450 4000 4450 3700
Wire Wire Line
	4450 3700 5200 3700
Text GLabel 5200 3900 0    60   Input ~ 0
Vfb
$Comp
L C_Small C3
U 1 1 58967E11
P 5250 2950
F 0 "C3" H 5260 3020 50  0000 L CNN
F 1 "15pF" H 5260 2870 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5250 2950 50  0001 C CNN
F 3 "" H 5250 2950 50  0000 C CNN
	1    5250 2950
	0    1    1    0   
$EndComp
Wire Wire Line
	5150 3300 4800 3300
Text GLabel 4950 3150 1    60   Input ~ 0
Vfb
Wire Wire Line
	4950 3300 4950 3150
Connection ~ 4950 3300
$Comp
L GND #PWR5
U 1 1 58967FFD
P 4550 3300
F 0 "#PWR5" H 4550 3050 50  0001 C CNN
F 1 "GND" H 4550 3150 50  0000 C CNN
F 2 "" H 4550 3300 50  0000 C CNN
F 3 "" H 4550 3300 50  0000 C CNN
	1    4550 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 3300 4550 3300
Wire Wire Line
	5150 2950 5050 2950
Wire Wire Line
	5050 2950 5050 3300
Connection ~ 5050 3300
Wire Wire Line
	5450 3300 5350 3300
Wire Wire Line
	5450 2600 5450 3300
Wire Wire Line
	5450 2950 5350 2950
Connection ~ 5450 2950
Text Label 6050 4700 3    60   ~ 0
Vsw
Wire Wire Line
	4700 2600 4450 2600
Text Label 4450 2600 0    60   ~ 0
Vsw
Connection ~ 5450 2600
$Comp
L GND #PWR8
U 1 1 58968BDB
P 5600 2800
F 0 "#PWR8" H 5600 2550 50  0001 C CNN
F 1 "GND" H 5600 2650 50  0000 C CNN
F 2 "" H 5600 2800 50  0000 C CNN
F 3 "" H 5600 2800 50  0000 C CNN
	1    5600 2800
	1    0    0    -1  
$EndComp
Connection ~ 5600 2600
$Comp
L CONN_01X02 P2
U 1 1 58968CD9
P 3750 4550
F 0 "P2" H 3750 4700 50  0000 C CNN
F 1 "VOUT" V 3850 4550 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_PT-3.5mm_2pol" H 3750 4550 50  0001 C CNN
F 3 "" H 3750 4550 50  0000 C CNN
	1    3750 4550
	0    1    1    0   
$EndComp
Wire Wire Line
	5200 2600 5600 2600
$Comp
L +5V #PWR7
U 1 1 58969042
P 5600 2500
F 0 "#PWR7" H 5600 2350 50  0001 C CNN
F 1 "+5V" H 5600 2640 50  0000 C CNN
F 2 "" H 5600 2500 50  0000 C CNN
F 3 "" H 5600 2500 50  0000 C CNN
	1    5600 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2600 5600 2500
$Comp
L +5V #PWR4
U 1 1 589690C9
P 3900 4250
F 0 "#PWR4" H 3900 4100 50  0001 C CNN
F 1 "+5V" H 3900 4390 50  0000 C CNN
F 2 "" H 3900 4250 50  0000 C CNN
F 3 "" H 3900 4250 50  0000 C CNN
	1    3900 4250
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 4350 3800 4250
Wire Wire Line
	3800 4250 3900 4250
$Comp
L GND #PWR2
U 1 1 5896914A
P 3600 4250
F 0 "#PWR2" H 3600 4000 50  0001 C CNN
F 1 "GND" H 3600 4100 50  0000 C CNN
F 2 "" H 3600 4250 50  0000 C CNN
F 3 "" H 3600 4250 50  0000 C CNN
	1    3600 4250
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 4350 3700 4250
Wire Wire Line
	3700 4250 3600 4250
Wire Wire Line
	5650 4700 5800 4700
Text Label 6400 3800 0    60   ~ 0
SENSE
Text Label 6900 3700 0    60   ~ 0
MODE
Text Label 4850 3800 0    60   ~ 0
Ith
Text Label 4550 3700 0    60   ~ 0
RUN/SS
$Comp
L GND #PWR10
U 1 1 5898D751
P 6900 3500
F 0 "#PWR10" H 6900 3250 50  0001 C CNN
F 1 "GND" H 6900 3350 50  0000 C CNN
F 2 "" H 6900 3500 50  0000 C CNN
F 3 "" H 6900 3500 50  0000 C CNN
	1    6900 3500
	-1   0    0    1   
$EndComp
Wire Wire Line
	6900 3700 6900 3500
Wire Wire Line
	6900 3800 6900 3950
Connection ~ 6900 3800
Wire Wire Line
	7350 3800 7500 3800
Wire Wire Line
	6500 3800 6500 4250
Connection ~ 6500 3800
Wire Wire Line
	6900 4150 7300 4150
Wire Wire Line
	7300 4150 7300 3900
Connection ~ 7300 3900
$Comp
L GND #PWR9
U 1 1 58965DDE
P 5650 4700
F 0 "#PWR9" H 5650 4450 50  0001 C CNN
F 1 "GND" H 5650 4550 50  0000 C CNN
F 2 "" H 5650 4700 50  0000 C CNN
F 3 "" H 5650 4700 50  0000 C CNN
	1    5650 4700
	0    1    1    0   
$EndComp
$Comp
L SI3421DV-T1-GE3 U2
U 1 1 58D46DD3
P 6800 5050
F 0 "U2" H 6700 5250 60  0000 C CNN
F 1 "SI3421DV-T1-GE3" H 6800 4850 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-6_Handsoldering" H 6800 4800 60  0001 C CNN
F 3 "" H 6800 4800 60  0001 C CNN
	1    6800 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 4000 6300 5150
Wire Wire Line
	6300 5150 6450 5150
Text Label 6300 5150 0    60   ~ 0
GATE
Wire Wire Line
	6450 4700 6450 5050
Connection ~ 6450 4950
Wire Wire Line
	7150 4700 7150 5050
Connection ~ 6450 4700
Connection ~ 7150 4950
Wire Wire Line
	7150 5150 7300 5150
Wire Wire Line
	7300 5150 7300 4250
Wire Wire Line
	7300 4250 6500 4250
$Comp
L C_Small C7
U 1 1 58E148D1
P 7800 4150
F 0 "C7" H 7810 4220 50  0000 L CNN
F 1 "100nF" H 7810 4070 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7800 4150 50  0001 C CNN
F 3 "" H 7800 4150 50  0000 C CNN
	1    7800 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4050 7800 3900
Connection ~ 7800 3900
$Comp
L GND #PWR12
U 1 1 58E149CA
P 7800 4250
F 0 "#PWR12" H 7800 4000 50  0001 C CNN
F 1 "GND" H 7800 4100 50  0000 C CNN
F 2 "" H 7800 4250 50  0000 C CNN
F 3 "" H 7800 4250 50  0000 C CNN
	1    7800 4250
	1    0    0    -1  
$EndComp
$EndSCHEMATC
