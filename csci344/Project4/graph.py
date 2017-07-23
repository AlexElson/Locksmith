import pygraphviz as pgv
import os, shutil
from subprocess import call                                                      
if (os.path.isdir("images")):                                                         
    shutil.rmtree("images", ignore_errors=False, onerror=None)
os.makedirs("images")                                                            

G=pgv.AGraph()
G.graph_attr['label']='The Best Graph'                                            
G.node_attr['style']='filled'
G.node_attr['shape']='circle'

c = 0
with open('duplications.txt') as f:
    begin = int(f.readline())
    num = 0
    for line in f:
        num = num + 1
        G.node_attr['fillcolor']=line.rstrip()
        G.add_node(num)
        c = c + 1
        if (num >= begin):
            break

    for a in range(begin):
        for b in range(begin):
            if (a != b):
                G.add_edge(a+1,b+1,color='black')

    for copy in f:
        c = c + 1
        op = copy.split()
        for n in range(len(op)):
            if (n < 2):
                G.add_node(op[0])
                e1 = G.get_node(op[0])
                e2 = G.get_node(op[1])
                e1.attr['fillcolor'] = e2.attr['fillcolor']
            else:
                if (op[n][0] == 'c'):
                    G.add_edge(op[0], op[n][1:], color='black')
                if (op[n][0] == 'm'):
                    G.remove_edge(op[1], op[n][1:])
                    G.add_edge(op[0], op[n][1:])
                    #G.get_edge(op[0], op[n][1:]).attr['len']=2

G.layout()

pos = []
color = []
for n in range(0,c):
    pos.append([float(x) for x in G.get_node(n+1).attr["pos"].split(',')])
    color.append(G.get_node(n+1).attr["fillcolor"])
    print(pos[n])
    #print(color[n])

Q=pgv.AGraph()
Q.graph_attr['label']='The Best Graph'
Q.node_attr['style']='filled'
Q.node_attr['shape']='circle'
Q.graph_attr['pad']='100'
Q.graph_attr['size']="100,100"

#for n in range(len(pos)):
order = 0
with open('duplications.txt') as f:
    begin = int(f.readline())
    num = 0
    for line in f:
        num = num + 1
        Q.add_node(num, pos="%f,%f" % (pos[num-1][0], pos[num-1][1]), fillcolor=line.rstrip())
        if (num >= begin):
            break

    for a in range(begin):
        for b in range(begin):
            if (a != b):
                Q.add_edge(a+1,b+1,color='black')

    for copy in f:
        op = copy.split()
        for n in range(len(op)):
            if (n < 2):
                Q.add_node(op[0])
                e1 = Q.get_node(op[0])
                e2 = Q.get_node(op[1])
                e1.attr['fillcolor'] = e2.attr['fillcolor']
                e1.attr['pos'] = e2.attr['pos']
                #e1.attr['pos'] = "%f,%f" % (pos[ int(op[1]) ][0], pos[ int(op[1]) ][1] )
            else:
                if (op[n][0] == 'c'):
                    Q.add_edge(op[0], op[n][1:], color='black')
                if (op[n][0] == 'm'):
                    Q.remove_edge(op[1], op[n][1:])
                    Q.add_edge(op[0], op[n][1:])

        #print(pos[int(op[0])-1])
        d = Q.get_node(op[0]).attr['pos'].split(',')

        for n in range(11):

            x = pos[int(op[0])-1][0]
            y = pos[int(op[0])-1][1]
            dx = x - float(d[0])
            dy = y - float(d[1])

            Q.get_node(op[0]).attr['pos']="%f,%f" % (float(d[0]) + dx/10.0*n, float(d[1]) + dy/10.0*n)
            Q.write("images/%d.dot" % (order))
            Q.draw("images/%d.gif" % (order), prog='neato', args='-n2')
            os.remove("images/%d.dot" % (order))
            order = order + 1
            print(order)

#for n in range(4):
#    print(Q.get_node(n+1).attr["pos"])
#    print(pos[n])

os.system("gifsicle --crop 0,0-511,413 --colors 256 -V --delay=1 --optimize=3 images/* >final.gif")

#call(['gifsicle', '--colors', '256', '--delay=10', '--optimize=3', 'images/*', '>', 'final.gif'])

#Q.layout(args='-n2')
#Q.write("file.dot")
#Q.draw("file.gif",prog='neato', args='-n2')