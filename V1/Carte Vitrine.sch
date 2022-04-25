EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Carte Vitrine"
Date "2022-04-25"
Rev "V1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Fuse F1
U 1 1 62577618
P 1700 1600
F 0 "F1" V 1600 1550 50  0000 L CNN
F 1 "Fuse" V 1700 1500 50  0000 L CNN
F 2 "ComponentsEvo:8040-PORTE-FUSIBLE" V 1630 1600 50  0001 C CNN
F 3 "~" H 1700 1600 50  0001 C CNN
	1    1700 1600
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 6257CF0D
P 1550 6350
F 0 "R3" H 1620 6396 50  0000 L CNN
F 1 "150" H 1620 6305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1480 6350 50  0001 C CNN
F 3 "~" H 1550 6350 50  0001 C CNN
	1    1550 6350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 6257D07D
P 1850 6350
F 0 "R4" H 1920 6396 50  0000 L CNN
F 1 "150" H 1920 6305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1780 6350 50  0001 C CNN
F 3 "~" H 1850 6350 50  0001 C CNN
	1    1850 6350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 6257D0C3
P 2150 6350
F 0 "R5" H 2220 6396 50  0000 L CNN
F 1 "150" H 2220 6305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2080 6350 50  0001 C CNN
F 3 "~" H 2150 6350 50  0001 C CNN
	1    2150 6350
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 6257DEA3
P 1550 6650
F 0 "D3" H 1600 6550 50  0000 R CNN
F 1 "Green" H 1650 6750 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 1550 6650 50  0001 C CNN
F 3 "~" H 1550 6650 50  0001 C CNN
	1    1550 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D4
U 1 1 6257ECE9
P 1850 6650
F 0 "D4" H 1900 6550 50  0000 R CNN
F 1 "Green" H 1950 6750 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 1850 6650 50  0001 C CNN
F 3 "~" H 1850 6650 50  0001 C CNN
	1    1850 6650
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D5
U 1 1 6257ED47
P 2150 6650
F 0 "D5" H 2200 6550 50  0000 R CNN
F 1 "Green" H 2300 6750 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 2150 6650 50  0001 C CNN
F 3 "~" H 2150 6650 50  0001 C CNN
	1    2150 6650
	0    -1   -1   0   
$EndComp
Text GLabel 6400 2500 0    50   Input ~ 0
BTN_MOVE
Text GLabel 1550 6200 1    50   Input ~ 0
LED_UP
Text GLabel 1850 6200 1    50   Input ~ 0
LED_DOWN
Text GLabel 2150 6200 1    50   Input ~ 0
LED_DETECT
$Comp
L power:+5V #PWR013
U 1 1 6258B409
P 2350 2750
F 0 "#PWR013" H 2350 2600 50  0001 C CNN
F 1 "+5V" H 2350 2900 50  0000 C CNN
F 2 "" H 2350 2750 50  0001 C CNN
F 3 "" H 2350 2750 50  0001 C CNN
	1    2350 2750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR015
U 1 1 6258BEF9
P 3250 1000
F 0 "#PWR015" H 3250 850 50  0001 C CNN
F 1 "+5V" H 3265 1173 50  0000 C CNN
F 2 "" H 3250 1000 50  0001 C CNN
F 3 "" H 3250 1000 50  0001 C CNN
	1    3250 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 1600 2200 1650
Wire Wire Line
	1850 6800 1850 7000
Wire Wire Line
	1550 6800 1550 7000
Wire Wire Line
	2150 6800 2150 7000
Wire Wire Line
	2150 7000 1850 7000
Text GLabel 3550 2400 0    50   Output ~ 0
SERVO_RIGHT
Text GLabel 3550 2500 0    50   Output ~ 0
SERVO_LEFT
Text GLabel 4550 2200 2    50   Input ~ 0
BTN_MOVE
Text GLabel 4550 2000 2    50   Input ~ 0
CAPTEUR_1
Text GLabel 4550 2100 2    50   Input ~ 0
CAPTEUR_2
Text GLabel 3550 1700 0    50   Output ~ 0
LEDSTRIP_1
Text GLabel 3550 1600 0    50   Output ~ 0
LED_UP
Text GLabel 3550 2200 0    50   Output ~ 0
LED_DOWN
Text GLabel 3550 2600 0    50   Output ~ 0
LED_DETECT
NoConn ~ 4550 1400
NoConn ~ 4550 1500
NoConn ~ 4550 1800
NoConn ~ 4550 2400
NoConn ~ 4550 2500
NoConn ~ 4550 2600
NoConn ~ 4550 2700
NoConn ~ 3550 2700
NoConn ~ 4150 1000
NoConn ~ 3550 1400
NoConn ~ 3550 1500
$Comp
L ComponentsEvo:MP1584EB U1
U 1 1 62583128
P 1450 2850
F 0 "U1" H 1350 2850 50  0000 L CNN
F 1 "MP1584EB" H 1250 3100 50  0000 L CNN
F 2 "ComponentsEvo:MP1584EN" H 1450 2500 50  0001 C CNN
F 3 "" H 1450 2500 50  0001 C CNN
	1    1450 2850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR09
U 1 1 625955AF
P 1850 4150
F 0 "#PWR09" H 1850 4000 50  0001 C CNN
F 1 "+5V" H 1750 4300 50  0000 L CNN
F 2 "" H 1850 4150 50  0001 C CNN
F 3 "" H 1850 4150 50  0001 C CNN
	1    1850 4150
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR05
U 1 1 6259616B
P 1300 3700
F 0 "#PWR05" H 1300 3550 50  0001 C CNN
F 1 "+12V" H 1200 3850 50  0000 L CNN
F 2 "" H 1300 3700 50  0001 C CNN
F 3 "" H 1300 3700 50  0001 C CNN
	1    1300 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR010
U 1 1 6259777A
P 1950 4950
F 0 "#PWR010" H 1950 4800 50  0001 C CNN
F 1 "+5V" H 1850 5100 50  0000 L CNN
F 2 "" H 1950 4950 50  0001 C CNN
F 3 "" H 1950 4950 50  0001 C CNN
	1    1950 4950
	1    0    0    -1  
$EndComp
Text GLabel 2300 4750 0    50   Input ~ 0
AIN1
Text GLabel 2300 4850 0    50   Input ~ 0
AIN2
Text GLabel 2300 4550 0    50   Input ~ 0
BIN1
Text GLabel 2300 4450 0    50   Input ~ 0
BIN2
Text GLabel 3550 1800 0    50   Output ~ 0
BIN2
Text GLabel 3550 1900 0    50   Output ~ 0
BIN1
Text GLabel 3550 2100 0    50   Output ~ 0
AIN2
Text GLabel 3550 2000 0    50   Output ~ 0
AIN1
Connection ~ 2200 1600
NoConn ~ 2300 4650
$Comp
L Device:CP_Small C3
U 1 1 6259ABCE
P 2200 1750
F 0 "C3" H 2288 1796 50  0000 L CNN
F 1 "470uF" H 2288 1705 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 2200 1750 50  0001 C CNN
F 3 "~" H 2200 1750 50  0001 C CNN
	1    2200 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C4
U 1 1 6259E130
P 2200 2850
F 0 "C4" H 2300 2900 50  0000 L CNN
F 1 "330uF" H 2300 2800 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 2200 2850 50  0001 C CNN
F 3 "~" H 2200 2850 50  0001 C CNN
	1    2200 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C1
U 1 1 625A8C24
P 1550 3950
F 0 "C1" H 1350 4000 50  0000 C CNN
F 1 "180uF" H 1350 3900 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 1550 3950 50  0001 C CNN
F 3 "~" H 1550 3950 50  0001 C CNN
	1    1550 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 625AB896
P 1950 4250
F 0 "C2" H 2100 4200 50  0000 C CNN
F 1 "100nF" H 2150 4300 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1950 4250 50  0001 C CNN
F 3 "~" H 1950 4250 50  0001 C CNN
	1    1950 4250
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C5
U 1 1 625ADBF2
P 3350 1100
F 0 "C5" H 3442 1146 50  0000 L CNN
F 1 "100nF" H 3442 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3350 1100 50  0001 C CNN
F 3 "~" H 3350 1100 50  0001 C CNN
	1    3350 1100
	-1   0    0    -1  
$EndComp
Text GLabel 3550 2300 0    50   Output ~ 0
LEDSTRIP_2
$Comp
L power:GND #PWR014
U 1 1 625DC50C
P 2350 2950
F 0 "#PWR014" H 2350 2700 50  0001 C CNN
F 1 "GND" H 2355 2777 50  0000 C CNN
F 2 "" H 2350 2950 50  0001 C CNN
F 3 "" H 2350 2950 50  0001 C CNN
	1    2350 2950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 625DDB5A
P 2200 1850
F 0 "#PWR011" H 2200 1600 50  0001 C CNN
F 1 "GND" H 2205 1677 50  0000 C CNN
F 2 "" H 2200 1850 50  0001 C CNN
F 3 "" H 2200 1850 50  0001 C CNN
	1    2200 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 625DE95F
P 4050 3000
F 0 "#PWR017" H 4050 2750 50  0001 C CNN
F 1 "GND" H 4055 2827 50  0000 C CNN
F 2 "" H 4050 3000 50  0001 C CNN
F 3 "" H 4050 3000 50  0001 C CNN
	1    4050 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 625F730F
P 1450 4350
F 0 "#PWR06" H 1450 4100 50  0001 C CNN
F 1 "GND" H 1455 4177 50  0000 C CNN
F 2 "" H 1450 4350 50  0001 C CNN
F 3 "" H 1450 4350 50  0001 C CNN
	1    1450 4350
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male BATT1
U 1 1 625E244B
P 1300 1050
F 0 "BATT1" H 950 1050 50  0000 C CNN
F 1 "Conn_01x02_Male" H 950 950 50  0000 C CNN
F 2 "ConnectorsEvo:649002227222" H 1300 1050 50  0001 C CNN
F 3 "~" H 1300 1050 50  0001 C CNN
	1    1300 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 625E3859
P 1500 1150
F 0 "#PWR07" H 1500 900 50  0001 C CNN
F 1 "GND" H 1505 977 50  0000 C CNN
F 2 "" H 1500 1150 50  0001 C CNN
F 3 "" H 1500 1150 50  0001 C CNN
	1    1500 1150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male BAU1
U 1 1 625E439A
P 1300 1500
F 0 "BAU1" H 950 1500 50  0000 C CNN
F 1 "Conn_01x02_Male" H 950 1400 50  0000 C CNN
F 2 "ConnectorsEvo:649002227222" H 1300 1500 50  0001 C CNN
F 3 "~" H 1300 1500 50  0001 C CNN
	1    1300 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1600 1550 1600
Wire Wire Line
	1500 1500 1650 1500
Wire Wire Line
	1650 1500 1650 1050
Wire Wire Line
	1650 1050 1500 1050
Wire Wire Line
	1850 1600 2200 1600
Wire Wire Line
	2100 2750 2200 2750
Connection ~ 2200 2750
Wire Wire Line
	2200 2750 2350 2750
Wire Wire Line
	2350 2950 2200 2950
Connection ~ 2200 2950
Wire Wire Line
	2200 2950 2100 2950
$Comp
L power:+12V #PWR01
U 1 1 625F6F4F
P 750 2750
F 0 "#PWR01" H 750 2600 50  0001 C CNN
F 1 "+12V" H 750 2950 50  0000 C CNN
F 2 "" H 750 2750 50  0001 C CNN
F 3 "" H 750 2750 50  0001 C CNN
	1    750  2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	750  2750 800  2750
$Comp
L power:GND #PWR02
U 1 1 625F89A0
P 750 2950
F 0 "#PWR02" H 750 2700 50  0001 C CNN
F 1 "GND" H 755 2777 50  0000 C CNN
F 2 "" H 750 2950 50  0001 C CNN
F 3 "" H 750 2950 50  0001 C CNN
	1    750  2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	750  2950 800  2950
Wire Wire Line
	4050 3000 4150 3000
Wire Wire Line
	3350 1000 3950 1000
Connection ~ 4050 3000
$Comp
L MCU_Module:Arduino_Nano_v3.x U3
U 1 1 6257379F
P 4050 2000
F 0 "U3" H 4050 1850 50  0000 C CNN
F 1 "Arduino Nano" H 4050 2000 50  0000 C CNN
F 2 "ComponentsEvo:ArduinoNano" H 4050 2000 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 4050 2000 50  0001 C CNN
	1    4050 2000
	1    0    0    -1  
$EndComp
NoConn ~ 4250 1000
Connection ~ 3350 1000
$Comp
L power:GND #PWR016
U 1 1 626116CE
P 3350 1200
F 0 "#PWR016" H 3350 950 50  0001 C CNN
F 1 "GND" H 3355 1027 50  0000 C CNN
F 2 "" H 3350 1200 50  0001 C CNN
F 3 "" H 3350 1200 50  0001 C CNN
	1    3350 1200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Male Motor1
U 1 1 6261FC6B
P 4000 4350
F 0 "Motor1" H 3972 4374 50  0000 R CNN
F 1 "Conn_01x05_Male" H 3972 4283 50  0000 R CNN
F 2 "Connector_JST:JST_XH_B5B-XH-A_1x05_P2.50mm_Vertical" H 4000 4350 50  0001 C CNN
F 3 "~" H 4000 4350 50  0001 C CNN
	1    4000 4350
	-1   0    0    1   
$EndComp
Wire Wire Line
	3200 4450 3200 4500
$Comp
L ComponentsEvo:TB6612FNG U2
U 1 1 625943A2
P 2750 4500
F 0 "U2" H 2750 4500 50  0000 C CNN
F 1 "TB6612FNG" H 2850 5000 50  0000 C CNN
F 2 "ComponentsEvo:TB6612FNG" H 2850 3600 50  0001 C CNN
F 3 "" H 2850 3600 50  0001 C CNN
	1    2750 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 4150 2150 4150
Connection ~ 1950 4150
Wire Wire Line
	2300 4250 2050 4250
Wire Wire Line
	2050 4250 2050 4350
Wire Wire Line
	2050 4350 1950 4350
Connection ~ 1950 4350
Wire Wire Line
	1550 4050 1550 4350
Wire Wire Line
	1550 4350 1950 4350
Wire Wire Line
	1550 3850 2300 3850
Wire Wire Line
	2300 3850 2300 4050
Connection ~ 1550 3850
Wire Wire Line
	2300 4350 2150 4350
Wire Wire Line
	2150 4350 2150 4150
Connection ~ 2150 4150
Wire Wire Line
	2150 4150 2300 4150
Wire Wire Line
	1950 4950 2300 4950
$Comp
L power:+5V #PWR026
U 1 1 62652760
P 6300 2400
F 0 "#PWR026" H 6300 2250 50  0001 C CNN
F 1 "+5V" H 6200 2550 50  0000 L CNN
F 2 "" H 6300 2400 50  0001 C CNN
F 3 "" H 6300 2400 50  0001 C CNN
	1    6300 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C7
U 1 1 6265276A
P 5800 1750
F 0 "C7" H 5600 1700 50  0000 L CNN
F 1 "4.7uF" H 5500 1800 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5800 1750 50  0001 C CNN
F 3 "~" H 5800 1750 50  0001 C CNN
	1    5800 1750
	1    0    0    1   
$EndComp
$Comp
L Connector:Conn_01x03_Male Servo2
U 1 1 62652774
P 6550 1650
F 0 "Servo2" H 6522 1674 50  0000 R CNN
F 1 "Conn_01x03_Male" H 6522 1583 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6550 1650 50  0001 C CNN
F 3 "~" H 6550 1650 50  0001 C CNN
	1    6550 1650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6350 1650 5800 1650
Wire Wire Line
	5700 1850 5800 1850
Wire Wire Line
	6350 1850 6350 1750
$Comp
L power:GND #PWR021
U 1 1 62652782
P 5700 1850
F 0 "#PWR021" H 5700 1600 50  0001 C CNN
F 1 "GND" H 5705 1677 50  0000 C CNN
F 2 "" H 5700 1850 50  0001 C CNN
F 3 "" H 5700 1850 50  0001 C CNN
	1    5700 1850
	1    0    0    -1  
$EndComp
Text GLabel 6350 1550 0    50   Input ~ 0
SERVO_LEFT
$Comp
L Connector:Conn_01x02_Male Button1
U 1 1 626593BC
P 6600 2400
F 0 "Button1" H 6572 2374 50  0000 R CNN
F 1 "Conn_01x02_Male" H 6572 2283 50  0000 R CNN
F 2 "ConnectorsEvo:B02B-PASK" H 6600 2400 50  0001 C CNN
F 3 "~" H 6600 2400 50  0001 C CNN
	1    6600 2400
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male Sensor1
U 1 1 6265CFDE
P 6650 2900
F 0 "Sensor1" H 6622 2924 50  0000 R CNN
F 1 "Conn_01x03_Male" H 6622 2833 50  0000 R CNN
F 2 "ConnectorsEvo:B03B-PASK" H 6650 2900 50  0001 C CNN
F 3 "~" H 6650 2900 50  0001 C CNN
	1    6650 2900
	-1   0    0    -1  
$EndComp
$Comp
L power:+12V #PWR027
U 1 1 6265DFAD
P 6350 2800
F 0 "#PWR027" H 6350 2650 50  0001 C CNN
F 1 "+12V" H 6250 2950 50  0000 L CNN
F 2 "" H 6350 2800 50  0001 C CNN
F 3 "" H 6350 2800 50  0001 C CNN
	1    6350 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 6265EDFF
P 6150 2900
F 0 "R6" V 6100 2700 50  0000 C CNN
F 1 "10k" V 6100 3100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6080 2900 50  0001 C CNN
F 3 "~" H 6150 2900 50  0001 C CNN
	1    6150 2900
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 2900 6450 2900
Text GLabel 5800 2900 0    50   Input ~ 0
CAPTEUR_1
Wire Wire Line
	5800 2900 5850 2900
$Comp
L Device:R R7
U 1 1 62662EDA
P 6150 3000
F 0 "R7" V 6100 2800 50  0000 C CNN
F 1 "4.7k" V 6100 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6080 3000 50  0001 C CNN
F 3 "~" H 6150 3000 50  0001 C CNN
	1    6150 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 3000 5850 3000
Wire Wire Line
	5850 3000 5850 2900
Connection ~ 5850 2900
Wire Wire Line
	5850 2900 6000 2900
Wire Wire Line
	6300 3000 6350 3000
$Comp
L power:GND #PWR028
U 1 1 62666293
P 6350 3000
F 0 "#PWR028" H 6350 2750 50  0001 C CNN
F 1 "GND" H 6355 2827 50  0000 C CNN
F 2 "" H 6350 3000 50  0001 C CNN
F 3 "" H 6350 3000 50  0001 C CNN
	1    6350 3000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male Sensor2
U 1 1 62669907
P 6650 3550
F 0 "Sensor2" H 6622 3574 50  0000 R CNN
F 1 "Conn_01x03_Male" H 6622 3483 50  0000 R CNN
F 2 "ConnectorsEvo:B03B-PASK" H 6650 3550 50  0001 C CNN
F 3 "~" H 6650 3550 50  0001 C CNN
	1    6650 3550
	-1   0    0    -1  
$EndComp
$Comp
L power:+12V #PWR029
U 1 1 62669911
P 6350 3450
F 0 "#PWR029" H 6350 3300 50  0001 C CNN
F 1 "+12V" H 6250 3600 50  0000 L CNN
F 2 "" H 6350 3450 50  0001 C CNN
F 3 "" H 6350 3450 50  0001 C CNN
	1    6350 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 6266991B
P 6150 3550
F 0 "R8" V 6100 3350 50  0000 C CNN
F 1 "10k" V 6100 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6080 3550 50  0001 C CNN
F 3 "~" H 6150 3550 50  0001 C CNN
	1    6150 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 3550 6450 3550
Text GLabel 5800 3550 0    50   Input ~ 0
CAPTEUR_2
Wire Wire Line
	5800 3550 5850 3550
$Comp
L Device:R R9
U 1 1 62669928
P 6150 3650
F 0 "R9" V 6100 3450 50  0000 C CNN
F 1 "4.7k" V 6100 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6080 3650 50  0001 C CNN
F 3 "~" H 6150 3650 50  0001 C CNN
	1    6150 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 3650 5850 3650
Wire Wire Line
	5850 3650 5850 3550
Connection ~ 5850 3550
Wire Wire Line
	5850 3550 6000 3550
Wire Wire Line
	6300 3650 6350 3650
$Comp
L power:GND #PWR030
U 1 1 62669937
P 6350 3650
F 0 "#PWR030" H 6350 3400 50  0001 C CNN
F 1 "GND" H 6355 3477 50  0000 C CNN
F 2 "" H 6350 3650 50  0001 C CNN
F 3 "" H 6350 3650 50  0001 C CNN
	1    6350 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C8
U 1 1 6266E9BD
P 5800 4300
F 0 "C8" H 5650 4350 50  0000 C CNN
F 1 "4.7uF" H 5600 4250 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5800 4300 50  0001 C CNN
F 3 "~" H 5800 4300 50  0001 C CNN
	1    5800 4300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male Ledstrip1
U 1 1 6266ED53
P 6600 4300
F 0 "Ledstrip1" H 6572 4324 50  0000 R CNN
F 1 "Conn_01x03_Male" H 6572 4233 50  0000 R CNN
F 2 "ConnectorsEvo:B03B-PASK" H 6600 4300 50  0001 C CNN
F 3 "~" H 6600 4300 50  0001 C CNN
	1    6600 4300
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR022
U 1 1 6266FCD7
P 5700 4200
F 0 "#PWR022" H 5700 4050 50  0001 C CNN
F 1 "+5V" H 5600 4350 50  0000 L CNN
F 2 "" H 5700 4200 50  0001 C CNN
F 3 "" H 5700 4200 50  0001 C CNN
	1    5700 4200
	1    0    0    -1  
$EndComp
Text GLabel 6400 4300 0    50   Input ~ 0
LEDSTRIP_1
Wire Wire Line
	5800 4200 6400 4200
Connection ~ 5800 4200
Wire Wire Line
	6400 4400 5800 4400
$Comp
L power:GND #PWR023
U 1 1 62674793
P 5700 4400
F 0 "#PWR023" H 5700 4150 50  0001 C CNN
F 1 "GND" H 5705 4227 50  0000 C CNN
F 2 "" H 5700 4400 50  0001 C CNN
F 3 "" H 5700 4400 50  0001 C CNN
	1    5700 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C9
U 1 1 62674BDE
P 5800 4950
F 0 "C9" H 5650 5000 50  0000 C CNN
F 1 "4.7uF" H 5600 4900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5800 4950 50  0001 C CNN
F 3 "~" H 5800 4950 50  0001 C CNN
	1    5800 4950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male Ledstrip2
U 1 1 62674BE8
P 6600 4950
F 0 "Ledstrip2" H 6572 4974 50  0000 R CNN
F 1 "Conn_01x03_Male" H 6572 4883 50  0000 R CNN
F 2 "ConnectorsEvo:B03B-PASK" H 6600 4950 50  0001 C CNN
F 3 "~" H 6600 4950 50  0001 C CNN
	1    6600 4950
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR024
U 1 1 62674BF2
P 5700 4850
F 0 "#PWR024" H 5700 4700 50  0001 C CNN
F 1 "+5V" H 5600 5000 50  0000 L CNN
F 2 "" H 5700 4850 50  0001 C CNN
F 3 "" H 5700 4850 50  0001 C CNN
	1    5700 4850
	1    0    0    -1  
$EndComp
Text GLabel 6400 4950 0    50   Input ~ 0
LEDSTRIP_2
Wire Wire Line
	5800 4850 6400 4850
Wire Wire Line
	6400 5050 5800 5050
$Comp
L power:GND #PWR025
U 1 1 62674C00
P 5700 5050
F 0 "#PWR025" H 5700 4800 50  0001 C CNN
F 1 "GND" H 5705 4877 50  0000 C CNN
F 2 "" H 5700 5050 50  0001 C CNN
F 3 "" H 5700 5050 50  0001 C CNN
	1    5700 5050
	1    0    0    -1  
$EndComp
Connection ~ 5800 5050
Wire Wire Line
	2200 1600 2300 1600
$Comp
L power:+12V #PWR012
U 1 1 6258AF89
P 2300 1600
F 0 "#PWR012" H 2300 1450 50  0001 C CNN
F 1 "+12V" H 2300 1800 50  0000 C CNN
F 2 "" H 2300 1600 50  0001 C CNN
F 3 "" H 2300 1600 50  0001 C CNN
	1    2300 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 1000 3350 1000
Wire Wire Line
	1450 4350 1550 4350
Connection ~ 1550 4350
Wire Wire Line
	1850 4150 1950 4150
Wire Wire Line
	5700 5050 5800 5050
Wire Wire Line
	5700 4850 5800 4850
Connection ~ 5800 4850
Wire Wire Line
	5700 4200 5800 4200
Wire Wire Line
	5700 4400 5800 4400
Connection ~ 5800 4400
Wire Wire Line
	6350 3450 6450 3450
Connection ~ 6350 3650
Wire Wire Line
	6350 3650 6450 3650
Connection ~ 6350 3000
Wire Wire Line
	6350 3000 6450 3000
Wire Wire Line
	6350 2800 6450 2800
Wire Wire Line
	6300 2400 6400 2400
Wire Wire Line
	5800 1850 6350 1850
Wire Wire Line
	5800 1650 5700 1650
$Comp
L power:+5V #PWR020
U 1 1 6268EC2A
P 5700 1650
F 0 "#PWR020" H 5700 1500 50  0001 C CNN
F 1 "+5V" H 5600 1800 50  0000 L CNN
F 2 "" H 5700 1650 50  0001 C CNN
F 3 "" H 5700 1650 50  0001 C CNN
	1    5700 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C6
U 1 1 62692DC8
P 5800 1050
F 0 "C6" H 5600 1000 50  0000 L CNN
F 1 "4.7uF" H 5450 1100 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5800 1050 50  0001 C CNN
F 3 "~" H 5800 1050 50  0001 C CNN
	1    5800 1050
	1    0    0    1   
$EndComp
$Comp
L Connector:Conn_01x03_Male Servo1
U 1 1 62692DE0
P 6550 950
F 0 "Servo1" H 6522 974 50  0000 R CNN
F 1 "Conn_01x03_Male" H 6522 883 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6550 950 50  0001 C CNN
F 3 "~" H 6550 950 50  0001 C CNN
	1    6550 950 
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6350 950  5800 950 
Wire Wire Line
	5700 1150 5800 1150
Wire Wire Line
	6350 1150 6350 1050
$Comp
L power:GND #PWR019
U 1 1 62692DED
P 5700 1150
F 0 "#PWR019" H 5700 900 50  0001 C CNN
F 1 "GND" H 5705 977 50  0000 C CNN
F 2 "" H 5700 1150 50  0001 C CNN
F 3 "" H 5700 1150 50  0001 C CNN
	1    5700 1150
	1    0    0    -1  
$EndComp
Text GLabel 6350 850  0    50   Input ~ 0
SERVO_RIGHT
Wire Wire Line
	5800 1150 6350 1150
Wire Wire Line
	5800 950  5700 950 
$Comp
L power:+5V #PWR018
U 1 1 62692DFC
P 5700 950
F 0 "#PWR018" H 5700 800 50  0001 C CNN
F 1 "+5V" H 5600 1100 50  0000 L CNN
F 2 "" H 5700 950 50  0001 C CNN
F 3 "" H 5700 950 50  0001 C CNN
	1    5700 950 
	1    0    0    -1  
$EndComp
Connection ~ 5800 950 
Connection ~ 5800 1150
Connection ~ 5800 1650
Connection ~ 5800 1850
Text Notes 1400 650  0    50   ~ 0
Power Input
Wire Notes Line
	500  500  2650 500 
Wire Notes Line
	2650 500  2650 2150
Wire Notes Line
	2650 2150 500  2150
Wire Notes Line
	500  2150 500  500 
Text Notes 1300 2350 0    50   ~ 0
5V Regulation
Wire Notes Line
	500  2200 2650 2200
Wire Notes Line
	2650 2200 2650 3250
Wire Notes Line
	2650 3250 500  3250
Wire Notes Line
	500  3250 500  2200
Wire Notes Line
	2700 3250 5250 3250
Wire Notes Line
	5250 3250 5250 500 
Wire Notes Line
	5250 500  2700 500 
Wire Notes Line
	2700 500  2700 3250
Text Notes 3750 650  0    50   ~ 0
Arduino Nano
$Comp
L Device:R R2
U 1 1 626B8928
P 1250 6350
F 0 "R2" H 1320 6396 50  0000 L CNN
F 1 "150" H 1320 6305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1180 6350 50  0001 C CNN
F 3 "~" H 1250 6350 50  0001 C CNN
	1    1250 6350
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 626B893E
P 1250 6650
F 0 "D2" H 1300 6550 50  0000 R CNN
F 1 "Red" H 1350 6750 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 1250 6650 50  0001 C CNN
F 3 "~" H 1250 6650 50  0001 C CNN
	1    1250 6650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1250 6800 1250 7000
$Comp
L Device:R R1
U 1 1 626BCF27
P 950 6350
F 0 "R1" H 1020 6396 50  0000 L CNN
F 1 "510" H 1020 6305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 880 6350 50  0001 C CNN
F 3 "~" H 950 6350 50  0001 C CNN
	1    950  6350
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 626BCF3D
P 950 6650
F 0 "D1" H 1000 6550 50  0000 R CNN
F 1 "Red" H 1050 6750 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 950 6650 50  0001 C CNN
F 3 "~" H 950 6650 50  0001 C CNN
	1    950  6650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	950  6800 950  7000
Connection ~ 1250 7000
Connection ~ 1550 7000
Connection ~ 1850 7000
Wire Wire Line
	1250 7000 1550 7000
Wire Wire Line
	950  7000 1250 7000
Wire Wire Line
	1550 7000 1850 7000
$Comp
L power:+12V #PWR03
U 1 1 626CB529
P 950 6200
F 0 "#PWR03" H 950 6050 50  0001 C CNN
F 1 "+12V" H 850 6350 50  0000 L CNN
F 2 "" H 950 6200 50  0001 C CNN
F 3 "" H 950 6200 50  0001 C CNN
	1    950  6200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 626CB941
P 1250 6200
F 0 "#PWR04" H 1250 6050 50  0001 C CNN
F 1 "+5V" H 1150 6350 50  0000 L CNN
F 2 "" H 1250 6200 50  0001 C CNN
F 3 "" H 1250 6200 50  0001 C CNN
	1    1250 6200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 626CBE75
P 1550 7000
F 0 "#PWR08" H 1550 6750 50  0001 C CNN
F 1 "GND" H 1555 6827 50  0000 C CNN
F 2 "" H 1550 7000 50  0001 C CNN
F 3 "" H 1550 7000 50  0001 C CNN
	1    1550 7000
	1    0    0    -1  
$EndComp
Text Notes 1350 5500 0    50   ~ 0
Status Leds
Wire Notes Line
	2650 5350 500  5350
Wire Notes Line
	500  5350 500  7350
Wire Notes Line
	500  7350 2650 7350
Wire Notes Line
	2650 7350 2650 5350
Text Notes 2500 3450 0    50   ~ 0
Motor Control
Wire Notes Line
	500  3300 5250 3300
Wire Notes Line
	5250 3300 5250 5300
Wire Notes Line
	5250 5300 500  5300
Wire Notes Line
	500  5300 500  3300
Text Notes 6050 650  0    50   ~ 0
Servomotors
Wire Notes Line
	5300 2100 7400 2100
Wire Notes Line
	7400 2100 7400 500 
Wire Notes Line
	7400 500  5300 500 
Wire Notes Line
	5300 500  5300 2100
Text Notes 5500 2350 0    50   ~ 0
Inputs
Wire Notes Line
	5300 2150 7400 2150
Wire Notes Line
	7400 2150 7400 3900
Wire Notes Line
	7400 3900 5300 3900
Wire Notes Line
	5300 3900 5300 2150
Text Notes 6850 4100 0    50   ~ 0
Ledstrips
Wire Notes Line
	7400 3950 5300 3950
Wire Notes Line
	5300 3950 5300 5300
Wire Notes Line
	5300 5300 7400 5300
Wire Notes Line
	7400 5300 7400 3950
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 625E45A3
P 3050 6150
F 0 "H1" H 3150 6199 50  0000 L CNN
F 1 "MountingHole_Pad" H 3150 6108 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 3050 6150 50  0001 C CNN
F 3 "~" H 3050 6150 50  0001 C CNN
	1    3050 6150
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 625E4ADE
P 3950 6150
F 0 "H3" H 4050 6199 50  0000 L CNN
F 1 "MountingHole_Pad" H 4050 6108 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 3950 6150 50  0001 C CNN
F 3 "~" H 3950 6150 50  0001 C CNN
	1    3950 6150
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 625E4FA8
P 3050 6650
F 0 "H2" H 3150 6699 50  0000 L CNN
F 1 "MountingHole_Pad" H 3150 6608 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 3050 6650 50  0001 C CNN
F 3 "~" H 3050 6650 50  0001 C CNN
	1    3050 6650
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 625E5657
P 3950 6650
F 0 "H4" H 4050 6699 50  0000 L CNN
F 1 "MountingHole_Pad" H 4050 6608 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 3950 6650 50  0001 C CNN
F 3 "~" H 3950 6650 50  0001 C CNN
	1    3950 6650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 625E5868
P 3050 6250
F 0 "#PWR0101" H 3050 6000 50  0001 C CNN
F 1 "GND" H 3055 6077 50  0000 C CNN
F 2 "" H 3050 6250 50  0001 C CNN
F 3 "" H 3050 6250 50  0001 C CNN
	1    3050 6250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 625E5C98
P 3950 6250
F 0 "#PWR0102" H 3950 6000 50  0001 C CNN
F 1 "GND" H 3955 6077 50  0000 C CNN
F 2 "" H 3950 6250 50  0001 C CNN
F 3 "" H 3950 6250 50  0001 C CNN
	1    3950 6250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 625E600A
P 3050 6750
F 0 "#PWR0103" H 3050 6500 50  0001 C CNN
F 1 "GND" H 3055 6577 50  0000 C CNN
F 2 "" H 3050 6750 50  0001 C CNN
F 3 "" H 3050 6750 50  0001 C CNN
	1    3050 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 625E63A9
P 3950 6750
F 0 "#PWR0104" H 3950 6500 50  0001 C CNN
F 1 "GND" H 3955 6577 50  0000 C CNN
F 2 "" H 3950 6750 50  0001 C CNN
F 3 "" H 3950 6750 50  0001 C CNN
	1    3950 6750
	1    0    0    -1  
$EndComp
Wire Notes Line
	2700 5350 5250 5350
Wire Notes Line
	5250 5350 5250 7350
Wire Notes Line
	5250 7350 2700 7350
Wire Notes Line
	2700 7350 2700 5350
Text Notes 3700 5500 0    50   ~ 0
Mouting Holes
$Comp
L Jumper:Jumper_3_Open JP1
U 1 1 6261B076
P 1550 3700
F 0 "JP1" H 950 3700 50  0000 C CNN
F 1 "Jumper_3_Open" H 900 3650 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 1550 3700 50  0001 C CNN
F 3 "~" H 1550 3700 50  0001 C CNN
	1    1550 3700
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR031
U 1 1 6261D775
P 1800 3700
F 0 "#PWR031" H 1800 3550 50  0001 C CNN
F 1 "+5V" H 1700 3850 50  0000 L CNN
F 2 "" H 1800 3700 50  0001 C CNN
F 3 "" H 1800 3700 50  0001 C CNN
	1    1800 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 4250 3200 4250
Wire Wire Line
	3200 4350 3800 4350
Wire Wire Line
	3400 4450 3400 4650
Wire Wire Line
	3400 4650 3200 4650
Wire Wire Line
	3400 4450 3800 4450
Wire Wire Line
	3200 4750 3500 4750
Wire Wire Line
	3500 4750 3500 4550
Wire Wire Line
	3500 4550 3800 4550
Wire Wire Line
	3800 4150 3300 4150
Wire Wire Line
	3300 4150 3300 4500
Wire Wire Line
	3300 4500 3200 4500
Connection ~ 3200 4500
Wire Wire Line
	3200 4500 3200 4550
$EndSCHEMATC
