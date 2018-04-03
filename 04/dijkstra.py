# pip install graphviz
import graphviz

g = graphviz.Digraph(name="G", format="png", engine="neato", graph_attr={"inputscale": "1.5", "size": "1.6,3.2!"})
g.attr("node", shape="circle")

# Nodes (x,y)
nodes = [
    (0,1),
    (1,0),
    (3,0),
    (4,1),
    (3,2),
    (1,2)
]

#Edges (start,end,weight)
edges = [
    (0,1,3),
    (1,2,1),
    (1,5,2),
    (2,1,13),
    (2,3,3),
    (2,5,9),
    (3,4,1),
    (4,2,3),
    (4,5,4),
    (5,0,1)
]

def markdownTableRow(arr):
    return "{1}{0}{1}".format("|".join(arr), "|")

def Dijkstra(graph, nodes, edges, root):
    n = len(nodes)
    dist = [float("inf")]*n
    inTree = [False]*n
    parent = [None]*n
    dist[root], parent[root] = 0, -1
    path = []
    for stage in range(n):
        minDist, u = min((val, idx) for (idx, val) in enumerate(dist) if not inTree[idx])
        inTree[u] = True
        path.append((parent[u],u,minDist))

        for start,stop,weight in edges:
            if u == start and not inTree[stop]:
                v = stop
            else:
                continue
            if dist[u]+weight<dist[v]:
                dist[v] = dist[u]+weight
                parent[v] = u

        # render graph
        g = graph.copy()
        for idx, (x,y) in enumerate(nodes):
            g.node(
                str(idx),
                pos="{},{}!".format(x,y),
                style="filled",
                fillcolor="grey" if inTree[idx] else "white"
            )

        for start,stop,weight in edges:
            solid = (parent[stop] == start)
            fixed = (solid and inTree[start] and inTree[stop])
            g.edge(
                str(start),
                str(stop),
                label=str(weight),
                style="solid" if solid or fixed else "dotted",
                arrowhead="normal" if solid or fixed else "empty",
                penwidth="2" if fixed else "1"
            )
        g.render("dijkstra-r{}-stage-{}".format(root,stage),cleanup=True)

        # render markdown
        print("{0}. Stage {0}".format(stage))
        print("  "+markdownTableRow(["i"]+[str(i) for i in range(n)]))
        print("  "+markdownTableRow([":--:"]*(n+1)))
        print("  "+markdownTableRow(["dist[i]"]+[str(d) for d in dist]))
        print("  "+markdownTableRow(["parent[i]"]+[str(p) if p is not None else "-" for p in parent]))
        print("  "+markdownTableRow(["inTree[i]"]+["T" if t else "F" for t in inTree]))
        print("  ![Stage {0} diagram](dijkstra-r{1}-stage-{0}.png)\n\n".format(stage, root))

    #render result
    g = graph.copy()
    for idx, (x,y) in enumerate(nodes):
        g.node(
            str(idx),
            pos="{},{}!".format(x,y),
        )

    for start,stop,weight in path[1:]:
        g.edge(
            str(start),
            str(stop),
            label=str(weight)
        )
    g.render("dijkstra-r{}-result".format(root),cleanup=True)


Dijkstra(g.copy(), nodes, edges, 2)
Dijkstra(g.copy(), nodes, edges, 3)

for idx, (x,y) in enumerate(nodes):
    g.node(str(idx), pos="{},{}!".format(x,y))
for start,stop,weight in edges:
    g.edge(str(start), str(stop), label=str(weight))
g.render("digraph-dijkstra",cleanup=True)
