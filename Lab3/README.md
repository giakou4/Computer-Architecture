# LAB 3 REPORT

## STEP 1

### [1.1] Dynamic Power and Leakage

*Leakage power*: The transistors are not perfect. Even when they are supposed to be “off”, they’re not truly off. They let a bit of current through. So, in any steady state, one transistor is on, and the other is off, but that “off” transistor allows some current to leak through it.

*Dynamic power*: This is split into two types: *short-circuit current* and *capacitance*

* Short-circuit current: The transistors do not switch instantaneously. For a short period during the switching process, both transistors will be partially open. For this period, there is a direct path for electrical current to go straight from Vss to Vdd. This happens each time the transistor switches, and each time, a fixed amount of charge is allowed to flow, so the more frequently it switches (the higher the frequency), the higher the current.

* Capacitance: Each time the transistor is switched on, the capacitance is charged and discharged. Like short-circuit current, we use up a fixed amount current each time the transistor switches, so the more frequently we switch, the higher the rate of consumption of average current.

So

> Dynamic_Power ~ 1/2 x (Capacity Load) x (Voltage)(^2) x (Frequency switched)

Source : [Computer Architecture by Hennesy and Patterson](https://www.sciencedirect.com/topics/computer-science/dynamic-power)

The capacitive load is a function of the number of transistors connected to an output. So the programm with the most transistor switches will have a higher dynamic power. We assume that both programms run on the same proccessor at the same frequency and voltage. Regarding the leakage, the programm with the least transistor switches will have a higher leakage. Those transistors are supposed to be off (we disable the transistors which are not used, suchs as a the transistors connected to floating points operations, in a programm with integers manipulations) but a small amount of current is allowed to leak through them.
Running the same programm twice for example (higher run-time), will result in more leakage (the current leaked will be dobuled) but the dynamic power will not change(frequency, voltage, capacity load = ct).


### [1.2] 5W vs 40W battery

With a first glance we would say that the 40W CPU would consume more power than the 5W CPU. We have not taken into consideration, though, the energy efficiency of each CPU:

* For leakage power, we can use transistors that are less leaky. The downside of this is that these transistors are slower to switch, and therefore your circuit will run slower.
* For dynamic power, we need to reduce the frequency at which the transistors switch. Some examples are:
  * Slowing down (or even turning off) the clock when appropriate (e.g. when a CPU is iddle)
  * Isolating sections of logic when they are not used, preventing them from seeing changes on a particular signal that is changing frequently
* In both cases, reducing the power supply voltage also helps reducing power consumption because power is proportional to square of voltage (P=V^2/R). This also causes the transistors to switch more slowly.

If the 40W CPU takes advantages of all these, while to 5W CPU does not, the battery of the 40W CPU may last longer.

### [1.3] Xeon vs ARM-9

We run Xeon and ARM9 2GHz in McPAT.

|                                          | ARM-9 2GHz | XEON 3.4GHz |
|------------------------------------------|-----------|-------------|
| Lithography                              | 40 nm     | 65nm        |
| Area                                     | 5.39 mm^2 | 410.50 mm^2 |
| Peak Power                               | 1.74 W    | 134.93 W    |
| Total Leakage                            | 0.10 W    | 36.83 W     |
| Peak Dyamic                              | 1.63 W    | 98.10 W     |
| Subthreshold Leakage                     | 0.05 W    | 35.16 W     |
| Substhreshhold Leakage with power gating |           | 16.39 W     |
| Gate Leakage                             | 0.05 W    | 1.66 W      |
| Runtime Dynamic                          | 2.96 W    | 72.91 W     |

Taking into consideration that Xeon is 40 times faster than ARM9, in order to get the most efficient CPU we take the ratio   
K = Energy(Xeon) / Energy(ARM9), where  
Energy = (Total Leakage + Runtime Dynamic) * runtime  
so  
K = (109.74 / 3.06) * 1/40 = 0.89  
which means that if Xeon is 40 times faster, Xeon is more energy efficient.  

## STEP 2

Minimize Enery-Delay-Area Product (EDAP)

### [2.1] 

EDAP = Energy x Delay x Area

* Area: obvious
* Energy [Joule] = (Total Leakage[Watt] + Runtime Dynamic[Watt]) * runtime(sec), where Total Leakage[Watt] = Subthreshold Leakage[Watt] + Gate Leakage[Watt]
* Delay: Propagation delay aka Gate Delay is the length of time which starts when the input to a logic gate becomes stable and valid to change, to the time that the output of that logic gate is stable and valid to change. 

### [2.2] 

### [2.3]
