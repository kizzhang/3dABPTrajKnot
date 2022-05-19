"""
Created on Wed May  4 13:22:23 2022

@author: Zhiyu
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt

box_r = 1
df = pd.read_csv('S:\Programs\knot\BrownWalk\walk_trajectory.txt',  header = None,index_col= False,)
num = df.iloc[0].to_numpy(dtype ='int')[0]
x = np.zeros((1000,3))

for i in range(num):
    x[i][0] = df.iloc[i+1].str.split(pat = '\t',).to_numpy()[0][1]
    x[i][1] = df.iloc[i+1].str.split(pat = '\t',).to_numpy()[0][2]
    x[i][2] = df.iloc[i+1].str.split(pat = '\t',).to_numpy()[0][3]
    
fig = plt.figure(1)
ax = plt.axes(projection='3d')
ax.plot3D(x[:,0], x[:,1], x[:,2])    
u, v = np.mgrid[0:2*np.pi:20j, 0:np.pi:10j]
sph_x = box_r * np.cos(u)*np.sin(v)
sph_y = box_r * np.sin(u)*np.sin(v)
sph_z = box_r * np.cos(v)
ax.plot_wireframe(sph_x, sph_y, sph_z, color="k")
#df['result'] = df['result'].str.replace(r'\D', '')

# fig = plt.figure()
# ax = fig.gca(projection='3d')
# ax.set_aspect("equal")



# for  i in range(0,1000):
#     fig = plt.figure(dpi=111)
#     ax = plt.axes(xlim=(-1*box_r - 4, 1*box_r + 4), ylim=(-1*box_r- 4, 1*box_r + 4))
#     ax.set_aspect(1)
#     circle2 = plt.Circle((0, 0), box_r, color='k', fill=False)
#     ax.add_patch(circle2)
#     ax.plot(x[i][0], x[i][1], 'ro')
#     ax.set_xlabel("x")
#     ax.set_ylabel("y")
# #   ax.quiver(x[:,i][0], x[:,i][1],\
# #                 5 * np.cos(phi[:,i]), 5 * np.sin(phi[:,i]), scale_units='x',scale = 1)
#     ax = plt.gca()
#     plt.axis('off')
#     plt.savefig(r"C:\Users\Zhiyu\Documents\test\snap_{0}.png".format(i))
#     plt.close()         