from tkinter import *
import socket
import sys

root = Tk()
root.title('Slider')
root.geometry("400x400")


HEADERSIZE = 10

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 54000))


while True:
    def slide(var):
        d = horizontal.get()
    #    e = vertical.get()

        s.sendall(f"{d}".encode())
    #    s.sendall(f"V{e}".encode())

    vertical = Scale(root,from_=100, to=0,length=390, command=slide)
    vertical.grid(row=0, column=0)

    horizontal = Scale(root, from_=100, to=0,length=390, command=slide)
    horizontal.grid(row=0, column=1)

    root.mainloop()
