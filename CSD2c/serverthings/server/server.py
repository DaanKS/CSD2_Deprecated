from tkinter import *
import socket
import time
import pickle

HEADERSIZE = 10


root = Tk()
root.title('Slider')
root.geometry("400x400")


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(),1235))
s.listen(5)

while True:
    clientsocket, address = s.accept()
    print(f"Connection from {address} has been established!")

    def slide(var):
        d = horizontal.get()
        msg = pickle.dumps(d)
        msg = bytes(f'{len(msg):<{HEADERSIZE}}', "utf-8") + msg
        clientsocket.send(msg)

    vertical = Scale(root,from_=100, to=0, command=slide)
    vertical.pack()

    horizontal = Scale(root, from_=0, to=100, command=slide)
    horizontal.pack()

    root.mainloop()
