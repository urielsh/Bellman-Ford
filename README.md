# Bellman-Ford

bellman ford algorithm for network routing.
All the connections through UDP sockets.
Here is an example of the input file:
3                        // number of router nodes
Router1 127.0.0.1 7000   // name,IP,Port
Router2 127.0.0.1 8000
Router3 127.0.0.1 9000
Router1 Router2 1      // route,distance
Router1 Router3 2
Router2 Router3 7

