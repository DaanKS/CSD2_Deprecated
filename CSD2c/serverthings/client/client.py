from tkinter import *
import socket
import pickle

root = Tk()
root.title('Slider')
root.geometry("400x400")


HEADERSIZE = 10

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 54000))

while True:
'''
    full_msg = b''
    new_msg = True
    while True:
        msg = s.recv(16)
        if new_msg:
            print(f"new message length: {msg[:HEADERSIZE]}")
            msglen = int(msg[:HEADERSIZE])
            new_msg = False

        full_msg += msg

        if len(full_msg)-HEADERSIZE == msglen:
            print("full msg recvd")
            print(full_msg[HEADERSIZE:])

            d = pickle.loads(full_msg[HEADERSIZE:])
            print(d)

            new_msg = True
            full_msg = b''
    print(full_msg)
'''

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
