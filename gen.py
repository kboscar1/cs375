import sys
import random
from random import randint

#
#To run "python gen.py <fileName> <#nodes> <avgEdgesPerNode> <avgWeightPerNode>"
#Edit randomEdgeRatio & randomWeightRatio 



#factor of randomness for amount of edges
randomEdgeRatio = .3
#factor of randomness for weight per node
randomWeightRatio = .3

fileName = sys.argv[1]
File = open(fileName,'w') 
anumNodes = sys.argv[2]
aavgEdges = sys.argv[3]
aavgWeight = sys.argv[4]
numNodes = int(anumNodes)
avgEdges = int(aavgEdges)
avgWeight = int(aavgWeight)


File.write("{}\n".format(numNodes))
for fromNode in range(0,numNodes):
	numEdges = avgEdges
	numEdges += randint(int(-(avgEdges*randomEdgeRatio)),int(avgEdges*randomEdgeRatio))
	previousToNode = [fromNode]
	for x in range(0,numEdges):
		weight = avgWeight
		weight += randint(int(-(avgWeight*randomWeightRatio)),int(avgWeight*randomWeightRatio))
		notUnique = True
		while notUnique:
			toNode = randint(0, numNodes-1)
			if toNode not in previousToNode:
				previousToNode.append(toNode)
				notUnique = False

		File.write("{} {} {}\n".format(fromNode, toNode, weight))