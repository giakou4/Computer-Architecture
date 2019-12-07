# LAB 3 REPORT

## STEP 1

### [1.1] Dynamic Power and Leakage

*Leakage power*: The transistors are not perfect. Even when they are supposed to be “off”, they’re not truly off. They let a bit of current through. So, in any steady state, one transistor is on, and the other is off, but that “off” transistor allows some current to leak through it.

*Dynamic power*: This is split into two types: *short-circuit current* and *capacitance*

* Short-circuit current: The transistors do not switch instantaneously. For a short period during the switching process, both transistors will be partially open. For this period, there is a direct path for electrical current to go straight from Vss to Vdd. This happens each time the transistor switches, and each time, a fixed amount of charge is allowed to flow, so the more frequently it switches (the higher the frequency), the higher the current.

* Capacitance: Each time the transistor is switched on, the capacitance is charged and discharged. Like short-circuit current, we use up a fixed amount current each time the transistor switches, so the more frequently we switch, the higher the rate of consumption of average current.

So

Dynamic_Power ¬ 1/2 x Capacity_Load x Voltage^2 x Frequency switched

Source : [Computer Architecture by Hennesy and Patterson](https://www.sciencedirect.com/topics/computer-science/dynamic-power)

The capacitive load is a function of the number of transistors connected to an output. So the programm with the most transistor switches will have a higher dynamic power. We assume that both programms run on the same proccessor at the same frequency and voltage. Regarding the leakage, the programm with the least transistor switches will have a higher leakage. Those transistors are supposed to be off (we disable the transistors which are not used, suchs as a the transistors connected to floating points operations, in a programm with integers manipulations) but a small amount of current is allowed to leak through them.
Running the same programm twice for example (higher run-time), will result in more leakage (the current leaked will be dobuled) but the dynamic power will not change(frequency, voltage, capacity load = ct).


### [1.2] 

### [1.3] 

## STEP 2

### [2.1] 

### [2.2] 

### [2.3]
