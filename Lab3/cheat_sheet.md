# McPAT

https://www.hpl.hp.com/research/mcpat/


```
git clone https://github.com/kingmouf/cmcpat.git my_mcpat

sudo apt install libc6-dev-i386
sudo apt install gcc-7-multilib g++-7-multilib

cd my_mcpat
make
```

```
./mcpat -infile ProcessorDescriptionFiles/Xeon.xml -print_level 1

./mcpat -infile my_cpu.xml -print_level 1 > results.txt
```

## GEM5 to McPAT
```
GEM5toMcPAT.py [options] <gem5 stats file> <gem5 config file (json)> <mcpat template xml file> -o <output xml file>
```
-h, --help	show help message and exit
-q, --quiet	don't print status messages to stdout

## McPAT print_energy

```
print_energy.py [options] <mcpat output file> <gem5 stats file> 
```

# TESTS

```
python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/spec_results1/specbzip/stats.txt ~/Desktop/Computer-Architecture/lab2/spec_results1/specbzip/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/scepbzip_def.xml

./mcpat -infile my_cpu111.xml -print_level 1 > results.txt
```


```
python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/spec_results1/speclibm/stats.txt ~/Desktop/Computer-Architecture/lab2/spec_results1/speclibm/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm0.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm1/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm1/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm1.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm2/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm2/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm2.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm3/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm3/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm3.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm4/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm4/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm4.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm5/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm5/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm5.xml


python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm6/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm6/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm6.xml


python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm7/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm7/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm7.xml


python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm8/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm8/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm8.xml


python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm9/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm9/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm9.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm10/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm10/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm10.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm11/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm11/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm11.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm12/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm12/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm12.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm13/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm13/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm13.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm14/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm14/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm14.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm15/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm15/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm15.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm16/stats.txt ~/Desktop/Computer-Architecture/lab2/speclibm_improvement/speclibm16/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speclibm16.xml

```


