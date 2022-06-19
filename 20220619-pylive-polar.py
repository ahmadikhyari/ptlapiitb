import socket
import numpy as np
import matplotlib.pyplot as plt

plt.style.use('ggplot')

def live_plotter(a_vec,r1_data,line1,keyword='',identifier='',pause_time=0.01):
    if line1==[]:
        # this is the call to matplotlib that allows dynamic plotting
        plt.ion()
        fig = plt.figure() # fig = plt.figure(figsize=(13,6))
        # create a variable for the line so we can later update it
        line1, = plt.polar(a_vec,r1_data,keyword,alpha=0.8)        
        # update plot title
        plt.title('Title: {}'.format(identifier))
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

def find_between( s, first, last ):
    try:
        start = s.index( first ) + len( first )
        end = s.index( last, start )
        return s[start:end]
    except ValueError:
        return ""

def find_between_r( s, first, last ):
    try:
        start = s.rindex( first ) + len( first )
        end = s.rindex( last, start )
        return s[start:end]
    except ValueError:
        return ""


localIP     = "192.168.10.11"

localPort   = 8888

bufferSize  = 1024

data = [];
 

msgFromServer       = "Hello UDP Client, Im From PC Ali"

bytesToSend         = str.encode(msgFromServer)

 

# Create a datagram socket

UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

 

# Bind to address and ip

UDPServerSocket.bind((localIP, localPort))

 

print("UDP server up and listening")

 
# Initialization

size = 360*4
line1 = []
d_vec = np.linspace(0,360,size+1) # [0:-1]
p_vec = d_vec / 180 * np.pi
r_vec = np.linspace(-70,-70,size+1)

# Listen for incoming datagrams

while(True):

    bytesAddressPair = UDPServerSocket.recvfrom(bufferSize)

    message = bytesAddressPair[0]
    

    address = bytesAddressPair[1]

    clientMsg = "Message from Client:{}".format(message)
    clientIP  = "Client IP Address:{}".format(address)
    
    power = find_between( str(message), "#", ";" )
    angle = find_between( str(message), ";", "*" )
    #print(str(message))
    
    #data.append ([float(angle),float(power)])
    print(power)
    print(angle)
    i = int(float(angle) * 4)
    r_vec[i] = float(power)
    line1 = live_plotter(p_vec,r_vec,line1)
    #plt.rcParams["figure.figsize"] = [7.50, 3.50]
    #plt.rcParams["figure.autolayout"] = True
    #plt.plot(data)
    #print(str(address))
    #print (bytesAddressPair)

   

    # Sending a reply to client

   # UDPServerSocket.sendto(bytesToSend, address)
