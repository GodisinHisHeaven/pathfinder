## Leading Question

As the gas price increased so much, we want to find a way to save money for our road trip. In this final project, we
will analyze the gas consumption point to point by finding the shortest distance.

## Dataset Acquisition and Processing

The dataset we are using is retrieved at https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm.

The dataset contains about 6,000 nodes and about 170,000 edges
in `Node ID, Normalized X Coordinate, Normalized Y Coordinate` and `Edge ID, Start Node ID, End Node ID, L2 Distance` in

each line. The dataset is about 10MB.

We could check the data by check the coordinates are in the boundary of the United States or not.

We would store this dataset by an array. The total storage costs should be **_O(N)_**.

## Graph Algorithms

### BFS Traversal

We will use BFS to traverse the points by giving start and end nodes.

The time complexity should be **_$$O(|V| + |E|) $$_** while the **$V$** is the most significant number of adjacent nodes
in the graph and **$E$** is the numer of the edge in the shortest path. In our implementation, we would use a queue so
that the space complexity should be **_$O(N)$_**.

### Dijkstra's Algorithm

By the given latitude and longitude, we could calculate the distance between each point and get the weight of edges, and
then we would use Dijkstra's Algorithm to get the shortest route from start to end node. Finally, we could calculate the
gas consumption.

The time complexity should be _**$O((E + V)logV)$**_ while the E edges and V are vertices in our graph. The space
complexity should be **_$O(E + V)$_**.

### Project on to Map Based on Data

By the given latitude, longitude and the shortest path we find, we could project this graph onto a map.

The time complexity should be **_$O(E + V)$_** while we just iterate through the graph and project it. The space complexity
should be **_$O(E + V)$_**, too.

## Timeline

### Week 1 (March 27 - April 2)

Complete implementation for the BFS traversal and write test cases for it.

### Week 2 (April 3 - April 9)

Start implementing Dijkstra's Algorithm.

### Week 3 (April 10 - April 15)

Complete implementation for Dijkstra's Algorithm and write test cases for it.
