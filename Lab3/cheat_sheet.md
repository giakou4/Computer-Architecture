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
python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/spec_results1/specmcf/stats.txt ~/Desktop/Computer-Architecture/lab2/spec_results1/specmcf/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf0.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf1/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf1/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf1.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf2/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf2/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf2.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf3/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf3/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf3.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf4/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf4/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf4.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf5/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf5/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf5.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf6/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf6/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf6.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf7/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf7/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf7.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf8/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf8/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf8.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf9/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf91/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf9.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf10/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf10/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf10.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf11/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf11/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf11.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf12/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf12/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf12.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf13/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf13/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf13.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf14/stats.txt ~/Desktop/Computer-Architecture/lab2/specmcf_improvement/specmcf14/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmcf14.xml







```


