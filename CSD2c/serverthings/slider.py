from tkinter import *

root = Tk()
root.title('Slider')
root.geometry("400x400")

def slide(var):
#    my_label = Label(root, text=vertical.get()).pack()
#    my_label2 = Label(root, text=horizontal.get()).pack()
    root.geometry(str(horizontal.get()) + "x" + str(vertical.get()))

vertical = Scale(root,from_=800, to=200, command=slide)
vertical.grid(row=0, column=0)

horizontal = Scale(root, from_=100, to=800, orient=HORIZONTAL, command=slide)
horizontal.grid(row=1, column=0)

#my_label = Label(root, text=vertical.get()).pack()
#my_label2 = Label(root, text=horizontal.get()).pack()



#my_button = Button(root, text="lick me!", command=slide).pack()


#event loop
root.mainloop()
