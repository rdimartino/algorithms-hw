# pip install graphviz
import graphviz

# neato (or fdp) is required for inputscale and pos
g = graphviz.Digraph(name="G", format="png", engine="neato", graph_attr={"inputscale": "1.5", "size": "2,4!"})
g.attr("node", shape="circle")

# Nodes (x,y)
nodes = [
    (1,1),
    (2,0),
    (4,0),
    (5,1),
    (4,2),
    (2,2),
    (0,2),
    (0,0)
]

#Edges (start,end,weight)
edges = [
    (0,1,4),
    (0,5,2),
    (0,7,3),
    (1,2,7),
    (1,5,3),
    (1,7,9),
    (2,3,5),
    (2,4,3),
    (2,5,8),
    (3,4,2),
    (4,5,6),
    (5,6,2),
    (6,7,8)
]

def markdownTableRow(arr):
    return "{1}{0}{1}".format("|".join(arr), "|")

def Prim(graph, nodes, edges, root):
    n = len(nodes)
    nearest = [float("inf")] * n
    inTree = [False] * n
    parent = [None] * n
    chosenEdges = [False] * len(edges)
    total = 0
    graph.node("r", shape="plaintext")
    graph.edge("r",str(root))

    parent[root], nearest[root] = -1, 0
    for stage in range(n):
        minWeight, u = min((val, idx) for (idx, val) in enumerate(nearest) if not inTree[idx])
        inTree[u] = True
        total += minWeight

        for start,stop,weight in edges:
            if u == start and not inTree[stop]:
                v = stop
            elif u == stop and not inTree[start]:
                v = start
            else:
                continue
            if weight < nearest[v]:
                nearest[v] = weight
                parent[v] = u

        # Render graph
        g = graph.copy()
        for idx, (x,y) in enumerate(nodes):
            g.node(
                str(idx),
                pos="{},{}!".format(x,y),
                style="filled",
                fillcolor="grey" if inTree[idx] else "white"
            )

        for start,stop,weight in edges:
            solid = (parent[start] == stop or parent[stop] == start)
            fixed = (solid and inTree[start] and inTree[stop])
            direction = ("none" if not solid
                else "forward" if parent[start] == stop
                else "back")
            g.edge(
                str(start),
                str(stop),
                label=str(weight),
                style="solid" if solid or fixed else "dotted",
                penwidth="2" if fixed else "1",
                dir=direction
            )
        g.render("images/4/prim/stage-{}".format(stage),cleanup=True)

        # Print markdown results
        print("{0}. Stage {0}".format(stage))
        print("  "+markdownTableRow(["i"]+[str(i) for i in range(n)]))
        print("  "+markdownTableRow([":--:"]*(n+1)))
        print("  "+markdownTableRow(["nearest[i]"]+[str(w) for w in nearest]))
        print("  "+markdownTableRow(["parent[i]"]+[str(p) if p is not None else "-" for p in parent]))
        print("  "+markdownTableRow(["inTree[i]"]+["T" if t else "F" for t in inTree]))
        print("  Weight = {}".format(total))
        print("  ![Stage {0} diagram](images/4/prim/stage-{0}.png)\n\n".format(stage))

def Kruskal(graph, nodes, edges):
    sortedEdges = sorted(edges, key=lambda e: e[2])
    n = len(nodes)
    forest, size = [], 0
    parents = [-1] * n
    j = -1
    while size < n-1 and j < len(edges):
        j += 1
        g = graph.copy()
        parents, r = find(parents, sortedEdges[j][0])
        parents, s = find(parents, sortedEdges[j][1])
        if r != s:
            forest.append(sortedEdges[j])
            size += 1
            parents = union(parents, r, s)
            for idx, (x,y) in enumerate(nodes):
                g.node(
                    str(idx),
                    pos="{},{}!".format(x,y),
                    style=None if idx in [node for e in forest for node in [*e][:2]] else "invis")

            for start,stop,weight in forest:
                g.edge(
                    str(start),
                    str(stop),
                    label=str(weight),
                    dir='none'
                )
            g.render("images/4/kruskal/stage-{}".format(size),cleanup=True)
            print("{0}. Stage {0}".format(size))
            print("  ![Stage {0} diagram](images/4/kruskal/stage-{0}.png)\n\n".format(size))


def find(parents, x):
    r = x
    while parents[r]>=0:
        r = parents[r]
    y = x
    while y != r:
        temp = parents[y]
        parents[y] = r
        y = temp
    return parents, r

def union(parents, r, s):
    total = parents[r] + parents[s]
    if parents[r] > parents[s]:
        parents[r] = s
        parents[s] = total
    else:
        parents[s] = r
        parents[r] = total
    return parents

Kruskal(g.copy(), nodes, edges)
Prim(g.copy(), nodes, edges, 1)


for idx, (x,y) in enumerate(nodes):
    g.node(str(idx), pos="{},{}!".format(x,y))

for start,stop,weight in edges:
    g.edge(str(start), str(stop), label=str(weight), dir='none')
g.render("images/4/graph-G",cleanup=True)
