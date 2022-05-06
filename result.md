<span style="color: grey;">The output and correctness of each algorithm – You should summarize, visualize, or highlight some part of the full-scale run of each algorithm. Additionally, the report should briefly describe what tests you performed to confirm that each algorithm was working as intended.</span>

<span style="color: grey;">The answer to your leading question – You should direct address your proposed leading question. How did you answer this question? What did you discover? If your project was ultimately unsuccessful, give a brief reflection about what worked and what you would do differently as a team. </span>

# Introduction
Throughout the course, we have seen several algorithms and structures for organizing and manipulating data，and with the current circumstance where gas prices in the U.S. hit a fresh new high, we decide to build a project which is able to draw the shortest path between a starting point and a destination on road network of North America

# Data Parsing
# BFS Algorithm
In our final program, we implement Breadth-first search (BFS) algorithm for finding the shortest path between two given points. Data structure queue is used as an extra memory in this algorithm so that the space complexity is $O(N)$. We test this algorithm on a small dataset as draw below and we make sure that our BFS visit correct nodes in correct order. Edge cases like cyclic route and disconnected route are also tested.
 
 ![BFS test graph](tests/BFS_test_graph.png)

However, this algorithm cannot solve our leading questions, as BFS take the distance between each node as equal while in practice road length varies.

# Dijkstra's Algorithm
# Graph Visualization
# Summary


