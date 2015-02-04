#!/bin/bash
./robogen-server 8001 &
./robogen-evolver 1 results/my_first_evolution_experiment ../examples/stress-$1/evolConf.txt
