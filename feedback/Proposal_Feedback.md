### Grade
Incomplete (0%)

Must resubmit!
### Comments
A solid proposal overall but unfortunately you will need to resubmit it to include three valid algorithms (see 'algorithm' section below).

**Leading Question**
The leading question of finding the shortest distance path is reasonable. You may want to add on to this leading question once you determine your third algorithm (see below).

**Dataset**
The dataset is described clearly, but for data correction you may want to consider other scenarios as well (such as when a data point is missing a field, for example). 

As for data storage, it's fine to use an array, but you should mention more in detail what the array will store. What will the indices of the array be? 

**Algorithm**
Your runtime for BFS is correct, although for our purposes O(|V| + |E|) is a more useful metric. One thing that's worth pointing out is how will start and end nodes be identified? I'm assuming you will use some sort of ID for each node, but that is not clearly mentioned.

Note that your runtime for Dijkstra's algorithm is somewhat ambitious, as the runtime you have given uses a Fibonnaci heap implementation which is slightly more advanced. You may want to consider using the priority queue implementation, which has a runtime of O((E + V)log(V)).

The main issue with  your proposal (and the reason for an 'incomplete' grade) is that you have not specified a third algorithm. Note that this third algorithm must be an 'uncovered' algorithm (please see the 'Project Goals' link from the final project webpage for more details).
