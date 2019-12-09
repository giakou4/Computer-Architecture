# LAB 3 REPORT

## STEP 1

### [1.1] DYNAMIC POWER AND LEAKAGE

*Leakage power*: The transistors are not perfect. Even when they are supposed to be “off”, they’re not truly off. They let a bit of current through. So, in any steady state, one transistor is on, and the other is off, but that “off” transistor allows some current to leak through it.

*Dynamic power*: This is split into two types: *short-circuit current* and *capacitance*

* Short-circuit current: The transistors do not switch instantaneously. For a short period during the switching process, both transistors will be partially open. For this period, there is a direct path for electrical current to go straight from Vss to Vdd. This happens each time the transistor switches, and each time, a fixed amount of charge is allowed to flow, so the more frequently it switches (the higher the frequency), the higher the current.

* Capacitance: Each time the transistor is switched on, the capacitance is charged and discharged. Like short-circuit current, we use up a fixed amount current each time the transistor switches, so the more frequently we switch, the higher the rate of consumption of average current.

So

> Dynamic_Power ~ 1/2 x (Capacity Load) x (Voltage)(^2) x (Frequency switched)

Source : [Computer Architecture by Hennesy and Patterson](https://www.sciencedirect.com/topics/computer-science/dynamic-power)

The capacitive load is a function of the number of transistors connected to an output. So the programm with the most transistor switches will have a higher dynamic power. We assume that both programms run on the same proccessor at the same frequency and voltage. Regarding the leakage, the programm with the least transistor switches will have a higher leakage. Those transistors are supposed to be off (we disable the transistors which are not used, suchs as a the transistors connected to floating points operations, in a programm with integers manipulations) but a small amount of current is allowed to leak through them.
Running the same programm twice for example (higher run-time), will result in more leakage (the current leaked will be dobuled) but the dynamic power will not change(frequency, voltage, capacity load = ct).


### [1.2] 5W vs 40W BATTERY

With a first glance we would say that the 40W CPU would consume more power than the 5W CPU. We have not taken into consideration, though, the energy efficiency of each CPU:

* For leakage power, we can use transistors that are less leaky. The downside of this is that these transistors are slower to switch, and therefore your circuit will run slower.
* For dynamic power, we need to reduce the frequency at which the transistors switch. Some examples are:
  * Slowing down (or even turning off) the clock when appropriate (e.g. when a CPU is iddle)
  * Isolating sections of logic when they are not used, preventing them from seeing changes on a particular signal that is changing frequently
* In both cases, reducing the power supply voltage also helps reducing power consumption because power is proportional to square of voltage (P=V^2/R). This also causes the transistors to switch more slowly.

If the 40W CPU takes advantages of all these, while to 5W CPU does not, the battery of the 40W CPU may last longer.

In order to have a specific asnwer, we would need the run-time of the simulated programs that would run on the CPU. This could be a combination of gem5 output and PcPAT.

### [1.3] XEON vs ARM-9

We run Xeon and ARM9 2GHz in McPAT.
Detailed results are presented in results.zip ARM9_2GHz.txt and XEON.txt

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

Xeon total power is P1 = 72.91W + 36.83W = 109.74W and out of the total Power, only 66.43% is used, while
ARM-9 total power is P2 = 2.96W + 0.10W = 3.06W and out of the total Power, only 96.73% is used.

## STEP 2

Minimize Enery-Delay-Area Product (EDAP)

### [2.1] EDAP

EDAP = Energy x Delay x Area

* 	__Area__ [mm^2]: obvious
* 	__Energy__ [Joule] = (Total Leakage[Watt] + Runtime Dynamic[Watt]) * run-time(sec), where Total Leakage[Watt] = Subthreshold Leakage[Watt] + Gate Leakage[Watt]
* 	__Delay__ [sec] = run-time of the simulated program.

### [2.2] RUN McPAT FOR THE SIMULATED GEM-5 STATISTICS

First we created the .xml files from the stats.txt and config.json from each simulation.  
Then we ran the McPAT.  
Detailed results are presented in __results.txt__ in the relative folders for each benchmark.
The information for the EDAP and Graphs are held in 	__results.xlsx__, an excel file which contains:
* 	__Contents__ sheet: each benchmark number represents a certain execution of gem5 with the specific parametrs.
* 	__Processor__ sheet: the proccessor information
* 	__Core+L2__ sheet: the core and L2 information to calculate EDAP.

For the calculations:
* Energy = (Subthreshold Leakage + Gate Leakage + Runtime Dynamic) * sim_sec for core and L2  
  Total Energy is the sum of both.
* Total Area equals the sum of core and L2 area.
* Delay = sim_sec

The best EDAP for each benchmark was achieved for:

| BENCHMARK | No | ENERGY[J] | DELAY[sec] | AREA[mm^2] | EDAP     | l1d_size | l1i_size | l2_size | l1i_assoc | l1d_assoc | l2_assoc | cache_line |
|-----------|----|-----------|------------|------------|----------|----------|----------|---------|-----------|-----------|----------|------------|
| specbzip  | 0  | 0.233168  | 0.161337   | 14.22863   | 0.535262 | 64       | 32       | 2       | 2         | 2         | 8        | 64         |
| specmcf   | 0  | 0.160247  | 0.109125   | 14.22863   | 0.248815 | 64       | 32       | 2       | 2         | 2         | 8        | 64         |
| spechmmer | 7  | 0.143592  | 0.118426   | 13.09206   | 0.22263  | 64       | 32       | 2       | 2         | 4         | 8        | 64         |
| specsjeng | 0  | 0.625926  | 0.513541   | 14.22863   | 4.573629 | 64       | 32       | 2       | 2         | 2         | 8        | 64         |
| speclibm  | 0  | 0.348443  | 0.262355   | 14.22863   | 1.30072  | 64       | 32       | 2       | 2         | 2         | 8        | 64         |


> We observe that for the most benchmarks, the best EDAP was achieved for the default(No 0) parametrs. That is because in LAB-2 we aimed for the best CPI, which was achieved for increasing memory and cache-line, while associativity as mentioned at LAB-2 report, does not affect any criteria of the EDAP as much as memory size and cache-line.
> We could achieve lower EDAP by decreasing memory more, but in this section we used the results from LAB-2 as they were, and did not run any additional simulations.

#### Important Note for Graphs
* 0-value represents the default value (see [1.1] from Lab-2)
* 1-value is 2x the default value. 2-value is 4x the default value and so on.
* -1-value is /2 the default value. -2-value is /4 the default value and so on.

![speclibm_area](https://user-images.githubusercontent.com/57758089/70469897-a3b19500-1ad2-11ea-95d8-0052cdcd4bbc.png)
![specbzip_peakpower](https://user-images.githubusercontent.com/57758089/70469898-a44a2b80-1ad2-11ea-9419-81ab80479f8e.png)
![specbzip_area](https://user-images.githubusercontent.com/57758089/70469900-a4e2c200-1ad2-11ea-8edb-ca5852fdecc3.png)
![specmcf_peakpower](https://user-images.githubusercontent.com/57758089/70469901-a57b5880-1ad2-11ea-982b-18a271c718a1.png)
![specmcf_area](https://user-images.githubusercontent.com/57758089/70469903-a613ef00-1ad2-11ea-957f-3e143f0a063f.png)
![spechmmer_peakpower](https://user-images.githubusercontent.com/57758089/70469904-a6ac8580-1ad2-11ea-8115-dfb232d57d12.png)
![spechmmer_area](https://user-images.githubusercontent.com/57758089/70469907-a6ac8580-1ad2-11ea-930f-f87b3aedd102.png)
![specsjeng_peakpower](https://user-images.githubusercontent.com/57758089/70469908-a7451c00-1ad2-11ea-8bd8-40bb3eeba043.png)
![specsjeng_area](https://user-images.githubusercontent.com/57758089/70469910-a7451c00-1ad2-11ea-92f2-f041f7ca7933.png)
![speclibm_peakpower](https://user-images.githubusercontent.com/57758089/70469911-a7ddb280-1ad2-11ea-88ff-8ef9fa62cf1a.png)

### [2.3] OBSERVATION: COST-FUNCTION VS McPAT

We observe that indeed, increasing cache size L1 or L2, the area and the peak power is increased, while the associativity does not affect neither area not peak power that much. The most significant change to those factors is observed by increasing the cache-line. The truth is that cache-line is 64, 128 or rarely 256, while in our measurements, the cache-line sometimes reached 2048! [software.intel.com](https://software.intel.com/en-us/articles/loop-optimizations-where-blocks-are-required)

## CONCLUSION

Lab-3 was easier to be implemented and most importantly, the simulation did not take much time. McPAT was an easy to use tool, at least this version, with some important outputs. I personally never thought that power consumption could be such a restrictive factor for modern architecture.

## CONCLUSION FOR ALL 3 LABS

The lab was __very interesting__. We got closer to design architectures (mostly caches) in order to maximize some standards for the CPU to perform better in specific benchmarks. GEM5 helped us to optimize the CPU for better results. We were free to change charachteristics -not as many as we wanted but enough to see a beter result. I would personally like to be able to change __more__ factors, like branch predictors,or use other policies in some cases. Changing just caches is quite __monotonous__. On the other hand, McPAT limited the options and made us look for other implementations because energy efficiency and size matters.

*__To sum up, the lab was interesting and quite easy, although the workload was high. We had better use less benchmarks (1 or 2) and change more factors.__

-Nikolaos Giakoumoglou
