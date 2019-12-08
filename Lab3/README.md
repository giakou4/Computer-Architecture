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

### [2.2] Run McPAT for the simulated Gem5 statistics.

First we created the .xml files from the stats.txt and config.json from each simulation.  
Then we run the McPAT.  
Below are the results:  

| Benchmark No | Area [mm^2] | Peak Power [W] | Runtime Dynamic [W] | Subthreshold Leakage [W] | Gate Leakage [W] | Subthreshold + Gate Leakage | Simulated Seconds |
|--------------|-------------|----------------|---------------------|--------------------------|------------------|-----------------------------|-------------------|
| specbzip 1   | 21.0012     | 5.36199        | 0.45965             | 1.82964                  | 0.0141307        |                             | 0.158500          |
| specbzip 2   | 17.2098     | 4.59736        | 0.361326            | 1.27398                  | 0.0090865        |                             | 0.159772          |
| specbzip 3   | 24.665      | 4.99011        | 0.368531            | 1.55084                  | 0.012234         |                             | 0.15993           |
| specbzip 4   | 19.0201     | 4.86624        | 0.361324            | 1.54667                  | 0.0117354        |                             | 0.161413          |
| specbzip 5   | 28.4386     | 5.26733        | 0.484413            | 1.58045                  | 0.0120246        |                             | 0.156349          |
| specbzip 6   | 25.0795     | 5.26541        | 0.573511            | 1.38748                  | 0.0101832        |                             | 0.155590          |
| specbzip 7   | 25.8368     | 5.83038        | 0.776057            | 1.42727                  | 0.0105313        |                             | 0.155438          |
| specbzip 8   | 39.55558    | 12.4691        | 1.91203             | 1.69454                  | 0.0122891        |                             | 0.154827          |
| specbzip 9   | 154.371     | 43.0317        | 7.70812             | 4.05166                  | 0.0339996        |                             | 0.154347          |
| specbzip 10  | 40.918      | 12.4684        | 1.91164             | 1.69449                  | 0.0122858        |                             | 0.154849          |
| specbzip 11  | 53.7714     | 17.0803        | 3.90032             | 2.18252                  | 0.0149441        |                             | 0.154699          |
| specbzip 12  | 393.39      | 153.365        | 28.0436             | 12.3372                  | 0.093019         |                             | 0.156223          |
| specbzip 0   | 15.9545     | 3.86567        | 0.361428            | 1.14522                  | 0.0080513        |                             | 0.161337          |

| Benchmark No | Area [mm^2] | Peak Power [W] | Runtime Dynamic [W] | Subthreshold Leakage [W] | Gate Leakage [W] | Subthreshold + Gate Leakage | Simulated Seconds |
|--------------|-------------|----------------|---------------------|--------------------------|------------------|-----------------------------|-------------------|
| specmcf 1    | -           | -              | -                   | -                        | -                | -                           | 0.106695          |
| specmcf 2    | 26.0468     | 4.268          | 0.495081            | 1.17921                  | 0.00837412       |                             | 0.108960          |
| specmcf 3    | 22.6877     | 4.26608        | 0.58509             | 0.98624                  | 0.00653264       |                             | 0.108960          |
| specmcf 4    | 24.483      | 4.48491        | 0.478392            | 1.43255                  | 0.0109845        |                             | 0.109007          |
| specmcf 5    | 24.7716     | 4.4865         | 0.478409            | 1.43263                  | 0.0109919        |                             | 0.109007          |
| specmcf 6    | 32.7452     | 9.72875        | 1.07103             | 1.39819                  | 0.010286         |                             | 0.107138          |
| specmcf 7    | 128.35      | 34.0412        | 3.67746             | 3.15025                  | 0.0290129        |                             | 0.106654          |
| specmcf 8    | 128.263     | 34.0575        | 3.67753             | 3.15044                  | 0.0290397        |                             | 0.106654          |
| specmcf 9    | 154.371     | 43.0317        | 7.34072             | 4.05166                  | 0.0339996        |                             | 0.106652          |
| specmcf 10   | 108.0899    | 33.366         | 3.67628             | 3.14185                  | 0.0275653        |                             | 0.106658          |
| specmcf 11   | 393.39      | 153.365        | 27.026              | 12.3372                  | 0.093019         |                             | 0.106256          |
| specmcf 12   | -           | -              | -                   | -                        | -                | -                           | 0.110831          |
| specmcf 13   | 117.181     | 29.5166        | 1.745               | 2.74583                  | 0.0261941        |                             | 0.106695          |
| specmcf 14   | 242.011     | 97.6913        | 3.80896             | 7.12324                  | 0.0639827        |                             | 0.106325          |
| specmcf 0    | 15.9545     | 3.86567        | 0.38062             | 1.14522                  | 0.0080513        |                             | 0.109125          |

| Benchmark No | Area [mm^2] | Peak Power [W] | Runtime Dynamic [W] | Subthreshold Leakage [W] | Gate Leakage [W] | Subthreshold + Gate Leakage | Simulated Seconds |
|--------------|-------------|----------------|---------------------|--------------------------|------------------|-----------------------------|-------------------|
| spechmmer 1  | 22.2732     | 3.99078        | 0.404227            | 1.1496                   | 0.00858348       |                             | 0.117922          |
| spechmmer 2  | 18.3463     | 4.865          | 0.403561            | 1.54646                  | 0.0117018        |                             | 0.118436          |
| spechmmer 3  | 21.0012     | 5.36199        | 0.509691            | 1.82964                  | 0.0141307        |                             | 0.118263          |
| spechmmer 4  | 51.1994     | 9.22886        | 0.632599            | 1.24227                  | 0.0110139        |                             | 0.118171          |
| spechmmer 5  | 92.1132     | 27.2066        | 1.15042             | 2.46399                  | 0.0232253        |                             | 0.118093          |
| spechmmer 6  | 221.719     | 97.1094        | 4.11124             | 7.16028                  | 0.0617923        |                             | 0.119210          |
| spechmmer 7  | 14.818      | 3.59803        | 0.398803            | 0.87274                  | 0.00543599       |                             | 0.118426          |
| spechmmer 8  | 15.1186     | 3.84194        | 0.480633            | 0.893243                 | 0.00559721       |                             | 0.118423          |
| spechmmer 9  | 35.3268     | 10.4118        | 1.12127             | 1.49843                  | 0.0110018        |                             | 0.117922          |
| spechmmer 10 | 33.9646     | 10.4124        | 1.12128             | 1.49848                  | 0.0110051        |                             | 0.117922          |
| spechmmer 11 | 35.31       | 10.4136        | 1.12128             | 1.49869                  | 0.0110387        |                             | 0.117922          |
| spechmmer 12 | 128.437     | 34.0373        | 3.91168             | 3.15015                  | 0.0289996        |                             | 0.117816          |
| spechmmer 13 | 128.35      | 34.0412        | 3.91169             | 3.15025                  | 0.0290129        |                             | 0.117816          |
| spechmmer 14 | 128.263     | 34.0575        | 3.91171             | 3.15044                  | 0.0290397        |                             | 0.117816          |
| spechmmer 15 | 108.138     | 33.3619        | 3.91133             | 3.1418                   | 0.0275587        |                             | 0.117816          |
| spechmmer 16 | 85.6223     | 32.63          | 3.91097             | 3.13218                  | 0.0253433        |                             | 0.117816          |
| spechmmer 0  | 15.9545     | 3.86567        | 0.403546            | 1.14522                  | 0.0080513        |                             | 0.118453          |


### [2.3]
