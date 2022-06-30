#------------------------------------------------------------------------------#
#      Interactive polar plot, Jun 2022, by Ahmad Ikhyari & Ali Rhomadoni      #
#------------------------------------------------------------------------------#

import socket
import numpy as np
import matplotlib.pyplot as plt

# for more sophisticated visuals, use
plt.style.use('ggplot')

# the function below is for updating radius values of a polar plot
def live_plotter(a_vec,r1_data,line1,keyword='',identifier='',pause_time=0.01):
    if line1==[]:
        # this is the call to matplotlib that allows dynamic plotting
        plt.ion()
        # initiating a blank figure
        fig = plt.figure()                    # fig = plt.figure(figsize=(13,6))
        # for a polar plot...
        ax = fig.add_subplot(111, projection='polar')
        # making a certain offset for theta = 0 at the polar plot
        ax.set_theta_zero_location('N')
        # create a variable for the line so we can later update it
        line1, = ax.plot(a_vec,r1_data,keyword,alpha=0.8)
        # update plot title
        plt.title(''.format(identifier))
        # do not forget, as long as you want to display the plot, to have this!
        plt.show()
    
    # after the figure, axis, and line are created,
    # we only need to update the y-data
    line1.set_ydata(r1_data)
    # adjust limits if new data goes beyond bounds
    if np.min(r1_data)<=line1.axes.get_ylim()[0] \
    or np.max(r1_data)>=line1.axes.get_ylim()[1]:
        plt.ylim([np.min(r1_data)-np.std(r1_data), \
                  np.max(r1_data)+np.std(r1_data)])
    # this pauses the data so the figure/axis can catch up
    # the amount of pause can be altered above
    plt.pause(pause_time)
    
    # return line so we can update it again in the next iteration
    return line1

# a function for taking out the desired value/string among a message string
def find_between( s, first, last ):
    try:
        start = s.index( first ) + len( first )
        end = s.index( last, start )
        return s[start:end]
    except ValueError:
        return ""

# Initiating all values related to UDP connection
localIP     = "192.168.10.11"
localPort   = 8888
bufferSize  = 8192

# Create a datagram socket
UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

# Bind to address and IP
UDPServerSocket.bind((localIP, localPort))

# Displaying a message when UDP connection is ready
print("UDP server up and listening")

# Initializations
# declaring the presumably fixed theta array size
size = int(360*2.5)
# theta in degrees
d_vec = np.linspace(0,360,size+1)                                       # [0:-1]
# theta in radians
p_vec = d_vec / 180 * np.pi
# assigning a preset power values at all theta values
r_vec = np.linspace(-70,-70,size+1)
# creating a variable for plot line
line1 = []
# declaring a dedicated plot data file
file = open('data.csv','a')                                        # append mode
# for data counting purpose
j = 0;

# Listen for incoming datagrams
STATUS = True                                                   # Initial status
while(STATUS):                                         # iteration goes ahead...
    # Returns a bytes object read from an UDP socket
    # and the address of the client socket as a tuple
    bytesAddressPair = UDPServerSocket.recvfrom(bufferSize)
    message = bytesAddressPair[0]                # address = bytesAddressPair[1]

    #clientMsg = "Message from Client:{}".format(message)
    #clientIP  = "Client IP Address:{}".format(address)

    # extracting both power and angle data from received UDP data
    # calling "find_between" predefined function
    power = find_between( str(message), "#", ";" )
    angle = find_between( str(message), ";", "*" )
    print(power)
    print(angle)
    
    # inspecting the suitable array element number for each angle in degree
    i = int(float(angle) * size / 360)
    # assigning the updated power value at each angle
    r_vec[i] = float(power)
    # plotting, calling "live_plotter" predefined function
    line1 = live_plotter(p_vec,r_vec,line1)
    # file writing format
    file.write(str(angle)+(",")+str(power)+"\n")
    # addition assignment, every single power::angle measurement
    j += 1
    if j > size:        # while the iteration reached the end of its allocation,
        STATUS=False          # ...program, by means of iteration, is terminated

# closing the data file
file.close()
