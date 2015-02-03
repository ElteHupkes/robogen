# Stress test
I'm going to document the approach to stress testing the robogen environment with
multiple robots. Since the entire setup of Robogen is not compatible with the multiple robot idea, 
I'm not going to cleanly incorporate it in the stress test. The first approach is merely aimed at
hacking together a simulation which uses 50 sufficiently complicated robots, and seeing how fast
it will run.

# Approach
For the stress test I will leave the Evolver alone, and rather only alter the Simulator. This will
then simulate 50 identical robots, of the type sent by the EvaluationRequest. I'll ignore their
original simulated positions as well. Obstacles are disabled since their rendering mechanics
are unclear with them not being generated within a certain bounding box.
